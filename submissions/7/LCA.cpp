int getDepth(TreeNode *node) {
    int d = 0;
    while (node) d++, node = node->parent;
    return d;
}
TreeNode *getLCA(TreeNode *node1, TreeNode *node2) {
    int d1 = getDepth(node1), d2 = getDepth(node2);
    if (d1 > d2) {
        swap(d1, d2);
        swap(node1, node2);
    }
    while (d1 < d2) d2--, node2 = node2->parent;
    while (node1 != node2) {
        node1 = node1->parent;
        node2 = node2->parent;
    }
    return node1;
}