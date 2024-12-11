import matplotlib.pyplot as plt

# Data for average times in seconds
array_sizes = [10, 100, 1000, 10000, 30000]
bubble_random = [0.000003, 0.000066, 0.004529, 0.434661, 5.654751]
insertion_random = [0.000002, 0.000023, 0.001715, 0.165902, 1.400308]
selection_random = [0.000003, 0.000045, 0.003367, 0.323258, 2.728557]

bubble_reverse = [0.000002, 0.000058, 0.005224, 0.514711, 4.329768]
insertion_reverse = [0.000002, 0.000039, 0.003413, 0.335615, 2.871088]
selection_reverse = [0.000002, 0.000033, 0.002964, 0.278786, 2.479673]

# Create a line plot
plt.figure(figsize=(12, 6))

# Random data
plt.plot(array_sizes, bubble_random, marker='o', label='Bubble Sort (random)', color='blue')
plt.plot(array_sizes, insertion_random, marker='o', label='Insertion Sort (random)', color='orange')
plt.plot(array_sizes, selection_random, marker='o', label='Selection Sort (random)', color='green')

# Reverse data
plt.plot(array_sizes, bubble_reverse, marker='o', linestyle='--', label='Bubble Sort (reverse)', color='cyan')
plt.plot(array_sizes, insertion_reverse, marker='o', linestyle='--', label='Insertion Sort (reverse)', color='red')
plt.plot(array_sizes, selection_reverse, marker='o', linestyle='--', label='Selection Sort (reverse)', color='purple')

# Log scale for better visibility
plt.yscale('log')

# Labels and title
plt.title('Sorting Algorithm Performance Comparison')
plt.xlabel('Array Size')
plt.ylabel('Average Time (seconds)')
plt.xticks(array_sizes)
plt.grid(True, which="both", ls="--")
plt.legend()
plt.tight_layout()

# Show the plot
plt.savefig('sorting_algorithm_comparison.png')  # Save as PNG
plt.show()
