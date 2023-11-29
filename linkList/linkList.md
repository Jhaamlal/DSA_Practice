### Link list nodes

1) Link list is not continues as array . It is placed randomly in heap and just link together .While array is continues in heap memory they are not needed . 
2) This is reason you cannot use simple find length operation .You need to reach to the each element, and check if it's null or not.

3) Node or LinkList node is type of class in itself ,it has the same as told the item . ListNode is self define dataStructure in itself .

```
struct Node{
    int data;
    Node* next;

    Node(data,next){
        this->data=data;
        this->next=next;
    }
}
<!-- X below is just a object,not memory location pointer -->
<!-- Here you can access the data and the next -->
Node x=Node(2,nulpointer);

<!-- X , Below  will give the pointer to the memory location -->
<!-- Point to note is here ,it has * and New keyoword -->
Node* x= new  Node(2,nulpointer);

<!-- Below is creating the null pointer,Now Y will point to the x -->
Node*y=&x

```
***
### NEVER TEMPER WITH HEAD OF LINKLIST ,OTHERWISE LIFE WILL BE HELL 

