import re
import matplotlib.pyplot as plt


archivo = "resultados.txt"


patron_N = re.compile(r"N\s*=\s*(\d+)")
patron_stats = re.compile(r"Promedio:\s*([\d.]+)\s*ms,\s*Desviacion:\s*([\d.]+)")


Ns = []
promedios = []
desviaciones = []

with open(archivo, "r") as f:
    for linea in f:
        matchN = patron_N.search(linea)
        if matchN:
            Ns.append(int(matchN.group(1)))
        matchStats = patron_stats.search(linea)
        if matchStats:
            promedios.append(float(matchStats.group(1)))
            desviaciones.append(float(matchStats.group(2)))


plt.figure(figsize=(8,5))
plt.errorbar(Ns, promedios, yerr=deviaciones, fmt='-o', capsize=5, label="Tiempo promedio (ms)")

plt.xscale("log", base=2)  # Escala log base 2 para N
plt.xlabel("Tamaño de entrada N")
plt.ylabel("Tiempo (ms)")
plt.title("Benchmark – Mediana de Medianas")
plt.grid(True, which="both", linestyle="--", alpha=0.6)
plt.legend()
plt.tight_layout()


plt.show()


plt.savefig("benchmark_mediana.pdf")
plt.savefig("benchmark_mediana.png", dpi=300)
print("✅ Gráficas exportadas como 'benchmark_mediana.pdf' y 'benchmark_mediana.png'")
