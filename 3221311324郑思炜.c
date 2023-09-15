#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ShoppingItem {
 char name[50]; // ��Ʒ����
 int quantity; // ��Ʒ����
 struct ShoppingItem* next; // ָ����һ���ڵ��ָ��
};
//Ȼ�����Ǵ���һ������ͷָ�룬��ʾ�����嵥����ʼ�㣺
struct ShoppingItem* shoppingList = NULL; // ��ʼ�������嵥Ϊ��
//1. �����Ʒ�������嵥��
void addItem(char itemName[], int itemQuantity) {
 struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct 
ShoppingItem));
	strcpy(newItem->name,itemName);
	newItem->quantity=itemQuantity;
	newItem->next=NULL;
	if(shoppingList==NULL)
	{
		shoppingList=newItem;
	}
	else
	{
		struct ShoppingItem* current=shoppingList;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=newItem;
	}
}
//2. �ӹ����嵥���Ƴ���Ʒ��
void removeItem(char itemName[]) {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* previous = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (previous != NULL) {
 previous->next = current->next;
 } else {
 shoppingList = current->next;
 }
 free(current);
 break;
 }
 previous=current;
 current=current->next;
 }
}

//3. �鿴�����嵥��
void displayList() {
 struct ShoppingItem* current = shoppingList;
 printf("�����嵥:\n");
 while (current != NULL) {
 printf("%s - ������%d\n", current->name, current->quantity);
 current=current->next;
 }
}
//4. �޸Ĺ����嵥����Ʒ��������
void updateQuantity(char itemName[], int newItemQuantity) {
 struct ShoppingItem* current = shoppingList;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 current->next=current->next->next;
 break;
 }
 current = current->next;
 }
}
//5. ��չ����嵥��
void clearList() {
 while (shoppingList != NULL) {
 struct Shoppingltem *temp=shoppingList;
 shoppingList=shoppingList->next;
 free(temp);
 }
}
//6. ���㹺���嵥����Ʒ����������
int totalQuantity() {
 struct ShoppingItem* current = shoppingList;
 int total = 0;
 while (current != NULL) {
 total++;
 current=current->next;
 }
 return total;
}

//7. ���ҹ����嵥�е���Ʒ��
void findItem(char itemName[]) {
 struct ShoppingItem* current = shoppingList;
 printf("������Ʒ \"%s\" ��\n", itemName);
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 printf("%s - ������%d\n", current->name, current->quantity);
 return;
 }
 current=current->next;
 }
 printf("δ�ҵ���Ʒ \"%s\"��\n", itemName);
}
//8. �������嵥��
void sortList() {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* nextItem = NULL;
 char tempName[50];
 int tempQuantity;
 while (current != NULL) {
 nextItem = current->next;
 while (nextItem != NULL) {
 if (strcmp(current->name, nextItem->name) > 0) {
 // ������Ʒ��Ϣ
 strcpy(tempName,current->name);;
 strcpy(current->name,nextItem->name);
 strcpy(nextItem->name,tempName);
 tempQuantity = current->quantity;
 current->quantity = nextItem->quantity;
 nextItem->quantity = tempQuantity;
 }
 nextItem = nextItem->next;
 }
 current = current->next;
 }
}
//9. �ϲ������嵥��
//��������������ͬ�Ĺ����嵥����ϣ�������Ǻϲ���һ����
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
 struct ShoppingItem* current = *list1;

 // ��������һ�������嵥��ĩβ
 //����ѭ����䣻
 while(current->next!=NULL)
 	current=current->next;
 // ���ڶ��������嵥���ӵ���һ���嵥��ĩβ
 current->next = *list2;
 *list2 = NULL; // ��յڶ��������嵥��ͷָ�룬��ֹ����
}
//10. ɾ�������嵥�е���Ʒ��
//ʵ��һ�����������Ը�����Ʒ����ɾ�������嵥�е���Ʒ�����ж����ͬ���Ƶ���Ʒ��
//����ѡ��ɾ������һ����ȫ����
void deleteItem(char itemName[], int deleteAll) {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* prev = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (prev == NULL) {
 // ���Ҫɾ�����ǵ�һ���ڵ�
 struct ShoppingItem* temp = shoppingList;
 shoppingList=shoppingList->next;
 free(temp);
 if (!deleteAll) break;
 } else {
 // ���Ҫɾ���Ĳ��ǵ�һ���ڵ�
prev->next=current->next;
 free(current);
 current = prev->next;
 if (!deleteAll) break;
 }
 } else {
 prev = current;
 current = current->next;
 }
 }
}
int main(void)
{
	addItem("�ﵶ��",20);
	addItem("������",25);
	addItem("����",30);
	
	displayList();//��ʾ�����嵥
	printf("\n");
	updateQuantity("������",20);//�޸�����Ϊ20
	displayList();//�ٴ���ʾ�����嵥
	printf("\n");
	removeItem("����");//�Ƴ�����
	displayList();// �ٴ���ʾ�����嵥
	clearList();//��չ����嵥
	return 0; 
	 
}
