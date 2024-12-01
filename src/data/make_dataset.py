import pandas as pd
from glob import glob
from pathlib import Path

# --------------------------------------------------------------
# Read single CSV file
# --------------------------------------------------------------

# Загрузка данных для акселерометра
single_file_acc = pd.read_csv("../../data/raw/MetaMotion/A-bench-heavy2-rpe8_MetaWear_2019-01-11T16.10.08.270_C42732BE255C_Accelerometer_12.500Hz_1.4.4.csv")

# Загрузка данных для гироскопа
single_file_gyr = pd.read_csv("../../data/raw/MetaMotion/A-bench-heavy2-rpe8_MetaWear_2019-01-11T16.10.08.270_C42732BE255C_Gyroscope_25.000Hz_1.4.4.csv")

# --------------------------------------------------------------
# List all data in data/raw/MetaMotion
# --------------------------------------------------------------

files = glob("../../data/raw/MetaMotion/*.csv")
len(files)

# --------------------------------------------------------------
# Extract features from filename
# --------------------------------------------------------------
def read_data_from_files(files):
    data_path = "../../data/raw/MetaMotion/"

    acc_df = pd.DataFrame()
    gyr_df = pd.DataFrame()

    acc_set = 1
    gyr_set = 1

    for f in files:
        normalized_path = Path(f).name  # Извлекает только имя файла
        df=pd.read_csv(f)
        particepment = normalized_path.split("-")[0]
        label = normalized_path.split("-")[1]
        category = normalized_path.split("-")[2].rstrip("12345").rstrip("_MetaWear_2019")

        df = pd.read_csv(f)
        df["particepment"] = particepment
        df["label"] = label
        df["category"] = category

        if "Accelerometer" in f:
            df["set"]=acc_set
            acc_df = pd.concat([acc_df, df], ignore_index=True)
            acc_set += 1
        elif "Gyroscope" in f:
            df["set"]=acc_set
            df["set"]=gyr_set

            gyr_df = pd.concat([gyr_df, df], ignore_index=True)
            gyr_set += 1
    
        
        
    # --------------------------------------------------------------
    # Working with datetimes
    # --------------------------------------------------------------
    pd.to_datetime(df["epoch (ms)"],unit="ms")
    pd.to_datetime(df["time (01:00)"]).dt.month
    acc_df.index = pd.to_datetime(acc_df["epoch (ms)"], unit="ms")
    gyr_df.index = pd.to_datetime(gyr_df["epoch (ms)"], unit="ms")

    del acc_df["epoch (ms)"]
    del acc_df["time (01:00)"]
    del acc_df["elapsed (s)"]

    del gyr_df["epoch (ms)"]
    del gyr_df["time (01:00)"]
    del gyr_df["elapsed (s)"]
    return acc_df,gyr_df
acc_df,gyr_df=read_data_from_files(files)



# --------------------------------------------------------------
# Merging datasets
# --------------------------------------------------------------
data_merged=pd.concat([acc_df.iloc[:,:3],gyr_df],axis=1)
data_merged.head(50)

data_merged.columns = [
    "acc_x",
    "acc_y",
    "acc_z",
    "gyr_x",
    "gyr_y",
    "gyr_z",
    "participant",
    "label",
    "category",
    "set",
]
# --------------------------------------------------------------
# Resample data (frequency conversion)
# --------------------------------------------------------------
days = [g for n, g in data_merged.groupby(pd.Grouper(freq="D"))] 
# Определяем словарь для передискретизации
sampling = {
    "acc_x": "mean",
    "acc_y": "mean",
    "acc_z": "mean",
    "gyr_x": "mean",
    "gyr_y": "mean",
    "gyr_z": "mean",
    "participant": "last",
    "label": "last",
    "category": "last",
    "set": "last",
}

resampled_data = data_merged[:1000].resample(rule="200ms").apply(sampling)


data_resampled = pd.concat([df.resample(rule='200ms').apply(sampling).dropna() for df in days])
# Accelerometer:    12.500HZ
# Gyroscope:        25.000Hz
data_resampled["set"]=data_resampled["set"].astype("int")
data_resampled.info()
# --------------------------------------------------------------
# Export dataset
# --------------------------------------------------------------
data_resampled.to_pickle("../../data/interim/01_data_processed.pkl")
