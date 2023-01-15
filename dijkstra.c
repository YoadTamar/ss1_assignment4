int dijkstra(pnode *head, int n1, int n2) 
{
    pnode current = head;
    while (current) 
    {
        current->dist = INT_MAX;
        current->visited = 0;
        current = current->next;
    }
    current = head;
    while (current) 
    {
        if(current->node_num == n1) 
        {
            current->dist = 0;
            break;
        }
        current = current->next;
    }
    while (1) 
    {
        int min_dist = INT_MAX;
        pnode min_node = NULL;
        current = head;
        while (current) 
        {
            if (!current->visited && current->dist < min_dist) 
            {
                min_dist = current->dist;
                min_node = current;
            }
            current = current->next;
        }
        if (!min_node) 
        {
            break;
        }
        min_node->visited = 1;
        pedge e = min_node->edges;
        while (e) 
        {
            if (e->endpoint->dist > min_node->dist + e->weight) 
            {
                e->endpoint->dist = min_node->dist + e->weight;
            }
            e = e->next;
        }
    }
    current = head;
    while (current) 
    {
        if (current->node_num == n2)
         {
            if (current->dist == INT_MAX) 
            {
                return -1;
            }
            return current->dist;
        }
        current = current->next;
    }
    return -1;
}