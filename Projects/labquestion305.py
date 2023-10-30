import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Simulated data for a given time period (e.g., days)
days = 100
date_range = pd.date_range(start="2023-01-01", periods=days, freq="D")

# Generating random data for simulation
np.random.seed(42)
corruption = np.random.randint(0, 5, days)  # Random corruption incidents
degradation = np.random.randint(0, 10, days)  # Random degradation incidents
unauthorized_access = np.random.randint(0, 3, days)  # Random unauthorized access incidents
redundancy = np.random.randint(95, 100, days)  # Random redundancy percentage
error_recovery = np.random.randint(90, 100, days)  # Random error recovery percentage

# Building the DataFrame
data = {
    "Date": date_range,
    "Data Corruption": corruption,
    "Data Degradation": degradation,
    "Unauthorized Access": unauthorized_access,
    "Redundancy (%)": redundancy,
    "Error Recovery (%)": error_recovery,
}
df = pd.DataFrame(data)
df.set_index("Date", inplace=True)

# Plotting the data
fig, ax = plt.subplots(2, 1, figsize=(12, 10))

# Subplot for incidents
df[["Data Corruption", "Data Degradation", "Unauthorized Access"]].plot(ax=ax[0], marker='o')
ax[0].set_title("Incidents Over Time")
ax[0].set_ylabel("Number of Incidents")
ax[0].legend(loc="upper left")

# Subplot for percentages
df[["Redundancy (%)", "Error Recovery (%)"]].plot(ax=ax[1], marker='o')
ax[1].set_title("Redundancy and Error Recovery Over Time")
ax[1].set_ylabel("Percentage (%)")
ax[1].legend(loc="upper left")

plt.tight_layout()
plt.show()
