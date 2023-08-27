import csv
import math

def calculate_distance(point1, point2):
    return math.sqrt((point2[0] - point1[0])**2 + (point2[1] - point1[1])**2)

def nearest_neighbor(points):
    num_points = len(points)
    visited = [False] * num_points
    path = []
    current_point = 0 

    for _ in range(num_points):
        path.append(current_point)
        visited[current_point] = True

        min_distance = float('inf')
        next_point = None

        for i in range(num_points):
            if not visited[i]:
                distance = calculate_distance(points[current_point], points[i])
                if distance < min_distance:
                    min_distance = distance
                    next_point = i

        current_point = next_point

    path.append(path[0]) 
    return path

csv_filename = '1.csv' 
points = []

with open(csv_filename, 'r') as csvfile:
    csvreader = csv.reader(csvfile)
    for row in csvreader:
        x, y = float(row[0]), float(row[1])
        points.append((x, y))


path = nearest_neighbor(points)

output_csv_filename = 'path_coordinates.csv'
with open(output_csv_filename, 'w', newline='') as csvfile:
    csvwriter = csv.writer(csvfile)
    for index in path:
        x, y = points[index]
        csvwriter.writerow([x, y])

print("Path taken:", path)
total_distance = sum(calculate_distance(points[path[i]], points[path[i+1]]) for i in range(len(path)-1))
print("Total distance:", total_distance)
