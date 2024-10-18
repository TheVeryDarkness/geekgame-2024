// 00000000004040A0 __int32 node_tops[0x20]
// 0000000000404120 __int32 node_cnt

struct Node {
  int key;
  char data[8];
  int size;
}

int __fastcall print_node(__int64 a1)
{
  printf("key: %d\n", *(_DWORD *)a1);
  printf("size: %d\n", *(_DWORD *)(a1 + 16));
  return printf("data: %s\n", *(const char **)(a1 + 8));
}

// 122c
int backdoor()
{
  puts("congratulations! you reach the backdoor!");
  return system("/bin/sh");
}

int print_info()
{
  puts("1. insert a node");
  puts("2. show a node");
  puts("3. edit a node");
  puts("4. quit");
  return puts(">> ");
}

// 1316
int __fastcall insert(_BYTE a1[0x200])
{
  int v1; // eax
  int v3; // eax
  int size; // [rsp+18h] [rbp-18h] BYREF
  int key; // [rsp+1Ch] [rbp-14h] BYREF
  __int64 v6; // [rsp+20h] [rbp-10h]
  int v7; // [rsp+2Ch] [rbp-4h]

  puts("please enter the node key:");
  __isoc99_scanf("%d", &key);
  puts("please enter the size of the data:");
  __isoc99_scanf("%d", &size);
  if ( node_cnt )
    v1 = node_tops[node_cnt - 1];
  else
    v1 = 0;
  v7 = v1;
  if ( (unsigned __int64)(size + v1 + 24LL) > 0x200 )
    return puts("no enough space");
  v3 = node_cnt++;
  node_tops[v3] = size + v7 + 24;
  v6 = a1 + v7;
  *(_DWORD *)v6 = key;
  *(_DWORD *)(v6 + 16) = size + 24;
  *(_QWORD *)(v6 + 8) = v6 + 24;
  puts("please enter the data:");
  read(0, *(void **)(v6 + 8), *(unsigned int *)(v6 + 16));
  return puts("insert success!");
}

// 147f
__int64 __fastcall show(__int64 a1)
{
  __int64 result; // rax
  int v2; // [rsp+1Ch] [rbp-14h] BYREF
  _DWORD *v3; // [rsp+20h] [rbp-10h]
  int i; // [rsp+2Ch] [rbp-4h]

  puts("please enter the key of the node you want to show:");
  __isoc99_scanf("%d", &v2);
  if ( node_cnt > 0 )
    print_node(a1);
  for ( i = 1; ; ++i )
  {
    result = (unsigned int)node_cnt;
    if ( i >= node_cnt )
      break;
    v3 = (_DWORD *)((int)node_tops[i - 1] + a1);
    if ( *v3 == v2 )
      return print_node(v3);
  }
  return result;
}

int edit()
{
  return puts("sorry, not implemented :(");
}

int __fastcall main(int argc, const char **argv, const char **envp)
{
  int option; // [rsp+Ch] [rbp-204h] BYREF
  _BYTE buffer[0x200]; // [rsp+10h] [rbp-200h] BYREF

  init(argc, argv, envp);
  node_cnt = 0;
  do
  {
    print_info();
    __isoc99_scanf("%d", &option);
    if ( option == 3 )
    {
      edit();
    }
    else if ( option <= 3 )
    {
      if ( option == 1 )
      {
        insert(buffer);
      }
      else if ( option == 2 )
      {
        show(buffer);
      }
    }
  }
  while ( option != 4 );
  return 0;
}