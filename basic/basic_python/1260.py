import sys

vertex_num, edge_num, starting_vertex = map(int, sys.stdin.readline().split())

adjacent = [[0] for i in range(vertex_num + 1)]
is_visited = [False for i in range(vertex_num + 1)]


def dfs(curr_vertex):
    is_visited[curr_vertex] = True
    print(curr_vertex, end=" ")
    for vertex_idx in range(len(adjacent[curr_vertex])):
        if is_visited[adjacent[curr_vertex][vertex_idx]]:
            pass
        dfs(adjacent[curr_vertex][vertex_idx])


# 정보를 읽어들인다.
for i in range(edge_num):
    tmp_start, tmp_end = map(int, sys.stdin.readline().split())
    adjacent[tmp_start].append(tmp_end)
    adjacent[tmp_end].append(tmp_start)

dfs(starting_vertex)
