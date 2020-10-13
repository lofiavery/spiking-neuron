import json
import networkx as nx
import matplotlib.pyplot as plt


def get_graph(source):
    mydict = {}
    with open(source) as f:
        data = json.load(f)
    return data

def draw_graph(network):
    G = nx.DiGraph(directed=True)
    edges = []
    for node in network:
        for con in node['connections']:
            edges.append((str(con), str(node['id'])))
    print(edges)
    G.add_edges_from(edges)


    # G.add_edges_from(
    #     [('A', 'B'), ('A', 'C'), ('D', 'B'), ('E', 'C'), ('E', 'F'),
    #      ('B', 'H'), ('B', 'G'), ('B', 'F'), ('C', 'G')])

    # val_map = {'A': 1.0,
    #            'D': 0.5714285714285714,
               # 'H': 0.0}

    # values = [val_map.get(node, 0.25) for node in G.nodes()]
    values = [1 for node in G.nodes]

    # Specify the edges you want here
    # red_edges = [('A', 'C'), ('E', 'C')]
    # edge_colours = ['black' if not edge in red_edges else 'red'
    #                 for edge in G.edges()]
    # black_edges = [edge for edge in G.edges() if edge not in red_edges]
    black_edges = [edge for edge in G.edges()]

    # Need to create a layout when doing
    # separate calls to draw nodes and edges
    pos = nx.spring_layout(G)
    nx.draw_networkx_nodes(G, pos, cmap=plt.get_cmap('jet'),
                           node_color=values, node_size=500)
    nx.draw_networkx_labels(G, pos)
    # nx.draw_networkx_edges(G, pos, edgelist=red_edges, edge_color='r', arrows=True)
    nx.draw_networkx_edges(G, pos, edgelist=black_edges, arrows=True)
    plt.show()




if __name__ == "__main__":
    file_name = "../log/test-output.json"
    graph = get_graph(file_name)
    print(graph)
    print("hi")
    draw_graph(graph)
