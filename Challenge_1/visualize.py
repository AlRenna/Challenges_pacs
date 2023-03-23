import pandas as pd
import matplotlib.pyplot as plt


def plot_result(filename):
    df = pd.read_csv(filename)
    plt.figure()
    plt.plot(df["t"], df["y_t"], label="Numerical Result")
    plt.ylabel("y(t)")
    plt.xlabel("t")
    plt.legend()
    plt.savefig("result.png")



if __name__ == "__main__":
    plot_result("result.txt")
    plot_result("result_muparser.txt")