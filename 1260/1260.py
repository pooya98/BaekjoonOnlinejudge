def dfs(graph, start_node):
    visit = list()
    stack = list()

    stack.append(start_node)

    while stack:
        node = stack.pop()
        if node not in visit:
            visit.append(node)
            graph[node].sort(reverse=True)
            stack.extend(graph[node])

    return visit


def bfs(graph, start_node):
    visit = list()
    queue = list()

    queue.append(start_node)

    while queue:
        node = queue.pop(0)
        if node not in visit:
            visit.append(node)
            graph[node].sort()
            queue.extend(graph[node])

    return visit


N, M, V = map(int, input().split(" "))


graph = [[] for _ in range(N + 1)]

for i in range(1, M + 1):
    v1, v2 = map(int, input().split(" "))
    graph[v1].append(v2)
    graph[v2].append(v1)

dfs_result = dfs(graph, V)
bfs_result = bfs(graph, V)

for i in dfs_result:
    print(i, end=' ')

print()

for i in bfs_result:
    print(i, end=' ')
