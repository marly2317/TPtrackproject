import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
from LearningAlgorithms import ClassificationAlgorithms
import seaborn as sns
import itertools
from sklearn.metrics import accuracy_score, confusion_matrix


# Plot settings
plt.style.use("fivethirtyeight")
plt.rcParams["figure.figsize"] = (20, 5)
plt.rcParams["figure.dpi"] = 100
plt.rcParams["lines.linewidth"] = 2

df=pd.read_pickle("../../data/interim/03_data_features.pkl")

# --------------------------------------------------------------
# Create a training and test set
# --------------------------------------------------------------

df_train=df.drop(["participant","category","set"],axis=1)
X=df_train.drop(["label"],axis=1)
y=df_train["label"]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

fig, ax = plt.subplots(figsize=(10, 5))

# Построение гистограммы для общего количества меток
df_train["label"].value_counts().plot(kind="bar", ax=ax, color="lightblue", label="Total")

# Построение гистограммы для количества меток в обучающей выборке
y_train.value_counts().plot(kind="bar", ax=ax, color="dodgerblue", label="Train")

# Построение гистограммы для количества меток в тестовой выборке
y_test.value_counts().plot(kind="bar", ax=ax, color="royalblue", label="Test")

# Добавление легенды
plt.legend()

# Отображение графика
plt.show()
# --------------------------------------------------------------
# Split feature subsets
# --------------------------------------------------------------
basic_features=["acc_x","acc_y","acc_z","gyr_x","gyr_x","gyr_x"]
square_features=["acc_r","gyr_r"]
pca_features=['pca_1','pca_2','pca_3']
time_features = [f for f in df_train.columns if "_temp_" in f]
freq_features = [f for f in df_train.columns if ("_freq" in f) or ("_pce_" in f)]
cluster_features=["cluster"]

feature_set_1 = list(set(basic_features))

feature_set_2 = list(set(basic_features + square_features + pca_features))

feature_set_3 = list(set(feature_set_2 + time_features))

feature_set_4 = list(set(feature_set_3 + freq_features + cluster_features))

# --------------------------------------------------------------
# Perform forward feature selection using simple decision tree
# --------------------------------------------------------------


# --------------------------------------------------------------
# Grid search for best hyperparameters and model selection
# --------------------------------------------------------------


# --------------------------------------------------------------
# Create a grouped bar plot to compare the results
# --------------------------------------------------------------


# --------------------------------------------------------------
# Select best model and evaluate results
# --------------------------------------------------------------


# --------------------------------------------------------------
# Select train and test data based on participant
# --------------------------------------------------------------


# --------------------------------------------------------------
# Use best model again and evaluate results
# --------------------------------------------------------------


# --------------------------------------------------------------
# Try a simpler model with the selected features
# --------------------------------------------------------------