import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

# Load dataset
data = pd.read_csv("datasets/training_dataset.csv")

X = data[["Soil_Moisture", "Temperature", "Humidity"]]
y = data["Irrigation_Required"]

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Train model
model = RandomForestClassifier(n_estimators=100, random_state=42)
model.fit(X_train, y_train)

# Evaluate
print("Accuracy:", accuracy_score(y_test, model.predict(X_test)))

# Example prediction
print("Prediction (Moisture=22, Temp=32, Humidity=55):", model.predict([[22, 32, 55]]))
