import sys
sys.setrecursionlimit(10**6)

class Graph:
    def __init__(self, V):
        self.V = V
        self.E = 0
        self.adj = [[] for _ in range(V + 1)]

    def addEdge(self, v, w):
        self.adj[v].append(w)
        self.E += 1

    def reverse(self):
        g = Graph(self.V)

        for v in range(self.V + 1):
            for w in self.adj[v]:
                g.addEdge(w, v)

        return g
    
    def __str__(self):
        rtList = [f"{self.V} vertices and {self.E} edges\n"]
        for v in range(self.V):
            for w in self.adj[v]:
                rtList.append(f"{v}->{w}\n")
        return "".join(rtList)       
    
def topologicalSort(g):
    def recur(v):
        visited[v] = True
        for w in g.adj[v]:
            if not visited[w]: recur(w)

        reverseList.append(v)

    visited = [False for _ in range(g.V + 1)]
    reverseList = []

    for v in range(1, g.V + 1):
        if not visited[v]: recur(v)

    reverseList.reverse()
    return reverseList
    
class SCC:
    def __init__(self, g):
        self.count = 0
        self.id = [-1 for _ in range(g.V + 1)]
        visited = [False for _ in range(g.V + 1)]

        def recur(v):
            visited[v] = True
            self.id[v] = self.count
            for w in g.adj[v]:
                if not visited[w]:
                    recur(w)

        reversed_g = g.reverse()
        to_of_reversed_g = topologicalSort(reversed_g)

        for v in to_of_reversed_g:
            if visited[v] == False:
                recur(v)
                self.count += 1

if __name__ == "__main__":
    V, E = map(int, input().split())
    g = Graph(V)

    for _ in range(E):
        v, w = map(int, input().split())
        g.addEdge(v, w)

    my_scc = SCC(g)

    scc_list = [[] for _ in range(my_scc.count)]

    for index, value in enumerate(my_scc.id):
        if value >= 0:
            scc_list[value].append(index)

    scc_list.sort(key=lambda x : x[0])

    print(my_scc.count)
    for scc in scc_list:
        for i in scc:
            print(i, end=" ")
        print(-1)