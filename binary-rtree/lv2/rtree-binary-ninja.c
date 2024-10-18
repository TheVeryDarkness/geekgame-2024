// https://dogbolt.org/?id=056ab44d-9b7c-4bf3-8739-fb4c8b27add1#Hex-Rays=301&BinaryNinja=322
void _init()
{
    if (__gmon_start__ != 0)
        __gmon_start__();
}

int64_t sub_401020()
{
    int64_t var_8 = data_404008;
    /* jump -> data_404010 */
}

int64_t sub_401030()
{
    int64_t var_8 = 0;
    /* tailcall */
    return sub_401020();
}

int64_t sub_401040()
{
    int64_t var_8 = 1;
    /* tailcall */
    return sub_401020();
}

int64_t sub_401050()
{
    int64_t var_8 = 2;
    /* tailcall */
    return sub_401020();
}

int64_t sub_401060()
{
    int64_t var_8 = 3;
    /* tailcall */
    return sub_401020();
}

int64_t sub_401070()
{
    int64_t var_8 = 4;
    /* tailcall */
    return sub_401020();
}

int64_t sub_401080()
{
    int64_t var_8 = 5;
    /* tailcall */
    return sub_401020();
}

int64_t sub_401090()
{
    int64_t var_8 = 6;
    /* tailcall */
    return sub_401020();
}

int64_t sub_4010a0()
{
    int64_t var_8 = 7;
    /* tailcall */
    return sub_401020();
}

int32_t puts(char const* str)
{
    /* tailcall */
    return puts(str);
}

void __stack_chk_fail() __noreturn
{
    /* tailcall */
    return __stack_chk_fail();
}

void setbuf(FILE* fp, char* buf)
{
    /* tailcall */
    return setbuf(fp, buf);
}

int32_t system(char const* line)
{
    /* tailcall */
    return system(line);
}

int32_t printf(char const* format, ...)
{
    /* tailcall */
    return printf();
}

ssize_t read(int32_t fd, void* buf, uint64_t nbytes)
{
    /* tailcall */
    return read(fd, buf, nbytes);
}

int64_t malloc(uint64_t bytes)
{
    /* tailcall */
    return malloc(bytes);
}

int32_t __isoc99_scanf(char const* format, ...)
{
    /* tailcall */
    return __isoc99_scanf();
}

void _start(int64_t arg1, int64_t arg2, void (* arg3)()) __noreturn
{
    int64_t stack_end_1;
    int64_t stack_end = stack_end_1;
    __libc_start_main(main, __return_addr, &ubp_av, nullptr, nullptr, arg3, &stack_end);
    /* no return */
}

int64_t _dl_relocate_static_pie() __pure
{
    return;
}

void deregister_tm_clones()
{
    return;
}

void register_tm_clones()
{
    return;
}

void __do_global_dtors_aux()
{
    if (completed.0 != 0)
        return;
    
    deregister_tm_clones();
    completed.0 = 1;
}

void frame_dummy()
{
    /* tailcall */
    return register_tm_clones();
}

int64_t init()
{
    setbuf(stdin, nullptr);
    setbuf(stdout, nullptr);
    setbuf(stderr, nullptr);
    puts("welcome to the rtree system!");
    puts("in this level, we consider when …");
    return puts("It's time to construct your own …");
}

int64_t backdoor()
{
    return system("echo 'this is a fake backdoor'");
}

int64_t edit(int64_t arg1, int32_t arg2)
{
    void* fsbase;
    int64_t rax = *(fsbase + 0x28);
    puts("sry, but you can only edit 8 byt…");
    puts("please enter the index of the da…");
    int32_t var_14;
    __isoc99_scanf(&data_40214d, &var_14);
    
    if (arg2 > var_14)
    {
        puts("please enter the new data:");
        read(0, (arg1 + var_14), 8);
        puts("edit success!");
    }
    else
        puts("invalid index");
    
    if (rax == *(fsbase + 0x28))
        return (rax - *(fsbase + 0x28));
    
    __stack_chk_fail();
    /* no return */
}

int64_t print_node(int32_t* arg1)
{
    printf("key: %d\n", *arg1);
    printf("size: %d\n", arg1[4]);
    return printf("data: %s\n", *(arg1 + 8));
}

int64_t print_info()
{
    puts("1. insert a node");
    puts("2. show a node");
    puts("3. edit a node");
    puts("4. quit");
    return puts(&data_4021db);
}

int32_t main(int32_t argc, char** argv, char** envp)
{
    void* fsbase;
    int64_t rax = *(fsbase + 0x28);
    init();
    
    while (true)
    {
        print_info();
        int32_t var_38;
        __isoc99_scanf(&data_40214d, &var_38);
        
        if (var_38 == 1)
        {
            uint64_t rax_5 = malloc(0x28);
            puts("please enter the node key:");
            __isoc99_scanf(&data_40214d, rax_5);
            puts("please enter the size of the dat…");
            __isoc99_scanf(&data_40214d, (rax_5 + 0x10));
            
            if (*(rax_5 + 0x10) <= 8)
                puts("sry, but plz enter a bigger size");
            
            *(rax_5 + 8) = malloc(*(rax_5 + 0x10));
            puts("please enter the data:");
            read(0, *(rax_5 + 8), *(rax_5 + 0x10));
            *(rax_5 + 0x18) = edit;
            *(rax_5 + 0x20) = 0;
            puts("insert success!");
            
            if (root != 0)
            {
                uint64_t root_1 = root;
                
                while (*(root_1 + 0x20) != 0)
                    root_1 = *(root_1 + 0x20);
                
                *(root_1 + 0x20) = rax_5;
            }
            else
                root = rax_5;
        }
        else
        {
            int32_t var_34;
            
            if (var_38 == 2)
            {
                puts("please enter the key of the node…");
                __isoc99_scanf(&data_40214d, &var_34);
                uint64_t root_2;
                
                for (root_2 = root; root_2 != 0; root_2 = *(root_2 + 0x20))
                {
                    if (*root_2 == var_34)
                    {
                        print_node(root_2);
                        break;
                    }
                }
                
                if (root_2 == 0)
                    puts("node not found :(");
            }
            else if (var_38 != 3)
            {
                if (var_38 == 4)
                    break;
                
                puts("invalid choice");
            }
            else
            {
                puts("please enter the key of the node…");
                __isoc99_scanf(&data_40214d, &var_34);
                uint64_t root_3;
                
                for (root_3 = root; root_3 != 0; root_3 = *(root_3 + 0x20))
                {
                    if (*root_3 == var_34)
                    {
                        if (*(root_3 + 0x18) != 0)
                        {
                            *(root_3 + 0x18)(*(root_3 + 8), *(root_3 + 0x10));
                            *(root_3 + 0x18) = 0;
                        }
                        
                        break;
                    }
                }
                
                if (root_3 == 0)
                    puts("node not found");
            }
        }
    }
    
    *(fsbase + 0x28);
    
    if (rax == *(fsbase + 0x28))
        return 0;
    
    __stack_chk_fail();
    /* no return */
}

int64_t _fini() __pure
{
    return;
}

