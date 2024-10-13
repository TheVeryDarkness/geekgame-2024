int __fastcall insert(__int64 a1)
{
  int v1; // eax
  int v3; // eax
  int v4; // [rsp+18h] [rbp-18h] BYREF
  int v5; // [rsp+1Ch] [rbp-14h] BYREF
  __int64 v6; // [rsp+20h] [rbp-10h]
  int v7; // [rsp+2Ch] [rbp-4h]

  puts("please enter the node key:");
  __isoc99_scanf("%d", &v5);
  puts("please enter the size of the data:");
  __isoc99_scanf("%d", &v4);
  if ( node_cnt )
    v1 = node_tops[node_cnt - 1];
  else
    v1 = 0;
  v7 = v1;
  if ( (unsigned __int64)(v4 + v1 + 24LL) > 0x200 )
    return puts("no enough space");
  v3 = node_cnt++;
  node_tops[v3] = v4 + v7 + 24;
  v6 = v7 + a1;
  *(_DWORD *)v6 = v5;
  *(_DWORD *)(v6 + 16) = v4 + 24;
  *(_QWORD *)(v6 + 8) = v6 + 24;
  puts("please enter the data:");
  read(0, *(void **)(v6 + 8), *(unsigned int *)(v6 + 16));
  return puts("insert success!");
}

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
  int v4; // [rsp+Ch] [rbp-204h] BYREF
  _BYTE v5[512]; // [rsp+10h] [rbp-200h] BYREF

  init(argc, argv, envp);
  node_cnt = 0;
  do
  {
    print_info();
    __isoc99_scanf("%d", &v4);
    if ( v4 == 3 )
    {
      edit();
    }
    else if ( v4 <= 3 )
    {
      if ( v4 == 1 )
      {
        insert(v5);
      }
      else if ( v4 == 2 )
      {
        show(v5);
      }
    }
  }
  while ( v4 != 4 );
  return 0;
}