def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])

    return parent[x]

def union_parent(parent, a, b):
    a_parent = find_parent(parent, a)
    b_parent = find_parent(parent, b)

    if a_parent < b_parent:
        parent[b_parent] = a_parent
    else:
        parent[a_parent] = b_parent

v, e = map(int, input().split())
parent = [0] * (v + 1)

edges = []
result = 0
last_cost = 0

for i in range(1, v + 1):
    parent[i] = i

for _ in range(e):
    a, b, cost = map(int, input().split())

    edges.append((cost, a, b))


edges.sort()

for edge in edges:
    cost, a, b = edge

    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        result += cost
        last_cost = cost

print(result - last_cost)
