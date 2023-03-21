import pandas as pd
import matplotlib.pyplot as plt


def plot_result():
    df = pd.read_csv("result.txt")
    plt.figure()
    plt.plot(df["t"], df["y(t)"], label="Numerical Result")
    plt.ylabel("y(t)")
    plt.xlabel("t")
    plt.legend()
    plt.savefig("result.png")



if __name__ == "__main__":
    plot_result()