extern struct_0 *g_403ff8;

long long _init()
{
    struct struct_0 **v1;  // rax

    v1 = g_403ff8;
    if (v1)
        v1 = v1();
    return v1;
}

extern unsigned long long g_404008;

void sub_401020()
{
    unsigned long long v0;  // [sp-0x8]
    int tmp_6;  // tmp #6

    v0 = g_404008;
    goto tmp_6;
}

long long sub_401030()
{
    void* v0;  // [sp-0x8]

    v0 = 0;
    sub_401020(); /* do not return */
}

long long sub_401040()
{
    unsigned long long v0;  // [sp-0x8]

    v0 = 1;
    sub_401020(); /* do not return */
}

long long sub_401050()
{
    unsigned long long v0;  // [sp-0x8]

    v0 = 2;
    sub_401020(); /* do not return */
}

long long sub_401060()
{
    unsigned long long v0;  // [sp-0x8]

    v0 = 3;
    sub_401020(); /* do not return */
}

long long sub_401070()
{
    unsigned long long v0;  // [sp-0x8]

    v0 = 4;
    sub_401020(); /* do not return */
}

long long sub_401080()
{
    unsigned long long v0;  // [sp-0x8]

    v0 = 5;
    sub_401020(); /* do not return */
}

long long sub_401090()
{
    unsigned long long v0;  // [sp-0x8]

    v0 = 6;
    sub_401020(); /* do not return */
}

long long sub_4010a0()
{
    unsigned long long v0;  // [sp-0x8]

    v0 = 7;
    sub_401020(); /* do not return */
}

long long _start()
{
    unsigned long long v0;  // [sp+0x0]
    unsigned long v1;  // [bp+0x8]
    unsigned long v2;  // rax
    unsigned long long v3;  // rdx

    v0 = v2;
    __libc_start_main(main, v0, &v1, 0, 0, v3); /* do not return */
}

long long sub_401155()
{
    [D] Unsupported jumpkind Ijk_SigTRAP at address 4198741
}

long long _dl_relocate_static_pie()
{
    unsigned long v1;  // rax

    return v1;
}

extern char __TMC_END__;

void deregister_tm_clones()
{
    return;
}

void register_tm_clones()
{
    return;
}

extern char completed.0;

long long __do_global_dtors_aux()
{
    unsigned long v0;  // [sp-0x8]
    unsigned long v3;  // rax

    if (!completed.0)
    {
        *((int *)&v0) = vvar_4{reg 56};
        completed.0 = 1;
        return (unsigned long long)deregister_tm_clones();
    }
    return v3;
}

long long frame_dummy()
{
    return (unsigned long long)register_tm_clones();
}

extern FILE_t *stderr@GLIBC_2.2.5;
extern FILE_t *stdin@GLIBC_2.2.5;
extern FILE_t *stdout@GLIBC_2.2.5;

void init()
{
    setbuf(stdin@GLIBC_2.2.5, NULL);
    setbuf(stdout@GLIBC_2.2.5, NULL);
    setbuf(stderr@GLIBC_2.2.5, NULL);
    puts("welcome to the rtree system!");
    puts("in this level, we consider when every node in the tree has not more than one child, the tree becomes a linked list");
    puts("It's time to construct your own tree!");
    return;
}

long long backdoor()
{
    return system("echo 'this is a fake backdoor'");
}

long long edit(__int64 key, __int64 size1, __int64 size2, long long (*edit)(unsigned long long, unsigned int, unsigned int, unsigned long long))
{
    __int32 index;  // [bp-0x14]
    unsigned long v1;  // [sp-0x10]
    unsigned long long *v3;  // fs

    puts("sry, but you can only edit 8 bytes at a time");
    puts("please enter the index of the data you want to edit:");
    __isoc99_scanf("%d", &index);
    if (a1 <= (int)index)
    {
        puts("invalid index");
    }
    else
    {
        puts("please enter the new data:");
        read(0, a0 + index, 8);
        puts("edit success!");
    }
    return v1 - v3[5];
}

typedef struct struct_0 {
    __int64 key; // 0x0
    __int64 field_8; // pointer to data
    __int64 field_10; // size
    long long (*edit)(unsigned long long, unsigned int, unsigned int, unsigned long long); // 0x18
    struct_0 *next; // 0x20
} struct_0;

void print_node(struct_0 *a0)
{
    printf("key: %d\n", a0->key);
    printf("size: %d\n", a0->field_10);
    printf("data: %s\n", a0->field_8);
    return;
}

void print_info()
{
    puts("1. insert a node");
    puts("2. show a node");
    puts("3. edit a node");
    puts("4. quit");
    puts(">> ");
    return;
}

struct_0 *root;

int main()
{
    __int32 option;  // [bp-0x38]
    __int32 key;  // [bp-0x34]
    struct_0 *v2;  // [sp-0x30]
    unsigned long v3;  // [sp-0x28]
    unsigned long v4;  // [sp-0x20]
    struct_0 *v5;      // [sp-0x18]
    unsigned long v6;  // [sp-0x10]
    unsigned long v8;  // fs

    v6 = *((long long *)(40 + v8));
    init();
    while (true)
    {
        while (true)
        {
            while (true)
            {
                while (true)
                {
                    print_info();
                    __isoc99_scanf("%d", &option);
                    if (option != 1)
                        break;
                    v5 = malloc(40);
                    puts("please enter the node key:");
                    __isoc99_scanf("%d", v5);
                    puts("please enter the size of the data:");
                    __isoc99_scanf("%d", v5 + 16);
                    if (v5->size <= 8)
                        puts("sry, but plz enter a bigger size");
                    v5->data = malloc((int)v5->size);
                    puts("please enter the data:");
                    read(0, v5->data, v5->size);
                    v5->edit = edit;
                    v5->next = 0;
                    puts("insert success!");
                    if (!root)
                    {
                        root = v5;
                    }
                    else
                    {
                        for (v2 = root; v2->next; v2 = v2->next);
                        v2->next = v5;
                    }
                }
                if (option != 2)
                    break;
                puts("please enter the key of the node you want to show:");
                __isoc99_scanf("%d", &key);
                for (v3 = root; v3; v3 = v3->next)
                {
                    if ((int)v3->key == key)
                    {
                        print_node(v3);
                        break;
                    }
                }
                if (!v3)
                    puts("node not found :(");
            }
            if (option != 3)
                break;
            puts("please enter the key of the node you want to edit:");
            __isoc99_scanf("%d", &key);
            for (v4 = root; v4; v4 = v4->next)
            {
                if (v4->key == key)
                {
                    if (v4->edit)
                    {
                        // Will not pass the this pointer implicitly
                        v4->edit(v4->data, (int)v4->size, (int)v4->size, v4->next);
                        // Set to 0 to prevent re-edit
                        v4->edit = 0;
                    }
                    break;
                }
            }
            if (!v4)
                puts("node not found");
        }
        if (option == 4)
            break;
        puts("invalid choice");
    }
    if (v6 != *((long long *)(40 + v8)))
        __stack_chk_fail(); /* do not return */
    return 0;
}

long long _fini()
{
    unsigned long v1;  // rax

    return v1;
}

