import pandas as pd
import matplotlib.pyplot as plt

csv_file = "benchmark_results.csv"
df = pd.read_csv(csv_file, skiprows=1)

sizes = df.iloc[:, 0]
dense_times = df.iloc[:, 1]
csr_times = df.iloc[:, 3]

plt.figure(figsize=(10, 6))
plt.plot(sizes, dense_times, marker='o', linestyle='-', label='Dense Matrix')
plt.plot(sizes, csr_times, marker='s', linestyle='-', label='CSR Matrix')

plt.xlabel("Размер матрицы")
plt.ylabel("Время (сек)")
plt.title("Скорость умножения матриц на вектор")
plt.legend()
plt.grid(True)

plt.savefig("benchmark_plot.png")
plt.show()
