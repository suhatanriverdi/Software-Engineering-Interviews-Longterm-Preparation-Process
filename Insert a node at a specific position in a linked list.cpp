/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode *walk = head;
    while(walk != NULL) {
        if(position-1 == 0) {
            SinglyLinkedListNode *temp = new SinglyLinkedListNode(data);
            temp->next = walk->next;
            walk->next = temp;
        }
        position--;
        walk = walk->next;
    }
    return head;
}
