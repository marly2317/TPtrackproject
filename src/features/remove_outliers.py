import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import math
import scipy
from sklearn.neighbors import LocalOutlierFactor
from sklearn.preprocessing import StandardScaler


df = pd.read_pickle("../../data/interim/01_data_processed.pkl")

numerical_cols = df.select_dtypes(include=[np.number]).columns
outlier_columns = list(numerical_cols)

for col in outlier_columns:
    df[col] = pd.to_numeric(df[col], errors='coerce')

df = df.dropna()


def plot_binary_outliers(dataset, col, outlier_col, reset_index):
    if outlier_col not in dataset.columns:
        return
    
    dataset = dataset.dropna(axis=0, subset=[col, outlier_col])
    dataset[outlier_col] = dataset[outlier_col].astype("bool")
    
    if reset_index:
        dataset = dataset.reset_index()
    
    fig, ax = plt.subplots()
    plt.xlabel("samples")
    plt.ylabel("value")
    
    ax.plot(dataset.index[~dataset[outlier_col]], dataset[col][~dataset[outlier_col]], "+")
    ax.plot(dataset.index[dataset[outlier_col]], dataset[col][dataset[outlier_col]], "r+")
    
    plt.legend(["outlier " + col, "no outlier " + col], loc="upper center", ncol=2, fancybox=True, shadow=True)
    plt.show()


def mark_outliers_chauvenet(dataset, col, C=2):
    dataset = dataset.copy()
    mean = dataset[col].mean()
    std = dataset[col].std()
    N = len(dataset.index)
    criterion = 1.0 / (C * N)
    
    if std == 0:
        dataset[col + "_outlier"] = False
    else:
        deviation = abs(dataset[col] - mean) / std
        low = -deviation / math.sqrt(C)
        high = deviation / math.sqrt(C)
        prob = 1.0 - 0.5 * (scipy.special.erf(high) - scipy.special.erf(low))
        mask = prob < criterion
        dataset[col + "_outlier"] = mask
    return dataset


def mark_outliers_lof_fixed(dataset, columns, n=10):
    dataset = dataset.copy()
    
    # Масштабируем данные
    scaler = StandardScaler()
    data_scaled = scaler.fit_transform(dataset[columns])
    
    # Применяем LOF
    lof = LocalOutlierFactor(n_neighbors=n, metric='manhattan', novelty=False)
    outliers = lof.fit_predict(data_scaled)
    X_scores = lof.negative_outlier_factor_
    
    # Добавляем информацию о выбросах в DataFrame
    dataset["outlier_lof"] = outliers == -1
    dataset["lof_score"] = X_scores
    return dataset, outliers, X_scores

# Исправленный вызов функции LOF
dataset, outliers, X_scores = mark_outliers_lof_fixed(df, outlier_columns, n=20)

# Построение графиков для LOF
for col in outlier_columns:
    print(f"Plotting column: {col}")
    plot_binary_outliers(dataset=dataset, col=col, outlier_col="outlier_lof", reset_index=True)




for col in outlier_columns:
    for label in df["label"].unique():
        category_dataset = df[df["label"] == label]
        
        category_dataset = mark_outliers_chauvenet(category_dataset, col)
        
        plot_binary_outliers(
            dataset=category_dataset, 
            col=col, 
            outlier_col=col + "_outlier", 
            reset_index=True
        )


for col in outlier_columns:
    print(f"Plotting column: {col}")
    plot_binary_outliers(dataset=dataset, col=col, outlier_col="outlier_lof", reset_index=True)

outliers_removed_df = df.copy()

for col in outlier_columns:
    for label in df["label"].unique():
        dataset = mark_outliers_chauvenet(df[df["label"] == label], col)
        
        dataset.loc[dataset[col + "_outlier"], col] = np.nan
        
        outliers_removed_df.loc[(outliers_removed_df["label"] == label), col] = dataset[col]
        
outliers_removed_df.to_pickle("../../data/interim/02_outliers_removed_df.pkl")
