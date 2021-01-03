struct Interval
{
        int low, high;
};
 
struct ITNode
{
        Interval *i; // 'i' could also be a normal variable
        int max;
        ITNode *left, *right;
};
 
// A utility function to create a new Interval Search Tree Node
ITNode * newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
    return temp;
};
 
// A utility function to insert a new Interval Search Tree Node
// This is similar to BST Insert.  Here the low value of interval
// is used tomaintain BST property
ITNode *insert(ITNode *root, Interval i)
{
    // Base case: Tree is empty, new node becomes root
    if (root == NULL)
        return newNode(i);
 
    // Get low value of interval at root
    int l = root->i->low;
 
    // If root's low value is smaller, then new interval goes to
    // left subtree
    if (i.low < l)
        root->left = insert(root->left, i);
 
    // Else, new node goes to right subtree.
    else
        root->right = insert(root->right, i);
 
    // Update the max value of this ancestor if needed
    if (root->max < i.high)
        root->max = i.high;
 
    return root;
}
 
// A utility function to check if given two intervals overlap
bool doOVerlap(Interval i1, Interval i2)
{
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}
 
// The main function that searches a given interval i in a given
// Interval Tree.
Interval *intervalSearch(ITNode *root, Interval i)
{
    // Base Case, tree is empty
    if (root == NULL)
        return NULL;
 
    // If given interval overlaps with root
    if (doOVerlap(*(root->i), i))
        return root->i;
 
    // If left child of root is present and max of left child is
    // greater than or equal to given interval, then i may
    // overlap with an interval is left subtree
    if (root->left != NULL && root->left->max >= i.low)
        return intervalSearch(root->left, i);
 
    // Else interval can only overlap with right subtree
    return intervalSearch(root->right, i);
}
 
void inorder(ITNode *root)
{
    if (root == NULL)
        return;
 
    inorder(root->left);
 
    cout << "[" << root->i->low << ", " << root->i->high << "]" << " max = "
            << root->max << endl;
 
    inorder(root->right);
}
 
int main(int argc, char **argv)
{
 
    Interval ints[] = { { 15, 20 }, { 10, 30 }, { 17, 19 }, { 5, 20 },
            { 12, 15 }, { 30, 40 } };
    int n = sizeof(ints) / sizeof(ints[0]);
    ITNode *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, ints[i]);
 
    cout << "In-order traversal of constructed Interval Tree is\n";
    inorder(root);
 
    Interval x = { 6, 7 };
 
    cout << "\nSearching for interval [" << x.low << "," << x.high << "]";
    Interval *res = intervalSearch(root, x);
    if (res == NULL)
        cout << "\nNo Overlapping Interval";
    else
        cout << "\nOverlaps with [" << res->low << ", " << res->high << "]";
}



/*
In-order traversal of constructed Interval Tree is
[5, 20] max = 20
[10, 30] max = 30
[12, 15] max = 15
[15, 20] max = 40
[17, 19] max = 40
[30, 40] max = 40
 
Searching for interval [6,7]
Overlaps with [5, 20]
*/
