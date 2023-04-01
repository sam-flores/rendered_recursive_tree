struct treenode
{
    double x;
    double y;
    double z;
    struct treenode *left;
    struct treenode *right;
};

struct treenode *insert(struct treenode *node, double x, double y, double z)
{

    if (node == NULL)
    {
        node = malloc(sizeof(struct treenode));
        node->x = x;
        node->y = y;
        node->z = z;
        node->left = node->right = NULL;
    }
    else
    {
        if (drand48() < .6)
        {
            if (x < node->x)
            {
                node->right = insert(node->right, x, y, z);
            }
            else
            {
                node->left = insert(node->left, x, y, z);
            }
        }
        else
        {
            if (drand48() < .5)
            {
                node->right = insert(node->right, x, y, z);
            }
            else
            {
                node->left = insert(node->left, x, y, z);
            }
        }
    }

    return node;
}
