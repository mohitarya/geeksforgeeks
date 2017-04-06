#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKETSIZE 10

typedef struct node{
  int num;
  struct node *next;
}node;

int max(int *arr, int size)
{
  int i, max_num, max_dig=0;
  max_num = arr[0];
  for(i = 1; i < size; i++){
    if(arr[i] > max_num){
      max_num = arr[i];
    }
  }
  printf("Max Number in array is %d\n", max_num);
  while(max_num != 0){
    max_dig++;
    max_num = max_num / 10;
  }
  printf("Max_dig = %d\n", max_dig);
  return max_dig;
}

node *create_node(int num)
{
  node *new_node;
  new_node = (node *) malloc(sizeof(node));
  if(new_node == NULL){
    return NULL;
  }else{
    new_node->num = num;
    new_node->next = NULL;
    return new_node;
  }
}

// Insert into the linked List
insert(node *head, node *new_node)
{
  node *temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = new_node;
}

insert_num_bucket(node **bucket, int bucket_index, int num)
{
  node *new_node;
  // Create a Node
  new_node = create_node(num);
  if(new_node == NULL){
    printf("Can not allocate the memory\n");
    return;
  }
  // If pointer in the bucket is NULL at bucket_index
  // Then its a first element to add at that index
  if(bucket[bucket_index] == NULL){
    bucket[bucket_index] = new_node;
  }else{
    // Inserting the element in the linked list
    insert(bucket[bucket_index], new_node);
  }
}

fill_arr(node *head, int *arr, int *arr_curr_index)
{
  node *temp = head;
  node *prev;
  int index = *arr_curr_index;
  while(temp != NULL){
    arr[index] = temp->num;
    index++;
    prev = temp;
    temp = temp->next;
  }
  *arr_curr_index = index;
}

del_bucket_list(node *head)
{
  node *temp = head, *prev;
  while(temp != NULL){
    prev = temp;
    temp = temp->next;
    free(prev);
    prev = NULL;
  }
  
}

extract_num_bucket(node **bucket, int *arr)
{
  int arr_curr_index = 0, i;
  for(i = 0; i < BUCKETSIZE; i++){
    if(bucket[i] == NULL){
      continue;
    }else{
      fill_arr(bucket[i], arr, &arr_curr_index);
      del_bucket_list(bucket[i]);
      bucket[i] = NULL;
    }
  }
}

radix_sort(int *arr, int size)
{
  int max_dig, i = 1, j, k, bucket_index, temp;
  node **bucket;

  bucket = (node **) malloc(sizeof(node *) * BUCKETSIZE);
  
  // Find Max Number of digits in array
  max_dig = max(arr, size);
  if(max_dig == 0){
    return;
  }else{
    while(i <= max_dig){
      for(j = 0; j < size; j++){
	temp = arr[j];
	for(k = 1; k <= i; k++){
	  bucket_index = temp % 10;
	  temp = temp / 10;
	}
	// Inserting Number into the bucket
	insert_num_bucket(bucket, bucket_index, arr[j]);
      }
      i++;
      // Taking out number from the bucket and inserting them back to the array in order
      extract_num_bucket(bucket, arr);
      printf("Array after iteration %d\n", i);
      print(arr, size);
    }
  }
}

int main()
{
  // Input array
  int arr[] = {3, 56, 34, 21, 595, 606, 65, 809, 93, 12};
  int arr_size = sizeof(arr)/sizeof(int);
  printf("Array before sorting\n");
  print(arr, arr_size);
  printf("Array Size is %d\n", arr_size);
  // Radix sort function call
  radix_sort(arr, arr_size);
  printf("Array after radix sorting\n");
  printf("Array size id %d\n", arr_size);
  print(arr, arr_size);
}
