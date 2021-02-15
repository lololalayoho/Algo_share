# 테스트 케이스 2 통과 / 실패

def solution(tickets):
    nation_num = len(tickets)

    graph = []
    graph_new = []
    result = []

    for inf in tickets:
        graph.append([inf[0]])

    for inf in tickets:
        for i in range(nation_num):
            if inf[0] == graph[i][0]:
                graph[i].append(inf[1])

    for inf in graph:
        if inf not in graph_new:
            graph_new.append(inf)
            
    for inf_new in graph_new:
        temp1 = inf_new[0]
        inf_new.sort()
        temp2 = inf_new.index(temp1)
        inf_new[0], inf_new[temp2] = inf_new[temp2], inf_new[0]
            
    # 초기값 ICN 입력
    result.append(graph_new[0][0])
    
    while tickets:
        for node in graph_new:
            if node[0] == result[-1]:
                depart = node[0]
                arrival = node[1]
                result.append(arrival)
                temp_num1 = graph_new.index(node)
                del graph_new[temp_num1][1]
                for ticket in tickets:
                    if ticket[0] == depart and ticket[1] == arrival:
                        temp_num2 = tickets.index(ticket)
                        del tickets[temp_num2]
            
    return result