#include <iostream>

using namespace std;

/* Structure of Doubly Linked List */
struct DLLNode{
	int data;
	struct DLLNode *prev;
	struct DLLNode *next;
};

/**
* Add data to the beginning of the Doubly Linked List.
*
* @param head - start node of the linked list
* @param data - data to be added
*/
void InsertNodeStart(struct DLLNode **head, int data){
	// create new node
	struct DLLNode *new_node = (struct DLLNode *)malloc(sizeof(struct DLLNode));
	if (!new_node){
		cout<<"Memory error."<<endl;
		return;
	}
	// fill data
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;

	// tree is empty
	if (*head == NULL){
		*head = new_node;
		return;
	}
	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;
}

/**
* Function to find the middle node of the Linked List.
*
* @param head - start node of the linked list
* @return - middle node of the linked list
*/
struct DLLNode* findMiddle(struct DLLNode* head)
{
	/* define 2 pointer */
	struct DLLNode *slowPtr = head, *fastPtr = head;
	while (slowPtr && fastPtr){
		fastPtr = fastPtr->next;
		/* fastPtr reaches the end of the list */
		if (fastPtr == NULL)
			break;
		fastPtr = fastPtr->next;
		/* fastPtr reaches the end of the list */
		if (fastPtr == NULL)
			break;
		slowPtr = slowPtr->next;
	}
	/* slowPtr show the middle of the list */
	return slowPtr;
}

/**
* Convert Doubly Linked List to Binary Search Tree.
*
* @param head - start node of the linked list
* @return - root node of the binary search tree
*/
struct DLLNode *DLLToBST(struct DLLNode *head){
	struct DLLNode *tmp, *p, *q;
	// empty
	if (head == NULL)
		return NULL;

	/* list divided into three parts: head, tmp, q
	tmp=middle node, head=left linked list, q=right linked list */
	// set middle, root
	tmp = findMiddle(head);
	// set left list
	if (head == tmp){
		head = NULL;
	}
	else{
		p = tmp->prev;
		if (p)
			p->next = NULL;
	}
	// set right list
	q = tmp->next;

	// left part processing
	tmp->prev = DLLToBST(head);
	// right part processing
	tmp->next = DLLToBST(q);

	return tmp;
}

/**
* Function to print Doubly Linked List.
*
* @param head - start node of the linked list
*/
void DisplayDLL(struct DLLNode *head){
	cout<<"nDoubly Linked List:"<<endl;
	cout<<"nRepresentation: (previous-node, current-node, next-node)n"<<endl;
	while (head){
		// previous node
		if (head->prev)
			cout<<head->prev->data<<endl;
		else
			cout<<"(NULL,"<<endl;
		// current node
		cout<<head->data<<endl;
		// next node
		if (head->next)
			cout<<",%d) "<< head->next->data<<endl;
		else
			cout<<",NULL) "<<endl;
		// moving to next pointer
		head = head->next;
	}
}

/**
* Helper function for DisplayTree function. Recursively print the
* tree nodes. We pass 0 as default value for level.
*
* @param level - shows the level of the binary tree
* @param root - root of the tree
*/
void Display(int level, struct DLLNode *root){
	int i;
	cout<<endl;
	if (root){
		Display(level + 1, root->next);

		for (i = 0; i<level; i++)
			cout<<"    "<<endl;
		if (level == 0)
			cout << root->data<<"(R)"<<endl;
		else
			cout<<root->data<<endl;
		Display(level + 1, root->prev);
	}
}

/**
* Display the tree in 90 degree anti-clockwise direction.
*  R shows Root node, nodes above R shows Right Subtree and nodes
*  below R shows left subtree.
*
* @param root - root of the tree
*/
void DisplayTree(struct DLLNode *root){
	cout <<"nTree:(R-Root node, Above R-right subtree, Below R-left subtree)"<<endl;
	Display(0, root);
}

int main(){
	struct DLLNode *root = NULL;
	InsertNodeStart(&root, 12);
	InsertNodeStart(&root, 10);
	InsertNodeStart(&root, 9);
	InsertNodeStart(&root, 8);
	InsertNodeStart(&root, 7);
	InsertNodeStart(&root, 6);
	InsertNodeStart(&root, 5);
	InsertNodeStart(&root, 4);
	InsertNodeStart(&root, 3);
	InsertNodeStart(&root, 2);
	InsertNodeStart(&root, 1);
	DisplayDLL(root);

	root = DLLToBST(root);
	DisplayTree(root);

	getchar();
	return 0;
}