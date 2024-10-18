int init()
{
  setbuf(stdin, 0LL);
  setbuf(stdout, 0LL);
  setbuf(stderr, 0LL);
  puts("welcome to the rtree system!");
  puts("in this level, we consider when every node in the tree has not more than one child, the tree becomes a linked list");
  return puts("It's time to construct your own tree!");
}
int backdoor()
{
  return system("echo 'this is a fake backdoor'");
}
// 4012a4
unsigned __int64 __fastcall edit(__int64 a1, int a2)
{
  int v3; // [rsp+14h] [rbp-Ch] BYREF
  unsigned __int64 v4; // [rsp+18h] [rbp-8h]

  v4 = __readfsqword(0x28u);
  puts("sry, but you can only edit 8 bytes at a time");
  puts("please enter the index of the data you want to edit:");
  __isoc99_scanf("%d", &v3);
  if ( a2 > v3 )
  {
    puts("please enter the new data:");
    read(0, (void *)(v3 + a1), 8uLL);
    puts("edit success!");
  }
  else
  {
    puts("invalid index");
  }
  return v4 - __readfsqword(0x28u);
}
int __fastcall print_node(__int64 a1)
{
  printf("key: %d\n", *(_DWORD *)a1);
  printf("size: %d\n", *(_DWORD *)(a1 + 16));
  return printf("data: %s\n", *(const char **)(a1 + 8));
}
int print_info()
{
  puts("1. insert a node");
  puts("2. show a node");
  puts("3. edit a node");
  puts("4. quit");
  return puts(">> ");
}
struct Node2
{
  int key;
  char *data;
  int size;
  (__int64 (*edit)(unsigned __int64, int))edit;
  struct Node2 *next;
};
int __fastcall main(int argc, const char **argv, const char **envp)
{
  int v4; // [rsp+0h] [rbp-30h] BYREF
  int v5; // [rsp+4h] [rbp-2Ch] BYREF
  __int64 i; // [rsp+8h] [rbp-28h]
  __int64 j; // [rsp+10h] [rbp-20h]
  __int64 k; // [rsp+18h] [rbp-18h]
  char *v9; // [rsp+20h] [rbp-10h]
  unsigned __int64 v10; // [rsp+28h] [rbp-8h]

  v10 = __readfsqword(0x28u);
  init(argc, argv, envp);
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          print_info();
          __isoc99_scanf("%d", &v4);
          if ( v4 != 1 )
            break;
          v9 = (char *)malloc(0x28uLL);
          puts("please enter the node key:");
          __isoc99_scanf("%d", v9);
          puts("please enter the size of the data:");
          __isoc99_scanf("%d", v9 + 16);
          if ( *((int *)v9 + 4) <= 8 )
            puts("sry, but plz enter a bigger size");
          *((_QWORD *)v9 + 1) = malloc(*((int *)v9 + 4));
          puts("please enter the data:");
          read(0, *((void **)v9 + 1), *((unsigned int *)v9 + 4));
          *((_QWORD *)v9 + 3) = edit;
          *((_QWORD *)v9 + 4) = 0LL;
          puts("insert success!");
          if ( root )
          {
            for ( i = root; *(_QWORD *)(i + 32); i = *(_QWORD *)(i + 32) )
              ;
            *(_QWORD *)(i + 32) = v9;
          }
          else
          {
            root = (__int64)v9;
          }
        }
        if ( v4 != 2 )
          break;
        puts("please enter the key of the node you want to show:");
        __isoc99_scanf("%d", &v5);
        for ( j = root; j; j = *(_QWORD *)(j + 32) )
        {
          if ( *(_DWORD *)j == v5 )
          {
            print_node(j);
            break;
          }
        }
        if ( !j )
          puts("node not found :(");
      }
      if ( v4 != 3 )
        break;
      puts("please enter the key of the node you want to edit:");
      __isoc99_scanf("%d", &v5);
      for ( k = root; k; k = *(_QWORD *)(k + 32) )
      {
        if ( *(_DWORD *)k == v5 )
        {
          if ( *(_QWORD *)(k + 24) )
          {
            (*(void (__fastcall **)(_QWORD, _QWORD))(k + 24))(*(_QWORD *)(k + 8), *(unsigned int *)(k + 16));
            *(_QWORD *)(k + 24) = 0LL;
          }
          break;
        }
      }
      if ( !k )
        puts("node not found");
    }
    if ( v4 == 4 )
      return 0;
    puts("invalid choice");
  }
}