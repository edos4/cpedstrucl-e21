#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
struct node {
	int data;
	int index;
	struct node * next;
	struct node * prev;
} *head;
  
int count() {
  struct node * n;
  int c = 0;
  n = head;
  while (n != NULL) {
    n = n -> next;
    c++;
  }
  return c;
}

void append(int num) {
  struct node * temp, * right;
  temp = (struct node * ) malloc(sizeof(struct node));
  temp -> data = num;
  right = (struct node * ) head;
  while (right -> next != NULL)
    right = right -> next;
  right -> next = temp;
  right = temp;
  right -> next = NULL;
}

void add(int num) {
  struct node * temp;
  temp = (struct node * ) malloc(sizeof(struct node));
  temp -> data = num;
  if (head == NULL) {
    head = temp;
    head -> next = NULL;
  } else {
    temp -> next = head;
    head = temp;
  }
}

void addafter(int num, int loc) {
  int i;
  struct node * temp, * left, * right;
  right = head;
  for (i = 1; i < loc; i++) {
    left = right;
    right = right -> next;
  }
  temp = (struct node * ) malloc(sizeof(struct node));
  temp -> data = num;
  left -> next = temp;
  left = temp;
  left -> next = right;
  return;
}

int delete_val(int num) {
  struct node * temp, * prev;
  temp = head;
  while (temp != NULL) {
    if (temp -> data == num) {
      if (temp == head) {
        head = temp -> next;
        //free(temp);
        return 1;
      } else {
        prev -> next = temp -> next;
        free(temp);
        return 1;
      }
    } else {
      prev = temp;
      temp = temp -> next;
    }
  }
  return 0;
}


void delete_all(int num){

	struct node * n;
  int c = 0;
  n= head;
  while (n != NULL) {
  	delete_val(num);
	  
    n = n -> next;
    c++;
  }

}

void insert(int num) {
  int c = 0;
  struct node * temp;
  temp = head;
  if (temp == NULL) {
    add(num);
  } else {
    while (temp != NULL) {
      temp = temp -> next;
    }
      append(num);
  }
}

void bubble_sort(struct node * r) {
    for(int i = count() ; i > 1 ; i-- ){
        node *temp, *swap1;
        swap1 = head;
        for(int j = 0 ; j < count()-1 ; j++ ){
            if(swap1->data > swap1->next->data){
                node *swap2 = swap1->next;
                swap1->next = swap2->next;
                swap2->next = swap1;
                if(swap1 == head){
                    head = swap2;
                    swap1 = swap2;
                }
                else{
                    swap1 = swap2;
                    temp->next = swap2;
                }
            }
            temp = swap1;
            swap1 = swap1->next;
        }
    }
}

void display(struct node * r) {
  r = head;
  if (r == NULL) {
    return;
  }
  while (r != NULL) {
    printf("%d ", r -> data);
    r = r -> next;
  }
  printf("\n");
}

void selection_sort(struct node * r) {
	node *ip, *jp, *index, *swap2;
	ip = head;
	jp = ip;
    for(int i = 0 ; i < count()-1 ; i++ ){
        int min = ip->data;
        index = ip;
        cout <<"a"<<endl;
        for(int j = i+1 ; j < count() ; j++ ){
        	cout <<"b"<<endl;
            if(jp->data < min){
            	if(jp == head){
                    head = swap2;
                    jp = swap2;
                }
                else{
                    cout <<"in if jp:"<< jp->data <<"min: "<<min<<endl;
	                min = jp->data;
	                index = jp;
                }
            }
            jp = jp->next;
        }
        cout <<"c"<<endl;
        index = ip;
        ip->data = min;
        ip = ip->next;
        display(r);
    }
}

void display_sorted(struct node * r) {
  r = head;
  if (r == NULL) {
    return;
  }
  cout << "Pointer Data Next"<<endl;
  while (r != NULL) {
    cout << r << " " << r->data << " " << r->next<<endl;
    r = r -> next;
  }
  printf("\n");
}

int search(int num) {
  struct node * n;
  int c = 1;
  n = head;
  while (n != NULL) {
  	if(n->data==num){
  		cout<<"Location: "<<c;
	  }
    n = n -> next;
    c++;
  }
  return c;
}
void reverse(struct node** head_ref) {
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}



int main() {
  int i, num, loc;
  struct node * n;
  head = NULL;
  
  insert(4);
  insert(2);
  insert(5);
  insert(1);
  insert(3);
  insert(7);
  insert(6);

  while (1) {
  	system("cls");
  	cout<<"Linked List Operations:"<<endl;
  	cout<<"============================"<<endl;
  	cout<<"1. Insert"<<endl;
  	cout<<"2. Display"<<endl;
  	cout<<"3. Size"<<endl;
  	cout<<"4. Delete"<<endl;
  	cout<<"5. Search"<<endl;
  	cout<<"6. Reverse"<<endl;
  	cout<<"7. Add After"<<endl;
  	cout<<"8. Delete all"<<endl;
  	cout<<"9. Exit"<<endl;
  	cout<<"10. Bubble Sort"<<endl;
  	cout<<"11. Selection Sort"<<endl;
  	cout<<"Enter choice: ";
  	cin >> i;
  	if(i <= 0){
  		cout<<"Enter only integer";
	  }
	else{
		switch(i){
		case 1:
			cout<<"Enter the number to insert: ";
			cin>> num;
			insert(num);
			break;
		case 2:
			if (head==NULL){
			 cout<<"List is Empty"<<endl;	
			}
			else{
			 cout<<"Element(s) in the list are : ";
			}
			display(n);
			break;
		case 3:
			cout<<"Size of the list is: "<<count()<<endl;
			break;
		case 4:
			if(head==NULL)
			  cout<<"List is Empty";
			else{
				cout<<"Enter the number to delete: ";
				cin>> num;
			if(delete_val(num))
			  cout<<num<<" is deleted successfully";
			else
			  cout<<num<<" is not found in the list";
			}
			break;
		case 5:
			cout<<"Enter number to search: ";
			cin>>num;
			search(num);
			break;
			
		case 6:
			  if (head == NULL) {
          cout<<"\nList is Empty\n";
        } else {
          cout<<"Element(s) in the list are : ";
        }
        reverse(&head);
        display(n);
        break;
        
		case 7:
			cout<<"Enter number to add: ";
			cin>>num;
			cout<<"Enter location: ";
			cin>>loc;
			addafter(num,loc);
			break;
			
		case 8:
			cout<<"Enter number to delete: ";
			cin>>num;
			delete_all(num);
			cout<<"Deleted successfully";
			break;
			
		case 9:
			return 0;
		
		case 10:
			bubble_sort(n);
			display_sorted(n);
			break;
			
		case 11:
			selection_sort(n);
			display_sorted(n);
			break;
			
		default:
			cout<<"Invalid choice!!";
		}
		getch();
	}
  	
}
	return 0;
}
