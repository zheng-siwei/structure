#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ShoppingItem {
 char name[50]; // 商品名称
 int quantity; // 商品数量
 struct ShoppingItem* next; // 指向下一个节点的指针
};
//然后，我们创建一个链表头指针，表示购物清单的起始点：
struct ShoppingItem* shoppingList = NULL; // 初始化购物清单为空
//1. 添加商品到购物清单：
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
//2. 从购物清单中移除商品：
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

//3. 查看购物清单：
void displayList() {
 struct ShoppingItem* current = shoppingList;
 printf("购物清单:\n");
 while (current != NULL) {
 printf("%s - 数量：%d\n", current->name, current->quantity);
 current=current->next;
 }
}
//4. 修改购物清单中商品的数量：
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
//5. 清空购物清单：
void clearList() {
 while (shoppingList != NULL) {
 struct Shoppingltem *temp=shoppingList;
 shoppingList=shoppingList->next;
 free(temp);
 }
}
//6. 计算购物清单中商品的总数量：
int totalQuantity() {
 struct ShoppingItem* current = shoppingList;
 int total = 0;
 while (current != NULL) {
 total++;
 current=current->next;
 }
 return total;
}

//7. 查找购物清单中的商品：
void findItem(char itemName[]) {
 struct ShoppingItem* current = shoppingList;
 printf("查找商品 \"%s\" ：\n", itemName);
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 printf("%s - 数量：%d\n", current->name, current->quantity);
 return;
 }
 current=current->next;
 }
 printf("未找到商品 \"%s\"。\n", itemName);
}
//8. 排序购物清单：
void sortList() {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* nextItem = NULL;
 char tempName[50];
 int tempQuantity;
 while (current != NULL) {
 nextItem = current->next;
 while (nextItem != NULL) {
 if (strcmp(current->name, nextItem->name) > 0) {
 // 交换商品信息
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
//9. 合并购物清单：
//假设你有两个不同的购物清单，你希望将它们合并成一个。
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
 struct ShoppingItem* current = *list1;

 // 遍历到第一个购物清单的末尾
 //补充循环语句；
 while(current->next!=NULL)
 	current=current->next;
 // 将第二个购物清单连接到第一个清单的末尾
 current->next = *list2;
 *list2 = NULL; // 清空第二个购物清单的头指针，防止误用
}
//10. 删除购物清单中的商品：
//实现一个函数，可以根据商品名称删除购物清单中的商品项。如果有多个相同名称的商品，
//可以选择删除其中一个或全部。
void deleteItem(char itemName[], int deleteAll) {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* prev = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (prev == NULL) {
 // 如果要删除的是第一个节点
 struct ShoppingItem* temp = shoppingList;
 shoppingList=shoppingList->next;
 free(temp);
 if (!deleteAll) break;
 } else {
 // 如果要删除的不是第一个节点
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
	addItem("秋刀鱼",20);
	addItem("三文鱼",25);
	addItem("带鱼",30);
	
	displayList();//显示购物清单
	printf("\n");
	updateQuantity("三文鱼",20);//修改数量为20
	displayList();//再次显示购物清单
	printf("\n");
	removeItem("带鱼");//移除带鱼
	displayList();// 再次显示购物清单
	clearList();//清空购物清单
	return 0; 
	 
}
