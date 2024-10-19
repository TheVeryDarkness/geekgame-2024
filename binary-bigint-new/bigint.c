int64_t SI_PRC_$$__FPC_PROC_START()
{
    void* const __return_addr_1 = __return_addr;
    data_4266c8 = __return_addr_1;
    data_4266d0 = &arg_8;
    data_4266d8 = (((__return_addr_1 << 3) + 8) + &arg_8);
    data_4266e0 = &__return_addr;
    data_4266e8 = &__stklen;
    data_4266f0 = SI_PRC_$$__FPC_PROC_HALTPROC$LONGINT;
    return FPC_SysEntry(&TC_$SI_PRC_$$_SYSINITENTRYINFORMATION);
}

int64_t SI_PRC_$$__FPC_DYNAMIC_PROC_START(int64_t arg1, int64_t arg2, int64_t arg3)
{
    U_$SI_PRC_$$_DLEXITPROC = arg3;
    /* tailcall */
    return SI_PRC_$$__FPC_PROC_START();
}

int64_t sub_40105f() __pure
{
    return;
}

void SI_PRC_$$__FPC_PROC_HALTPROC$LONGINT(int32_t arg1) __noreturn
{
    int64_t U_$SI_PRC_$$_DLEXITPROC_1 = U_$SI_PRC_$$_DLEXITPROC;
    
    if (U_$SI_PRC_$$_DLEXITPROC_1 != 0)
        U_$SI_PRC_$$_DLEXITPROC_1();
    
    syscall(sys_exit_group {0xe7}, arg1);
    /* no return */
}

int64_t sub_401089(int64_t* arg1 @ rbp)
{
    *arg1;
}

bool BIGINT::COMPARE(class BIGINT this, class BIGINT B)
{
    int64_t rsi;
    int64_t var_10 = rsi;
    int32_t var_12e4;
    int32_t* rsi_2;
    int32_t* rdi_1;
    rdi_1 = __builtin_memcpy(&var_12e4, rsi, 0x258);
    *rdi_1 = *rsi_2;
    char var_1c;
    int32_t rax_2;
    int32_t* rdi;
    
    if (*rdi > var_12e4)
        var_1c = 1;
    else if (*rdi >= var_12e4)
    {
        rax_2 = *rdi;
        
        if (rax_2 >= 1)
        {
            int32_t var_20_1 = rax_2;
            int32_t i = (rax_2 + 1);
            
            do
            {
                i -= 1;
                
                if (rdi[i] > &var_12e4[i])
                {
                    var_1c = 1;
                    goto label_401146;
                }
                
                if (rdi[i] < &var_12e4[i])
                {
                    var_1c = 0;
                    goto label_401146;
                }
            } while (i > 1);
        }
        
        var_1c = 1;
    }
    else
        var_1c = 0;
    
label_401146:
    rax_2 = var_1c;
    return rax_2;
}

uint64_t BIGINT::ADD(class BIGINT this, class BIGINT B)
{
    int64_t rdx;
    int64_t var_10 = rdx;
    int32_t result_2;
    int32_t* rsi_2;
    int32_t* rdi_1;
    rdi_1 = __builtin_memcpy(&result_2, rdx, 0x258);
    *rdi_1 = *rsi_2;
    char* rsi;
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(rsi, 0x12c4, 0);
    int32_t result_1;
    int32_t* rdi;
    
    if (*rdi <= result_2)
        result_1 = result_2;
    else
        result_1 = *rdi;
    
    if (result_1 >= 1)
    {
        int32_t var_24_1 = 0;
        
        do
        {
            var_24_1 += 1;
            uint64_t rsi_5 = var_24_1;
            *(rsi + (rsi_5 << 2)) += (&result_2[var_24_1] + rdi[var_24_1]);
            
            if (*(rsi + (var_24_1 << 2)) >= 0xa)
            {
                uint64_t rdx_5 = var_24_1;
                *(rsi + (rdx_5 << 2)) -= 0xa;
                int64_t rdx_6 = var_24_1;
                *((rsi + (rdx_6 << 2)) + 4) += 1;
            }
        } while (result_1 > var_24_1);
    }
    
    if (*((rsi + (result_1 << 2)) + 4) > 0)
        result_1 += 1;
    
    uint64_t result = result_1;
    *rsi = result;
    return result;
}

char* BIGINT::SUB(class BIGINT this, class BIGINT B)
{
    int64_t rdx;
    int64_t var_10 = rdx;
    void var_12ec;
    int32_t* rsi_1;
    int32_t* rdi_1;
    rdi_1 = __builtin_memcpy(&var_12ec, rdx, 0x258);
    *rdi_1 = *rsi_1;
    char* result;
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(result, 0x12c4, 0);
    int32_t* rdi;
    int32_t i_1 = *rdi;
    int32_t i = i_1;
    
    if (i_1 >= 1)
    {
        int32_t var_24_1 = 0;
        
        do
        {
            var_24_1 += 1;
            uint64_t rsi_4 = var_24_1;
            *(result + (rsi_4 << 2)) += (rdi[var_24_1] - *(&var_12ec + (var_24_1 << 2)));
            
            if (*(result + (var_24_1 << 2)) < 0)
            {
                uint64_t rdx_5 = var_24_1;
                *(result + (rdx_5 << 2)) += 0xa;
                int64_t rdx_6 = var_24_1;
                *((result + (rdx_6 << 2)) + 4) -= 1;
            }
        } while (i_1 > var_24_1);
    }
    
    for (; i > 1; i -= 1)
    {
        if (*(result + (i << 2)) != 0)
            break;
    }
    
    *result = i;
    return result;
}

uint64_t BIGINT::MUL(class BIGINT this, LONGINT B)
{
    int32_t* B_1 = B;
    char* rsi;
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(rsi, 0x12c4, 0);
    int32_t rsi_1 = *B_1;
    
    if (rsi_1 >= 1)
    {
        int32_t var_24_1 = 0;
        
        do
        {
            var_24_1 += 1;
            uint64_t rcx_1 = var_24_1;
            int32_t rdx;
            *(rsi + (rcx_1 << 2)) += (rdx * B_1[var_24_1]);
            int64_t rcx_4 = var_24_1;
            *((rsi + (rcx_4 << 2)) + 4) += (*(rsi + (var_24_1 << 2)) / 0xa);
            *(rsi + (var_24_1 << 2)) = (*(rsi + (var_24_1 << 2)) % 0xa);
        } while (rsi_1 > var_24_1);
    }
    
    int32_t i = (rsi_1 + 1);
    
    while (*(rsi + (i << 2)) >= 0xa)
    {
        *((rsi + (i << 2)) + 4) = (*(rsi + (i << 2)) / 0xa);
        *(rsi + (i << 2)) = (*(rsi + (i << 2)) % 0xa);
        i += 1;
    }
    
    for (; i > 1; i -= 1)
    {
        if (*(rsi + (i << 2)) != 0)
            break;
    }
    
    uint64_t result = i;
    *rsi = result;
    return result;
}

char* BIGINT::MUL2(class BIGINT this, class BIGINT B)
{
    int64_t rdx;
    int64_t var_10 = rdx;
    int32_t var_12f0;
    int32_t* rsi_1;
    int32_t* rdi_1;
    rdi_1 = __builtin_memcpy(&var_12f0, rdx, 0x258);
    *rdi_1 = *rsi_1;
    char* result;
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(result, 0x12c4, 0);
    int32_t* rdi;
    int32_t rdi_4 = *rdi;
    
    if (rdi_4 >= 1)
    {
        int32_t var_24_1 = 0;
        
        do
        {
            var_24_1 += 1;
            int32_t rsi_3 = var_12f0;
            
            if (rsi_3 >= 1)
            {
                int32_t var_28_1 = 0;
                
                do
                {
                    var_28_1 += 1;
                    int64_t rdx_4 = (var_28_1 + var_24_1);
                    *((result + (rdx_4 << 2)) - 4) += (&var_12f0[var_28_1] * rdi[var_24_1]);
                    int64_t rax_9 = (var_28_1 + var_24_1);
                    *(result + (rax_9 << 2)) += (*((result + ((var_28_1 + var_24_1) << 2)) - 4) / 0xa);
                    *((result + ((var_24_1 + var_28_1) << 2)) - 4) = (*((result + ((var_28_1 + var_24_1) << 2)) - 4) % 0xa);
                } while (rsi_3 > var_28_1);
            }
        } while (rdi_4 > var_24_1);
    }
    
    int32_t i;
    
    for (i = ((*rdi + var_12f0) + 1); i > 1; i -= 1)
    {
        if (*(result + (i << 2)) != 0)
            break;
    }
    
    *result = i;
    return result;
}

int32_t* BIGINT::MODN(class BIGINT this, class BIGINT B)
{
    int64_t rdx;
    int64_t var_10 = rdx;
    void var_12ec;
    int32_t* rsi_1;
    int32_t* rdi_1;
    rdi_1 = __builtin_memcpy(&var_12ec, rdx, 0x258);
    *rdi_1 = *rsi_1;
    int32_t* result_1;
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(result_1, 0x12c4, 0);
    int32_t* rdi;
    int32_t rax_2 = *rdi;
    int32_t* result = result_1;
    *result = 1;
    
    if (rax_2 >= 1)
    {
        int32_t i = (rax_2 + 1);
        
        do
        {
            i -= 1;
            void var_25b8;
            BIGINT::MUL(var_25b8, result_1);
            void var_25b0;
            int32_t* rsi_3;
            int32_t* rdi_6;
            rdi_6 = __builtin_memcpy(result_1, &var_25b0, 0x258);
            *rdi_6 = *rsi_3;
            result_1[1] = rdi[i];
            
            while (true)
            {
                result = BIGINT::COMPARE();
                
                if (result == 0)
                    break;
                
                BIGINT::SUB();
                int32_t* rsi_5;
                int32_t* rdi_10;
                rdi_10 = __builtin_memcpy(result_1, &var_25b0, 0x258);
                *rdi_10 = *rsi_5;
            }
        } while (i > 1);
    }
    
    return result;
}

char* CREATENUM(LONGINT X)
{
    char* result = X;
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(result, 0x12c4, 0);
    int32_t rsi;
    *(result + 4) = rsi;
    int32_t var_1c = 1;
    
    while (*(result + (var_1c << 2)) >= 0xa)
    {
        *((result + (var_1c << 2)) + 4) = (*(result + (var_1c << 2)) / 0xa);
        *(result + (var_1c << 2)) = (*(result + (var_1c << 2)) % 0xa);
        var_1c += 1;
    }
    
    *result = var_1c;
    return result;
}

char* STR2INT(struct ShortString X)
{
    char* rsi;
    char* var_10 = rsi;
    char var_11c;
    FPC_SHORTSTR_TO_SHORTSTR(&var_11c, 0xff, rsi);
    int64_t rdi;
    char* result = CREATENUM(rdi);
    uint32_t rbx_1 = var_11c;
    
    if (rbx_1 >= 1)
    {
        int32_t var_1c_1 = 0;
        
        do
        {
            var_1c_1 += 1;
            int64_t rbx;
            BIGINT::MUL(rbx, rdi);
            &var_11c[var_1c_1];
            void X_1;
            CREATENUM(&X_1);
            result = BIGINT::ADD();
            void var_26a4;
            int32_t* rsi_3;
            int32_t* rdi_6;
            rdi_6 = __builtin_memcpy(rdi, &var_26a4, 0x258);
            *rdi_6 = *rsi_3;
        } while (rbx_1 > var_1c_1);
    }
    
    return result;
}

bool CHECKFLAG1(class BIGINT X)
{
    int64_t rdi;
    int64_t var_10 = rdi;
    void var_3860;
    int32_t* rsi_1;
    int32_t* rdi_1;
    rdi_1 = __builtin_memcpy(&var_3860, rdi, 0x258);
    *rdi_1 = *rsi_1;
    BIGINT::MUL2();
    void X_1;
    STR2INT(X_1);
    BIGINT::ADD();
    BIGINT::MUL2();
    BIGINT::MUL2();
    STR2INT();
    BIGINT::MUL2();
    STR2INT();
    BIGINT::ADD();
    
    if ((BIGINT::COMPARE() != 0 && BIGINT::COMPARE() != 0))
        return true;
    
    return false;
}

int64_t main()
{
    FPC_INITIALIZEUNITS();
    void X;
    STR2INT(X);
    void var_12cc;
    int32_t* rsi_1;
    int32_t* rdi;
    rdi = __builtin_memcpy(0x42fff0, &var_12cc, 0x258);
    *rdi = *rsi_1;
    STR2INT();
    int32_t* rsi_4;
    int32_t* rdi_2;
    rdi_2 = __builtin_memcpy(0x4312c0, &var_12cc, 0x258);
    *rdi_2 = *rsi_4;
    void* rax = fpc_get_output();
    FPC_WRITE_TEXT_SHORTSTR(0, rax, "*Which flag do you want to check…");
    FPC_IOCHECK();
    fpc_write_end(rax);
    FPC_IOCHECK();
    void* rax_1 = fpc_get_input();
    uint8_t var_10;
    fpc_read_text_sint(rax_1, &var_10);
    int64_t rsi_8 = FPC_IOCHECK();
    OPTION = var_10;
    FPC_READLN_END(rax_1, rsi_8);
    FPC_IOCHECK();
    void* rax_3 = fpc_get_output();
    FPC_WRITE_TEXT_SHORTSTR(0, rax_3, &_$PROGRAM$_Ld7);
    FPC_IOCHECK();
    fpc_write_end(rax_3);
    FPC_IOCHECK();
    void* rax_4 = fpc_get_input();
    fpc_read_text_shortstr(rax_4, &S, 0xff);
    FPC_READLN_END(rax_4, FPC_IOCHECK());
    FPC_IOCHECK();
    STR2INT();
    int32_t* rsi_12;
    int32_t* rdi_10;
    rdi_10 = __builtin_memcpy(0x432590, &var_12cc, 0x258);
    *rdi_10 = *rsi_12;
    uint8_t OPTION_1 = OPTION;
    
    if (OPTION_1 == 1)
    {
        int32_t temp1_1;
        int32_t temp2_1;
        temp1_1 = HIGHD((0xaaaaaaab * S.length));
        temp2_1 = LOWD((0xaaaaaaab * S.length));
        *S.st[0xff] = (temp1_1 >> 1);
        void var_13cc;
        fpc_shortstr_copy(&var_13cc, &S, 1, *S.st[0xff]);
        STR2INT();
        
        if (CHECKFLAG1() == 0)
            OK = 0;
        else
        {
            void var_108;
            fpc_shortstr_copy(&var_108, &S, (*S.st[0xff] + 1), *S.st[0xff]);
            STR2INT();
            
            if (CHECKFLAG1() == 0)
                OK = 0;
            else
            {
                fpc_shortstr_copy(&var_108, &S, ((*S.st[0xff] << 1) + 1), 0x7fffffffffffffff);
                STR2INT();
                
                if (CHECKFLAG1() == 0)
                    OK = 0;
                else
                    OK = 1;
            }
        }
    }
    else if (OPTION_1 == 2)
    {
        *S.st[0xff] = 0;
        
        do
        {
            *S.st[0xff] += 1;
            BIGINT::MUL2();
            BIGINT::MODN();
            void var_2690;
            int32_t* rsi_14;
            int32_t* rdi_16;
            rdi_16 = __builtin_memcpy(0x432590, &var_2690, 0x258);
            *rdi_16 = *rsi_14;
        } while (*S.st[0xff] < 0x10);
        
        STR2INT();
        BIGINT::MUL2();
        BIGINT::MODN();
        void var_3954;
        int32_t* rsi_17;
        int32_t* rdi_19;
        rdi_19 = __builtin_memcpy(0x432590, &var_3954, 0x258);
        *rdi_19 = *rsi_17;
        bool rax_12 = BIGINT::COMPARE();
        bool rax_13;
        
        if (rax_12 != 0)
            rax_13 = BIGINT::COMPARE();
        
        if ((rax_12 == 0 || rax_13 == 0))
            OK = 0;
        else
            OK = 1;
    }
    else
    {
        void* rax_14 = fpc_get_output();
        FPC_WRITE_TEXT_SHORTSTR(0, rax_14, &_$PROGRAM$_Ld8);
        FPC_IOCHECK();
        fpc_writeln_end(rax_14);
        FPC_IOCHECK();
        SYSTEM_$$_HALT$LONGINT(0);
    }
    
    if (OK == 0)
    {
        void* rax_16 = fpc_get_output();
        FPC_WRITE_TEXT_SHORTSTR(0, rax_16, &_$PROGRAM$_Ld10);
        FPC_IOCHECK();
        fpc_writeln_end(rax_16);
        FPC_IOCHECK();
    }
    else
    {
        void* rax_15 = fpc_get_output();
        FPC_WRITE_TEXT_SHORTSTR(0, rax_15, &_$PROGRAM$_Ld9);
        FPC_IOCHECK();
        fpc_writeln_end(rax_15);
        FPC_IOCHECK();
    }
    
    return FPC_DO_EXIT();
}

int64_t FPC_SYSCALL0(int64_t arg1)
{
    int64_t result = syscall(arg1);
    
    if (result < -0xfff)
        return result;
    
    FPC_SYS_SETERRNO(-(result));
    return -1;
}

int64_t FPC_SYSCALL1(int64_t arg1, int64_t arg2)
{
    int64_t result = syscall(arg1, arg2);
    
    if (result < -0xfff)
        return result;
    
    FPC_SYS_SETERRNO(-(result));
    return -1;
}

int64_t FPC_SYSCALL2(int64_t arg1, int64_t arg2, int64_t arg3)
{
    int64_t result = syscall(arg1, arg2, arg3);
    
    if (result < -0xfff)
        return result;
    
    FPC_SYS_SETERRNO(-(result));
    return -1;
}

int64_t FPC_SYSCALL3(int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4)
{
    int64_t result = syscall(arg1, arg2, arg3, arg4);
    
    if (result < -0xfff)
        return result;
    
    FPC_SYS_SETERRNO(-(result));
    return -1;
}

int64_t FPC_SYSCALL4(int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4, int64_t arg5)
{
    int64_t result = syscall(arg1, arg2, arg3, arg4, arg5);
    
    if (result < -0xfff)
        return result;
    
    FPC_SYS_SETERRNO(-(result));
    return -1;
}

int64_t FPC_SYSCALL5(int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4, int64_t arg5, int64_t arg6)
{
    int64_t result = syscall(arg1, arg2, arg3, arg4, arg5, arg6);
    
    if (result < -0xfff)
        return result;
    
    FPC_SYS_SETERRNO(-(result));
    return -1;
}

int64_t FPC_SYSCALL6(int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4, int64_t arg5, int64_t arg6, int64_t arg7)
{
    int64_t result = syscall(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    
    if (result < -0xfff)
        return result;
    
    FPC_SYS_SETERRNO(-(result));
    return -1;
}

int64_t SYSTEM_$$_LINUX_RESTORE(uint64_t arg1)
{
    return syscall(sigreturn {0xf}, arg1);
}

void SYSTEM_$$_SPTR$$POINTER() __pure
{
    return;
}

void* const SYSTEM_$$_GET_PC_ADDR$$POINTER() __pure
{
    return __return_addr;
}

uint64_t FPC_MOVE(int64_t arg1, char* arg2, uint64_t arg3)
{
    uint64_t i_1 = arg3;
    char* rdx = arg2;
    uint64_t result = i_1;
    char* rcx_1 = (arg1 - rdx);
    
    if (arg1 != rdx)
    {
        if (arg1 < rdx)
        {
            uint64_t result_1 = result;
            result = &rcx_1[result];
            
            if (&rcx_1[result_1] < result_1)
            {
                int32_t* rdx_1 = &rdx[i_1];
                
                if (i_1 >= 8)
                {
                    if ((rdx_1 & 7) != 0)
                    {
                        if ((rdx_1 & 1) != 0)
                        {
                            rdx_1 -= 1;
                            result = *(rcx_1 + rdx_1);
                            i_1 -= 1;
                            *rdx_1 = result;
                        }
                        
                        if ((rdx_1 & 2) != 0)
                        {
                            rdx_1 -= 2;
                            result = *(rcx_1 + rdx_1);
                            i_1 -= 2;
                            *rdx_1 = result;
                        }
                        
                        if ((rdx_1 & 4) != 0)
                        {
                            rdx_1 -= 4;
                            result = *(rcx_1 + rdx_1);
                            i_1 -= 4;
                            *rdx_1 = result;
                        }
                    }
                    
                    while (true)
                    {
                        uint64_t i_9 = (i_1 >> 5);
                        
                        if (i_9 == 0)
                            break;
                        
                        if ((i_9 < 0x2000 || rcx_1 >= -0x1000))
                        {
                            uint64_t i;
                            
                            do
                            {
                                rdx_1 -= 0x20;
                                int64_t r10_7 = *((rcx_1 + rdx_1) + 0x10);
                                *(rdx_1 + 0x18) = *((rcx_1 + rdx_1) + 0x18);
                                *(rdx_1 + 0x10) = r10_7;
                                i = i_9;
                                i_9 -= 1;
                                result = *((rcx_1 + rdx_1) + 8);
                                int64_t r10_8 = *(rcx_1 + rdx_1);
                                *(rdx_1 + 8) = result;
                                *rdx_1 = r10_8;
                            } while (i != 1);
                            i_1 &= 0x1f;
                            break;
                        }
                        
                        do
                        {
                            int32_t j_5 = 0x20;
                            int32_t j;
                            
                            do
                            {
                                rdx_1 -= 0x80;
                                j = j_5;
                                j_5 -= 1;
                            } while (j != 1);
                            rdx_1 = &rdx_1[0x400];
                            result = 0x40;
                            int32_t j_1;
                            
                            do
                            {
                                rdx_1 -= 0x40;
                                int64_t r10_9 = *((rcx_1 + rdx_1) + 0x30);
                                *(rdx_1 + 0x38) = *((rcx_1 + rdx_1) + 0x38);
                                *(rdx_1 + 0x30) = r10_9;
                                int64_t r10_10 = *((rcx_1 + rdx_1) + 0x20);
                                *(rdx_1 + 0x28) = *((rcx_1 + rdx_1) + 0x28);
                                *(rdx_1 + 0x20) = r10_10;
                                j_1 = result;
                                result = (result - 1);
                                int64_t r10_11 = *((rcx_1 + rdx_1) + 0x10);
                                *(rdx_1 + 0x18) = *((rcx_1 + rdx_1) + 0x18);
                                *(rdx_1 + 0x10) = r10_11;
                                int64_t r10_12 = *(rcx_1 + rdx_1);
                                *(rdx_1 + 8) = *((rcx_1 + rdx_1) + 8);
                                *rdx_1 = r10_12;
                            } while (j_1 != 1);
                            i_1 -= 0x1000;
                        } while (i_1 >= 0x1000);
                        
                        continue;
                    }
                    
                    uint64_t i_10 = (i_1 >> 3);
                    
                    if (i_10 != 0)
                    {
                        uint64_t i_2;
                        
                        do
                        {
                            rdx_1 -= 8;
                            result = *(rcx_1 + rdx_1);
                            i_2 = i_10;
                            i_10 -= 1;
                            *rdx_1 = result;
                        } while (i_2 != 1);
                        i_1 &= 7;
                    }
                }
                
                if (i_1 > 0)
                {
                    uint64_t i_3;
                    
                    do
                    {
                        rdx_1 -= 1;
                        result = *(rcx_1 + rdx_1);
                        i_3 = i_1;
                        i_1 -= 1;
                        *rdx_1 = result;
                    } while (i_3 != 1);
                }
                
                return result;
            }
        }
        
        if (i_1 >= 8)
        {
            if ((rdx & 7) != 0)
            {
                if ((rdx & 1) != 0)
                {
                    result = *(rcx_1 + rdx);
                    i_1 -= 1;
                    *rdx = result;
                    rdx = &rdx[1];
                }
                
                if ((rdx & 2) != 0)
                {
                    result = *(rcx_1 + rdx);
                    i_1 -= 2;
                    *rdx = result;
                    rdx = &rdx[2];
                }
                
                if ((rdx & 4) != 0)
                {
                    result = *(rcx_1 + rdx);
                    i_1 -= 4;
                    *rdx = result;
                    rdx = &rdx[4];
                }
            }
            
            while (true)
            {
                uint64_t i_7 = (i_1 >> 5);
                
                if (i_7 == 0)
                    break;
                
                if ((i_7 < 0x2000 || rcx_1 < 0x1000))
                {
                    uint64_t i_4;
                    
                    do
                    {
                        rdx = &rdx[0x20];
                        int64_t r10_1 = *((rcx_1 + rdx) - 0x18);
                        *(rdx - 0x20) = *((rcx_1 + rdx) - 0x20);
                        *(rdx - 0x18) = r10_1;
                        i_4 = i_7;
                        i_7 -= 1;
                        result = *((rcx_1 + rdx) - 0x10);
                        int64_t r10_2 = *((rcx_1 + rdx) - 8);
                        *(rdx - 0x10) = result;
                        *(rdx - 8) = r10_2;
                    } while (i_4 != 1);
                    i_1 &= 0x1f;
                    break;
                }
                
                do
                {
                    int32_t j_4 = 0x20;
                    int32_t j_2;
                    
                    do
                    {
                        rdx = &rdx[0x80];
                        j_2 = j_4;
                        j_4 -= 1;
                    } while (j_2 != 1);
                    rdx -= 0x1000;
                    result = 0x40;
                    int32_t j_3;
                    
                    do
                    {
                        rdx = &rdx[0x40];
                        int64_t r10_3 = *((rcx_1 + rdx) - 0x38);
                        *(rdx - 0x40) = *((rcx_1 + rdx) - 0x40);
                        *(rdx - 0x38) = r10_3;
                        int64_t r10_4 = *((rcx_1 + rdx) - 0x28);
                        *(rdx - 0x30) = *((rcx_1 + rdx) - 0x30);
                        *(rdx - 0x28) = r10_4;
                        j_3 = result;
                        result = (result - 1);
                        int64_t r10_5 = *((rcx_1 + rdx) - 0x18);
                        *(rdx - 0x20) = *((rcx_1 + rdx) - 0x20);
                        *(rdx - 0x18) = r10_5;
                        int64_t r10_6 = *((rcx_1 + rdx) - 8);
                        *(rdx - 0x10) = *((rcx_1 + rdx) - 0x10);
                        *(rdx - 8) = r10_6;
                    } while (j_3 != 1);
                    i_1 -= 0x1000;
                } while (i_1 >= 0x1000);
                
                continue;
            }
            
            uint64_t i_8 = (i_1 >> 3);
            
            if (i_8 != 0)
            {
                uint64_t i_5;
                
                do
                {
                    result = *(rcx_1 + rdx);
                    *rdx = result;
                    rdx = &rdx[8];
                    i_5 = i_8;
                    i_8 -= 1;
                } while (i_5 != 1);
                i_1 &= 7;
            }
        }
        
        if (i_1 > 0)
        {
            uint64_t i_6;
            
            do
            {
                result = *(rcx_1 + rdx);
                *rdx = result;
                rdx = &rdx[1];
                i_6 = i_1;
                i_1 -= 1;
            } while (i_6 != 1);
        }
    }
    
    return result;
}

int64_t sub_402312() __pure
{
    return;
}

void SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(char* arg1, int64_t arg2, int64_t arg3)
{
    int64_t r8_1 = arg3;
    int64_t i_6 = arg2;
    char* rcx = arg1;
    
    if (i_6 >= 8)
    {
        r8_1 = ((r8_1 & 0xff) * 0x101010101010101);
        
        if ((rcx & 7) != 0)
        {
            if ((rcx & 1) != 0)
            {
                *rcx = r8_1;
                rcx = &rcx[1];
                i_6 -= 1;
            }
            
            if ((rcx & 2) != 0)
            {
                *rcx = r8_1;
                rcx = &rcx[2];
                i_6 -= 2;
            }
            
            if ((rcx & 4) != 0)
            {
                *rcx = r8_1;
                rcx = &rcx[4];
                i_6 -= 4;
            }
        }
        
        int64_t rdx = (i_6 & 0x3f);
        uint64_t i_5 = (i_6 >> 6);
        
        if (i_5 != 0)
        {
            if (i_5 >= 0x2000)
            {
                uint64_t i;
                
                do
                {
                    rcx = &rcx[0x40];
                    *(rcx - 0x40) = r8_1;
                    *(rcx - 0x38) = r8_1;
                    *(rcx - 0x30) = r8_1;
                    *(rcx - 0x28) = r8_1;
                    i = i_5;
                    i_5 -= 1;
                    *(rcx - 0x20) = r8_1;
                    *(rcx - 0x18) = r8_1;
                    *(rcx - 0x10) = r8_1;
                    *(rcx - 8) = r8_1;
                } while (i != 1);
            }
            else
            {
                uint64_t i_1;
                
                do
                {
                    rcx = &rcx[0x40];
                    *(rcx - 0x40) = r8_1;
                    *(rcx - 0x38) = r8_1;
                    *(rcx - 0x30) = r8_1;
                    *(rcx - 0x28) = r8_1;
                    i_1 = i_5;
                    i_5 -= 1;
                    *(rcx - 0x20) = r8_1;
                    *(rcx - 0x18) = r8_1;
                    *(rcx - 0x10) = r8_1;
                    *(rcx - 8) = r8_1;
                } while (i_1 != 1);
            }
        }
        
        i_6 = (rdx & 7);
        uint64_t i_4 = (rdx >> 3);
        
        if (i_4 != 0)
        {
            uint64_t i_2;
            
            do
            {
                *rcx = r8_1;
                rcx = &rcx[8];
                i_2 = i_4;
                i_4 -= 1;
            } while (i_2 != 1);
        }
    }
    
    if (i_6 > 0)
    {
        int64_t i_3;
        
        do
        {
            *rcx = r8_1;
            rcx = &rcx[1];
            i_3 = i_6;
            i_6 -= 1;
        } while (i_3 != 1);
    }
}

int64_t sub_402439() __pure
{
    return;
}

void* SYSTEM_$$_INDEXBYTE$formal$INT64$BYTE$$INT64(char (* arg1)[0x10], int64_t arg2, int32_t arg3)
{
    uint128_t zmm1 = arg3;
    zmm1 = _mm_unpacklo_epi8(zmm1, zmm1);
    zmm1 = _mm_unpacklo_epi8(zmm1, zmm1);
    
    if (arg2 != 0)
    {
        zmm1 = _mm_shuffle_epi32(zmm1, 0);
        void* rcx_3 = (((arg1 & 0xfffffffffffffff0) + 0x10) - arg1);
        uint32_t rax_4 = (((_mm_movemask_epi8(_mm_cmpeq_epi8(*(arg1 & 0xfffffffffffffff0), zmm1)) << rcx_3) & 0xffff0000) >> rcx_3);
        
        while (true)
        {
            if (rax_4 != 0)
            {
                uint64_t rflags_1;
                int32_t temp0_7;
                temp0_7 = _bit_scan_forward(rax_4);
                
                if (arg2 > ((rcx_3 + temp0_7) - 0x10))
                    return ((rcx_3 + temp0_7) - 0x10);
                
                break;
            }
            
            if (arg2 <= rcx_3)
                break;
            
            char zmm0[0x10] = *(arg1 + rcx_3);
            rcx_3 += 0x10;
            rax_4 = _mm_movemask_epi8(_mm_cmpeq_epi8(zmm0, zmm1));
        }
    }
    
    return -1;
}

int64_t SYSTEM_$$_INDEXWORD$formal$INT64$WORD$$INT64(int16_t (* arg1)[0x8], int64_t arg2, int32_t arg3)
{
    uint128_t zmm1 = arg3;
    zmm1 = _mm_shuffle_epi32(_mm_unpacklo_epi16(zmm1, zmm1), 0);
    
    if (arg2 != 0)
    {
        int16_t zmm0[0x8] = *(arg1 & 0xfffffffffffffff0);
        void* rcx_3 = (((arg1 & 0xfffffffffffffff0) + 0x10) - arg1);
        
        if ((arg1 & 1) != 0)
        {
            zmm1 = (_mm_slli_epi16(zmm1, 8) | _mm_srli_epi16(zmm1, 8));
            uint32_t rax_12 = (((_mm_movemask_epi8(_mm_cmpeq_epi8(zmm0, zmm1)) << rcx_3) & 0xffff0000) >> rcx_3);
            int64_t rdx_1 = (arg2 * 2);
            uint32_t r10 = 0;
            
            while (true)
            {
                uint32_t rax_14 = ((rax_12 << 1) | r10);
                int32_t rax_17 = (((rax_14 >> 1) & rax_14) & 0x5555);
                
                if (rax_17 != 0)
                {
                    uint64_t rflags_2;
                    int32_t temp0_13;
                    temp0_13 = _bit_scan_forward(rax_17);
                    
                    if (rdx_1 > ((rcx_3 + temp0_13) - 0x10))
                        return (((rcx_3 + temp0_13) - 0x10) >> 1);
                    
                    return -1;
                }
                
                if (rdx_1 <= rcx_3)
                    return -1;
                
                zmm0 = *(arg1 + rcx_3);
                rcx_3 += 0x10;
                r10 = (rax_14 >> 0x10);
                rax_12 = _mm_movemask_epi8(_mm_cmpeq_epi8(zmm0, zmm1));
            }
        }
        else
        {
            uint32_t rax_4 = (((_mm_movemask_epi8(_mm_cmpeq_epi16(zmm0, zmm1)) << rcx_3) & 0xffff0000) >> rcx_3);
            uint64_t rcx_4 = (rcx_3 >> 1);
            
            while (true)
            {
                if (rax_4 != 0)
                {
                    uint64_t rflags_1;
                    int32_t temp0_6;
                    temp0_6 = _bit_scan_forward(rax_4);
                    
                    if (arg2 > ((rcx_4 + (temp0_6 >> 1)) - 8))
                        return ((rcx_4 + (temp0_6 >> 1)) - 8);
                    
                    break;
                }
                
                if (arg2 <= rcx_4)
                    break;
                
                zmm0 = *(arg1 + (rcx_4 << 1));
                rcx_4 += 8;
                rax_4 = _mm_movemask_epi8(_mm_cmpeq_epi16(zmm0, zmm1));
            }
        }
    }
    
    return -1;
}

uint64_t SYSTEM_$$_COMPAREBYTE$formal$formal$INT64$$INT64(int64_t arg1, int64_t arg2, int64_t arg3)
{
    int64_t i_1 = -(arg3);
    
    if (i_1 != 0)
    {
        void* rcx_1 = (arg1 - i_1);
        char* rdx_1 = (arg2 - i_1);
        int64_t i;
        
        do
        {
            uint64_t rax_1 = *(rcx_1 + i_1);
            
            if (rax_1 != rdx_1[i_1])
                return (rax_1 - rdx_1[i_1]);
            
            i = i_1;
            i_1 += 1;
        } while (i != -1);
    }
    
    return 0;
}

uint32_t* SYSTEM_$$_DECLOCKED$LONGINT$$BOOLEAN(int32_t* arg1)
{
    bool cond:1;
    
    if (TC_$SYSTEM_$$_ISMULTITHREAD == 0)
    {
        int32_t temp0_1 = *arg1;
        *arg1 -= 1;
        cond:1 = temp0_1 == 1;
    }
    else
    {
        int32_t temp1_1 = *arg1;
        *arg1 -= 1;
        cond:1 = temp1_1 == 1;
    }
    
    uint32_t* result;
    result = cond:1;
    return result;
}

uint32_t* SYSTEM_$$_DECLOCKED$INT64$$BOOLEAN(int64_t* arg1)
{
    bool cond:1;
    
    if (TC_$SYSTEM_$$_ISMULTITHREAD == 0)
    {
        int64_t temp0_1 = *arg1;
        *arg1 -= 1;
        cond:1 = temp0_1 == 1;
    }
    else
    {
        int64_t temp1_1 = *arg1;
        *arg1 -= 1;
        cond:1 = temp1_1 == 1;
    }
    
    uint32_t* result;
    result = cond:1;
    return result;
}

void SYSTEM_$$_INCLOCKED$LONGINT(int32_t* arg1)
{
    if (TC_$SYSTEM_$$_ISMULTITHREAD == 0)
        *arg1 += 1;
    else
        *arg1 += 1;
}

void SYSTEM_$$_INCLOCKED$INT64(int64_t* arg1)
{
    if (TC_$SYSTEM_$$_ISMULTITHREAD == 0)
        *arg1 += 1;
    else
        *arg1 += 1;
}

uint64_t FPC_INTERLOCKEDDECREMENT(int32_t* arg1)
{
    int32_t rax = *arg1;
    *arg1 -= 1;
    return (rax - 1);
}

uint64_t FPC_INTERLOCKEDINCREMENT(int32_t* arg1)
{
    int32_t rax = *arg1;
    *arg1 += 1;
    return (rax + 1);
}

uint64_t FPC_INTERLOCKEDEXCHANGE(int32_t* arg1, int32_t arg2)
{
    int32_t temp0 = *arg1;
    *arg1 = arg2;
    return temp0;
}

uint64_t FPC_INTERLOCKEDEXCHANGEADD(int32_t* arg1, int32_t arg2)
{
    int32_t rdi = *arg1;
    *arg1 += arg2;
    return rdi;
}

int32_t FPC_INTERLOCKEDCOMPAREEXCHANGE(int32_t* arg1, int32_t arg2, int32_t arg3)
{
    if (arg3 != *arg1)
        return *arg1;
    
    *arg1 = arg2;
    return arg3;
}

int64_t FPC_INTERLOCKEDDECREMENT64(int64_t* arg1)
{
    int64_t rax = *arg1;
    *arg1 -= 1;
    return (rax - 1);
}

int64_t FPC_INTERLOCKEDINCREMENT64(int64_t* arg1)
{
    int64_t rax = *arg1;
    *arg1 += 1;
    return (rax + 1);
}

int64_t FPC_INTERLOCKEDEXCHANGE64(int64_t* arg1, int64_t arg2)
{
    int64_t result = *arg1;
    *arg1 = arg2;
    return result;
}

int64_t FPC_INTERLOCKEDEXCHANGEADD64(int64_t* arg1, int64_t arg2)
{
    int64_t result = *arg1;
    *arg1 += arg2;
    return result;
}

int64_t FPC_INTERLOCKEDCOMPAREEXCHANGE64(int64_t* arg1, int64_t arg2, int64_t arg3)
{
    if (arg3 != *arg1)
        return *arg1;
    
    *arg1 = arg2;
    return arg3;
}

int64_t SYSTEM_$$_READBARRIER() __pure
{
    return;
}

int64_t SYSTEM_$$_READDEPENDENCYBARRIER() __pure
{
    return;
}

int64_t SYSTEM_$$_READWRITEBARRIER() __pure
{
    return;
}

int64_t SYSTEM_$$_WRITEBARRIER() __pure
{
    return;
}

uint64_t SYSTEM_$$_SWAPENDIAN$LONGINT$$LONGINT(int32_t arg1)
{
    return _bswap(arg1);
}

uint64_t SYSTEM_$$_SWAPENDIAN$LONGWORD$$LONGWORD(int32_t arg1)
{
    return _bswap(arg1);
}

uint64_t SYSTEM_$$_SWAPENDIAN$INT64$$INT64(uint64_t arg1)
{
    return _bswap(arg1);
}

uint64_t SYSTEM_$$_SWAPENDIAN$QWORD$$QWORD(uint64_t arg1)
{
    return _bswap(arg1);
}

uint64_t SYSTEM_$$_GET8087CW$$WORD(void arg1 @ x87control)
{
    int16_t x87status;
    int16_t temp0;
    temp0 = __fnstcw_memmem16(arg1);
    return temp0;
}

uint64_t SYSTEM_$$_GETMXCSR$$LONGWORD(int32_t arg1 @ mxcsr) __pure
{
    return arg1;
}

long double fpc_exp_real(long double arg1)
{
    long double result_1 = (round(((1.4426950407214463 + 1.675171316223821e-10) * arg1), arg1));
    long double result = result_1;
    long double result_3 = fabsl((((arg1 - (TC_$SYSTEM$_$fpc_exp_real$EXTENDED$$EXTENDED_$$_LN2HI * result_1)) - (*TC_$SYSTEM$_$fpc_exp_real$EXTENDED$$EXTENDED_$$_LN2LO * result_1)) * (1.4426950407214463 + 1.675171316223821e-10)));
    long double x87_r4 = 1;
    (x87_r4 - result_3);
    long double result_2 = result_3;
    long double x87_r6_6;
    
    if ((FCMP_UO(x87_r4, result_3)))
    {
    label_40287e:
        result = result_2;
        x87_r6_6 = __f2xm1(0);
    }
    else if (x87_r4 >= result_3)
        x87_r6_6 = __f2xm1(result_2);
    else
    {
        long double result_4 = fabsl(result);
        result_2 = result_4;
        
        if (TC_$SYSTEM$_$fpc_exp_real$EXTENDED$$EXTENDED_$$_LARGE < result_4)
            goto label_40287e;
        
        long double st0 = __f2xm1((result_2 * TC_$SYSTEM$_$fpc_exp_real$EXTENDED$$EXTENDED_$$_HALF));
        x87_r6_6 = (st0 * (st0 + TC_$SYSTEM$_$fpc_exp_real$EXTENDED$$EXTENDED_$$_TWO));
    }
    
    __fscale((x87_r6_6 + 1), result);
    return result;
}

long double fpc_frac_real(int16_t arg1 @ x87control, long double arg2)
{
    int16_t x87status;
    int16_t temp0;
    temp0 = __fnstcw_memmem16(arg1);
    int16_t x87control;
    int16_t x87status_1;
    x87control = __fldcw_memmem16((temp0 | 0xc3f));
    __fnclex();
    int16_t x87control_1;
    int16_t x87status_3;
    x87control_1 = __fldcw_memmem16(temp0);
    return (round(arg2, temp0));
}

long double fpc_int_real(int16_t arg1 @ x87control, long double arg2)
{
    int16_t x87status;
    int16_t temp0;
    temp0 = __fnstcw_memmem16(arg1);
    int16_t x87control;
    int16_t x87status_1;
    x87control = __fldcw_memmem16((temp0 | 0xc3f));
    int16_t x87control_1;
    int16_t x87status_2;
    x87control_1 = __fldcw_memmem16(temp0);
    return (round(arg2, temp0));
}

int64_t fpc_trunc_real(int16_t arg1 @ x87control, long double arg2)
{
    int16_t x87status;
    int16_t temp0;
    temp0 = __fnstcw_memmem16(arg1);
    int16_t x87control;
    int16_t x87status_1;
    x87control = __fldcw_memmem16((temp0 | 0xc3f));
    int16_t x87control_1;
    int16_t x87status_2;
    x87control_1 = __fldcw_memmem16(temp0);
    return arg2;
}

int64_t fpc_round_real(long double arg1) __pure
{
    return arg1;
}

int64_t FPC_SETJMP(int64_t* arg1, int64_t arg2 @ rbx, int64_t arg3 @ rbp, int64_t arg4 @ r12, int64_t arg5 @ r13, int64_t arg6 @ r14, int64_t arg7 @ r15)
{
    *arg1 = arg2;
    arg1[1] = arg3;
    arg1[2] = arg4;
    arg1[3] = arg5;
    arg1[4] = arg6;
    arg1[5] = arg7;
    arg1[6] = &arg_8;
    arg1[7] = __return_addr;
    return 0;
}

int64_t FPC_LONGJMP(int64_t* arg1, int32_t arg2)
{
    *arg1;
    arg1[1];
    arg1[2];
    arg1[3];
    arg1[4];
    arg1[5];
    arg1[6];
    /* jump -> *(arg1 + 0x38) */
}

int64_t SYSTEM_$$_SIGNALTOHANDLEERRORADDRFRAME$LONGINT$POINTER$POINTER(int32_t arg1, uint64_t arg2, uint64_t arg3)
{
    uint64_t var_8 = arg2;
    /* tailcall */
    return FPC_BREAK_ERROR(arg1, arg2, arg3);
}

int64_t sub_4029c6() __pure
{
    return;
}

uint64_t SYSTEM_$$_SETUPENTRYINFORMATION$TENTRYINFORMATION(void* arg1)
{
    __builtin_memcpy(&U_$SYSTEM_$$_ENTRYINFORMATION, arg1, 0xd);
    _FPC_ResStrInitTables = *(arg1 + 0x18);
    _FPC_ResourceStringTables = *(arg1 + 0x10);
    _FPC_ResLocation = *(arg1 + 0x20);
    return SYSTEM_$$_OSSETUPENTRYINFORMATION$TENTRYINFORMATION(arg1);
}

uint64_t FPC_SYS_GETERRNO()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int32_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434ca8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_ERRNO);
    
    return *rax;
}

int32_t* FPC_SYS_SETERRNO(int32_t arg1)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int32_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434ca8;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_ERRNO);
    
    *result = arg1;
    return result;
}

int64_t FPC_SYSC_TIME(int64_t arg1)
{
    return FPC_SYSCALL1(0xc9, arg1);
}

int64_t FPC_SYSC_OPEN(int64_t arg1, int32_t arg2, int32_t arg3)
{
    return FPC_SYSCALL3(2, arg1, (arg2 | 0x8000), arg3);
}

int64_t FPC_SYSC_CLOSE(int32_t arg1)
{
    return FPC_SYSCALL1(3, arg1);
}

int64_t FPC_SYSC_LSEEK(int32_t arg1, int64_t arg2, int32_t arg3)
{
    return FPC_SYSCALL3(8, arg1, arg2, arg3);
}

int64_t FPC_SYSC_READ(int32_t arg1, int64_t arg2, int64_t arg3)
{
    return FPC_SYSCALL3(0, arg1, arg2, arg3);
}

int64_t FPC_SYSC_WRITE(int32_t arg1, int64_t arg2, int64_t arg3)
{
    return FPC_SYSCALL3(1, arg1, arg2, arg3);
}

int64_t FPC_SYSC_UNLINK(int64_t arg1)
{
    return FPC_SYSCALL1(0x57, arg1);
}

int64_t FPC_SYSC_RENAME(int64_t arg1, int64_t arg2)
{
    return FPC_SYSCALL2(0x52, arg1, arg2);
}

int64_t FPC_SYSC_STAT(int64_t arg1, int64_t arg2)
{
    return FPC_SYSCALL2(4, arg1, arg2);
}

int64_t FPC_SYSC_CHDIR(int64_t arg1)
{
    return FPC_SYSCALL1(0x50, arg1);
}

int64_t FPC_SYSC_MKDIR(int64_t arg1, int32_t arg2)
{
    return FPC_SYSCALL2(0x53, arg1, arg2);
}

int64_t FPC_SYSC_RMDIR(int64_t arg1)
{
    return FPC_SYSCALL1(0x54, arg1);
}

int32_t* FPC_SYSC_OPENDIR(int64_t arg1)
{
    void var_a8;
    int32_t var_90;
    
    if (FPC_SYSC_STAT(arg1, &var_a8) >= 0)
    {
        if ((var_90 & 0xf000) == 0x4000)
        {
            int32_t rax_4 = FPC_SYSC_OPEN(arg1, 0, 0x1b6);
            
            if (rax_4 >= 0)
            {
                int32_t* result = FPC_GETMEM();
                
                if (result != 0)
                {
                    int64_t rax_5 = FPC_GETMEM();
                    *(result + 0x10) = rax_5;
                    
                    if (rax_5 != 0)
                    {
                        *result = rax_4;
                        result[1] = 0;
                        result[2] = 0;
                        result[6] = 0;
                        result[7] = 0x1000;
                        return result;
                    }
                }
            }
        }
        else
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            int32_t* rax_3;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                rax_3 = &data_434ca8;
            else
                rax_3 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_ERRNO);
            
            *rax_3 = 0x14;
        }
    }
    return nullptr;
}

uint64_t FPC_SYSC_CLOSEDIR(int32_t* arg1)
{
    int32_t rax_1;
    int32_t* rax_2;
    
    do
    {
        rax_1 = FPC_SYSC_CLOSE(*arg1);
        
        if (rax_1 == 0)
            break;
        
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_2 = &data_434ca8;
        else
            rax_2 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_ERRNO);
    } while (*rax_2 == 4);
    *(arg1 + 0x10);
    FPC_FREEMEM();
    FPC_FREEMEM();
    return rax_1;
}

int64_t* FPC_SYSC_READDIR(int32_t* arg1)
{
    int64_t* result;
    
    do
    {
        if (arg1[6] >= arg1[2])
        {
            int32_t rax_3 = FPC_SYSCALL3(0xd9, *arg1, *(arg1 + 0x10), arg1[7]);
            
            if (rax_3 <= 0)
                return nullptr;
            
            arg1[2] = rax_3;
            arg1[6] = 0;
        }
        
        result = (arg1[6] + *(arg1 + 0x10));
        arg1[6] += result[2];
        arg1[1] += result[2];
    } while (*result == 0);
    
    return result;
}

int64_t FPC_SYSC_EXIT(int32_t arg1)
{
    return FPC_SYSCALL1(0xe7, arg1);
}

int64_t FPC_SYSC_SIGACTION(int32_t arg1, void* arg2, int64_t arg3)
{
    if ((arg2 != 0 && (*(arg2 + 8) & 0xc000000) == 0))
    {
        *(arg2 + 8) |= 0x4000000;
        *(arg2 + 0x10) = SYSTEM_$$_LINUX_RESTORE;
    }
    
    return FPC_SYSCALL4(0xd, arg1, arg2, arg3, 8);
}

int64_t FPC_SYSC_FTRUNCATE(int32_t arg1, int64_t arg2)
{
    return FPC_SYSCALL2(0x4d, arg1, arg2);
}

int64_t FPC_SYSC_FSTAT(int32_t arg1, int64_t arg2)
{
    return FPC_SYSCALL2(5, arg1, arg2);
}

int64_t FPC_SYSC_FORK()
{
    return FPC_SYSCALL0(0x39);
}

int64_t FPC_SYSC_WAITPID(int32_t arg1, int64_t arg2, int32_t arg3)
{
    return FPC_SYSCALL4(0x3d, arg1, arg2, arg3, 0);
}

int64_t FPC_SYSC_ACCESS(int64_t arg1, int32_t arg2)
{
    return FPC_SYSCALL2(0x15, arg1, arg2);
}

int64_t FPC_SYSC_DUP(int32_t arg1)
{
    return FPC_SYSCALL1(0x20, arg1);
}

int64_t FPC_SYSC_DUP2(int32_t arg1, int32_t arg2)
{
    return FPC_SYSCALL2(0x21, arg1, arg2);
}

int64_t FPC_SYSC_MMAP(int64_t arg1, int64_t arg2, int32_t arg3, int32_t arg4, int32_t arg5, int64_t arg6)
{
    return FPC_SYSCALL6(9, arg1, arg2, arg3, arg4, arg5, arg6);
}

int64_t FPC_SYSC_MUNMAP(int64_t arg1, int64_t arg2)
{
    return FPC_SYSCALL2(0xb, arg1, arg2);
}

int64_t FPC_SYSC_MPROTECT(int64_t arg1, int64_t arg2, int32_t arg3)
{
    return FPC_SYSCALL3(0xa, arg1, arg2, arg3);
}

int64_t FPC_SYSC_IOCTL(int32_t arg1, int64_t arg2, int64_t arg3)
{
    return FPC_SYSCALL3(0x10, arg1, arg2, arg3);
}

int64_t FPC_SYSC_GETPID()
{
    return FPC_SYSCALL0(0x27);
}

int64_t FPC_SYSC_READLINK(int64_t arg1, int64_t arg2, int64_t arg3)
{
    return FPC_SYSCALL3(0x59, arg1, arg2, arg3);
}

int64_t FPC_SYSC_SIGPROCMASK(int32_t arg1, int64_t arg2, int64_t arg3)
{
    return FPC_SYSCALL4(0xe, arg1, arg2, arg3, 8);
}

int64_t FPC_SYSC_NANOSLEEP(int64_t arg1, int64_t arg2)
{
    return FPC_SYSCALL2(0x23, arg1, arg2);
}

int64_t FPC_SYSC_GETCWD(int64_t arg1, int64_t arg2)
{
    return FPC_SYSCALL2(0x4f, arg1, arg2);
}

int64_t FPC_SYSC_GETTIMEOFDAY(int64_t arg1, int64_t arg2)
{
    return FPC_SYSCALL2(0x60, arg1, arg2);
}

int64_t FPC_SYSC_GETRLIMIT(int32_t arg1, int64_t arg2)
{
    return FPC_SYSCALL2(0x61, arg1, arg2);
}

int64_t FPC_SYSC_SETRLIMIT(int32_t arg1, int64_t arg2)
{
    return FPC_SYSCALL2(0xa0, arg1, arg2);
}

void* FPC_SYSC_FPGETENVPCHAR(char* arg1)
{
    if ((arg1 == 0 || U_$SYSTEM_$$_ENVP == 0))
        return 0;
    
    char* rdx = arg1;
    
    while (true)
    {
        char rcx = *rdx;
        
        if (rcx == 0)
            break;
        
        if (rcx == 0x3d)
            break;
        
        rdx = &rdx[1];
    }
    
    uint64_t U_$SYSTEM_$$_ENVP_1 = U_$SYSTEM_$$_ENVP;
    
    while (*U_$SYSTEM_$$_ENVP_1 != 0)
    {
        char* r9_1 = *U_$SYSTEM_$$_ENVP_1;
        char* rdx_1 = arg1;
        int32_t i;
        
        for (i = (rdx - arg1); i != 0; i -= 1)
        {
            if (*r9_1 == 0)
                break;
            
            if (*r9_1 != *rdx_1)
            {
                r9_1 = &r9_1[1];
                break;
            }
            
            r9_1 = &r9_1[1];
            rdx_1 = &rdx_1[1];
        }
        
        if ((i == 0 && *r9_1 == 0x3d))
            return &r9_1[1];
        
        U_$SYSTEM_$$_ENVP_1 += 8;
    }
    
    return 0;
}

int64_t SYSTEM_$$_FPS_ISDIR$LONGINT$$BOOLEAN(int32_t arg1) __pure
{
    int64_t result;
    result = (arg1 & 0xf000) == 0x4000;
    return result;
}

int64_t SYSTEM_$$_FPS_ISCHR$LONGINT$$BOOLEAN(int32_t arg1) __pure
{
    int64_t result;
    result = (arg1 & 0xf000) == 0x2000;
    return result;
}

int64_t SYSTEM_$$_FPS_ISBLK$LONGINT$$BOOLEAN(int32_t arg1) __pure
{
    int64_t result;
    result = (arg1 & 0xf000) == 0x6000;
    return result;
}

int64_t SYSTEM_$$_FPS_ISREG$LONGINT$$BOOLEAN(int32_t arg1) __pure
{
    int64_t result;
    result = (arg1 & 0xf000) == 0x8000;
    return result;
}

int64_t SYSTEM_$$_FPS_ISFIFO$LONGINT$$BOOLEAN(int32_t arg1) __pure
{
    int64_t result;
    result = (arg1 & 0xf000) == 0x1000;
    return result;
}

int64_t SYSTEM_$$_FPS_ISLNK$LONGINT$$BOOLEAN(int32_t arg1) __pure
{
    int64_t result;
    result = (arg1 & 0xf000) == 0xa000;
    return result;
}

int64_t SYSTEM_$$_FPS_ISSOCK$LONGINT$$BOOLEAN(int32_t arg1) __pure
{
    int64_t result;
    result = (arg1 & 0xf000) == 0xc000;
    return result;
}

int64_t SYSTEM_$$_WIFEXITED$LONGINT$$BOOLEAN(int32_t arg1) __pure
{
    int64_t result;
    result = (arg1 & 0x7f) == 0;
    return result;
}

uint64_t SYSTEM_$$_WEXITSTATUS$LONGINT$$LONGINT(int32_t arg1) __pure
{
    return ((arg1 & 0xff00) >> 8);
}

uint64_t SYSTEM_$$_WSTOPSIG$LONGINT$$LONGINT(int32_t arg1) __pure
{
    return ((arg1 & 0xff00) >> 8);
}

uint32_t SYSTEM_$$_WIFSIGNALED$LONGINT$$BOOLEAN(int32_t arg1) __pure
{
    uint32_t result;
    
    if ((arg1 == 0x7f || (arg1 & 0x7f) == 0))
    {
        result = 0;
        return result;
    }
    
    result = 1;
    return result;
}

uint64_t SYSTEM_$$_WTERMSIG$LONGINT$$LONGINT(int32_t arg1) __pure
{
    return (arg1 & 0x7f);
}

uint64_t SYSTEM_$$_POSIXTORUNERROR$LONGINT$$WORD(int32_t arg1)
{
    if ((arg1 - 2) <= 0x25)
        /* jump -> (*(&.Ld1 + ((arg1 - 2) << 2)) + &.Ld1) */
    
    int64_t rbx;
    rbx = arg1;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    uint64_t rdx;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rdx = &data_434a78;
    else
        rdx = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    FPC_THREADVAR_RELOCATE_1 = rbx;
    *rdx = FPC_THREADVAR_RELOCATE_1;
    return (FPC_THREADVAR_RELOCATE_1 & 0xffff);
}

uint64_t SYSTEM_$$_ERRNO2INOUTRES$$WORD()
{
    int64_t rbx;
    rbx = SYSTEM_$$_POSIXTORUNERROR$LONGINT$$WORD(FPC_SYS_GETERRNO());
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    uint64_t rdx;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rdx = &data_434a78;
    else
        rdx = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    FPC_THREADVAR_RELOCATE_1 = rbx;
    *rdx = FPC_THREADVAR_RELOCATE_1;
    return (FPC_THREADVAR_RELOCATE_1 & 0xffff);
}

int64_t SYSTEM_$$_DO_ISDEVICE$LONGINT$$BOOLEAN(int32_t arg1)
{
    void var_108;
    int32_t result;
    result = FPC_SYSC_IOCTL(arg1, 0x5401, &var_108) != 0xffffffff;
    return result;
}

void* SYSTEM_$$_GET_CALLER_ADDR$POINTER$POINTER$$POINTER(void* arg1)
{
    if (arg1 == 0)
        return arg1;
    
    return *(arg1 + 8);
}

int64_t* SYSTEM_$$_GET_CALLER_FRAME$POINTER$POINTER$$POINTER(int64_t* arg1)
{
    if (arg1 == 0)
        return arg1;
    
    return *arg1;
}

int64_t SYSTEM_$$_FPC_CPUINIT()
{
    if (operatingsystem_islibrary != 0)
    {
        int16_t x87control;
        TC_$SYSTEM_$$_DEFAULT8087CW = SYSTEM_$$_GET8087CW$$WORD(x87control);
        int32_t mxcsr;
        TC_$SYSTEM_$$_DEFAULTMXCSR = SYSTEM_$$_GETMXCSR$$LONGWORD(mxcsr);
    }
    
    return SYSTEM_$$_SYSRESETFPU();
}

int64_t SYSTEM_$$_SYSINITFPU() __pure
{
    return;
}

uint32_t SYSTEM_$$_SYSRESETFPU()
{
    uint32_t TC_$SYSTEM_$$_DEFAULTMXCSR_1 = TC_$SYSTEM_$$_DEFAULTMXCSR;
    uint32_t TC_$SYSTEM_$$_DEFAULTMXCSR_2 = TC_$SYSTEM_$$_DEFAULTMXCSR_1;
    int16_t x87control;
    int16_t x87status;
    x87control = __fldcw_memmem16(TC_$SYSTEM_$$_DEFAULT8087CW);
    return TC_$SYSTEM_$$_DEFAULTMXCSR_1;
}

uint64_t SYSTEM_$$_SWAPENDIAN$SMALLINT$$SMALLINT(int16_t arg1) __pure
{
    uint32_t rdi_1 = arg1;
    return ((rdi_1 >> 8) | (rdi_1 << 8));
}

uint64_t SYSTEM_$$_SWAPENDIAN$WORD$$WORD(int16_t arg1) __pure
{
    uint32_t rdi_1 = arg1;
    return ((rdi_1 >> 8) | (rdi_1 << 8));
}

int64_t SYSTEM_$$_FILLCHAR$formal$INT64$BOOLEAN(char* arg1, int64_t arg2, char arg3)
{
    return SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(arg1, arg2, arg3);
}

int64_t SYSTEM_$$_FILLCHAR$formal$INT64$CHAR(char* arg1, int64_t arg2, char arg3)
{
    return SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(arg1, arg2, arg3);
}

int64_t SYSTEM_$$_FILLBYTE$formal$INT64$BYTE(char* arg1, int64_t arg2, char arg3)
{
    return SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(arg1, arg2, arg3);
}

void* SYSTEM_$$_INDEXCHAR$formal$INT64$CHAR$$INT64(char (* arg1)[0x10], int64_t arg2, char arg3)
{
    return SYSTEM_$$_INDEXBYTE$formal$INT64$BYTE$$INT64(arg1, arg2, arg3);
}

uint64_t SYSTEM_$$_COMPARECHAR$formal$formal$INT64$$INT64(int64_t arg1, int64_t arg2, int64_t arg3)
{
    return SYSTEM_$$_COMPAREBYTE$formal$formal$INT64$$INT64(arg1, arg2, arg3);
}

int64_t fpc_zeromem(char* arg1, int64_t arg2)
{
    return SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(arg1, arg2, 0);
}

int64_t fpc_fillmem(char* arg1, int64_t arg2, char arg3)
{
    return SYSTEM_$$_FILLBYTE$formal$INT64$BYTE(arg1, arg2, arg3);
}

uint64_t SYSTEM_$$_FPC_SHORTSTR_SHORTSTR_INTERN_CHARMOVE$SHORTSTRING$BYTE$OPENSTRING$BYTE$BYTE(int64_t arg1, char arg2, int64_t arg3, int64_t arg4, char arg5, char arg6)
{
    int64_t rax = arg1;
    arg1 = arg2;
    int64_t rsi = arg3;
    arg3 = arg6;
    return FPC_MOVE(((arg1 & 0xff) + rax), (rsi + arg5), (arg3 & 0xff));
}

uint64_t SYSTEM_$$_FPC_SHORTSTR_CHARARRAY_INTERN_CHARMOVE$SHORTSTRING$array_of_CHAR$INT64(int64_t arg1, char* arg2, int64_t arg3, uint64_t arg4)
{
    return FPC_MOVE((arg1 + 1), arg2, arg4);
}

void SYSTEM_$$_FILLWORD$formal$INT64$WORD(uint64_t* arg1, uint64_t arg2, int16_t arg3)
{
    if (arg2 > 0)
    {
        if (arg2 > 0x1f)
        {
            uint32_t rax_1 = arg3;
            uint64_t rcx_4 = ((rax_1 << 0x10) | rax_1);
            uint64_t rax_7 = ((arg1 & 7) >> 1);
            uint64_t rsi = (arg2 - rax_7);
            
            for (void* rax_9 = ((rax_7 << 1) + arg1); rax_9 > arg1; arg1 += 2)
                *arg1 = arg3;
            
            for (void* rax_10 = (((rsi << 1) & 0xfffffffffffffff8) + arg1); rax_10 > arg1; arg1 = &arg1[1])
                *arg1 = ((rcx_4 << 0x20) | rcx_4);
            
            arg2 = (((rsi << 1) & 7) >> 1);
        }
        
        for (void* rax = ((arg2 << 1) + arg1); rax > arg1; arg1 += 2)
            *arg1 = arg3;
    }
}

void SYSTEM_$$_FILLDWORD$formal$INT64$LONGWORD(uint64_t* arg1, uint64_t arg2, int32_t arg3)
{
    if (arg2 > 0)
    {
        if (arg2 > 0x1f)
        {
            uint64_t rcx_1 = arg3;
            uint64_t rax_6 = ((arg1 & 7) >> 2);
            uint64_t rsi = (arg2 - rax_6);
            
            for (void* rax_8 = ((rax_6 << 2) + arg1); rax_8 > arg1; arg1 += 4)
                *arg1 = arg3;
            
            for (void* rax_9 = (((rsi << 2) & 0xfffffffffffffff8) + arg1); rax_9 > arg1; arg1 = &arg1[1])
                *arg1 = ((rcx_1 << 0x20) | rcx_1);
            
            arg2 = (((rsi << 2) & 7) >> 2);
        }
        
        for (void* rax = ((arg2 << 2) + arg1); rax > arg1; arg1 += 4)
            *arg1 = arg3;
    }
}

void SYSTEM_$$_FILLQWORD$formal$INT64$QWORD(int64_t* arg1, int64_t arg2, int64_t arg3)
{
    if (arg2 > 0)
    {
        for (; &arg1[arg2] > arg1; arg1 = &arg1[1])
            *arg1 = arg3;
    }
}

int64_t SYSTEM_$$_INDEXDWORD$formal$INT64$LONGWORD$$INT64(int32_t* arg1, int64_t arg2, int32_t arg3)
{
    int32_t* rcx = arg1;
    void* r8;
    
    if (((arg2 < 0 || arg2 > 0x3fffffffffffffff) || &rcx[arg2] < rcx))
        r8 = -fffffffffffffffb;
    else
        r8 = &rcx[arg2];
    
    while (true)
    {
        if (r8 <= rcx)
            return -1;
        
        if (arg3 == *rcx)
            break;
        
        rcx = &rcx[1];
    }
    
    void* r9_1 = (rcx - arg1);
    return ((r9_1 + ((r9_1 >> 0x3f) & 3)) >> 2);
}

int64_t SYSTEM_$$_INDEXQWORD$formal$INT64$QWORD$$INT64(int64_t* arg1, int64_t arg2, int64_t arg3)
{
    int64_t* rcx = arg1;
    void* r8;
    
    if (((arg2 < 0 || arg2 > 0x1fffffffffffffff) || &rcx[arg2] < rcx))
        r8 = -fffffffffffffff7;
    else
        r8 = &rcx[arg2];
    
    while (true)
    {
        if (r8 <= rcx)
            return -1;
        
        if (arg3 == *rcx)
            break;
        
        rcx = &rcx[1];
    }
    
    void* r9_1 = (rcx - arg1);
    return ((r9_1 + ((r9_1 >> 0x3f) & 7)) >> 3);
}

int64_t SYSTEM_$$_COMPAREWORD$formal$formal$INT64$$INT64(int16_t* arg1, int16_t* arg2, uint64_t arg3)
{
    if (arg3 > 0x1f)
    {
        uint64_t rcx_3 = (((8 - (arg2 & 7)) & 7) >> 1);
        uint64_t rdx = (arg3 - rcx_3);
        
        for (; &arg1[rcx_3] > arg1; arg1 = &arg1[1])
        {
            uint64_t r9_2 = (*arg1 - *arg2);
            
            if (r9_2 != 0)
            {
                if (r9_2 >= 0)
                    return 1;
                
                return -1;
            }
            
            arg2 = &arg2[1];
        }
        
        void* rcx_6 = (((rdx << 1) & 0xfffffffffffffff8) + arg1);
        arg3 = (((rdx << 1) & 7) >> 1);
        
        for (; rcx_6 > arg1; arg1 = &arg1[4])
        {
            if ((*arg1 - *arg2) != 0)
            {
                arg3 = 4;
                break;
            }
            
            arg2 = &arg2[4];
        }
    }
    
    void* rcx_7;
    
    if (&arg1[arg3] < arg1)
        rcx_7 = -fffffffffffffffd;
    else
        rcx_7 = &arg1[arg3];
    
    uint64_t rdx_3;
    
    while (true)
    {
        if (rcx_7 <= arg1)
            return 0;
        
        rdx_3 = (*arg1 - *arg2);
        
        if (rdx_3 != 0)
            break;
        
        arg2 = &arg2[1];
        arg1 = &arg1[1];
    }
    
    if (rdx_3 >= 0)
        return 1;
    
    return -1;
}

int64_t SYSTEM_$$_COMPAREDWORD$formal$formal$INT64$$INT64(int32_t* arg1, int32_t* arg2, uint64_t arg3)
{
    if (arg3 > 0x15)
    {
        uint64_t rcx_3 = (((8 - (arg2 & 7)) & 7) >> 2);
        uint64_t rdx = (arg3 - rcx_3);
        
        while (true)
        {
            if (&arg1[rcx_3] <= arg1)
            {
                void* rcx_6 = (((rdx << 2) & 0xfffffffffffffff8) + arg1);
                arg3 = (((rdx << 2) & 7) >> 2);
                
                for (; rcx_6 > arg1; arg1 = &arg1[2])
                {
                    if (*arg1 != *arg2)
                    {
                        arg3 = 2;
                        break;
                    }
                    
                    arg2 = &arg2[2];
                }
                
                break;
            }
            
            if (*arg1 != *arg2)
            {
                if (*arg1 <= *arg2)
                    return -1;
                
                return 1;
            }
            
            arg2 = &arg2[1];
            arg1 = &arg1[1];
        }
    }
    
    void* rcx_7;
    
    if ((arg3 > 0x3fffffffffffffff || &arg1[arg3] < arg1))
        rcx_7 = -fffffffffffffffb;
    else
        rcx_7 = &arg1[arg3];
    
    while (true)
    {
        if (rcx_7 <= arg1)
            return 0;
        
        if (*arg1 != *arg2)
            break;
        
        arg2 = &arg2[1];
        arg1 = &arg1[1];
    }
    
    if (*arg1 <= *arg2)
        return -1;
    
    return 1;
}

void SYSTEM_$$_MOVECHAR0$formal$formal$INT64(char (* arg1)[0x10], char* arg2, uint64_t arg3)
{
    if (arg3 != 0)
    {
        void* rax_1 = SYSTEM_$$_INDEXBYTE$formal$INT64$BYTE$$INT64(arg1, arg3, 0);
        
        if (rax_1 == -1)
            FPC_MOVE(arg1, arg2, arg3);
        else
            FPC_MOVE(arg1, arg2, rax_1);
    }
}

void* SYSTEM_$$_INDEXCHAR0$formal$INT64$CHAR$$INT64(char* arg1, int64_t arg2, char arg3)
{
    char* rcx = arg1;
    void* r8;
    
    if (arg2 >= 0)
        r8 = &rcx[arg2];
    else
        r8 = -fffffffffffffffe;
    
    while (true)
    {
        if ((r8 <= rcx || *rcx == 0))
            return -1;
        
        if (arg3 == *rcx)
            break;
        
        rcx = &rcx[1];
        continue;
    }
    
    return (rcx - arg1);
}

int64_t SYSTEM_$$_COMPARECHAR0$formal$formal$INT64$$INT64(char* arg1, char* arg2, void* arg3)
{
    void* rdx = (arg3 + arg1);
    
    while (true)
    {
        if (rdx <= arg1)
            return 0;
        
        uint64_t r8_2 = (*arg1 - *arg2);
        
        if (r8_2 < 0)
            return -1;
        
        if (r8_2 > 0)
            break;
        
        if ((*arg1 == 0 || *arg2 == 0))
            return 0;
        
        arg2 = &arg2[1];
        arg1 = &arg1[1];
    }
    
    return 1;
}

char* FPC_HELP_CONSTRUCTOR(char* arg1, int64_t* arg2, int32_t arg3)
{
    char* result = arg1;
    int64_t* r14 = *arg2;
    
    if (r14 == 0)
        return result;
    
    if ((result == 0 && *r14 > 0))
    {
        SYSTEM_$$_GETMEM$POINTER$QWORD(&result, *r14);
        *arg2 = -1;
    }
    
    if (result != 0)
    {
        SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(result, *r14, 0);
        *(arg3 + result) = r14;
    }
    
    return result;
}

void FPC_HELP_DESTRUCTOR(int64_t arg1, int64_t arg2, int32_t arg3)
{
    if ((arg1 != 0 && (arg2 == -1 && *(arg3 + arg1) != 0)))
    {
        int64_t* rax_4 = *(arg3 + arg1);
        int64_t rdx = *rax_4;
        int64_t __saved_rbp;
        
        if ((rdx == 0 || (rdx + rax_4[1]) != 0))
            SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xd2, &data_403bc1, &__saved_rbp);
        *(arg3 + arg1) = 0;
        SYSTEM_$$_FREEMEM$POINTER$$QWORD();
    }
}

void FPC_HELP_FAIL(int64_t arg1, int64_t* arg2, int32_t arg3)
{
    if ((arg1 != 0 && *arg2 != 0))
    {
        if (*arg2 != -1)
            *(arg1 + arg3) = 0;
        else if ((arg1 == 0 || *(arg3 + arg1) == 0))
            FPC_HANDLEERROR(0xd2);
        else
        {
            *(arg3 + arg1) = 0;
            SYSTEM_$$_FREEMEM$POINTER$$QWORD();
            *arg2 = 0;
        }
    }
}

int64_t FPC_CHECK_OBJECT(int64_t* arg1)
{
    if (arg1 != 0)
    {
        int64_t rdx_1 = *arg1;
        
        if (rdx_1 != 0)
        {
            int64_t result = (rdx_1 + arg1[1]);
            
            if (result == 0)
                return result;
        }
    }
    
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xd2, &data_403ca6, &__saved_rbp);
}

int64_t** FPC_CHECK_OBJECT_EXT(int64_t* arg1, int64_t arg2)
{
    int64_t* rbx = arg1;
    int64_t __saved_rbp;
    int64_t** result;
    
    if (rbx == 0)
        result = SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xd2, &data_403cf9, &__saved_rbp);
    else
    {
        void* rdx_1 = *rbx;
        
        if (rdx_1 == 0)
            result = SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xd2, &data_403cf9, &__saved_rbp);
        else
        {
            result = (rdx_1 + rbx[1]);
            
            if (result != 0)
                result = SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xd2, &data_403cf9, &__saved_rbp);
        }
    }
    
    while (true)
    {
        if (rbx == 0)
            return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xdb, &data_403d31, &__saved_rbp);
        
        if (arg2 == rbx)
            break;
        
        if (rbx[2] == 0)
            rbx = nullptr;
        else
        {
            result = rbx[2];
            rbx = *result;
        }
    }
    
    return result;
}

uint64_t FPC_SHORTSTR_TO_SHORTSTR(char* arg1, int64_t arg2, char* arg3)
{
    int64_t r12;
    r12 = *arg3;
    
    if (r12 > arg2)
        r12 = arg2;
    
    uint64_t result = FPC_MOVE(arg3, arg1, (r12 + 1));
    *arg1 = r12;
    return result;
}

int64_t FPC_SHORTSTR_ASSIGN(uint32_t arg1, char* arg2, char* arg3)
{
    uint32_t result_1 = arg1;
    int64_t r13;
    r13 = *arg2;
    
    if (r13 < result_1)
        result_1 = r13;
    
    FPC_MOVE(arg2, arg3, (result_1 + 1));
    int64_t result = result_1;
    
    if ((r13 & 0xff) > result)
        *arg3 = result_1;
    
    return result;
}

int64_t fpc_shortstr_concat(char* arg1, int64_t arg2, char* arg3, char* arg4)
{
    uint32_t r12 = *arg3;
    uint32_t r13 = *arg4;
    
    if ((r12 + r13) > arg2)
    {
        if (r12 > arg2)
            r12 = arg2;
        
        r13 = (arg2 - r12);
    }
    
    if (arg1 == arg3)
    {
        char* rdx_1;
        rdx_1 = r13;
        FPC_MOVE(&arg4[1], &arg1[(r12 + 1)], (rdx_1 & 0xff));
    }
    else
    {
        char* rdx_3;
        
        if (arg1 != arg4)
        {
            rdx_3 = r12;
            FPC_MOVE(&arg3[1], &arg1[1], (rdx_3 & 0xff));
            FPC_MOVE(&arg4[1], &arg1[(r12 + 1)], r13);
        }
        else
        {
            rdx_3 = r13;
            FPC_MOVE(&arg1[1], &arg1[(r12 + 1)], (rdx_3 & 0xff));
            FPC_MOVE(&arg3[1], &arg1[1], r12);
        }
    }
    
    char result = (r12 + r13);
    *arg1 = result;
    return result;
}

char* fpc_shortstr_concat_multi(char* arg1, int64_t arg2, uint64_t arg3, int64_t arg4)
{
    int64_t r12;
    int64_t var_150 = r12;
    char* result;
    
    if (arg4 != 0)
    {
        int64_t rdx = 0;
        
        if (arg1 == *arg3)
            rdx = 1;
        
        char var_120_1 = 0;
        int32_t i = arg4;
        
        if (i >= rdx)
        {
            uint64_t var_130_1 = (rdx - 1);
            
            do
            {
                var_130_1 += 1;
                
                if (arg1 == *(arg3 + (var_130_1 << 3)))
                {
                    var_120_1 = 1;
                    break;
                }
            } while (i > var_130_1);
        }
        
        uint64_t rax;
        rax = var_120_1;
        char var_108;
        char* rsi_2;
        
        if (rax == 0)
        {
            if (rdx == 0)
                *arg1 = 0;
            
            rsi_2 = arg1;
        }
        else
        {
            rdx = 0;
            var_108 = 0;
            rsi_2 = &var_108;
        }
        
        int32_t r14_1 = *rsi_2;
        int32_t i_1 = arg4;
        
        if (i_1 >= rdx)
        {
            uint64_t var_130_2 = (rdx - 1);
            
            do
            {
                var_130_2 += 1;
                char* rbx_1 = *(arg3 + (var_130_2 << 3));
                
                if (rbx_1 != 0)
                {
                    r12 = *rbx_1;
                    
                    if ((r14_1 + r12) > arg2)
                        r12 = (arg2 - r14_1);
                    
                    FPC_MOVE(&rbx_1[1], &rsi_2[(r14_1 + 1)], r12);
                    r14_1 += r12;
                }
            } while (i_1 > var_130_2);
        }
        
        *rsi_2 = r14_1;
        result = var_120_1;
        
        if (result != 0)
            return FPC_SHORTSTR_TO_SHORTSTR(arg1, arg2, &var_108);
    }
    else
    {
        result = arg1;
        *result = 0;
    }
    
    return result;
}

int64_t FPC_SHORTSTR_APPEND_SHORTSTR(char* arg1, int64_t arg2, char* arg3)
{
    uint64_t r13 = *arg1;
    uint64_t r12 = *arg3;
    
    if ((r12 + r13) > arg2)
        r12 = (arg2 - r13);
    
    FPC_MOVE(&arg3[1], &arg1[(r13 + 1)], r12);
    char result = (r12 + r13);
    *arg1 = result;
    return result;
}

int64_t FPC_SHORTSTR_COMPARE(char* arg1, char* arg2)
{
    char rcx = *arg1;
    char r8 = *arg2;
    char rdx;
    
    if (r8 <= rcx)
        rdx = r8;
    else
        rdx = rcx;
    
    if (rdx >= 1)
    {
        char r10 = 0;
        
        do
        {
            r10 += 1;
            uint32_t rbx_2 = (arg1[r10] - arg2[r10]);
            
            if (rbx_2 > 0)
                return 1;
            
            if (rbx_2 < 0)
                return 0xffffffff;
        } while (rdx > r10);
    }
    
    if (r8 < rcx)
        return 1;
    
    if (r8 <= rcx)
        return 0;
    
    return 0xffffffff;
}

uint64_t FPC_SHORTSTR_COMPARE_EQUAL(char* arg1, char* arg2)
{
    uint32_t rbx = *arg1;
    uint32_t rax = *arg2;
    uint32_t rbx_1 = (rbx - rax);
    
    if (rbx == rax)
        rbx_1 = SYSTEM_$$_COMPAREBYTE$formal$formal$INT64$$INT64(&arg1[1], &arg2[1], *arg1);
    
    return rbx_1;
}

uint64_t FPC_PCHAR_TO_SHORTSTR(char* arg1, int64_t arg2, char (* arg3)[0x10])
{
    int32_t rbx;
    
    if (arg3 != 0)
        rbx = FPC_PCHAR_LENGTH(arg3);
    else
        rbx = 0;
    
    if (rbx > arg2)
        rbx = arg2;
    
    void var_127;
    
    if (rbx > 0)
        FPC_MOVE(arg3, &var_127, rbx);
    char var_128 = rbx;
    return FPC_SHORTSTR_TO_SHORTSTR(arg1, arg2, &var_128);
}

uint64_t SYSTEM_$$_STRPAS$PCHAR$$SHORTSTRING(char* arg1, char (* arg2)[0x10])
{
    return FPC_PCHAR_TO_SHORTSTR(arg1, 0xff, arg2);
}

void* SYSTEM_$$_UTF8CODEPOINTLEN$PCHAR$INT64$BOOLEAN$$INT64(char* arg1, int64_t arg2, char arg3)
{
    if (arg2 <= 0)
        return 0;
    
    void* result = 1;
    uint64_t rcx;
    
    if (*arg1 > 0x7f)
    {
        rcx = *arg1;
        rcx = !(rcx);
        uint64_t rcx_1 = (rcx & 0xff);
        uint64_t rflags_1;
        char rcx_2;
        rcx_2 = _bit_scan_reverse(rcx_1);
        
        if (rcx_1 == 0)
            rcx_2 = -1;
        
        if ((rcx_2 <= 1 || rcx_2 >= 6))
            return -1;
        
        int64_t r8_1 = (6 - rcx_2);
        
        while (arg2 > result)
        {
            if (r8_1 <= 0)
                break;
            
            rcx = *(arg1 + result);
            rcx &= 0xc0;
            
            if (rcx != 0x80)
                break;
            
            result += 1;
            r8_1 -= 1;
        }
        
        if (r8_1 != 0)
        {
            if (arg2 > result)
                return -(result);
            
            return 0;
        }
    }
    
    if (arg3 != 0)
    {
        char* rdx;
        void* result_1;
        
        do
        {
            result_1 = result;
            
            if ((result + 1) < arg2)
            {
                rcx = *(arg1 + result);
                rcx &= 0xcc;
                
                if (rcx == 0xcc)
                    rdx = *((arg1 + result) + 1);
                
                if (((rcx == 0xcc && rdx >= 0x80) && rdx <= 0xaf))
                    result += 2;
                else if (((result + 2) < arg2 && *(arg1 + result) >= 0xe1))
                {
                    char r10 = *(arg1 + result);
                    rcx = r10 == 0xe1;
                    char r9;
                    
                    if ((r10 == 0xe1 && *((arg1 + result) + 1) == 0xaa))
                        r9 = *((arg1 + result) + 2);
                    
                    if ((((r10 == 0xe1 && *((arg1 + result) + 1) == 0xaa) && r9 >= 0xb0) && r9 <= 0xbf))
                        result += 3;
                    else if ((rcx == 0 || *((arg1 + result) + 1) != 0xb7))
                    {
                    label_404384:
                        
                        if ((r10 == 0xe2 && *((arg1 + result) + 1) == 0x83))
                            rcx = *((arg1 + result) + 2);
                        
                        if ((((r10 == 0xe2 && *((arg1 + result) + 1) == 0x83) && rcx >= 0x90) && rcx <= 0xbf))
                            result += 3;
                        else if ((r10 == 0xef && *((arg1 + result) + 1) == 0xb8))
                        {
                            rdx = *((arg1 + result) + 2);
                            
                            if ((rdx >= 0xa0 && rdx <= 0xaf))
                                result += 3;
                        }
                    }
                    else
                    {
                        rcx = *((arg1 + result) + 2);
                        
                        if ((rcx < 0x80 || rcx > 0xbf))
                            goto label_404384;
                        
                        result += 3;
                    }
                }
            }
        } while (result != result_1);
        
        if (arg2 > result)
        {
            rcx = *(arg1 + result);
            rdx = rcx;
            rdx &= 0xcc;
            
            if ((rdx == 0xcc && (result + 1) >= arg2))
                return nullptr;
            
            if (rcx == 0xe1)
            {
                if (arg2 <= (result + 1))
                    return nullptr;
                
                void* rdx_2;
                rdx_2 = *(arg1 + (result + 1));
                
                if (rdx_2 == 0xaa)
                {
                    if (((result + 2) >= arg2 || (rcx == 0xe2 && (arg2 <= (result + 1) || (*(arg1 + (result + 1)) == 0x83 && (result + 2) >= arg2)))))
                        return nullptr;
                }
                else if (((rdx_2 == 0xb7 && (result + 2) >= arg2) || (rcx == 0xe2 && (arg2 <= (result + 1) || (*(arg1 + (result + 1)) == 0x83 && (result + 2) >= arg2)))))
                    return nullptr;
            }
            else if ((rcx == 0xe2 && (arg2 <= (result + 1) || (*(arg1 + (result + 1)) == 0x83 && (result + 2) >= arg2))))
                return nullptr;
            
            if (rcx == 0xef)
            {
                if (arg2 <= (result + 1))
                    return nullptr;
                
                if ((*(arg1 + (result + 1)) == 0xb8 && (result + 2) >= arg2))
                    return nullptr;
            }
        }
    }
    
    return result;
}

uint64_t FPC_CHARARRAY_TO_SHORTSTR(char* arg1, int64_t arg2, char (* arg3)[0x10], int32_t arg4, char arg5)
{
    int32_t r13 = (arg4 + 1);
    
    if (r13 >= (arg2 + 1))
        r13 = arg2;
    else if (r13 < 0)
        r13 = 0;
    
    int64_t r14;
    
    if (arg5 == 0)
        r14 = r13;
    else
    {
        int32_t rax_1 = SYSTEM_$$_INDEXBYTE$formal$INT64$BYTE$$INT64(arg3, r13, 0);
        
        if (rax_1 >= 0)
            r14 = rax_1;
        else
            r14 = r13;
    }
    
    uint64_t result = FPC_MOVE(arg3, &arg1[1], r14);
    *arg1 = r14;
    return result;
}

int64_t fpc_shortstr_to_chararray(char* arg1, int64_t arg2, char* arg3)
{
    uint32_t r13 = *arg3;
    
    if (r13 > (arg2 + 1))
        r13 = (arg2 + 1);
    
    if (r13 > 0)
        FPC_MOVE(&arg3[1], arg1, r13);
    
    return SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(&arg1[r13], ((arg2 + 1) - r13), 0);
}

void* FPC_PCHAR_LENGTH(char (* arg1)[0x10])
{
    if (arg1 == 0)
        return nullptr;
    
    return SYSTEM_$$_INDEXBYTE$formal$INT64$BYTE$$INT64(arg1, 0x7fffffffffffffff, 0);
}

int64_t FPC_PWIDECHAR_LENGTH(int64_t arg1)
{
    int64_t result = 0;
    
    if (arg1 != 0)
    {
        while (*(arg1 + (result << 1)) != 0)
            result += 1;
    }
    
    return result;
}

uint64_t SYSTEM_$$_ODD$LONGINT$$BOOLEAN(int32_t arg1) __pure
{
    return (arg1 & 1);
}

uint64_t SYSTEM_$$_ODD$LONGWORD$$BOOLEAN(int32_t arg1) __pure
{
    return (arg1 & 1);
}

uint64_t SYSTEM_$$_ODD$INT64$$BOOLEAN(int32_t arg1) __pure
{
    return (arg1 & 1);
}

uint64_t SYSTEM_$$_ODD$QWORD$$BOOLEAN(int32_t arg1) __pure
{
    return (arg1 & 1);
}

uint64_t SYSTEM_$$_SQR$LONGINT$$LONGINT(int32_t arg1) __pure
{
    return (arg1 * arg1);
}

int64_t SYSTEM_$$_SQR$INT64$$INT64(int64_t arg1) __pure
{
    return (arg1 * arg1);
}

int64_t SYSTEM_$$_SQR$QWORD$$QWORD(int64_t arg1) __pure
{
    return (arg1 * arg1);
}

int64_t SYSTEM_$$_ALIGN$QWORD$QWORD$$QWORD(int64_t arg1, int64_t arg2) __pure
{
    int64_t rcx = ((arg2 - 1) + arg1);
    return (rcx - (COMBINE(0, rcx) % arg2));
}

int64_t SYSTEM_$$_ALIGN$POINTER$QWORD$$POINTER(int64_t arg1, int64_t arg2) __pure
{
    int64_t rcx = ((arg2 - 1) + arg1);
    return (rcx - (COMBINE(0, rcx) % arg2));
}

void* SYSTEM_$$_INT_STR$LONGINT$OPENSTRING(int32_t arg1, char* arg2, int64_t arg3)
{
    char* r10 = &arg2[1];
    int32_t i_2;
    
    if (arg1 >= 0)
        i_2 = arg1;
    else
    {
        *r10 = 0x2d;
        r10 = &r10[1];
        i_2 = -(arg1);
    }
    
    void var_38;
    void* rdi = &var_38;
    void* i_1 = &var_38;
    uint32_t i;
    
    do
    {
        i = (i_2 / 0xa);
        i_1 += 1;
        *i_1 = ((i_2 - (i * 0xa)) + 0x30);
        i_2 = i;
    } while (i != 0);
    void* result = (((i_1 - &var_38) + (r10 - &arg2[1])) - arg3);
    
    if (result > 0)
    {
        result = result;
        rdi = (&var_38 + result);
    }
    
    for (; rdi < i_1; i_1 -= 1)
    {
        result = *i_1;
        *r10 = result;
        r10 = &r10[1];
    }
    
    *arg2 = (r10 - &arg2[1]);
    return result;
}

int64_t SYSTEM_$$_INT_STR_UNSIGNED$LONGWORD$OPENSTRING(uint32_t arg1, char* arg2, int64_t arg3)
{
    char* r9 = &arg2[1];
    void var_38;
    void* r10 = &var_38;
    void* i_1 = &var_38;
    uint32_t i;
    
    do
    {
        i_1 += 1;
        i = (arg1 / 0xa);
        *i_1 = ((arg1 - (i * 0xa)) + 0x30);
        arg1 = i;
    } while (i != 0);
    int64_t result = ((i_1 - &var_38) - arg3);
    
    if (result > 0)
    {
        result = result;
        r10 = (&var_38 + result);
    }
    
    for (; r10 < i_1; i_1 -= 1)
    {
        result = *i_1;
        *r9 = result;
        r9 = &r9[1];
    }
    
    *arg2 = (r9 - &arg2[1]);
    return result;
}

void* SYSTEM_$$_INT_STR$INT64$OPENSTRING(int64_t arg1, char* arg2, int64_t arg3)
{
    char* r10 = &arg2[1];
    int64_t i_2;
    
    if (arg1 >= 0)
        i_2 = arg1;
    else
    {
        *r10 = 0x2d;
        r10 = &r10[1];
        i_2 = -(arg1);
    }
    
    void var_38;
    void* rdi = &var_38;
    void* i_1 = &var_38;
    uint64_t i;
    
    do
    {
        i = (i_2 / 0xa);
        i_1 += 1;
        *i_1 = ((i_2 - (i * 0xa)) + 0x30);
        i_2 = i;
    } while (i != 0);
    void* result = (((i_1 - &var_38) + (r10 - &arg2[1])) - arg3);
    
    if (result > 0)
    {
        result = result;
        rdi = (&var_38 + result);
    }
    
    for (; rdi < i_1; i_1 -= 1)
    {
        result = *i_1;
        *r10 = result;
        r10 = &r10[1];
    }
    
    *arg2 = (r10 - &arg2[1]);
    return result;
}

int64_t SYSTEM_$$_INT_STR_UNSIGNED$QWORD$OPENSTRING(uint64_t arg1, char* arg2, int64_t arg3)
{
    char* r9 = &arg2[1];
    void var_58;
    void* r10 = &var_58;
    void* i_1 = &var_58;
    uint64_t i;
    
    do
    {
        i_1 += 1;
        i = (arg1 / 0xa);
        *i_1 = ((arg1 - (i * 0xa)) + 0x30);
        arg1 = i;
    } while (i != 0);
    int64_t result = ((i_1 - &var_58) - arg3);
    
    if (result > 0)
    {
        result = result;
        r10 = (&var_58 + result);
    }
    
    for (; r10 < i_1; i_1 -= 1)
    {
        result = *i_1;
        *r9 = result;
        r9 = &r9[1];
    }
    
    *arg2 = (r9 - &arg2[1]);
    return result;
}

uint64_t SYSTEM_$$_BETON$SMALLINT$$SMALLINT(int16_t arg1) __pure
{
    uint32_t rdi_1 = arg1;
    return ((rdi_1 >> 8) | (rdi_1 << 8));
}

uint64_t SYSTEM_$$_BETON$WORD$$WORD(int16_t arg1) __pure
{
    uint32_t rdi_1 = arg1;
    return ((rdi_1 >> 8) | (rdi_1 << 8));
}

uint64_t SYSTEM_$$_BETON$LONGINT$$LONGINT(int32_t arg1)
{
    return SYSTEM_$$_SWAPENDIAN$LONGINT$$LONGINT(arg1);
}

uint64_t SYSTEM_$$_BETON$LONGWORD$$LONGWORD(int32_t arg1)
{
    return SYSTEM_$$_SWAPENDIAN$LONGWORD$$LONGWORD(arg1);
}

uint64_t SYSTEM_$$_BETON$INT64$$INT64(uint64_t arg1)
{
    return SYSTEM_$$_SWAPENDIAN$INT64$$INT64(arg1);
}

uint64_t SYSTEM_$$_BETON$QWORD$$QWORD(uint64_t arg1)
{
    return SYSTEM_$$_SWAPENDIAN$QWORD$$QWORD(arg1);
}

uint64_t SYSTEM_$$_LETON$SMALLINT$$SMALLINT(int16_t arg1) __pure
{
    return arg1;
}

uint64_t SYSTEM_$$_LETON$WORD$$WORD(int16_t arg1) __pure
{
    return arg1;
}

uint64_t SYSTEM_$$_LETON$LONGINT$$LONGINT(int32_t arg1) __pure
{
    return arg1;
}

uint64_t SYSTEM_$$_LETON$LONGWORD$$LONGWORD(int32_t arg1) __pure
{
    return arg1;
}

int64_t SYSTEM_$$_LETON$INT64$$INT64(int64_t arg1) __pure
{
    return arg1;
}

int64_t SYSTEM_$$_LETON$QWORD$$QWORD(int64_t arg1) __pure
{
    return arg1;
}

uint64_t SYSTEM_$$_NTOBE$SMALLINT$$SMALLINT(int16_t arg1) __pure
{
    uint32_t rdi_1 = arg1;
    return ((rdi_1 >> 8) | (rdi_1 << 8));
}

uint64_t SYSTEM_$$_NTOBE$WORD$$WORD(int16_t arg1) __pure
{
    uint32_t rdi_1 = arg1;
    return ((rdi_1 >> 8) | (rdi_1 << 8));
}

uint64_t SYSTEM_$$_NTOBE$LONGINT$$LONGINT(int32_t arg1)
{
    return SYSTEM_$$_SWAPENDIAN$LONGINT$$LONGINT(arg1);
}

uint64_t SYSTEM_$$_NTOBE$LONGWORD$$LONGWORD(int32_t arg1)
{
    return SYSTEM_$$_SWAPENDIAN$LONGWORD$$LONGWORD(arg1);
}

uint64_t SYSTEM_$$_NTOBE$INT64$$INT64(uint64_t arg1)
{
    return SYSTEM_$$_SWAPENDIAN$INT64$$INT64(arg1);
}

uint64_t SYSTEM_$$_NTOBE$QWORD$$QWORD(uint64_t arg1)
{
    return SYSTEM_$$_SWAPENDIAN$QWORD$$QWORD(arg1);
}

uint64_t SYSTEM_$$_NTOLE$SMALLINT$$SMALLINT(int16_t arg1) __pure
{
    return arg1;
}

uint64_t SYSTEM_$$_NTOLE$WORD$$WORD(int16_t arg1) __pure
{
    return arg1;
}

uint64_t SYSTEM_$$_NTOLE$LONGINT$$LONGINT(int32_t arg1) __pure
{
    return arg1;
}

uint64_t SYSTEM_$$_NTOLE$LONGWORD$$LONGWORD(int32_t arg1) __pure
{
    return arg1;
}

int64_t SYSTEM_$$_NTOLE$INT64$$INT64(int64_t arg1) __pure
{
    return arg1;
}

int64_t SYSTEM_$$_NTOLE$QWORD$$QWORD(int64_t arg1) __pure
{
    return arg1;
}

uint64_t FPC_POPCNT_BYTE(int32_t arg1)
{
    return (*(&TC_$SYSTEM_$$_POPCNTDATA + (arg1 & 0xf)) + *(&TC_$SYSTEM_$$_POPCNTDATA + ((arg1 >> 4) & 0xf)));
}

uint64_t FPC_POPCNT_WORD(int32_t arg1)
{
    int16_t rax = 0;
    
    for (int64_t i = -1; i < 3; )
    {
        i += 1;
        uint64_t rcx_2;
        rcx_2 = *(&TC_$SYSTEM_$$_POPCNTDATA + (arg1 & 0xf));
        rax += rcx_2;
        arg1 u>>= 4;
    }
    
    return rax;
}

int64_t FPC_POPCNT_DWORD(uint32_t arg1)
{
    int32_t result = 0;
    
    for (int64_t i = -1; i < 7; )
    {
        i += 1;
        result += *(&TC_$SYSTEM_$$_POPCNTDATA + (arg1 & 0xf));
        arg1 u>>= 4;
    }
    
    return result;
}

uint64_t FPC_POPCNT_QWORD(int64_t arg1)
{
    uint64_t r12 = FPC_POPCNT_DWORD(arg1);
    return (FPC_POPCNT_DWORD((arg1 >> 0x20)) + r12);
}

int64_t fpc_varset_load(int64_t arg1, int32_t arg2, char* arg3, int64_t arg4, int64_t arg5)
{
    int32_t r14 = arg2;
    int64_t r15 = arg4;
    int64_t r12 = arg1;
    char* r13 = arg3;
    
    if (arg5 > 0)
    {
        SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(r13, arg5, 0);
        r13 = &r13[arg5];
        r15 -= arg5;
    }
    else if (arg5 < 0)
    {
        r12 -= arg5;
        r14 += arg5;
    }
    
    if (r14 > r15)
        r14 = r15;
    
    FPC_MOVE(r12, r13, r14);
    return SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(&r13[r14], (r15 - r14), 0);
}

uint64_t fpc_varset_create_element(int64_t arg1, int64_t arg2, char* arg3)
{
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(arg3, arg2, 0);
    uint64_t result = (arg1 >> 3);
    arg3[result] |= (1 << (arg1 & 7));
    return result;
}

uint64_t fpc_varset_set(int64_t arg1, char* arg2, int64_t arg3, uint64_t arg4)
{
    FPC_MOVE(arg1, arg2, arg4);
    uint64_t result = (arg3 >> 3);
    arg2[result] |= (1 << (arg3 & 7));
    return result;
}

uint64_t fpc_varset_unset(int64_t arg1, char* arg2, int64_t arg3, uint64_t arg4)
{
    FPC_MOVE(arg1, arg2, arg4);
    uint64_t result = (arg3 >> 3);
    arg2[result] &= !((1 << (arg3 & 7)));
    return result;
}

uint64_t fpc_varset_set_range(int64_t arg1, char* arg2, int64_t arg3, int64_t arg4, uint64_t arg5)
{
    uint64_t result = FPC_MOVE(arg1, arg2, arg5);
    
    if (arg4 >= arg3)
    {
        result = (arg3 - 1);
        
        do
        {
            result += 1;
            uint64_t rdx_2 = (result >> 3);
            arg2[rdx_2] |= (1 << (result & 7));
        } while (arg4 > result);
    }
    
    return result;
}

int64_t fpc_varset_add_sets(char* arg1, char* arg2, char* arg3, int64_t arg4)
{
    if ((arg4 - 1) >= 0)
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            arg3[i] = (arg2[i] | arg1[i]);
        } while ((arg4 - 1) > i);
    }
    
    return (arg4 - 1);
}

int64_t fpc_varset_mul_sets(char* arg1, char* arg2, char* arg3, int64_t arg4)
{
    if ((arg4 - 1) >= 0)
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            arg3[i] = (arg2[i] & arg1[i]);
        } while ((arg4 - 1) > i);
    }
    
    return (arg4 - 1);
}

int64_t fpc_varset_sub_sets(int64_t arg1, char* arg2, char* arg3, int64_t arg4)
{
    if ((arg4 - 1) >= 0)
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            arg3[i] = (!(arg2[i]) & *(arg1 + i));
        } while ((arg4 - 1) > i);
    }
    
    return (arg4 - 1);
}

int64_t fpc_varset_symdif_sets(char* arg1, char* arg2, char* arg3, int64_t arg4)
{
    if ((arg4 - 1) >= 0)
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            arg3[i] = (arg2[i] ^ arg1[i]);
        } while ((arg4 - 1) > i);
    }
    
    return (arg4 - 1);
}

int64_t fpc_varset_comp_sets(char* arg1, char* arg2, int64_t arg3)
{
    int64_t result;
    result = 0;
    
    if ((arg3 - 1) >= 0)
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            
            if (arg1[i] != arg2[i])
                return result;
        } while ((arg3 - 1) > i);
    }
    
    result = 1;
    return result;
}

int64_t fpc_varset_contains_sets(int64_t arg1, char* arg2, int64_t arg3)
{
    int64_t result;
    result = 0;
    
    if ((arg3 - 1) >= 0)
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            
            if ((!(arg2[i]) & *(arg1 + i)) != 0)
                return result;
        } while ((arg3 - 1) > i);
    }
    
    result = 1;
    return result;
}

uint64_t SYSTEM_$$_HI$BYTE$$BYTE(char arg1) __pure
{
    return (arg1 >> 4);
}

uint64_t SYSTEM_$$_LO$BYTE$$BYTE(int16_t arg1) __pure
{
    int32_t rax;
    rax = arg1;
    return (rax & 0xf);
}

uint64_t SYSTEM_$$_SWAP$WORD$$WORD(int16_t arg1) __pure
{
    uint32_t rdi_1 = arg1;
    return ((rdi_1 >> 8) | (rdi_1 << 8));
}

uint64_t SYSTEM_$$_SWAP$SMALLINT$$SMALLINT(int16_t arg1) __pure
{
    uint32_t rdi_1 = arg1;
    return ((rdi_1 >> 8) | (rdi_1 << 8));
}

uint64_t SYSTEM_$$_SWAP$LONGINT$$LONGINT(int32_t arg1) __pure
{
    return ((arg1 << 0x10) + (arg1 >> 0x10));
}

uint64_t SYSTEM_$$_SWAP$LONGWORD$$LONGWORD(int32_t arg1) __pure
{
    return ((arg1 << 0x10) + (arg1 >> 0x10));
}

int64_t SYSTEM_$$_SWAP$QWORD$$QWORD(int64_t arg1) __pure
{
    return ((arg1 << 0x20) + (arg1 >> 0x20));
}

int64_t SYSTEM_$$_SWAP$INT64$$INT64(int64_t arg1) __pure
{
    return ((arg1 << 0x20) + (arg1 >> 0x20));
}

int64_t SYSTEM_$$_$assign$REAL48$$DOUBLE(int32_t* arg1)
{
    int32_t var_8 = *arg1;
    int32_t* rax;
    rax = arg1[1];
    int16_t var_4 = rax;
    return SYSTEM_$$_REAL2DOUBLE$REAL48$$DOUBLE(&var_8);
}

long double SYSTEM_$$_$assign$REAL48$$EXTENDED(int32_t* arg1)
{
    int32_t var_18 = *arg1;
    int32_t* rax;
    rax = arg1[1];
    int16_t var_14 = rax;
    return SYSTEM_$$_REAL2DOUBLE$REAL48$$DOUBLE(&var_18);
}

uint16_t SYSTEM_$$_SET8087CW$WORD(uint16_t arg1)
{
    TC_$SYSTEM_$$_DEFAULT8087CW = arg1;
    __fnclex();
    int16_t x87control;
    int16_t x87status_1;
    x87control = __fldcw_memmem16(arg1);
    return arg1;
}

uint32_t SYSTEM_$$_SETMXCSR$LONGWORD(uint32_t arg1)
{
    TC_$SYSTEM_$$_DEFAULTMXCSR = arg1;
    return arg1;
}

int64_t SYSTEM_$$_SETSSECSR$LONGWORD(uint32_t arg1)
{
    return SYSTEM_$$_SETMXCSR$LONGWORD(arg1);
}

uint64_t SYSTEM_$$_GETSSECSR$$LONGWORD()
{
    int32_t mxcsr;
    return SYSTEM_$$_GETMXCSR$$LONGWORD(mxcsr);
}

long double fpc_abs_real()
{
    FPC_RUNERROR(0xcf);
    return 0;
}

long double fpc_sqr_real()
{
    FPC_RUNERROR(0xcf);
    return 0;
}

long double fpc_sqrt_real()
{
    FPC_RUNERROR(0xcf);
    return 0;
}

long double fpc_arctan_real()
{
    FPC_RUNERROR(0xcf);
    return 0;
}

long double fpc_ln_real()
{
    FPC_RUNERROR(0xcf);
    return 0;
}

long double fpc_sin_real()
{
    FPC_RUNERROR(0xcf);
    return 0;
}

long double fpc_cos_real()
{
    FPC_RUNERROR(0xcf);
    return 0;
}

int64_t SYSTEM_$$_FLOAT_RAISE$TFPUEXCEPTION(char arg1)
{
    return SYSTEM_$$_FLOAT_RAISE$TFPUEXCEPTIONMASK((0 | (1 << arg1)));
}

int64_t SYSTEM_$$_FLOAT_RAISE$TFPUEXCEPTIONMASK(int32_t arg1)
{
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int32_t* r12;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        r12 = &data_434ab8;
    else
        r12 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_SOFTFLOAT_EXCEPTION_FLAGS);
    
    *r12 |= arg1;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int32_t* rax_2;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax_2 = &data_434aa8;
    else
        rax_2 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_SOFTFLOAT_EXCEPTION_MASK);
    
    int32_t result = (*r12 & !(*rax_2));
    
    if ((result & 1) != 0)
        return FPC_HANDLEERROR(0xcf);
    
    if ((result & 4) != 0)
        return FPC_HANDLEERROR(0xd0);
    
    if ((result & 8) != 0)
        return FPC_HANDLEERROR(0xcd);
    
    if ((result & 0x10) != 0)
        return FPC_HANDLEERROR(0xce);
    
    if ((result & 0x20) == 0)
        return result;
    
    return FPC_HANDLEERROR(0xcf);
}

int64_t SYSTEM_$$_FPE_HELPER$EXTENDED$$BOOLEAN() __pure
{
    int64_t result;
    result = 1;
    return result;
}

uint64_t SYSTEM_$$_FLOAT64HIGH$DOUBLE$$LONGINT(int64_t arg1 @ zmm0) __pure
{
    return *arg1[4];
}

void* SYSTEM_$$_FLOAT64SETHIGH$DOUBLE$LONGINT(void* arg1, int32_t arg2)
{
    *(arg1 + 4) = arg2;
    return arg1;
}

uint64_t SYSTEM_$$_FLOAT64LOW$DOUBLE$$LONGINT(int32_t arg1 @ zmm0) __pure
{
    return arg1;
}

int32_t* SYSTEM_$$_FLOAT64SETLOW$DOUBLE$LONGINT(int32_t* arg1, int32_t arg2)
{
    *arg1 = arg2;
    return arg1;
}

int64_t* SYSTEM_$$_FREXP$REAL$REAL$LONGINT(int64_t* arg1, int32_t* arg2, uint64_t arg3[0x2] @ zmm0)
{
    *arg2 = 0;
    uint64_t temp0[0x2] = __andpd_xmmxuq_memxuq(arg3, FPC_ABSMASK_DOUBLE);
    (temp0[0] - 0.5);
    
    if (((FCMP_UO(temp0[0], 0.5)) || temp0[0] >= 0.5))
    {
        while (true)
        {
            uint64_t temp0_2[0x2] = __andpd_xmmxuq_memxuq(arg3, FPC_ABSMASK_DOUBLE);
            (temp0_2[0] - 1.0);
            
            if ((FCMP_UO(temp0_2[0], 1.0)))
                break;
            
            if (!(temp0_2[0] > 1.0))
                break;
            
            arg3[0] = (arg3[0] * 0.5);
            *arg2 += 1;
        }
    }
    else
    {
        while (true)
        {
            uint64_t temp0_1[0x2] = __andpd_xmmxuq_memxuq(arg3, FPC_ABSMASK_DOUBLE);
            (temp0_1[0] - 0.5);
            
            if ((FCMP_UO(temp0_1[0], 0.5)))
                break;
            
            if (!(temp0_1[0] < 0.5))
                break;
            
            arg3[0] = (arg3[0] * 2.0);
            *arg2 -= 1;
        }
    }
    
    *arg1 = arg3;
    return arg1;
}

uint128_t SYSTEM_$$_LDEXP$REAL$SMALLINT$$REAL(int16_t arg1, uint128_t arg2 @ zmm0)
{
    int64_t var_18 = arg2;
    uint16_t rax_4;
    
    while (true)
    {
        rax_4 = ((*var_18[4] & 0x7ff00000) >> 0x14);
        
        if ((rax_4 == 0x7ff || arg1 == 0))
            return var_18;
        
        arg2 = 0;
        (arg2 - var_18);
        
        if ((!((FCMP_UO(arg2, var_18))) && !(arg2 != var_18)))
            return var_18;
        
        if (rax_4 != 0)
            break;
        
        arg2 = (var_18 * TC_$SYSTEM_$$_H2_54);
        var_18 = arg2;
        arg1 -= 0x36;
    }
    
    int16_t rax_8 = (arg1 + rax_4);
    
    if (rax_8 > 0x7fe)
    {
        arg2 = 0;
        double temp1_1 = var_18;
        (arg2 - temp1_1);
        
        if ((!((FCMP_UO(arg2, temp1_1))) && !(arg2 >= temp1_1)))
        {
            arg2 = (0x4000000000000000 * TC_$SYSTEM_$$_HUGE);
            return arg2;
        }
        
        arg2 = (-0x4000000000000000 * TC_$SYSTEM_$$_HUGE);
        return arg2;
    }
    
    if (rax_8 >= 1)
    {
        *var_18[4] = ((*var_18[4] & 0x800fffff) | (rax_8 << 0x14));
        return var_18;
    }
    
    if (rax_8 < 0xffcb)
        return 0;
    
    *var_18[4] = ((*var_18[4] & 0x800fffff) | ((rax_8 + 0x36) << 0x14));
    arg2 = (var_18 / TC_$SYSTEM_$$_H2_54);
    return arg2;
}

uint128_t SYSTEM_$$_POLEVL$REAL$PREAL$INT64$$REAL(int64_t* arg1, int64_t arg2, uint128_t arg3 @ zmm0)
{
    int64_t zmm1 = arg3;
    arg3 = *arg1;
    
    if (arg2 >= 1)
    {
        int64_t rax_1 = 0;
        
        do
        {
            rax_1 += 1;
            uint128_t zmm2;
            zmm2 = (arg3 * zmm1);
            zmm2 = (zmm2 + arg1[rax_1]);
            arg3 = zmm2;
        } while (arg2 > rax_1);
    }
    
    return arg3;
}

int512_t SYSTEM_$$_P1EVL$REAL$PREAL$INT64$$REAL(int64_t* arg1, int64_t arg2, int128_t arg3 @ zmm0)
{
    int128_t zmm1 = arg3;
    arg3 = (zmm1 + *arg1);
    
    if ((arg2 - 1) >= 1)
    {
        int64_t i = 0;
        
        do
        {
            i += 1;
            int128_t zmm2;
            zmm2 = (arg3 * zmm1);
            zmm2 = (zmm2 + arg1[i]);
            arg3 = zmm2;
        } while ((arg2 - 1) > i);
    }
    
    return arg3;
}

long double SYSTEM_$$_FLOORD$DOUBLE$$DOUBLE(long double arg1)
{
    double var_10 = arg1;
    long double var_28 = arg1;
    int16_t x87control;
    uint80_t result = fpc_int_real(x87control, arg1);
    arg1 = var_10;
    (arg1 - 0.0);
    
    if (((FCMP_UO(arg1, 0.0)) || !(arg1 >= 0.0)))
    {
        (result - var_10);
        
        if (((FCMP_UO(result, var_10)) || result != var_10))
            result = (result - 1.0);
    }
    
    return result;
}

int64_t SYSTEM_$$_K_REM_PIO2$TDA02$TDA02$SMALLINT$SMALLINT$SMALLINT$$INT64(int64_t arg1, int64_t* arg2, int16_t arg3, int16_t arg4, int16_t arg5)
{
    int64_t* var_88 = arg2;
    arg2 = arg3;
    uint64_t rdi = *(&TC_$SYSTEM_$$_INIT_JK + (arg5 << 1));
    int32_t i_4 = rdi;
    int32_t r15 = ((arg2 - 3) / 0x18);
    
    if (r15 < 0)
        r15 = 0;
    
    uint64_t var_50 = (arg2 - ((r15 + 1) * 0x18));
    int32_t r14 = (r15 - (arg4 - 1));
    int32_t i = ((arg4 - 1) + rdi);
    void var_278;
    uint128_t zmm0;
    
    if (i >= 0)
    {
        int64_t var_80_1 = 0xffffffff;
        
        do
        {
            var_80_1 += 1;
            
            if (r14 >= 0)
            {
                zmm0 = *(&TC_$SYSTEM_$$_IPIO2 + (r14 << 2));
                *(&var_278 + (var_80_1 << 3)) = zmm0;
            }
            else
                *(&var_278 + (var_80_1 << 3)) = 0;
            
            r14 += 1;
        } while (i > var_80_1);
    }
    
    int32_t i_1 = rdi;
    void var_138;
    
    if (i_1 >= 0)
    {
        int64_t var_80_2 = 0xffffffff;
        
        do
        {
            var_80_2 += 1;
            uint64_t var_98_1 = 0;
            rdi = (arg4 - 1);
            
            if (rdi >= 0)
            {
                int32_t j = -1;
                
                do
                {
                    j += 1;
                    zmm0 = (*(arg1 + (j << 3)) * *(&var_278 + ((((arg4 - 1) + var_80_2) - j) << 3)));
                    zmm0 = (zmm0 + var_98_1);
                    var_98_1 = zmm0;
                } while (rdi > j);
            }
            
            *(&var_138 + (var_80_2 << 3)) = var_98_1;
        } while (i_1 > var_80_2);
    }
    
    uint64_t i_6 = i_1;
    void var_2c8;
    double var_90_4;
    uint64_t var_78_1;
    uint32_t var_70_1;
    
    while (true)
    {
        int64_t var_80_3 = 0;
        uint64_t var_90_1 = *(&var_138 + (i_6 << 3));
        
        if (i_6 >= 1)
        {
            int32_t i_2 = (i_6 + 1);
            
            do
            {
                i_2 -= 1;
                zmm0 = (TC_$SYSTEM_$$_TWON24 * var_90_1);
                zmm0 = zmm0;
                uint64_t var_98_2 = zmm0;
                zmm0 = (TC_$SYSTEM_$$_TWO24 * var_98_2);
                *(&var_2c8 + (var_80_3 << 2)) = (var_90_1 - zmm0);
                void var_140;
                zmm0 = (*(&var_140 + (i_2 << 3)) + var_98_2);
                var_90_1 = zmm0;
                var_80_3 += 1;
            } while (i_2 > 1);
        }
        
        rdi = var_50;
        long double zmm0_1;
        zmm0_1 = SYSTEM_$$_LDEXP$REAL$SMALLINT$$REAL(rdi, var_90_1);
        double var_90_2 = zmm0_1;
        zmm0_1 = (zmm0_1 * 0.125);
        zmm0 = (SYSTEM_$$_FLOORD$DOUBLE$$DOUBLE(zmm0_1) * 8.0);
        double var_90_3 = (var_90_2 - zmm0);
        var_78_1 = var_90_3;
        zmm0 = (var_90_3 - var_78_1);
        var_90_4 = zmm0;
        var_70_1 = 0;
        void var_2cc;
        
        if (var_50 > 0)
        {
            uint64_t rbx_1 = (*(&var_2cc + (i_6 << 2)) >> (0x18 - var_50));
            var_78_1 += rbx_1;
            int64_t rdx_11 = i_6;
            *(&var_2cc + (rdx_11 << 2)) -= (rbx_1 << (0x18 - var_50));
            var_70_1 = (*(&var_2cc + (i_6 << 2)) >> (0x17 - var_50));
        }
        else if (var_50 != 0)
        {
            zmm0 = var_90_4;
            (zmm0 - 0.5);
            
            if ((!((FCMP_UO(zmm0, 0.5))) && !(zmm0 < 0.5)))
                var_70_1 = 2;
        }
        else
            var_70_1 = (*(&var_2cc + (i_6 << 2)) >> 0x17);
        
        if (var_70_1 > 0)
        {
            var_78_1 += 1;
            int32_t r12_1 = 0;
            
            if ((i_6 - 1) >= 0)
            {
                int64_t var_80_4 = 0xffffffff;
                
                do
                {
                    var_80_4 += 1;
                    int32_t rbx_2 = *(&var_2c8 + (var_80_4 << 2));
                    
                    if (r12_1 != 0)
                        *(&var_2c8 + (var_80_4 << 2)) = (0xffffff - rbx_2);
                    else if (rbx_2 != 0)
                    {
                        r12_1 = 1;
                        *(&var_2c8 + (var_80_4 << 2)) = (0x1000000 - rbx_2);
                    }
                } while ((i_6 - 1) > var_80_4);
            }
            
            if (var_50 > 0)
            {
                int32_t rdx_19 = var_50;
                
                if (rdx_19 == 1)
                    *(&var_2c8 + ((i_6 - 1) << 2)) &= 0x7fffff;
                else if (rdx_19 == 2)
                    *(&var_2c8 + ((i_6 - 1) << 2)) &= 0x3fffff;
            }
            
            if (var_70_1 == 2)
            {
                zmm0 = (0x3ff0000000000000 - var_90_4);
                var_90_4 = zmm0;
                
                if (r12_1 != 0)
                {
                    zmm0 = SYSTEM_$$_LDEXP$REAL$SMALLINT$$REAL(var_50, 0x3ff0000000000000);
                    var_90_4 = (var_90_4 - zmm0);
                }
            }
        }
        
        zmm0 = var_90_4;
        (zmm0 - 0.0);
        
        if ((FCMP_UO(zmm0, 0.0)))
            break;
        
        if (zmm0 != 0.0)
            break;
        
        int32_t rbx_3 = 0;
        
        if (i_1 <= (i_6 - 1))
        {
            int64_t var_80_6 = ((i_6 - 1) + 1);
            
            do
            {
                var_80_6 -= 1;
                rbx_3 |= *(&var_2c8 + (var_80_6 << 2));
            } while (i_1 < var_80_6);
        }
        
        if (rbx_3 != 0)
            break;
        
        int64_t var_48_1 = 1;
        
        while (*(&var_2c8 + ((i_1 - var_48_1) << 2)) == 0)
            var_48_1 += 1;
        
        int32_t i_3 = (var_48_1 + i_6);
        
        if (i_3 >= (i_6 + 1))
        {
            int64_t var_80_8 = ((i_6 + 1) - 1);
            
            do
            {
                var_80_8 += 1;
                int64_t rax_52 = var_80_8;
                zmm0 = *(&TC_$SYSTEM_$$_IPIO2 + ((r15 + rax_52) << 2));
                *(&var_278 + (((arg4 - 1) + rax_52) << 3)) = zmm0;
                uint64_t var_98_3 = 0;
                
                if ((arg4 - 1) >= 0)
                {
                    int32_t j_1 = -1;
                    
                    do
                    {
                        j_1 += 1;
                        zmm0 = (*(arg1 + (j_1 << 3)) * *(&var_278 + ((((arg4 - 1) + var_80_8) - j_1) << 3)));
                        zmm0 = (zmm0 + var_98_3);
                        var_98_3 = zmm0;
                    } while ((arg4 - 1) > j_1);
                }
                
                *(&var_138 + (var_80_8 << 3)) = var_98_3;
            } while (i_3 > var_80_8);
        }
        
        i_6 += var_48_1;
    }
    
    zmm0 = var_90_4;
    (zmm0 - 0.0);
    
    if (((FCMP_UO(zmm0, 0.0)) || zmm0 != 0.0))
    {
        zmm0 = SYSTEM_$$_LDEXP$REAL$SMALLINT$$REAL(-(var_50), var_90_4);
        uint64_t var_90_5 = zmm0;
        double TC_$SYSTEM_$$_TWO24_1 = TC_$SYSTEM_$$_TWO24;
        (zmm0 - TC_$SYSTEM_$$_TWO24_1);
        
        if (((FCMP_UO(zmm0, TC_$SYSTEM_$$_TWO24_1)) || zmm0 < TC_$SYSTEM_$$_TWO24_1))
            *(&var_2c8 + (i_6 << 2)) = var_90_5;
        else
        {
            zmm0 = (TC_$SYSTEM_$$_TWON24 * var_90_5);
            zmm0 = zmm0;
            uint64_t var_98_4 = zmm0;
            zmm0 = (var_90_5 - (TC_$SYSTEM_$$_TWO24 * var_98_4));
            *(&var_2c8 + (i_6 << 2)) = zmm0;
            i_6 += 1;
            var_50 += 0x18;
            *(&var_2c8 + (i_6 << 2)) = var_98_4;
        }
    }
    else
    {
        do
        {
            i_6 -= 1;
            var_50 -= 0x18;
        } while (*(&var_2c8 + (i_6 << 2)) == 0);
    }
    
    rdi = var_50;
    uint128_t zmm0_2;
    uint128_t zmm1_2;
    zmm0_2 = SYSTEM_$$_LDEXP$REAL$SMALLINT$$REAL(rdi, 0x3ff0000000000000);
    
    if (i_6 >= 0)
    {
        uint64_t var_80_9 = (i_6 + 1);
        
        do
        {
            var_80_9 -= 1;
            zmm1_2 = *(&var_2c8 + (var_80_9 << 2));
            zmm1_2 = (zmm1_2 * zmm0_2);
            *(&var_138 + (var_80_9 << 3)) = zmm1_2;
            zmm0_2 = (zmm0_2 * TC_$SYSTEM_$$_TWON24);
        } while (var_80_9 > 0);
    }
    
    int64_t var_1d8;
    
    if (i_6 >= 0)
    {
        uint64_t var_80_10 = (i_6 + 1);
        
        do
        {
            var_80_10 -= 1;
            zmm0_2 = 0;
            int64_t var_48_2 = 0;
            
            while (i_4 >= var_48_2)
            {
                if ((i_6 - var_80_10) < var_48_2)
                    break;
                
                zmm1_2 = (*(&TC_$SYSTEM_$$_PIO2CHUNKED + (var_48_2 << 3)) * *(&var_138 + ((var_80_10 + var_48_2) << 3)));
                zmm0_2 = (zmm0_2 + zmm1_2);
                var_48_2 += 1;
            }
            
            &var_1d8[(i_6 - var_80_10)] = zmm0_2;
        } while (var_80_10 > 0);
    }
    
    int32_t rax_74;
    rax_74 = arg5;
    
    if (rax_74 >= 0)
    {
        if (rax_74 == 0)
        {
            zmm0_2 = 0;
            
            if (i_6 >= 0)
            {
                uint64_t var_80_11 = (i_6 + 1);
                
                do
                {
                    var_80_11 -= 1;
                    zmm0_2 = (zmm0_2 + &var_1d8[var_80_11]);
                } while (var_80_11 > 0);
            }
            
            if (var_70_1 != 0)
                *var_88 = _mm_xor_pd(zmm0_2, -0x8000000000000000);
            else
                *var_88 = zmm0_2;
        }
        else
        {
            int16_t temp6_1 = rax_74;
            rax_74 -= 1;
            
            if (temp6_1 >= 1)
            {
                int16_t temp7_1 = rax_74;
                rax_74 -= 1;
                
                if (temp7_1 <= 1)
                {
                    zmm0_2 = 0;
                    
                    if (i_6 >= 0)
                    {
                        uint64_t var_80_12 = (i_6 + 1);
                        
                        do
                        {
                            var_80_12 -= 1;
                            zmm0_2 = (zmm0_2 + &var_1d8[var_80_12]);
                        } while (var_80_12 > 0);
                    }
                    
                    if (var_70_1 != 0)
                        *var_88 = _mm_xor_pd(zmm0_2, -0x8000000000000000);
                    else
                        *var_88 = zmm0_2;
                    
                    zmm1_2 = (var_1d8 - zmm0_2);
                    zmm0_2 = zmm1_2;
                    int32_t i_5 = i_6;
                    
                    if (i_5 >= 1)
                    {
                        int64_t var_80_13 = 0;
                        
                        do
                        {
                            var_80_13 += 1;
                            zmm0_2 = (zmm0_2 + &var_1d8[var_80_13]);
                        } while (i_5 > var_80_13);
                    }
                    
                    if (var_70_1 != 0)
                        var_88[1] = _mm_xor_pd(zmm0_2, -0x8000000000000000);
                    else
                        var_88[1] = zmm0_2;
                }
                else
                {
                    int16_t temp8_1 = rax_74;
                    rax_74 -= 1;
                    
                    if (temp8_1 == 1)
                    {
                        void var_1e0;
                        
                        if (i_6 >= 1)
                        {
                            uint64_t var_80_14 = (i_6 + 1);
                            
                            do
                            {
                                var_80_14 -= 1;
                                zmm1_2 = (*(&var_1e0 + (var_80_14 << 3)) + &var_1d8[var_80_14]);
                                zmm0_2 = zmm1_2;
                                zmm1_2 = (*(&var_1e0 + (var_80_14 << 3)) - zmm0_2);
                                zmm1_2 = (zmm1_2 + &var_1d8[var_80_14]);
                                &var_1d8[var_80_14] = zmm1_2;
                                *(&var_1e0 + (var_80_14 << 3)) = zmm0_2;
                            } while (var_80_14 > 1);
                        }
                        
                        if (i_6 >= 2)
                        {
                            uint64_t var_80_15 = (i_6 + 1);
                            
                            do
                            {
                                var_80_15 -= 1;
                                zmm1_2 = (*(&var_1e0 + (var_80_15 << 3)) + &var_1d8[var_80_15]);
                                zmm0_2 = zmm1_2;
                                zmm1_2 = (*(&var_1e0 + (var_80_15 << 3)) - zmm0_2);
                                zmm1_2 = (zmm1_2 + &var_1d8[var_80_15]);
                                &var_1d8[var_80_15] = zmm1_2;
                                *(&var_1e0 + (var_80_15 << 3)) = zmm0_2;
                            } while (var_80_15 > 2);
                        }
                        
                        zmm0_2 = 0;
                        
                        if (i_6 >= 2)
                        {
                            uint64_t var_80_16 = (i_6 + 1);
                            
                            do
                            {
                                var_80_16 -= 1;
                                zmm0_2 = (zmm0_2 + &var_1d8[var_80_16]);
                            } while (var_80_16 > 2);
                        }
                        
                        int64_t var_1d0;
                        
                        if (var_70_1 != 0)
                        {
                            *var_88 = _mm_xor_pd(var_1d8, -0x8000000000000000);
                            var_88[1] = _mm_xor_pd(var_1d0, -0x8000000000000000);
                            var_88[2] = _mm_xor_pd(zmm0_2, -0x8000000000000000);
                        }
                        else
                        {
                            *var_88 = var_1d8;
                            var_88[1] = var_1d0;
                            var_88[2] = zmm0_2;
                        }
                    }
                }
            }
        }
    }
    
    return (var_78_1 & 7);
}

int64_t SYSTEM_$$_REM_PIO2$DOUBLE$DOUBLE$$INT64(uint64_t* arg1, uint128_t arg2 @ zmm0)
{
    int64_t var_20 = arg2;
    arg2 = __andpd_xmmxuq_memxuq(var_20, FPC_ABSMASK_DOUBLE);
    long double x87_r7 = arg2;
    long double _$SYSTEM$_Ld16_1 = _$SYSTEM$_Ld16;
    (_$SYSTEM$_Ld16_1 - x87_r7);
    
    if ((!((FCMP_UO(_$SYSTEM$_Ld16_1, x87_r7))) && !(_$SYSTEM$_Ld16_1 <= x87_r7)))
    {
        *arg1 = var_20;
        return 0;
    }
    
    arg2 = arg2;
    (arg2 - 1073741824.0);
    int64_t result;
    
    if (((FCMP_UO(arg2, 1073741824.0)) || arg2 >= 1073741824.0))
    {
    label_406433:
        *arg1 = __andpd_xmmxuq_memxuq(var_20, FPC_ABSMASK_DOUBLE);
        int32_t rdx_5 = ((**arg1[4] >> 0x14) - 0x416);
        
        if (rdx_5 == 0x3e9)
        {
            arg2 = (var_20 - var_20);
            *arg1 = arg2;
            return 0;
        }
        
        *(arg1 + 4) = (**arg1[4] - (rdx_5 << 0x14));
        arg2 = *arg1;
        uint64_t var_58 = arg2;
        arg2 = (*arg1 - var_58);
        arg2 = (arg2 * TC_$SYSTEM_$$_TWO24);
        *arg1 = arg2;
        arg2 = arg2;
        arg2 = (*arg1 - arg2);
        arg2 = (arg2 * TC_$SYSTEM_$$_TWO24);
        uint64_t var_48_1 = arg2;
        int32_t rcx_3 = 3;
        
        while (true)
        {
            void var_60;
            arg2 = *(&var_60 + (rcx_3 << 3));
            (arg2 - 0.0);
            
            if ((FCMP_UO(arg2, 0.0)))
                break;
            
            if (!(arg2 == 0.0))
                break;
            
            rcx_3 -= 1;
        }
        
        int64_t var_40;
        result = SYSTEM_$$_K_REM_PIO2$TDA02$TDA02$SMALLINT$SMALLINT$SMALLINT$$INT64(&var_58, &var_40, rdx_5, rcx_3, 2);
        uint128_t zmm0_1 = var_20;
        (zmm0_1 - 0.0);
        int64_t var_38;
        
        if (((FCMP_UO(zmm0_1, 0.0)) || zmm0_1 >= 0.0))
        {
            zmm0_1 = (var_40 + var_38);
            *arg1 = zmm0_1;
        }
        else
        {
            result = (-(result) & 7);
            zmm0_1 = (_mm_xor_pd(var_40, -0x8000000000000000) - var_38);
            *arg1 = zmm0_1;
        }
    }
    else
    {
        long double zmm0 = SYSTEM_$$_FLOORD$DOUBLE$$DOUBLE((var_20 / _$SYSTEM$_Ld16));
        uint64_t var_18_1 = zmm0;
        zmm0 = (zmm0 * 0.0625);
        arg2 = (SYSTEM_$$_FLOORD$DOUBLE$$DOUBLE(zmm0) * 16.0);
        int32_t rax_1 = (var_18_1 - arg2);
        
        if ((rax_1 & 1) != 0)
        {
            rax_1 += 1;
            arg2 = (var_18_1 + 1.0);
            var_18_1 = arg2;
        }
        
        arg2 = (var_18_1 * 0.78539812564849854);
        uint64_t zmm1_1 = (var_20 - arg2);
        arg2 = (var_18_1 * 3.7748947079307982e-08);
        zmm1_1 = (zmm1_1 - arg2);
        arg2 = (var_18_1 * 2.6951514290790595e-15);
        *arg1 = (zmm1_1 - arg2);
        result = ((rax_1 >> 1) & 7);
        arg2 = __andpd_xmmxuq_memxuq(*arg1, FPC_ABSMASK_DOUBLE);
        double TC_$SYSTEM$_$REM_PIO2$DOUBLE$DOUBLE$$INT64_$$_TOL_1 = TC_$SYSTEM$_$REM_PIO2$DOUBLE$DOUBLE$$INT64_$$_TOL;
        (arg2 - TC_$SYSTEM$_$REM_PIO2$DOUBLE$DOUBLE$$INT64_$$_TOL_1);
        
        if (((FCMP_UO(arg2, TC_$SYSTEM$_$REM_PIO2$DOUBLE$DOUBLE$$INT64_$$_TOL_1)) || !(arg2 > TC_$SYSTEM$_$REM_PIO2$DOUBLE$DOUBLE$$INT64_$$_TOL_1)))
            goto label_406433;
    }
    
    return result;
}

uint32_t SYSTEM_$$_REAL2DOUBLE$REAL48$$DOUBLE(int32_t* arg1)
{
    uint32_t var_10 = *arg1;
    uint32_t result;
    result = arg1[1];
    int16_t var_c = result;
    int512_t zmm0;
    
    if (var_10 != 0)
    {
        uint8_t var_17_1 = (*var_10[1] << 5);
        uint8_t var_16_1 = ((*var_10[1] >> 3) | (*var_10[2] << 5));
        uint8_t var_15_1 = ((*var_10[2] >> 3) | (*var_10[3] << 5));
        char var_14_1 = ((*var_10[3] >> 3) | (var_c << 5));
        char var_13_1 = (((var_c & 0x7f) << 5) | (var_c >> 3));
        char var_12_2 = ((((var_10 + 0x37e) & 0xf) << 4) | ((var_c & 0x7f) >> 3));
        result = *var_c[1];
        result &= 0x80;
        result |= (((var_10 + 0x37e) & 0xffff) >> 4);
        char var_11_2 = result;
        zmm0 = 0;
    }
    else
        zmm0 = 0;
    return result;
}

long double SYSTEM_$$_FPOWER10$EXTENDED$LONGINT$$EXTENDED(int32_t arg1, long double arg2)
{
    long double result;
    
    if (arg1 >= 0)
    {
        result = (arg2 * *(&TC_$SYSTEM$_$FPOWER10$EXTENDED$LONGINT$$EXTENDED_$$_POW32 + ((arg1 & 0x1f) * 0xa)));
        uint32_t rax_4 = (arg1 >> 5);
        
        if (rax_4 != 0)
        {
            result = (result * *(&TC_$SYSTEM$_$FPOWER10$EXTENDED$LONGINT$$EXTENDED_$$_POW512 + ((rax_4 & 0xf) * 0xa)));
            uint32_t rax_5 = (rax_4 >> 4);
            
            if (rax_5 != 0)
            {
                if (rax_5 <= 9)
                    return (result * *(&TC_$SYSTEM$_$FPOWER10$EXTENDED$LONGINT$$EXTENDED_$$_POW4096 + (rax_5 * 0xa)));
                
                result = -0x8000000000000000;
                *result[8] = 0x7fff;
            }
        }
    }
    else
    {
        int32_t rdx_1 = -(arg1);
        result = (arg2 * *(&TC_$SYSTEM$_$FPOWER10$EXTENDED$LONGINT$$EXTENDED_$$_NEGPOW32 + ((rdx_1 & 0x1f) * 0xa)));
        uint32_t rax_2 = (rdx_1 >> 5);
        
        if (rax_2 != 0)
        {
            result = (result * *(&TC_$SYSTEM$_$FPOWER10$EXTENDED$LONGINT$$EXTENDED_$$_NEGPOW512 + ((rax_2 & 0xf) * 0xa)));
            uint32_t rax_3 = (rax_2 >> 4);
            
            if (rax_3 != 0)
            {
                if (rax_3 <= 9)
                    return (result * *(&TC_$SYSTEM$_$FPOWER10$EXTENDED$LONGINT$$EXTENDED_$$_NEGPOW4096 + (rax_3 * 0xa)));
                
                result = -0x8000000000000000;
                *result[8] = 0x7fff;
            }
        }
    }
    
    return result;
}

int64_t SYSTEM$_$TEXTENDED80REC_$__$$_MANTISSA$BOOLEAN$$QWORD(int64_t* arg1, char arg2)
{
    if (arg2 == 0)
        return (*arg1 & 0x7fffffffffffffff);
    
    return *arg1;
}

int80_t SYSTEM$_$TEXTENDED80REC_$__$$_FRACTION$$EXTENDED(int64_t* arg1)
{
    int64_t var_28 = *arg1;
    int64_t* rax;
    rax = arg1[1];
    int16_t var_20 = rax;
    return fpc_frac_real();
}

uint64_t SYSTEM$_$TEXTENDED80REC_$__$$_EXPONENT$$LONGINT(int64_t* arg1)
{
    int32_t r12 = 0;
    int64_t rax = SYSTEM$_$TEXTENDED80REC_$__$$_GETEXP$$QWORD(arg1);
    
    if ((rax <= 0 || rax >= 0x7fff))
    {
        if ((SYSTEM$_$TEXTENDED80REC_$__$$_GETEXP$$QWORD(arg1) == 0 && *arg1 != 0))
            r12 = -0x3ffe;
    }
    else
        r12 = (SYSTEM$_$TEXTENDED80REC_$__$$_GETEXP$$QWORD(arg1) - 0x3fff);
    
    return r12;
}

int64_t SYSTEM$_$TEXTENDED80REC_$__$$_GETEXP$$QWORD(void* arg1)
{
    return (*(arg1 + 8) & 0x7fff);
}

void* SYSTEM$_$TEXTENDED80REC_$__$$_SETEXP$QWORD(void* arg1, int16_t arg2)
{
    *(arg1 + 8) = ((*(arg1 + 8) & 0x8000) | (arg2 & 0x7fff));
    return arg1;
}

int64_t SYSTEM$_$TEXTENDED80REC_$__$$_GETSIGN$$BOOLEAN(void* arg1)
{
    int16_t result;
    result = (*(arg1 + 8) & 0x8000) != 0;
    return result;
}

void* SYSTEM$_$TEXTENDED80REC_$__$$_SETSIGN$BOOLEAN(void* arg1, char arg2)
{
    *(arg1 + 8) = (*(arg1 + 8) | (arg2 << 0xf));
    return arg1;
}

uint64_t SYSTEM$_$TEXTENDED80REC_$__$$_SPECIALTYPE$$TFLOATSPECIAL(int64_t* arg1, uint64_t arg2 @ r12)
{
    uint64_t var_10 = arg2;
    int64_t rax = SYSTEM$_$TEXTENDED80REC_$__$$_GETEXP$$QWORD(arg1);
    
    if (rax == 0)
    {
        if (SYSTEM$_$TEXTENDED80REC_$__$$_MANTISSA$BOOLEAN$$QWORD(arg1, 0) != 0)
            arg2 = *(&TC_$SYSTEM$_$TEXTENDED80REC_$_SPECIALTYPE$$TFLOATSPECIAL_$$_DENORMAL + (SYSTEM$_$TEXTENDED80REC_$__$$_GETSIGN$$BOOLEAN(arg1) << 2));
        else if (SYSTEM$_$TEXTENDED80REC_$__$$_GETSIGN$$BOOLEAN(arg1) == 0)
            arg2 = 0;
        else
            arg2 = 1;
    }
    else if (rax == 0x7fff)
    {
        int64_t rax_8 = ((*arg1 >> 0x3e) & 3);
        
        if (rax_8 <= 1)
            arg2 = 9;
        else if (rax_8 == 2)
        {
            if ((*arg1 & 0x3fffffffffffffff) != 0)
                arg2 = 8;
            else if (SYSTEM$_$TEXTENDED80REC_$__$$_GETSIGN$$BOOLEAN(arg1) == 0)
                arg2 = 6;
            else
                arg2 = 7;
        }
        else if (rax_8 == 3)
            arg2 = 8;
    }
    else if ((*arg1 & 0x8000000000000000) != 0)
    {
        if (SYSTEM$_$TEXTENDED80REC_$__$$_GETSIGN$$BOOLEAN(arg1) == 0)
            arg2 = 4;
        else
            arg2 = 5;
    }
    else
        arg2 = 9;
    
    return arg2;
}

void* SYSTEM$_$TEXTENDED80REC_$__$$_BUILDUP$BOOLEAN$QWORD$LONGINT(long double* arg1, char arg2, int64_t arg3, int32_t arg4)
{
    int64_t r12;
    r12 = arg2;
    *arg1 = 0;
    
    if ((arg3 != 0 || arg4 != 0))
        SYSTEM$_$TEXTENDED80REC_$__$$_SETEXP$QWORD(arg1, (arg4 + 0x3fff));
    else
        SYSTEM$_$TEXTENDED80REC_$__$$_SETEXP$QWORD(arg1, 0);
    
    void* result = SYSTEM$_$TEXTENDED80REC_$__$$_SETSIGN$BOOLEAN(arg1, r12);
    *arg1 = arg3;
    return result;
}

int64_t SYSTEM$_$TDOUBLEREC_$__$$_MANTISSA$BOOLEAN$$QWORD(int64_t* arg1, char arg2)
{
    int64_t rbx;
    rbx = arg2;
    int64_t result = (*arg1 & 0xfffffffffffff);
    uint64_t rax_1;
    
    if (result == 0)
        rax_1 = SYSTEM$_$TDOUBLEREC_$__$$_GETEXP$$QWORD(arg1);
    
    if (((result != 0 || rax_1 != 0) && rbx != 0))
        return (result | 0x10000000000000);
    
    return result;
}

int80_t SYSTEM$_$TDOUBLEREC_$__$$_FRACTION$$EXTENDED(double* arg1)
{
    long double var_28 = *arg1;
    return fpc_frac_real();
}

uint64_t SYSTEM$_$TDOUBLEREC_$__$$_EXPONENT$$LONGINT(int64_t* arg1)
{
    int32_t r12 = 0;
    uint64_t rax = SYSTEM$_$TDOUBLEREC_$__$$_GETEXP$$QWORD(arg1);
    
    if ((rax <= 0 || rax >= 0x7ff))
    {
        if ((SYSTEM$_$TDOUBLEREC_$__$$_GETEXP$$QWORD(arg1) == 0 && SYSTEM$_$TDOUBLEREC_$__$$_GETFRAC$$QWORD(arg1) != 0))
            r12 = -0x3fe;
    }
    else
        r12 = (SYSTEM$_$TDOUBLEREC_$__$$_GETEXP$$QWORD(arg1) - 0x3ff);
    
    return r12;
}

uint64_t SYSTEM$_$TDOUBLEREC_$__$$_GETEXP$$QWORD(int64_t* arg1)
{
    return ((*arg1 & 0x7ff0000000000000) >> 0x34);
}

int64_t* SYSTEM$_$TDOUBLEREC_$__$$_SETEXP$QWORD(int64_t* arg1, int64_t arg2)
{
    *arg1 = ((*arg1 & 0x800fffffffffffff) | ((arg2 & 0x7ff) << 0x34));
    return arg1;
}

int64_t SYSTEM$_$TDOUBLEREC_$__$$_GETSIGN$$BOOLEAN(int64_t* arg1)
{
    int64_t result;
    result = (*arg1 & 0x8000000000000000) != 0;
    return result;
}

int64_t* SYSTEM$_$TDOUBLEREC_$__$$_SETSIGN$BOOLEAN(int64_t* arg1, char arg2)
{
    *arg1 = ((*arg1 & 0x7fffffffffffffff) | (arg2 << 0x3f));
    return arg1;
}

int64_t SYSTEM$_$TDOUBLEREC_$__$$_GETFRAC$$QWORD(int64_t* arg1)
{
    return (*arg1 & 0xfffffffffffff);
}

int64_t* SYSTEM$_$TDOUBLEREC_$__$$_SETFRAC$QWORD(int64_t* arg1, int64_t arg2)
{
    *arg1 = ((*arg1 & 0x7ff0000000000000) | (arg2 & 0xfffffffffffff));
    return arg1;
}

uint64_t SYSTEM$_$TDOUBLEREC_$__$$_SPECIALTYPE$$TFLOATSPECIAL(int64_t* arg1)
{
    uint64_t rax = SYSTEM$_$TDOUBLEREC_$__$$_GETEXP$$QWORD(arg1);
    int32_t r12;
    
    if (rax == 0)
    {
        if (SYSTEM$_$TDOUBLEREC_$__$$_MANTISSA$BOOLEAN$$QWORD(arg1, 0) != 0)
            r12 = *(&TC_$SYSTEM$_$TDOUBLEREC_$_SPECIALTYPE$$TFLOATSPECIAL_$$_DENORMAL + (SYSTEM$_$TDOUBLEREC_$__$$_GETSIGN$$BOOLEAN(arg1) << 2));
        else if (SYSTEM$_$TDOUBLEREC_$__$$_GETSIGN$$BOOLEAN(arg1) == 0)
            r12 = 0;
        else
            r12 = 1;
    }
    else if (rax == 0x7ff)
    {
        if (SYSTEM$_$TDOUBLEREC_$__$$_MANTISSA$BOOLEAN$$QWORD(arg1, 0) != 0)
            r12 = 8;
        else if (SYSTEM$_$TDOUBLEREC_$__$$_GETSIGN$$BOOLEAN(arg1) == 0)
            r12 = 6;
        else
            r12 = 7;
    }
    else if (SYSTEM$_$TDOUBLEREC_$__$$_GETSIGN$$BOOLEAN(arg1) == 0)
        r12 = 4;
    else
        r12 = 5;
    
    return r12;
}

int64_t* SYSTEM$_$TDOUBLEREC_$__$$_BUILDUP$BOOLEAN$QWORD$LONGINT(int64_t* arg1, char arg2, int64_t arg3, int32_t arg4)
{
    *arg1 = 0;
    int64_t* result = SYSTEM$_$TDOUBLEREC_$__$$_SETSIGN$BOOLEAN(arg1, arg2);
    
    if ((arg3 == 0 && arg4 == 0))
        return result;
    
    SYSTEM$_$TDOUBLEREC_$__$$_SETEXP$QWORD(arg1, (arg4 + 0x3ff));
    return SYSTEM$_$TDOUBLEREC_$__$$_SETFRAC$QWORD(arg1, (arg3 & 0xfffffffffffff));
}

uint64_t SYSTEM$_$TSINGLEREC_$__$$_MANTISSA$BOOLEAN$$QWORD(int32_t* arg1, char arg2)
{
    int64_t rbx;
    rbx = arg2;
    uint64_t result = (*arg1 & 0x7fffff);
    uint64_t rax_1;
    
    if (result == 0)
        rax_1 = SYSTEM$_$TSINGLEREC_$__$$_GETEXP$$QWORD(arg1);
    
    if (((result != 0 || rax_1 != 0) && rbx != 0))
        return (result | 0x800000);
    
    return result;
}

int80_t SYSTEM$_$TSINGLEREC_$__$$_FRACTION$$EXTENDED(float* arg1)
{
    long double var_28 = *arg1;
    return fpc_frac_real();
}

uint64_t SYSTEM$_$TSINGLEREC_$__$$_EXPONENT$$LONGINT(int32_t* arg1)
{
    int32_t r12 = 0;
    uint64_t rax = SYSTEM$_$TSINGLEREC_$__$$_GETEXP$$QWORD(arg1);
    
    if ((rax <= 0 || rax >= 0xff))
    {
        if ((SYSTEM$_$TSINGLEREC_$__$$_GETEXP$$QWORD(arg1) == 0 && SYSTEM$_$TSINGLEREC_$__$$_GETFRAC$$QWORD(arg1) != 0))
            r12 = -0x7e;
    }
    else
        r12 = (SYSTEM$_$TSINGLEREC_$__$$_GETEXP$$QWORD(arg1) - 0x7f);
    
    return r12;
}

uint64_t SYSTEM$_$TSINGLEREC_$__$$_GETEXP$$QWORD(int32_t* arg1)
{
    return ((*arg1 & 0x7f800000) >> 0x17);
}

int32_t* SYSTEM$_$TSINGLEREC_$__$$_SETEXP$QWORD(int32_t* arg1, char arg2)
{
    *arg1 = ((*arg1 & 0x807fffff) | (arg2 << 0x17));
    return arg1;
}

int64_t SYSTEM$_$TSINGLEREC_$__$$_GETSIGN$$BOOLEAN(int32_t* arg1)
{
    int32_t result;
    result = (*arg1 & 0x80000000) != 0;
    return result;
}

int32_t* SYSTEM$_$TSINGLEREC_$__$$_SETSIGN$BOOLEAN(int32_t* arg1, char arg2)
{
    *arg1 = ((*arg1 & 0x7fffffff) | (arg2 << 0x1f));
    return arg1;
}

uint64_t SYSTEM$_$TSINGLEREC_$__$$_GETFRAC$$QWORD(int32_t* arg1)
{
    return (*arg1 & 0x7fffff);
}

int32_t* SYSTEM$_$TSINGLEREC_$__$$_SETFRAC$QWORD(int32_t* arg1, int32_t arg2)
{
    *arg1 = ((*arg1 & 0xff800000) | (arg2 & 0x7fffff));
    return arg1;
}

uint64_t SYSTEM$_$TSINGLEREC_$__$$_SPECIALTYPE$$TFLOATSPECIAL(int32_t* arg1)
{
    uint64_t rax = SYSTEM$_$TSINGLEREC_$__$$_GETEXP$$QWORD(arg1);
    int32_t r12;
    
    if (rax == 0)
    {
        if (SYSTEM$_$TSINGLEREC_$__$$_MANTISSA$BOOLEAN$$QWORD(arg1, 0) != 0)
            r12 = *(&TC_$SYSTEM$_$TSINGLEREC_$_SPECIALTYPE$$TFLOATSPECIAL_$$_DENORMAL + (SYSTEM$_$TSINGLEREC_$__$$_GETSIGN$$BOOLEAN(arg1) << 2));
        else if (SYSTEM$_$TSINGLEREC_$__$$_GETSIGN$$BOOLEAN(arg1) == 0)
            r12 = 0;
        else
            r12 = 1;
    }
    else if (rax == 0xff)
    {
        if (SYSTEM$_$TSINGLEREC_$__$$_MANTISSA$BOOLEAN$$QWORD(arg1, 0) != 0)
            r12 = 8;
        else if (SYSTEM$_$TSINGLEREC_$__$$_GETSIGN$$BOOLEAN(arg1) == 0)
            r12 = 6;
        else
            r12 = 7;
    }
    else if (SYSTEM$_$TSINGLEREC_$__$$_GETSIGN$$BOOLEAN(arg1) == 0)
        r12 = 4;
    else
        r12 = 5;
    
    return r12;
}

int32_t* SYSTEM$_$TSINGLEREC_$__$$_BUILDUP$BOOLEAN$QWORD$LONGINT(int32_t* arg1, char arg2, int64_t arg3, int32_t arg4)
{
    *arg1 = 0;
    int32_t* result = SYSTEM$_$TSINGLEREC_$__$$_SETSIGN$BOOLEAN(arg1, arg2);
    
    if ((arg3 == 0 && arg4 == 0))
        return result;
    
    SYSTEM$_$TSINGLEREC_$__$$_SETEXP$QWORD(arg1, (arg4 + 0x7f));
    return SYSTEM$_$TSINGLEREC_$__$$_SETFRAC$QWORD(arg1, (arg3 & 0x7fffff));
}

int64_t SYSTEM_$$_ALIGNTOPTR$POINTER$$POINTER(int64_t arg1) __pure
{
    return arg1;
}

int64_t SYSTEM_$$_ALIGNTOQWORD$POINTER$$POINTER(int64_t arg1) __pure
{
    return arg1;
}

char* FPC_SHORTSTR_SETLENGTH(char* arg1, int64_t, int64_t arg3)
{
    if (arg3 > 0xff)
        arg3 = 0xff;
    
    *arg1 = arg3;
    return arg1;
}

uint64_t fpc_shortstr_copy(char* arg1, char* arg2, int64_t arg3, int64_t arg4)
{
    int64_t rdx = arg4;
    
    if (rdx < 0)
        rdx = 0;
    
    int64_t rsi_1;
    
    if (arg3 <= 1)
        rsi_1 = 0;
    else
        rsi_1 = (arg3 - 1);
    
    if (*arg2 < rsi_1)
        rdx = 0;
    else if ((*arg2 - rsi_1) < rdx)
        rdx = (*arg2 - rsi_1);
    
    *arg1 = rdx;
    return FPC_MOVE(&arg2[(rsi_1 + 1)], &arg1[1], (rdx & 0xff));
}

char* fpc_shortstr_delete(char* arg1, int64_t arg2, int64_t arg3, int64_t arg4)
{
    char* result = arg1;
    
    if ((arg3 > 0 && (*result >= arg3 && arg4 > 0)))
    {
        if ((*result - arg3) < arg4)
            arg4 = ((*result - arg3) + 1);
        
        *result -= arg4;
        
        if (*result >= arg3)
        {
            arg1 = arg3;
            return FPC_MOVE(&result[(arg4 + arg3)], &result[(arg1 & 0xff)], ((*result - arg3) + 1));
        }
    }
    
    return result;
}

int64_t fpc_shortstr_insert(char* arg1, char* arg2, int64_t arg3, int64_t arg4)
{
    int64_t result_1 = arg4;
    
    if (result_1 < 1)
        result_1 = 1;
    
    int64_t result;
    
    if (*arg2 >= result_1)
    {
    label_407135:
        int64_t r12_1 = ((*arg2 - result_1) + 1);
        uint64_t r13_1 = *arg1;
        
        if ((*arg1 + *arg2) >= (arg3 + 1))
        {
            int64_t rax_10 = (((*arg2 + *arg1) - (arg3 + 1)) + 1);
            
            if (r12_1 >= rax_10)
                r12_1 -= rax_10;
            else
            {
                r13_1 -= (rax_10 - r12_1);
                r12_1 = 0;
            }
        }
        
        arg3 = r12_1;
        int64_t rcx_1;
        rcx_1 = result_1;
        FPC_MOVE(&arg2[(rcx_1 & 0xff)], &arg2[(result_1 + r13_1)], (arg3 & 0xff));
        FPC_MOVE(&arg1[1], &arg2[result_1], r13_1);
        result = (((result_1 + r13_1) + r12_1) - 1);
        *arg2 = result;
    }
    else
    {
        result = (*arg2 + 1);
        result_1 = result;
        
        if (arg3 >= result_1)
            goto label_407135;
    }
    
    return result;
}

int64_t fpc_shortstr_insert_char(char arg1, char* arg2, int64_t arg3, int64_t arg4)
{
    int64_t rbx;
    rbx = arg1;
    int64_t result_1 = arg4;
    
    if (result_1 < 1)
        result_1 = 1;
    
    int64_t result;
    
    if (*arg2 >= result_1)
    {
    label_407224:
        int64_t r13_1 = ((*arg2 - result_1) + 1);
        
        if (((*arg2 + 1) == (arg3 + 1) && r13_1 > 0))
            r13_1 -= 1;
        
        arg3 = r13_1;
        int64_t rcx;
        rcx = result_1;
        FPC_MOVE(&arg2[(rcx & 0xff)], &arg2[(result_1 + 1)], (arg3 & 0xff));
        arg2[result_1] = rbx;
        result = (result_1 + r13_1);
        *arg2 = result;
    }
    else
    {
        result = (*arg2 + 1);
        result_1 = result;
        
        if (arg3 >= result_1)
            goto label_407224;
    }
    
    return result;
}

int64_t SYSTEM_$$_POS$SHORTSTRING$SHORTSTRING$INT64$$INT64(char* arg1, char* arg2, int64_t arg3)
{
    if ((*arg1 > 0 && (arg3 > 0 && *arg2 >= arg3)))
    {
        uint64_t rbx_1 = (*arg2 - *arg1);
        int64_t result = (arg3 - 1);
        void* r13_1 = &arg2[(arg3 & 0xff)];
        
        while (rbx_1 >= result)
        {
            result += 1;
            uint64_t rax_3;
            rax_3 = arg1[1];
            
            if ((rax_3 == *r13_1 && SYSTEM_$$_COMPARECHAR$formal$formal$INT64$$INT64(&arg1[1], r13_1, *arg1) == 0))
                return result;
            
            r13_1 += 1;
        }
    }
    
    return 0;
}

int64_t SYSTEM_$$_POS$CHAR$SHORTSTRING$INT64$$INT64(char arg1, char* arg2, int64_t arg3)
{
    if ((arg3 >= 1 && *arg2 >= arg3))
    {
        void* rcx_3 = &arg2[arg3];
        uint64_t rsi = *arg2;
        
        if (rsi >= arg3)
        {
            int64_t result = (arg3 - 1);
            
            do
            {
                result += 1;
                
                if (arg1 == *rcx_3)
                    return result;
                
                rcx_3 += 1;
            } while (rsi > result);
        }
    }
    
    return 0;
}

char* fpc_char_copy(char* arg1, char arg2, int64_t arg3, int64_t arg4)
{
    if ((arg3 != 1 || arg4 <= 0))
    {
        *arg1 = 0;
        return arg1;
    }
    
    *arg1 = 1;
    arg1[1] = arg2;
    return arg1;
}

int64_t SYSTEM_$$_POS$SHORTSTRING$CHAR$INT64$$INT64(char* arg1, char arg2, int64_t arg3)
{
    if ((*arg1 == 1 && (arg2 == arg1[1] && arg3 == 1)))
        return 1;
    
    return 0;
}

uint64_t SYSTEM_$$_UPCASE$CHAR$$CHAR(char arg1) __pure
{
    int32_t rax;
    
    if ((arg1 - 0x61) >= 0x1a)
        rax = arg1;
    else
        rax = (arg1 - 0x20);
    
    return (rax & 0xff);
}

int64_t SYSTEM_$$_UPCASE$SHORTSTRING$$SHORTSTRING(char* arg1, char* arg2)
{
    char result = *arg2;
    *arg1 = result;
    uint32_t r13 = *arg2;
    
    if (r13 >= 1)
    {
        int32_t r14_1 = 0;
        
        do
        {
            r14_1 += 1;
            result = SYSTEM_$$_UPCASE$CHAR$$CHAR(arg2[r14_1]);
            arg1[r14_1] = result;
        } while (r13 > r14_1);
    }
    
    return result;
}

uint64_t SYSTEM_$$_LOWERCASE$CHAR$$CHAR(char arg1) __pure
{
    int32_t rax;
    
    if ((arg1 - 0x41) >= 0x1a)
        rax = arg1;
    else
        rax = (arg1 + 0x20);
    
    return (rax & 0xff);
}

int64_t SYSTEM_$$_LOWERCASE$SHORTSTRING$$SHORTSTRING(char* arg1, char* arg2)
{
    char result = *arg2;
    *arg1 = result;
    uint32_t r13 = *arg2;
    
    if (r13 >= 1)
    {
        int32_t r14_1 = 0;
        
        do
        {
            r14_1 += 1;
            result = SYSTEM_$$_LOWERCASE$CHAR$$CHAR(arg2[r14_1]);
            arg1[r14_1] = result;
        } while (r13 > r14_1);
    }
    
    return result;
}

void SYSTEM_$$_HEXSTR$LONGINT$BYTE$$SHORTSTRING(char* arg1, uint32_t arg2, char arg3)
{
    *arg1 = arg3;
    uint32_t rdx = arg3;
    
    if (rdx >= 1)
    {
        int32_t i = (rdx + 1);
        
        do
        {
            i -= 1;
            uint64_t rcx_2;
            rcx_2 = TC_$SYSTEM_$$_HEXTBL[(arg2 & 0xf)];
            arg1[i] = rcx_2;
            arg2 u>>= 4;
        } while (i > 1);
    }
}

void SYSTEM_$$_OCTSTR$LONGINT$BYTE$$SHORTSTRING(char* arg1, uint32_t arg2, char arg3)
{
    *arg1 = arg3;
    uint32_t rdx = arg3;
    
    if (rdx >= 1)
    {
        int32_t i = (rdx + 1);
        
        do
        {
            i -= 1;
            uint64_t rcx_2;
            rcx_2 = TC_$SYSTEM_$$_HEXTBL[(arg2 & 7)];
            arg1[i] = rcx_2;
            arg2 u>>= 3;
        } while (i > 1);
    }
}

void SYSTEM_$$_BINSTR$LONGINT$BYTE$$SHORTSTRING(char* arg1, uint32_t arg2, char arg3)
{
    *arg1 = arg3;
    uint32_t rdx = arg3;
    
    if (rdx >= 1)
    {
        int32_t i = (rdx + 1);
        
        do
        {
            i -= 1;
            arg1[i] = ((arg2 & 1) + 0x30);
            arg2 u>>= 1;
        } while (i > 1);
    }
}

void SYSTEM_$$_HEXSTR$INT64$BYTE$$SHORTSTRING(char* arg1, uint64_t arg2, char arg3)
{
    *arg1 = arg3;
    uint32_t rdx = arg3;
    
    if (rdx >= 1)
    {
        int32_t i = (rdx + 1);
        
        do
        {
            i -= 1;
            int64_t rcx_2;
            rcx_2 = TC_$SYSTEM_$$_HEXTBL[(arg2 & 0xf)];
            arg1[i] = rcx_2;
            arg2 u>>= 4;
        } while (i > 1);
    }
}

void SYSTEM_$$_OCTSTR$INT64$BYTE$$SHORTSTRING(char* arg1, uint64_t arg2, char arg3)
{
    *arg1 = arg3;
    uint32_t rdx = arg3;
    
    if (rdx >= 1)
    {
        int32_t i = (rdx + 1);
        
        do
        {
            i -= 1;
            int64_t rcx_2;
            rcx_2 = TC_$SYSTEM_$$_HEXTBL[(arg2 & 7)];
            arg1[i] = rcx_2;
            arg2 u>>= 3;
        } while (i > 1);
    }
}

void SYSTEM_$$_BINSTR$INT64$BYTE$$SHORTSTRING(char* arg1, uint64_t arg2, char arg3)
{
    *arg1 = arg3;
    uint32_t rdx = arg3;
    
    if (rdx >= 1)
    {
        int32_t i = (rdx + 1);
        
        do
        {
            i -= 1;
            arg1[i] = ((arg2 & 1) + 0x30);
            arg2 u>>= 1;
        } while (i > 1);
    }
}

int64_t SYSTEM_$$_HEXSTR$QWORD$BYTE$$SHORTSTRING(char* arg1, uint64_t arg2, char arg3)
{
    return SYSTEM_$$_HEXSTR$INT64$BYTE$$SHORTSTRING(arg1, arg2, arg3);
}

int64_t SYSTEM_$$_OCTSTR$QWORD$BYTE$$SHORTSTRING(char* arg1, uint64_t arg2, char arg3)
{
    return SYSTEM_$$_OCTSTR$INT64$BYTE$$SHORTSTRING(arg1, arg2, arg3);
}

int64_t SYSTEM_$$_BINSTR$QWORD$BYTE$$SHORTSTRING(char* arg1, uint64_t arg2, char arg3)
{
    return SYSTEM_$$_BINSTR$INT64$BYTE$$SHORTSTRING(arg1, arg2, arg3);
}

int64_t SYSTEM_$$_HEXSTR$POINTER$$SHORTSTRING(char* arg1, uint64_t arg2)
{
    *arg1 = 0x10;
    int32_t i;
    
    for (i = 0x11; i > 1; )
    {
        i -= 1;
        int64_t rcx_2;
        rcx_2 = TC_$SYSTEM_$$_HEXTBL[(arg2 & 0xf)];
        arg1[i] = rcx_2;
        arg2 u>>= 4;
    }
    
    return i;
}

int64_t SYSTEM_$$_SPACE$BYTE$$SHORTSTRING(char* arg1, char arg2)
{
    *arg1 = arg2;
    return SYSTEM_$$_FILLCHAR$formal$INT64$CHAR(&arg1[1], arg2, 0x20);
}

uint64_t FPC_SHORTSTR_SINT(int64_t arg1, int64_t arg2, char* arg3, int64_t arg4)
{
    SYSTEM_$$_INT_STR$INT64$OPENSTRING(arg1, arg3, arg4);
    uint64_t result = *arg3;
    
    if (result >= arg2)
        return result;
    
    void var_118;
    SYSTEM_$$_SPACE$BYTE$$SHORTSTRING(&var_118, (arg2 - *arg3));
    void var_218;
    fpc_shortstr_concat(&var_218, 0xff, &var_118, arg3);
    return FPC_SHORTSTR_TO_SHORTSTR(arg3, arg4, &var_218);
}

uint64_t FPC_SHORTSTR_UINT(uint64_t arg1, int64_t arg2, char* arg3, int64_t arg4)
{
    SYSTEM_$$_INT_STR_UNSIGNED$QWORD$OPENSTRING(arg1, arg3, arg4);
    uint64_t result = *arg3;
    
    if (result >= arg2)
        return result;
    
    void var_118;
    SYSTEM_$$_SPACE$BYTE$$SHORTSTRING(&var_118, (arg2 - *arg3));
    void var_218;
    fpc_shortstr_concat(&var_218, 0xff, &var_118, arg3);
    return FPC_SHORTSTR_TO_SHORTSTR(arg3, arg4, &var_218);
}

int64_t SYSTEM_$$_DIY_UTIL_ADD$LONGWORD$QWORD$LONGWORD$QWORD(int32_t* arg1, int64_t* arg2, int32_t arg3, int64_t arg4)
{
    int64_t result = (*arg2 + arg4);
    arg4 = result < *arg2;
    *arg1 = ((arg3 + *arg1) + (arg4 & 0xff));
    *arg2 = result;
    return result;
}

int32_t* SYSTEM_$$_DIY_UTIL_SHL$LONGWORD$QWORD$SMALLINT(int32_t* arg1, int64_t* arg2, int16_t arg3)
{
    if (arg3 != 0)
    {
        if (arg3 == 1)
        {
            int64_t rcx_2 = (*arg2 * 2);
            int64_t rdi;
            rdi = rcx_2 < *arg2;
            *arg1 = ((rdi & 0xff) + (*arg1 * 2));
            *arg2 = rcx_2;
            return arg1;
        }
        
        if (arg3 >= 0x40)
        {
            if (arg3 <= 0x40)
                *arg1 = *arg2;
            else
                *arg1 = (*arg2 << (arg3 - 0x40));
            
            *arg2 = 0;
            return arg1;
        }
        
        if (arg3 == 0x20)
            *arg1 = (*arg2 >> 0x20);
        else if (arg3 >= 0x20)
            *arg1 = (*arg2 >> (0x40 - arg3));
        else
        {
            char rdi_5 = arg3;
            *arg1 = ((*arg1 << rdi_5) + ((*arg2 >> 0x20) >> (0x20 - rdi_5)));
        }
        
        *arg2 <<= arg3;
    }
    
    return arg1;
}

int32_t* SYSTEM_$$_DIY_UTIL_SHR$LONGWORD$QWORD$SMALLINT(int32_t* arg1, uint64_t* arg2, int16_t arg3)
{
    if (arg3 != 0)
    {
        if (arg3 == 1)
        {
            *arg2 u>>= 1;
            
            if ((*arg1 & 1) != 0)
                *arg2 |= 0x8000000000000000;
            
            *arg1 u>>= 1;
            return arg1;
        }
        
        if (arg3 < 0x40)
        {
            int64_t rdi = arg3;
            *arg2 = ((*arg1 << (-(rdi) & 0x3f)) | (*arg2 >> rdi));
            
            if (arg3 >= 0x20)
            {
                *arg1 = 0;
                return arg1;
            }
            
            *arg1 u>>= arg3;
            return arg1;
        }
        
        if (arg3 >= 0x60)
            *arg2 = 0;
        else
            *arg2 = (*arg1 >> (arg3 & 0x3f));
        
        *arg1 = 0;
    }
    
    return arg1;
}

int64_t SYSTEM_$$_DIY_FP_MULTIPLY$TDIY_FP$TDIY_FP$BOOLEAN$$TDIY_FP(int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4, char arg5) __pure
{
    int64_t r15;
    r15 = arg5;
    int32_t rax = arg2;
    uint32_t rax_2 = (arg1 >> 0x20);
    int32_t r11 = arg4;
    uint32_t r8_1 = (arg3 >> 0x20);
    int64_t result;
    int64_t* var_38 = &result;
    int64_t* var_38_1 = &result;
    int64_t r9_3 = (rax_2 * r11);
    int64_t* var_38_2 = &result;
    int64_t rbx_2 = (arg1 * r11);
    int64_t* var_38_3 = &result;
    int64_t rbx_4 = (rax * r8_1);
    int64_t* var_38_4 = &result;
    int64_t r14_1 = (rax_2 * r8_1);
    int64_t* var_38_5 = &result;
    int64_t r14_3 = (arg1 * r8_1);
    int64_t* var_38_6 = &result;
    int64_t r12_2 = (rax * arg3);
    int64_t* var_38_7 = &result;
    int64_t rax_4 = (rax_2 * arg3);
    int64_t* var_38_8 = &result;
    int64_t rdx_8 = (((((r14_3 + (((arg1 * arg3) >> 0x20) + rax_4)) >> 0x20) + 0x80000000) + (rax_4 >> 0x20)) + (r14_3 >> 0x20));
    uint64_t rdx_15 = (((((((rdx_8 + r12_2) + r14_1) + rbx_2) >> 0x20) + (r12_2 >> 0x20)) + (r14_1 >> 0x20)) + (rbx_2 >> 0x20));
    uint64_t rdx_17 = ((rdx_15 + rbx_4) + r9_3);
    int64_t rax_33 = ((rdx_17 >> 0x20) + (((rbx_4 >> 0x20) + (rax * r11)) + (r9_3 >> 0x20)));
    result = (rdx_17 + (rax_33 << 0x20));
    uint32_t var_40 = (rax_33 >> 0x20);
    
    if ((r15 != 0 && (var_40 & 0x80000000) == 0))
    {
        int64_t result_1 = (result * 2);
        int64_t rsi;
        rsi = result_1 < result;
        var_40 = ((rsi & 0xff) + (var_40 * 2));
        result = result_1;
        int16_t var_3c_1 = ((((arg2 << 0x10) >> 0x30) + ((arg4 << 0x10) >> 0x30)) + 0x5f);
    }
    
    return result;
}

int64_t SYSTEM$_$DIY_FP_MULTIPLY$TDIY_FP$TDIY_FP$BOOLEAN$$TDIY_FP_$$_U32_MUL_U32_TO_U64$crc8C43652A(int64_t arg1, int32_t arg2, int32_t arg3) __pure
{
    int64_t var_8 = arg1;
    return (arg2 * arg3);
}

uint64_t SYSTEM_$$_DIY_FP_CACHED_POWER10$SMALLINT$TDIY_FP_POWER_OF_10(int16_t arg1, int64_t* arg2)
{
    int16_t rcx = (data_427940 + data_427c28);
    int64_t rbx;
    
    if (rcx < arg1)
    {
        int16_t rdx_3 = ((arg1 - rcx) / 0x25);
        rbx = rdx_3;
        
        if (((rdx_3 * 0x25) + rcx) != arg1)
            rbx += 1;
        
        if (rbx > 0x10f)
            rbx = 0x10f;
    }
    else
        rbx = 0;
    
    int16_t temp1 = (rbx % 0x10);
    int64_t r13 = rbx;
    uint64_t result;
    
    if (((r13 + ((r13 >> 0x3f) & 0xf)) >> 4) != 8)
    {
        int64_t rcx_3 = (temp1 * 0x18);
        int64_t rax_14 = *(&TC_$SYSTEM$_$DIY_FP_CACHED_POWER10$SMALLINT$TDIY_FP_POWER_OF_10_$$_BASE + rcx_3);
        int64_t rax_15 = *(rcx_3 + 0x427938);
        int16_t rax_16 = *(rcx_3 + &data_427940);
        
        if ((((r13 + ((r13 >> 0x3f) & 0xf)) >> 4) - 8) <= 0)
        {
            int16_t rax_27 = -(((((r13 + ((r13 >> 0x3f) & 0xf)) >> 4) - 8) + 1));
            arg2[2] = (*((rax_27 * 0x18) + 0x427b80) + rax_16);
            
            if (rax_16 == 0)
            {
                int64_t rcx_9 = (rax_27 * 0x18);
                *arg2 = *(&TC_$SYSTEM$_$DIY_FP_CACHED_POWER10$SMALLINT$TDIY_FP_POWER_OF_10_$$_FACTOR_MINUS + rcx_9);
                result = *(rcx_9 + 0x427b78);
                arg2[1] = result;
            }
            else
            {
                int64_t rcx_7 = (rax_27 * 0x18);
                int64_t rax_33;
                int64_t rdx_12;
                rax_33 = SYSTEM_$$_DIY_FP_MULTIPLY$TDIY_FP$TDIY_FP$BOOLEAN$$TDIY_FP(rax_14, rax_15, *(&TC_$SYSTEM$_$DIY_FP_CACHED_POWER10$SMALLINT$TDIY_FP_POWER_OF_10_$$_FACTOR_MINUS + rcx_7), *(rcx_7 + 0x427b78), 1);
                *arg2 = rax_33;
                arg2[1] = rdx_12;
            label_407df4:
                result = *(&TC_$SYSTEM$_$DIY_FP_CACHED_POWER10$SMALLINT$TDIY_FP_POWER_OF_10_$$_CORRECTOR + rbx);
                
                if (result != 0)
                {
                    int32_t rdi_3 = 0;
                    
                    if (result < 0)
                        rdi_3 = -1;
                    
                    result = (result + *arg2);
                    int64_t rsi_5;
                    rsi_5 = result < *arg2;
                    arg2[1] = ((rsi_5 & 0xff) + (rdi_3 + arg2[1]));
                    *arg2 = result;
                }
            }
        }
        else
        {
            arg2[2] = (*(((((r13 + ((r13 >> 0x3f) & 0xf)) >> 4) - 9) * 0x18) + 0x427ac0) + rax_16);
            
            if (rax_16 != 0)
            {
                int64_t rcx_4 = ((((r13 + ((r13 >> 0x3f) & 0xf)) >> 4) - 9) * 0x18);
                int64_t rax_22;
                int64_t rdx_9;
                rax_22 = SYSTEM_$$_DIY_FP_MULTIPLY$TDIY_FP$TDIY_FP$BOOLEAN$$TDIY_FP(rax_14, rax_15, *(&TC_$SYSTEM$_$DIY_FP_CACHED_POWER10$SMALLINT$TDIY_FP_POWER_OF_10_$$_FACTOR_PLUS + rcx_4), *(rcx_4 + 0x427ab8), 1);
                *arg2 = rax_22;
                arg2[1] = rdx_9;
                goto label_407df4;
            }
            
            int64_t rax_24 = ((((r13 + ((r13 >> 0x3f) & 0xf)) >> 4) - 9) * 0x18);
            *arg2 = *(&TC_$SYSTEM$_$DIY_FP_CACHED_POWER10$SMALLINT$TDIY_FP_POWER_OF_10_$$_FACTOR_PLUS + rax_24);
            result = *(rax_24 + 0x427ab8);
            arg2[1] = result;
        }
    }
    else
    {
        int64_t rcx_2 = (temp1 * 0x18);
        *arg2 = *(&TC_$SYSTEM$_$DIY_FP_CACHED_POWER10$SMALLINT$TDIY_FP_POWER_OF_10_$$_BASE + rcx_2);
        arg2[1] = *(rcx_2 + 0x427938);
        result = *(rcx_2 + &data_427940);
        arg2[2] = result;
    }
    
    return result;
}

char* SYSTEM_$$_STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING(int16_t arg1, int16_t arg2, int32_t arg3, char* arg4, int64_t arg5, uint64_t arg6, int16_t arg7)
{
    int16_t var_100 = arg1;
    int16_t var_118 = arg2;
    
    if (var_118 > 0xd8)
        var_118 = 0xd8;
    
    if (var_100 <= 0x8001)
        var_100 = 0xffff;
    else if (var_100 < 0)
        var_100 = 0;
    else if (var_100 > 0xff)
        var_100 = 0xff;
    
    arg2 = *("\n" + (arg3 << 2));
    int16_t rdx = *((arg3 << 2) + 0x4278f2);
    int64_t r15;
    r15 = data_4278f8;
    
    if (r15 > arg2)
        r15 = arg2;
    
    int16_t var_108;
    
    if (var_100 >= 0)
    {
        int16_t rdx_3 = ((var_100 - 4) - rdx);
        var_108 = rdx_3;
        
        if (rdx_3 < 2)
            var_108 = 2;
        
        if (arg2 < var_108)
            var_108 = arg2;
    }
    else
        var_108 = arg2;
    
    int64_t __saved_rbp;
    int64_t* var_d0 = &__saved_rbp;
    uint64_t rax_3;
    rax_3 = arg7;
    int16_t var_e0 = rax_3;
    rax_3 = *var_e0[1];
    rax_3 &= 0x80;
    bool var_68 = rax_3 != 0;
    int16_t var_bc = (var_e0 & 0x7fff);
    uint64_t var_38 = arg6;
    char* var_30 = 0;
    char* result;
    char var_b4;
    
    if ((*var_30[4] != 0 || var_38 != 0))
    {
        result = *var_30[4];
        
        if ((result != 0 && (result != 0x7fff && (var_38 & 0x8000000000000000) == 0)))
        {
            var_38 = -1;
            *var_30[4] = 0x7fff;
        }
        
        int32_t rbx;
        
        if (*var_30[4] == 0x7fff)
        {
            if (var_100 < 0)
                var_100 = ((*((arg3 << 2) + 0x4278f2) + *("\n" + (arg3 << 2))) + 4);
            
            rbx = (1 - (var_68 << 1));
            
            if (var_38 != -0x8000000000000000)
                return SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_RETURN_SPECIAL$crcC5D552AE(&__saved_rbp, arg4, arg5, 0, &TC_$SYSTEM_$$_C_STR_QNAN, var_100);
            
            return SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_RETURN_SPECIAL$crcC5D552AE(&__saved_rbp, arg4, arg5, rbx, &TC_$SYSTEM_$$_C_STR_INF, var_100);
        }
        
        int16_t temp0_1 = *var_30[4];
        
        if (temp0_1 == 0)
        {
            int64_t* var_c8_1 = &__saved_rbp;
            uint64_t rflags_1;
            int16_t rdx_9;
            rdx_9 = _bit_scan_reverse(var_38);
            
            if (temp0_1 == 0)
                rdx_9 = 0xff;
            
            rbx = ((0x3f - rdx_9) + 0x20);
            *var_30[4] += 1;
        }
        else
            rbx = 0x20;
        
        SYSTEM_$$_DIY_UTIL_SHL$LONGWORD$QWORD$SMALLINT(&var_30, &var_38, rbx);
        *var_30[4] -= (rbx + 0x403e);
        int16_t rax_24 = *var_30[4];
        int16_t var_50;
        uint64_t var_48_1;
        int48_t var_40_1;
        
        if ((rax_24 < 0xffa3 || rax_24 > 0x1e))
        {
            int64_t* rdi_5;
            rdi_5 = SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_K_COMP$crc4E37563F(&__saved_rbp, *var_30[4], 0xffa3);
            int64_t var_60;
            SYSTEM_$$_DIY_FP_CACHED_POWER10$SMALLINT$TDIY_FP_POWER_OF_10(rdi_5, &var_60);
            
            if (var_50 != 0)
            {
                int64_t var_58;
                int64_t rax_30;
                int48_t rdx_12;
                rax_30 = SYSTEM_$$_DIY_FP_MULTIPLY$TDIY_FP$TDIY_FP$BOOLEAN$$TDIY_FP(var_38, var_30, var_60, var_58, 0);
                var_48_1 = rax_30;
                var_40_1 = rdx_12;
            }
            else
            {
                var_48_1 = var_38;
                var_40_1 = var_30;
            }
        }
        else
        {
            var_48_1 = var_38;
            var_40_1 = var_30;
            var_50 = 0;
        }
        
        uint64_t var_70 = var_48_1;
        int32_t var_84 = var_40_1;
        uint64_t var_80;
        
        if (*var_40_1[4] <= 0)
        {
            SYSTEM_$$_DIY_UTIL_SHR$LONGWORD$QWORD$SMALLINT(&var_84, &var_70, -(*var_40_1[4]));
            var_80 = var_84;
        }
        else
        {
            var_80 = ((var_84 << *var_40_1[4]) & 0xffffffff00000000);
            SYSTEM_$$_DIY_UTIL_SHL$LONGWORD$QWORD$SMALLINT(&var_84, &var_70, *var_40_1[4]);
            var_80 += var_84;
        }
        
        int16_t var_64;
        
        if (var_80 != 0)
        {
            SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_U128_DIV_U64_TO_U64$crc483E5B8C(&__saved_rbp, var_80, var_70, -0x7538dcfb76180000, &var_80, &var_70);
            uint64_t r8_6;
            r8_6 = 0;
            int16_t rax_35;
            uint64_t r8_7;
            rax_35 = SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_GEN_DIGITS_64$crc14DEFC16(&__saved_rbp, &var_b4, 0, var_80, r8_6);
            var_64 = rax_35;
            r8_7 = rax_35 > 0;
            result = SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_GEN_DIGITS_64$crc14DEFC16(&__saved_rbp, &var_b4, var_64, var_70, r8_7);
            var_64 += result;
        }
        else
        {
            uint64_t r8_3;
            r8_3 = 0;
            var_64 = SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_GEN_DIGITS_64$crc14DEFC16(&__saved_rbp, &var_b4, 0, var_70, r8_3);
        }
        
        int64_t r14;
        r14 = var_64;
        int32_t r12_1 = 0;
        
        if (*var_40_1[4] < 0)
        {
            rbx = *var_40_1[4];
            int64_t* var_c8_2 = &__saved_rbp;
            int32_t var_88;
            uint64_t var_78;
            
            if (*var_40_1[4] > 0xffc0)
            {
                var_78 = ((1 << -(*var_40_1[4])) - 1);
                var_88 = 0;
            }
            else
            {
                var_78 = -1;
                var_88 = ((1 << (-(*var_40_1[4]) - 0x40)) - 1);
            }
            
            var_70 = (var_78 & var_48_1);
            var_84 = (var_88 & var_40_1);
            
            while (rbx < 0xffc3)
            {
                if ((r15 + 1) <= var_64)
                    break;
                
                if ((var_84 | var_70) == 0)
                    break;
                
                var_80 = var_70;
                int32_t var_8c = var_84;
                SYSTEM_$$_DIY_UTIL_SHL$LONGWORD$QWORD$SMALLINT(&var_84, &var_70, 2);
                uint64_t rcx_9 = (var_70 + var_80);
                uint64_t rax_51;
                rax_51 = rcx_9 < var_70;
                var_84 = ((var_84 + var_8c) + rax_51);
                var_70 = rcx_9;
                SYSTEM_$$_DIY_UTIL_SHR$LONGWORD$QWORD$SMALLINT(&var_88, &var_78, 1);
                rbx += 1;
                var_80 = var_70;
                var_8c = var_84;
                SYSTEM_$$_DIY_UTIL_SHR$LONGWORD$QWORD$SMALLINT(&var_8c, &var_80, -(rbx));
                &var_b4[var_64] = var_80;
                var_70 &= var_78;
                var_84 &= var_88;
                var_64 += 1;
            }
            
            if ((r15 + 1) > var_64)
            {
                while (rbx < 0xffe3)
                {
                    if ((r15 + 1) <= var_64)
                        break;
                    
                    if (var_70 == 0)
                        break;
                    
                    var_70 *= 5;
                    var_78 u>>= 1;
                    rbx += 1;
                    uint64_t rdx_32;
                    rdx_32 = (var_70 >> -(rbx));
                    &var_b4[var_64] = rdx_32;
                    var_70 &= var_78;
                    var_64 += 1;
                }
                
                if ((r15 + 1) > var_64)
                {
                    uint32_t r13_1 = var_78;
                    r12_1 = var_70;
                    
                    while ((r15 + 1) > var_64)
                    {
                        if (r12_1 == 0)
                            break;
                        
                        int32_t r12_2 = (r12_1 * 5);
                        r13_1 u>>= 1;
                        rbx += 1;
                        &var_b4[var_64] = (r12_2 >> -(rbx));
                        r12_1 = (r13_1 & r12_2);
                        var_64 += 1;
                    }
                }
                else
                {
                    int64_t rax_84;
                    rax_84 = var_70 != 0;
                    r12_1 = (rax_84 & 0xff);
                }
            }
            else
            {
                uint64_t rax_71;
                rax_71 = (var_84 | var_70) != 0;
                r12_1 = (rax_71 & 0xff);
            }
        }
        
        if ((r12_1 != 0 && (r15 + 1) <= var_64))
        {
            var_64 = (r15 + 2);
            void var_b3;
            *(&var_b3 + r15) = 1;
        }
        
        if (r15 < var_64)
            r14 += SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_ROUND_DIGITS$crcBF8CE791(&__saved_rbp, &var_b4, &var_64, r15, 1);
        
        if (var_118 < 0)
        {
        label_408695:
            result = var_108;
            
            if (result < var_64)
                r14 += SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_ROUND_DIGITS$crcBF8CE791(&__saved_rbp, &var_b4, &var_64, var_108, 0);
            
            result = var_100;
            int16_t var_150_2 = result;
            result = rdx;
            int16_t var_158_4 = result;
            result = var_108;
            return SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_RETURN_EXPONENTIAL$crcC3D7D0D1(&__saved_rbp, arg4, arg5, var_68, &var_b4, var_64, result, ((r14 - var_50) - 1), var_158_4, var_150_2);
        }
        
        result = var_118;
        int16_t var_158_3 = result;
        result = var_100;
        result = SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_TRY_RETURN_FIXED$crc15F54820(&__saved_rbp, arg4, arg5, var_68, &var_b4, var_64, (r14 - var_50), result, var_158_3);
        
        if (result == 0)
            goto label_408695;
    }
    else
    {
        var_b4 = 0;
        
        if (var_118 < 0)
        {
        label_408044:
            result = var_100;
            int16_t var_150_1 = result;
            result = rdx;
            int16_t var_158_2 = result;
            result = var_108;
            return SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_RETURN_EXPONENTIAL$crcC3D7D0D1(&__saved_rbp, arg4, arg5, var_68, &var_b4, 0, result, 0, var_158_2, var_150_1);
        }
        
        result = var_118;
        int16_t var_158_1 = result;
        result = var_100;
        result = SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_TRY_RETURN_FIXED$crc15F54820(&__saved_rbp, arg4, arg5, var_68, &var_b4, 0, 1, result, var_158_1);
        
        if (result == 0)
            goto label_408044;
    }
    return result;
}

uint64_t SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_K_COMP$crc4E37563F(int64_t arg1, int16_t arg2, int16_t arg3)
{
    int64_t var_8 = arg1;
    int16_t rdx_1 = (arg3 - arg2);
    double zmm0 = (rdx_1 * TC_$SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_K_COMP$SMALLINT$SMALLINT$$SMALLINT_$$_D_LOG10_2);
    int16_t rax_1 = zmm0;
    
    if (rdx_1 > 0)
    {
        double zmm1 = rax_1;
        (zmm0 - zmm1);
        
        if (((FCMP_UO(zmm0, zmm1)) || !(zmm0 == zmm1)))
            rax_1 += 1;
    }
    
    return rax_1;
}

int32_t* SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_MAKE_FRAC_MASK$crc119377E0(int64_t arg1, int32_t* arg2, int64_t* arg3, int16_t arg4)
{
    int64_t var_8 = arg1;
    int32_t* result = arg2;
    arg2 = arg4;
    
    if (arg2 > 0xffc0)
    {
        *arg3 = ((1 << -(arg2)) - 1);
        *result = 0;
    }
    else
    {
        *arg3 = -1;
        *result = ((1 << (-(arg2) - 0x40)) - 1);
    }
    
    return result;
}

uint64_t SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_COUNT_LEADING_ZERO$crc1CF7EDB4(int64_t arg1, uint64_t arg2)
{
    int64_t var_8 = arg1;
    uint64_t rflags;
    int16_t rdx;
    rdx = _bit_scan_reverse(arg2);
    bool z;
    
    if (z)
        rdx = 0xff;
    
    return (0x3f - rdx);
}

uint64_t SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_U128_DIV_U64_TO_U64$crc483E5B8C(int64_t arg1, int64_t arg2, int64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t* arg6)
{
    int64_t var_38 = arg1;
    int64_t r15;
    
    if (arg4 > arg2)
    {
        uint64_t rflags_1;
        int16_t rcx;
        rcx = _bit_scan_reverse(arg4);
        
        if (arg4 == arg2)
            rcx = 0xff;
        
        int64_t r14;
        r14 = (0x3f - rcx);
        uint64_t rax = (arg4 << (0x3f - rcx));
        uint64_t rax_2 = (rax >> 0x20);
        uint64_t rax_3 = rax;
        int64_t rsi = (arg2 << r14);
        
        if (r14 > 0)
            rsi |= (arg3 >> (0x40 - r14));
        
        int64_t rdx = (arg3 << r14);
        uint64_t rax_10 = (rdx >> 0x20);
        uint64_t rdx_1 = rdx;
        uint64_t i = (COMBINE(0, rsi) / rax_2);
        int64_t r13_1 = (rsi - (rax_2 * i));
        
        while ((0x100000000 <= i || ((r13_1 * 0x100000000) + rax_10) < (rax_3 * i)))
        {
            i -= 1;
            r13_1 += rax_2;
            
            if (0x100000000 <= r13_1)
                break;
        }
        
        int64_t rax_20 = (((0x100000000 * rsi) + rax_10) - (rax * i));
        uint64_t i_1 = (COMBINE(0, rax_20) / rax_2);
        int64_t rdx_12 = (rax_20 - (rax_2 * i_1));
        
        while ((0x100000000 <= i_1 || ((rdx_12 * 0x100000000) + rdx_1) < (rax_3 * i_1)))
        {
            i_1 -= 1;
            rdx_12 += rax_2;
            
            if (0x100000000 <= rdx_12)
                break;
        }
        
        *arg6 = ((((0x100000000 * rax_20) + rdx_1) - (rax * i_1)) >> r14);
        *arg5 = ((0x100000000 * i) + i_1);
        r15 = 1;
    }
    else
        r15 = 0;
    
    uint64_t result;
    result = r15;
    return result;
}

char* SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_RETURN_SPECIAL$crcC5D552AE(int64_t arg1, char* arg2, int64_t arg3, int16_t arg4, char* arg5, int16_t arg6)
{
    int64_t rsi = arg3;
    int64_t r13;
    r13 = arg4;
    arg3 = *arg5;
    int64_t r14;
    r14 = arg3;
    
    if (r13 != 0)
        arg3 = (r14 + 1);
    else
        arg3 = r14;
    
    int64_t rbx;
    rbx = (arg6 - arg3);
    
    if ((0xff - arg3) < rbx)
        rbx = (0xff - arg3);
    
    if (rbx > 0)
        arg3 += rbx;
    
    char* result = FPC_SHORTSTR_SETLENGTH(arg2, rsi, arg3);
    int64_t r12;
    r12 = 1;
    
    if (rbx > 0)
    {
        int64_t var_40_1 = arg1;
        result = SYSTEM_$$_FILLCHAR$formal$INT64$CHAR(&arg2[1], rbx, 0x20);
        r12 = (1 + rbx);
    }
    
    if (r13 != 0)
    {
        if (r13 <= 0)
        {
            result = r12;
            *(arg2 + result) = 0x2d;
        }
        else
        {
            result = r12;
            *(arg2 + result) = 0x2b;
        }
        
        r12 += 1;
    }
    
    while (r14 > 0)
    {
        result = ((r14 + r12) - 1);
        uint64_t rcx_1;
        rcx_1 = arg5[r14];
        *(arg2 + result) = rcx_1;
        r14 -= 1;
    }
    
    return result;
}

char* SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_RETURN_EXPONENTIAL$crcC3D7D0D1(int64_t arg1, char* arg2, int64_t arg3, char arg4, char* arg5, int16_t arg6, int16_t arg7, int16_t arg8, int16_t arg9, int16_t arg10)
{
    int64_t r12 = arg3;
    int64_t r13;
    r13 = arg4;
    char* var_68 = arg5;
    int64_t r15;
    r15 = arg6;
    int64_t r14;
    r14 = arg7;
    arg3 = arg8;
    int64_t rbx;
    rbx = arg10;
    bool var_60 = arg3 < 0;
    int16_t rax;
    rax = var_60;
    
    if (rax != 0)
        arg3 = -(arg3);
    
    arg5 = 0;
    void var_38;
    int16_t rax_1 = SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_GEN_DIGITS_32$crc66C340FE(arg1, &var_38, 0, arg3, arg5);
    int16_t rdx_1;
    
    if (arg9 < rax_1)
        rdx_1 = rax_1;
    else
        rdx_1 = arg9;
    
    rdx_1 += (r14 + 3);
    
    if (r14 > 1)
        rdx_1 += 1;
    
    rbx = (rbx - rdx_1);
    
    if ((0xff - rdx_1) < rbx)
        rbx = (0xff - rdx_1);
    
    if (rbx > 0)
        rdx_1 += rbx;
    
    FPC_SHORTSTR_SETLENGTH(arg2, r12, rdx_1);
    r12 = 1;
    
    if (rbx > 0)
    {
        int64_t var_40_1 = arg1;
        SYSTEM_$$_FILLCHAR$formal$INT64$CHAR(&arg2[1], rbx, 0x20);
        r12 = (1 + rbx);
    }
    
    if (r13 == 0)
        arg2[r12] = 0x20;
    else
        arg2[r12] = 0x2d;
    
    r12 += 1;
    
    if (r15 <= 0)
        arg2[r12] = 0x30;
    else
        arg2[r12] = (*var_68 + 0x30);
    
    r12 += 1;
    
    if (r14 > 1)
    {
        arg2[r12] = 0x2e;
        r12 += 1;
    }
    
    uint64_t rcx_2;
    rcx_2 = 1;
    
    while (r15 > rcx_2)
    {
        if (r14 <= rcx_2)
            break;
        
        arg2[r12] = (var_68[rcx_2] + 0x30);
        r12 += 1;
        rcx_2 += 1;
    }
    
    rbx = (r14 - rcx_2);
    
    if (rbx > 0)
    {
        int64_t var_40_2 = arg1;
        SYSTEM_$$_FILLCHAR$formal$INT64$CHAR(&arg2[r12], rbx, 0x30);
        r12 += rbx;
    }
    
    arg2[r12] = 0x45;
    r12 += 1;
    uint64_t rax_22;
    rax_22 = var_60;
    
    if (rax_22 == 0)
        arg2[r12] = 0x2b;
    else
        arg2[r12] = 0x2d;
    
    r12 += 1;
    char* result = rax_1;
    int16_t i = (arg9 - result);
    
    if (i > 0)
    {
        int64_t var_40_3 = arg1;
        result = SYSTEM_$$_FILLCHAR$formal$INT64$CHAR(&arg2[r12], i, 0x30);
        r12 += i;
    }
    
    if ((rax_1 - 1) >= 0)
    {
        i = 0xffff;
        
        do
        {
            i += 1;
            result = arg2;
            result[r12] = (*(&var_38 + i) + 0x30);
            r12 += 1;
        } while ((rax_1 - 1) > i);
    }
    
    return result;
}

uint64_t SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_TRY_RETURN_FIXED$crc15F54820(int64_t arg1, char* arg2, int64_t arg3, char arg4, int64_t arg5, int16_t arg6, int16_t arg7, int16_t arg8, int16_t arg9)
{
    char* var_58 = arg2;
    int64_t r15;
    r15 = arg4;
    int64_t var_60 = arg5;
    int16_t i_2 = arg6;
    int64_t r12;
    r12 = arg7;
    int64_t r13;
    r13 = arg8;
    char var_50 = 0;
    char var_68 = 0;
    int64_t rbx;
    rbx = (r12 + arg9);
    void var_40;
    
    if (rbx < 0)
        i_2 = 0;
    else if (rbx < i_2)
    {
        if (i_2 > 0)
            FPC_MOVE(var_60, &var_40, i_2);
        
        arg5 = 0;
        r12 += SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_ROUND_DIGITS$crcBF8CE791(arg1, &var_40, &i_2, rbx, arg5);
        var_68 = 1;
    }
    
    int16_t i;
    int16_t var_90;
    
    if ((r12 <= 0 || i_2 == 0))
    {
        i = 0;
        var_90 = 1;
    }
    else if (r12 <= i_2)
    {
        i = r12;
        var_90 = 0;
    }
    else
    {
        i = i_2;
        var_90 = (r12 - i_2);
    }
    
    int16_t var_88;
    
    if (r12 >= 0)
        var_88 = 0;
    else
        var_88 = -(r12);
    
    if (arg9 < var_88)
        var_88 = arg9;
    
    int16_t i_1 = (i_2 - i);
    int16_t rdx_8 = ((arg9 - i_1) - var_88);
    int16_t rdx_10 = ((r15 + i) + var_90);
    
    if (arg9 > 0)
        rdx_10 += (((i_1 + var_88) + rdx_8) + 1);
    
    arg2 = (0xff - rdx_10);
    uint64_t result;
    
    if (arg2 >= 0)
    {
        rbx = (r13 - rdx_10);
        
        if (arg2 < rbx)
            rbx = arg2;
        
        if (rbx > 0)
            rdx_10 += rbx;
        
        FPC_SHORTSTR_SETLENGTH(var_58, arg3, rdx_10);
        r12 = 1;
        int16_t rcx_4;
        
        if (rbx > 0)
        {
            int64_t var_48_1 = arg1;
            result = SYSTEM_$$_FILLCHAR$formal$INT64$CHAR(&var_58[1], rbx, 0x20);
            r12 = (1 + rbx);
        }
        
        if (r15 != 0)
        {
            *(var_58 + r12) = 0x2d;
            r12 += 1;
        }
        
        rbx = 0;
        result = var_68;
        
        if (result == 0)
        {
            for (; i > 0; i -= 1)
            {
                rcx_4 = (*(var_60 + rbx) + 0x30);
                *(var_58 + r12) = rcx_4;
                r12 += 1;
                rbx += 1;
            }
        }
        else
        {
            for (; i > 0; i -= 1)
            {
                rcx_4 = (*(&var_40 + rbx) + 0x30);
                var_58[r12] = rcx_4;
                r12 += 1;
                rbx += 1;
            }
        }
        
        if (var_90 > 0)
        {
            int64_t var_48_2 = arg1;
            SYSTEM_$$_FILLCHAR$formal$INT64$CHAR(&var_58[r12], var_90, 0x30);
            r12 += var_90;
        }
        
        result = arg9;
        
        if (result != 0)
        {
            *(var_58 + r12) = 0x2e;
            r12 += 1;
            
            if (var_88 > 0)
            {
                int64_t var_48_3 = arg1;
                SYSTEM_$$_FILLCHAR$formal$INT64$CHAR(&var_58[r12], var_88, 0x30);
                r12 += var_88;
            }
            
            result = var_68;
            
            if (result == 0)
            {
                for (; i_1 > 0; i_1 -= 1)
                {
                    var_58[r12] = (*(var_60 + rbx) + 0x30);
                    r12 += 1;
                    rbx += 1;
                }
            }
            else
            {
                for (; i_1 > 0; i_1 -= 1)
                {
                    var_58[r12] = (*(&var_40 + rbx) + 0x30);
                    r12 += 1;
                    rbx += 1;
                }
            }
            
            if (rdx_8 > 0)
            {
                int64_t var_48_4 = arg1;
                SYSTEM_$$_FILLCHAR$formal$INT64$CHAR(&var_58[r12], rdx_8, 0x30);
            }
        }
        
        var_50 = 1;
    }
    
    result = var_50;
    return result;
}

int64_t SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_DO_FILLCHAR$crcEDFA6FCF(int64_t arg1, int64_t arg2, char arg3, char arg4, int16_t arg5, char arg6)
{
    int64_t var_8 = arg1;
    int64_t rax = arg2;
    arg2 = arg5;
    return SYSTEM_$$_FILLCHAR$formal$INT64$CHAR((rax + arg4), arg2, arg6);
}

uint64_t SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_ROUND_DIGITS$crcBF8CE791(int64_t arg1, char* arg2, int16_t* arg3, int16_t arg4, char arg5)
{
    int64_t var_8 = arg1;
    int16_t rax = 0;
    int16_t r9 = *arg3;
    *arg3 = arg4;
    char r11 = arg2[arg4];
    
    if ((arg5 == 0 && (r11 == 4 && ((r9 - 3) > arg4 && arg2[(r9 - 2)] >= 8))))
    {
        int16_t rdi_5 = (r9 - 2);
        
        do
        {
            rdi_5 -= 1;
            
            if (arg4 == rdi_5)
                break;
        } while (arg2[rdi_5] == 9);
        
        if (arg4 == rdi_5)
            r11 = 9;
    }
    
    if (r11 >= 5)
    {
        if ((r11 != 5 || arg5 == 0))
        {
        label_4092c3:
            
            while (true)
            {
                if (arg4 <= 0)
                {
                    *arg2 = 1;
                    *arg3 = 1;
                    rax = 1;
                    break;
                }
                
                arg4 -= 1;
                uint64_t rdi_10 = arg4;
                arg2[rdi_10] += 1;
                
                if (arg2[arg4] < 0xa)
                {
                    *arg3 = (arg4 + 1);
                    break;
                }
            }
        }
        else
        {
            int64_t rdi_6;
            
            if (arg4 != 0)
            {
                rdi_6 = *((arg2 + arg4) - 1);
                rdi_6 &= 1;
            }
            
            if ((arg4 != 0 && rdi_6 != 0))
                goto label_4092c3;
            
            int64_t r10;
            r10 = 0;
            
            while ((arg4 + 1) < r9)
            {
                if (r10 != 0)
                    break;
                
                r9 -= 1;
                r10 = arg2[r9];
            }
            
            if (r10 != 0)
                goto label_4092c3;
        }
    }
    
    return rax;
}

uint64_t SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_GEN_DIGITS_64$crc14DEFC16(int64_t arg1, char* arg2, int16_t arg3, int64_t arg4, uint64_t arg5)
{
    int64_t var_38 = arg1;
    arg1 = arg3;
    int64_t r12;
    r12 = arg5;
    uint32_t var_30;
    uint32_t rcx;
    uint32_t r14;
    
    if (arg4 >= 0x3b9aca00)
    {
        int64_t rax_1;
        int64_t rdx;
        rdx = HIGHQ((0x12e0be826d694b2f * arg4));
        rax_1 = LOWQ((0x12e0be826d694b2f * arg4));
        uint64_t rdx_3 = ((RRCQ((rdx + arg4), 1, (rdx + arg4) < rdx)) >> 0x1d);
        var_30 = (arg4 - (rdx_3 * 0x3b9aca00));
        
        if (rdx_3 >= 0x3b9aca00)
        {
            int64_t rax_4;
            int64_t rdx_4;
            rdx_4 = HIGHQ((0x12e0be826d694b2f * rdx_3));
            rax_4 = LOWQ((0x12e0be826d694b2f * rdx_3));
            rcx = ((RRCQ((rdx_4 + rdx_3), 1, (rdx_4 + rdx_3) < rdx_4)) >> 0x1d);
            r14 = (rdx_3 - (rcx * 0x3b9aca00));
        }
        else
        {
            rcx = 0;
            r14 = rdx_3;
        }
    }
    else
    {
        rcx = 0;
        r14 = 0;
        var_30 = arg4;
    }
    
    int64_t rbx;
    rbx = arg1;
    arg5 = 0;
    int16_t rax_7;
    uint16_t r8_1;
    rax_7 = SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_GEN_DIGITS_32$crc66C340FE(var_38, arg2, arg1, rcx, arg5);
    int64_t r13;
    r13 = rax_7;
    
    if ((r12 != 0 && r13 == 0))
    {
        arg2[rbx] = 0;
        r13 = 1;
    }
    
    r8_1 = r13 != 0;
    int16_t rax_10;
    uint16_t r8_2;
    rax_10 = SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_GEN_DIGITS_32$crc66C340FE(var_38, arg2, (r13 + rbx), r14, r8_1);
    r13 += rax_10;
    r8_2 = r13 != 0;
    r13 += SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_GEN_DIGITS_32$crc66C340FE(var_38, arg2, (rbx + r13), var_30, r8_2);
    return r13;
}

uint64_t SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_GEN_DIGITS_32$crc66C340FE(int64_t arg1, char* arg2, int16_t arg3, uint32_t arg4, uint16_t arg5)
{
    int64_t var_8 = arg1;
    arg1 = arg3;
    uint16_t i;
    
    if (arg4 != 0)
    {
        uint64_t rflags_1;
        int32_t temp0_1;
        temp0_1 = _bit_scan_reverse(arg4);
        int32_t rax_1 = temp0_1;
        
        if (arg4 == 0)
            rax_1 = 0xff;
        
        uint16_t i_1 = (((rax_1 + 1) * 0x4d1) >> 0xc);
        i = i_1;
        
        if (arg4 >= *(&TC_$SYSTEM$_$$CRC079B7A7E_$$_DIGITS + (i_1 << 2)))
            i += 1;
    }
    else
        i = 0;
    
    if ((arg5 != 0 && i < 9))
        i = 9;
    
    arg5 = i;
    
    while (i > 0)
    {
        i -= 1;
        
        if (arg4 == 0)
            arg2[(arg1 + i)] = 0;
        else
        {
            uint32_t rdx_2 = (arg4 / 0xa);
            arg2[(arg1 + i)] = (arg4 - (rdx_2 * 0xa));
            arg4 = rdx_2;
        }
    }
    
    return arg5;
}

int64_t SYSTEM$_$STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING_$$_UNPACK_FLOAT$crc4742DF27(int64_t arg1, bool* arg2, int64_t arg3, int16_t arg4)
{
    int64_t var_10 = arg1;
    int64_t rdx;
    rdx = arg4;
    int16_t var_30 = rdx;
    rdx = *var_30[1];
    rdx &= 0x80;
    *arg2 = rdx != 0;
    int16_t var_14 = (var_30 & 0x7fff);
    int32_t var_18 = 0;
    return arg3;
}

uint16_t SYSTEM_$$_STR_REAL_ISO$LONGINT$LONGINT$EXTENDED$TREAL_TYPE$OPENSTRING(int16_t arg1, int16_t arg2, int32_t arg3, char* arg4, int64_t arg5, uint64_t arg6, int16_t arg7, int16_t arg8)
{
    int16_t var_30 = arg8;
    SYSTEM_$$_STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    uint16_t i = *arg4;
    
    if (i >= 1)
    {
        i += 1;
        
        do
        {
            i -= 1;
            
            if (arg4[i] == 0x45)
            {
                arg4[i] = 0x65;
                break;
            }
        } while (i > 1);
    }
    
    return i;
}

int80_t SYSTEM_$$_VAL_REAL$SHORTSTRING$INT64$$EXTENDED(char* arg1, int64_t* arg2)
{
    int64_t r12;
    int64_t var_10 = r12;
    *arg2 = 1;
    int64_t r15;
    r15 = 1;
    int64_t* rax;
    rax = *arg1;
    int64_t r14;
    r14 = rax;
    int80_t result;
    SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_PACK_FLOAT$EXTENDED$BOOLEAN$SMALLINT$QWORD(&result, &result, 0, 0, 0);
    char var_40 = 0;
    
    while (r14 >= r15)
    {
        r12 = *(r15 + arg1);
        char* rax_1;
        rax_1 = r12;
        
        if (rax_1 >= 0x2b)
        {
            char temp0_1 = rax_1;
            rax_1 -= 0x2b;
            
            if (temp0_1 == 0x2b)
            {
                r15 += 1;
                break;
            }
            
            char temp1_1 = rax_1;
            rax_1 -= 2;
            
            if (temp1_1 == 2)
            {
                var_40 = 1;
                r15 += 1;
                break;
            }
        }
        
        if (r12 != 0x20)
            break;
        
        r15 += 1;
    }
    
    if (r14 >= r15)
    {
        uint64_t rax_3;
        rax_3 = arg1[r15];
        int64_t rbx;
        
        if (rax_3 < 0x2e)
            rbx = 1;
        else
        {
            char temp2_1 = rax_3;
            rax_3 -= 0x2e;
            
            if (temp2_1 == 0x2e)
                rbx = 0;
            else
            {
                char temp3_1 = rax_3;
                rax_3 -= 2;
                
                if (temp3_1 < 2)
                    rbx = 1;
                else
                {
                    char temp4_1 = rax_3;
                    rax_3 -= 9;
                    
                    if (temp4_1 <= 9)
                        rbx = 0;
                    else
                    {
                        char temp5_1 = rax_3;
                        rax_3 -= 0xc;
                        
                        if (temp5_1 == 0xc)
                            rbx = 0;
                        else
                        {
                            char temp6_1 = rax_3;
                            rax_3 -= 0x20;
                            
                            if (temp6_1 != 0x20)
                                rbx = 1;
                            else
                                rbx = 0;
                        }
                    }
                }
            }
        }
        
        if (rbx == 0)
        {
            int64_t var_88_1 = 0;
            uint32_t var_80_1 = 0;
            rax_3 = 0;
            int16_t var_30_1 = 0;
            char rcx_1 = 0;
            char rdx_1 = 0;
            
            while (r14 >= r15)
            {
                if (arg1[r15] != 0x30)
                    break;
                
                r15 += 1;
            }
            
            while (r14 >= r15)
            {
                r12 = *(r15 + arg1);
                
                if (r12 < 0x30)
                    break;
                
                if (r12 > 0x39)
                    break;
                
                if (rax_3 >= 0x1c)
                {
                    if (rax_3 != 0x1c)
                        rdx_1 |= (r12 - 0x30);
                    else
                        rcx_1 = (r12 - 0x30);
                    
                    var_30_1 += 1;
                }
                else
                {
                    int80_t* var_50_1 = &result;
                    uint64_t rsi_9 = ((var_88_1 * 0xa) + (r12 - 0x30));
                    uint64_t rdi_10 = ((((var_88_1 >> 0x20) + (var_80_1 << 0x20)) * 0xa) + (rsi_9 >> 0x20));
                    var_80_1 = (rdi_10 >> 0x20);
                    var_88_1 = (rsi_9 + (rdi_10 << 0x20));
                }
                
                rax_3 += 1;
                r15 += 1;
            }
            
            if ((r14 >= r15 && arg1[r15] == 0x2e))
            {
                r15 += 1;
                
                if (rax_3 == 0)
                {
                    while (r14 >= r15)
                    {
                        if (*(r15 + arg1) != 0x30)
                            break;
                        
                        var_30_1 -= 1;
                        r15 += 1;
                    }
                }
                
                while (r14 >= r15)
                {
                    r12 = *(r15 + arg1);
                    
                    if (r12 < 0x30)
                        break;
                    
                    if (r12 > 0x39)
                        break;
                    
                    if (rax_3 < 0x1c)
                    {
                        int80_t* var_50_2 = &result;
                        uint64_t rsi_18 = ((var_88_1 * 0xa) + (r12 - 0x30));
                        uint64_t rdi_18 = ((((var_88_1 >> 0x20) + (var_80_1 << 0x20)) * 0xa) + (rsi_18 >> 0x20));
                        var_80_1 = (rdi_18 >> 0x20);
                        var_88_1 = (rsi_18 + (rdi_18 << 0x20));
                        var_30_1 -= 1;
                    }
                    else if (rax_3 != 0x1c)
                        rdx_1 |= (r12 - 0x30);
                    else
                        rcx_1 = (r12 - 0x30);
                    
                    rax_3 += 1;
                    r15 += 1;
                }
            }
            
            if ((rcx_1 == 5 && (rdx_1 == 0 && (var_88_1 & 1) == 0)))
                rcx_1 -= 1;
            
            if (rcx_1 >= 5)
            {
                var_88_1 += 1;
                
                if (var_88_1 == 0)
                    var_80_1 += 1;
            }
            
            uint64_t rdx_7 = 0;
            
            if (r14 < r15)
            {
            label_409a54:
                int32_t rax_23 = (var_30_1 + rdx_7);
                int16_t var_30_2;
                
                if ((rdx_7 >= 0x186a0 || rax_23 >= 0x2710))
                    var_30_2 = 0x2710;
                else if ((rdx_7 <= 0xfffe7960 || rax_23 <= 0xffffd8f0))
                    var_30_2 = 0xd8f0;
                else
                    var_30_2 = rax_23;
                
                if (r14 >= r15)
                    *arg2 = r15;
                else if (((var_80_1 | var_88_1) == 0 || var_30_2 <= 0xd8f0))
                {
                    rdx_7 = var_40;
                    SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_PACK_FLOAT$EXTENDED$BOOLEAN$SMALLINT$QWORD(&result, &result, rdx_7, 0, 0);
                    *arg2 = 0;
                }
                else
                {
                    int64_t var_78;
                    int64_t var_60;
                    uint32_t var_58;
                    int16_t var_54;
                    uint32_t r8;
                    
                    if (var_30_2 < 0x2710)
                    {
                        if (var_80_1 != 0)
                        {
                            int80_t* var_50_4 = &result;
                            uint64_t rflags_2;
                            char temp0_2;
                            temp0_2 = _bit_scan_reverse(var_80_1);
                            int16_t rax_32 = temp0_2;
                            
                            if (var_80_1 == 0)
                                rax_32 = 0xff;
                            
                            rbx = (0x1f - rax_32);
                        }
                        else
                        {
                            int80_t* var_50_3 = &result;
                            uint64_t rflags_1;
                            int16_t rax_29;
                            rax_29 = _bit_scan_reverse(var_88_1);
                            
                            if (var_80_1 == 0)
                                rax_29 = 0xff;
                            
                            rbx = ((0x3f - rax_29) + 0x20);
                        }
                        
                        var_60 = var_88_1;
                        var_58 = var_80_1;
                        SYSTEM_$$_DIY_UTIL_SHL$LONGWORD$QWORD$SMALLINT(&var_58, &var_60, rbx);
                        var_54 = -(rbx);
                        int16_t rax_37;
                        rax_37 = SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_FACTOR_10_INEXACT$crcDDB8D7AA(&result, var_30_2, &var_78);
                        r12 = rax_37;
                    }
                    else
                        r12 = 1;
                    
                    if (r12 == 0)
                    {
                        int16_t var_68;
                        
                        if (var_68 != 0)
                        {
                            r8 = 1;
                            int64_t var_70;
                            int64_t rax_38;
                            int64_t rdx_15;
                            rax_38 = SYSTEM_$$_DIY_FP_MULTIPLY$TDIY_FP$TDIY_FP$BOOLEAN$$TDIY_FP(var_60, var_58, var_78, var_70, r8);
                            var_60 = rax_38;
                            var_58 = rdx_15;
                        }
                        
                        char var_38_3;
                        
                        if ((var_60 & 0x1ffffffff) != 0x80000000)
                        {
                            int64_t rax_42;
                            rax_42 = (var_60 & 0x80000000) != 0;
                            var_38_3 = rax_42;
                        }
                        else
                            var_38_3 = 0;
                        
                        SYSTEM_$$_DIY_UTIL_SHR$LONGWORD$QWORD$SMALLINT(&var_58, &var_60, 0x20);
                        
                        if (var_38_3 != 0)
                        {
                            int64_t rax_45 = (var_38_3 + var_60);
                            int64_t rdx_16;
                            rdx_16 = rax_45 < var_60;
                            var_58 += (rdx_16 & 0xff);
                            var_60 = rax_45;
                        }
                        
                        if (var_58 != 0)
                        {
                            SYSTEM_$$_DIY_UTIL_SHR$LONGWORD$QWORD$SMALLINT(&var_58, &var_60, 1);
                            var_54 += 1;
                        }
                        
                        int16_t rax_47 = (var_54 + 0x405e);
                        var_54 = rax_47;
                        
                        if (rax_47 >= 0x7fff)
                            r12 = 1;
                        else if (var_54 < 0xffc1)
                            r12 = 0xffff;
                        else if (var_54 <= 0)
                        {
                            rbx = (1 - var_54);
                            rdx_7 = (1 << ((1 - var_54) - 1));
                            char var_38_4;
                            
                            if ((((rdx_7 << 2) + -ffffffffffffffff) & var_60) != rdx_7)
                            {
                                int64_t rax_52;
                                rax_52 = (rdx_7 & var_60) != 0;
                                var_38_4 = rax_52;
                            }
                            else
                                var_38_4 = 0;
                            
                            if (var_54 != 0xffc1)
                                var_60 = (var_38_4 + (var_60 >> rbx));
                            else
                            {
                                var_60 = var_38_4;
                                int64_t rax_53;
                                rax_53 = var_38_4;
                                
                                if (rax_53 == 0)
                                    r12 = 0xffff;
                            }
                            
                            var_54 = 0;
                        }
                    }
                    
                    if (r12 < 0)
                    {
                        rdx_7 = var_40;
                        SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_PACK_FLOAT$EXTENDED$BOOLEAN$SMALLINT$QWORD(&result, &result, rdx_7, 0, 0);
                    }
                    else if (r12 <= 0)
                    {
                        rdx_7 = var_40;
                        SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_PACK_FLOAT$EXTENDED$BOOLEAN$SMALLINT$QWORD(&result, &result, rdx_7, var_54, var_60);
                    }
                    else
                    {
                        rdx_7 = var_40;
                        SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_PACK_FLOAT$EXTENDED$BOOLEAN$SMALLINT$QWORD(&result, &result, rdx_7, 0x7fff, -0x8000000000000000);
                    }
                    
                    *arg2 = 0;
                }
            }
            else
            {
                rcx_1 = 0;
                char* rax_9;
                rax_9 = *(r15 + arg1);
                
                if (rax_9 < 0x45)
                    *arg2 = r15;
                else
                {
                    char temp7_1 = rax_9;
                    rax_9 -= 0x45;
                    char temp8_1;
                    
                    if (temp7_1 != 0x45)
                    {
                        temp8_1 = rax_9;
                        rax_9 -= 0x20;
                    }
                    
                    if ((temp7_1 != 0x45 && temp8_1 != 0x20))
                        *arg2 = r15;
                    else
                    {
                        r15 += 1;
                        
                        if (r14 >= r15)
                        {
                            char* rax_12;
                            rax_12 = *(r15 + arg1);
                            
                            if (rax_12 >= 0x2b)
                            {
                                char temp9_1 = rax_12;
                                rax_12 -= 0x2b;
                                
                                if (temp9_1 == 0x2b)
                                    r15 += 1;
                                else
                                {
                                    char temp10_1 = rax_12;
                                    rax_12 -= 2;
                                    
                                    if (temp10_1 == 2)
                                    {
                                        rcx_1 = 1;
                                        r15 += 1;
                                    }
                                }
                            }
                            
                            while (true)
                            {
                                if (r14 < r15)
                                {
                                    if (rcx_1 != 0)
                                        rdx_7 = -(rdx_7);
                                    
                                    break;
                                }
                                
                                r12 = *(r15 + arg1);
                                
                                if ((r12 < 0x30 || r12 > 0x39))
                                {
                                    *arg2 = r15;
                                    goto label_409d9e;
                                }
                                
                                if (rdx_7 < 0x186a0)
                                    rdx_7 = (rdx_7 + (((rdx_7 * 9) + r12) - 0x30));
                                
                                r15 += 1;
                                continue;
                            }
                            
                            goto label_409a54;
                        }
                        
                        *arg2 = r15;
                    }
                }
            }
        }
        else
        {
            int64_t var_88;
            var_88 = 0;
            *var_88[4] = 0x80000000;
            
            if (SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_MATCH_SPECIAL$crcD4AB17D1(&result, r15, arg1, &TC_$SYSTEM_$$_C_STR_INF) == 0)
            {
                if (SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_MATCH_SPECIAL$crcD4AB17D1(&result, r15, arg1, &TC_$SYSTEM_$$_C_STR_QNAN) == 0)
                    rbx = 0;
                else
                {
                    var_40 = 1;
                    var_88 = 0;
                    *var_88[4] = 0xc0000000;
                }
            }
            
            if (rbx != 0)
            {
                SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_PACK_FLOAT$EXTENDED$BOOLEAN$SMALLINT$QWORD(&result, &result, var_40, 0x7fff, var_88);
                r15 = 0;
            }
            
            *arg2 = r15;
        }
    }
    else
        *arg2 = r15;
    
label_409d9e:
    return result;
}

int64_t SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_MATCH_SPECIAL$crcD4AB17D1(int64_t arg1, int16_t arg2, char* arg3, char* arg4)
{
    int64_t rbx;
    int64_t var_8 = rbx;
    int64_t var_38 = arg1;
    char var_30 = 0;
    int64_t r13;
    r13 = *arg3;
    int64_t r12;
    r12 = *arg4;
    
    if (((r13 - arg2) + 1) == r12)
    {
        while (true)
        {
            rbx = SYSTEM_$$_UPCASE$CHAR$$CHAR(arg3[r13]);
            
            if (rbx != SYSTEM_$$_UPCASE$CHAR$$CHAR(arg4[r12]))
                break;
            
            r13 -= 1;
            r12 -= 1;
            
            if (r12 <= 0)
            {
                var_30 = 1;
                break;
            }
        }
    }
    
    int64_t result;
    result = var_30;
    return result;
}

uint64_t SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_COUNT_LEADING_ZERO$QWORD$$SMALLINT(int64_t arg1, uint64_t arg2)
{
    int64_t var_8 = arg1;
    uint64_t rflags;
    int16_t rdx;
    rdx = _bit_scan_reverse(arg2);
    bool z;
    
    if (z)
        rdx = 0xff;
    
    return (0x3f - rdx);
}

uint64_t SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_COUNT_LEADING_ZERO$LONGWORD$$SMALLINT(int64_t arg1, int32_t arg2)
{
    int64_t var_8 = arg1;
    uint64_t rflags;
    int16_t temp0;
    temp0 = _bit_scan_reverse(arg2);
    int16_t rdx = temp0;
    bool z;
    
    if (z)
        rdx = 0xff;
    
    return (0x1f - rdx);
}

uint64_t SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_ADD_DIGIT$LONGWORD$QWORD$BYTE(int64_t arg1, int32_t* arg2, int32_t* arg3, char arg4)
{
    int64_t var_8 = arg1;
    uint64_t rax_1 = ((*arg3 * 0xa) + arg4);
    uint64_t rcx_5 = ((((*arg2 << 0x20) + (*arg3 >> 0x20)) * 0xa) + (rax_1 >> 0x20));
    *arg2 = (rcx_5 >> 0x20);
    uint64_t result = (rax_1 + (rcx_5 << 0x20));
    *arg3 = result;
    return result;
}

uint64_t SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_FACTOR_10_INEXACT$crcDDB8D7AA(int64_t arg1, int16_t arg2, int64_t* arg3)
{
    int64_t var_58 = arg1;
    int64_t rbx;
    rbx = arg2;
    int64_t var_50;
    SYSTEM_$$_DIY_FP_CACHED_POWER10$SMALLINT$TDIY_FP_POWER_OF_10(rbx, &var_50);
    int16_t var_40;
    int16_t rdx_1 = (var_40 - rbx);
    int64_t r13;
    
    if (rdx_1 < 0)
        r13 = 1;
    else if (rdx_1 <= 0x24)
    {
        int64_t rdx_3 = (rdx_1 * 0x18);
        int64_t rax_1 = *(&TC_$SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_FACTOR_10_INEXACT$SMALLINT$TDIY_FP_POWER_OF_10$$SMALLINT_$$_FACTOR + rdx_3);
        int64_t rax_2 = *(rdx_3 + 0x427d88);
        int64_t rax_3 = *(rdx_3 + 0x427d90);
        int64_t var_48;
        
        if (rax_3 == 0)
        {
            *arg3 = var_50;
            arg3[1] = var_48;
            arg3[2] = var_40;
        }
        else if (var_40 != 0)
        {
            int64_t rax_10;
            int64_t rdx_5;
            rax_10 = SYSTEM_$$_DIY_FP_MULTIPLY$TDIY_FP$TDIY_FP$BOOLEAN$$TDIY_FP(var_50, var_48, rax_1, rax_2, 1);
            *arg3 = rax_10;
            arg3[1] = rdx_5;
            arg3[2] = rbx;
        }
        else
        {
            *arg3 = rax_1;
            arg3[1] = rax_2;
            arg3[2] = rax_3;
        }
        r13 = 0;
    }
    else
        r13 = 0xffff;
    
    return r13;
}

int64_t* SYSTEM$_$VAL_REAL$SHORTSTRING$INT64$$EXTENDED_$$_PACK_FLOAT$EXTENDED$BOOLEAN$SMALLINT$QWORD(int64_t arg1, int64_t* arg2, char arg3, int16_t arg4, int64_t arg5)
{
    int64_t var_28 = arg1;
    int16_t var_10 = (arg4 & 0x7fff);
    
    if (arg3 != 0)
        *var_10[1] |= 0x80;
    
    *arg2 = arg5;
    int64_t rdx;
    rdx = var_10;
    arg2[1] = rdx;
    return arg2;
}

char* FPC_SHORTSTR_FLOAT(int16_t arg1, int16_t arg2, int32_t arg3, char* arg4, int64_t arg5, uint64_t arg6, int16_t arg7, int16_t arg8)
{
    int16_t var_20 = arg8;
    return SYSTEM_$$_STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

uint64_t SYSTEM_$$_FPC_SHORTSTR_ENUM_INTERN$INT64$INT64$POINTER$POINTER$OPENSTRING$$LONGINT(int64_t arg1, int64_t arg2, void* arg3, int32_t* arg4, char* arg5, int64_t arg6)
{
    int32_t var_38 = 0x6b;
    
    if (*arg4 != 0)
    {
        int32_t rdx_3 = 0;
        int32_t rdi_1 = (arg4[1] - 1);
        int32_t rax_7;
        
        while (true)
        {
            int64_t rax_5 = (rdx_3 + rdi_1);
            rax_7 = ((rax_5 + (rax_5 >> 0x3f)) >> 1);
            
            if (arg4[(2 + (rax_7 * 3))] >= arg1)
            {
                if (arg4[(2 + (rax_7 * 3))] <= arg1)
                    break;
                
                rdi_1 = (rax_7 - 1);
            }
            else
                rdx_3 = (rax_7 + 1);
            
            if (rdi_1 < rdx_3)
                return var_38;
        }
        
        FPC_SHORTSTR_TO_SHORTSTR(arg5, arg6, *(((arg4 + 8) + (rax_7 * 0xc)) + 4));
        goto label_40a180;
    }
    
    void* rax_1 = ((arg3 + 2) + *(arg3 + 1));
    
    if ((*(rax_1 + 1) <= arg1 && *(rax_1 + 5) >= arg1))
    {
        char* rdx_2 = *((arg4 + ((arg1 - *(rax_1 + 1)) << 3)) + 4);
        
        if (rdx_2 != 0)
        {
            FPC_SHORTSTR_TO_SHORTSTR(arg5, arg6, rdx_2);
        label_40a180:
            
            if (*arg5 < arg2)
            {
                int32_t rdx_6 = (arg2 - *arg5);
                
                if (rdx_6 >= 1)
                {
                    int32_t rsi_3 = 0;
                    
                    do
                    {
                        rsi_3 += 1;
                        arg5[(*arg5 + rsi_3)] = 0x20;
                    } while (rdx_6 > rsi_3);
                }
                
                *arg5 += rdx_6;
            }
            
            var_38 = 0;
        }
    }
    
    return var_38;
}

int64_t FPC_SHORTSTR_ENUM(int64_t arg1, int64_t arg2, void* arg3, int32_t* arg4, char* arg5, int64_t arg6)
{
    int32_t result = SYSTEM_$$_FPC_SHORTSTR_ENUM_INTERN$INT64$INT64$POINTER$POINTER$OPENSTRING$$LONGINT(arg1, arg2, arg3, arg4, arg5, arg6);
    
    if (result == 0)
        return result;
    
    return FPC_RUNERROR(0x6b);
}

uint64_t FPC_SHORTSTR_BOOL(char arg1, int64_t arg2, char* arg3, int64_t arg4)
{
    if (arg1 == 0)
        FPC_SHORTSTR_TO_SHORTSTR(arg3, arg4, &_$SYSTEM$_Ld27);
    else
        FPC_SHORTSTR_TO_SHORTSTR(arg3, arg4, &_$SYSTEM$_Ld26);
    
    uint64_t result = *arg3;
    
    if (result >= arg2)
        return result;
    
    void var_118;
    SYSTEM_$$_SPACE$BYTE$$SHORTSTRING(&var_118, (arg2 - *arg3));
    void var_218;
    fpc_shortstr_concat(&var_218, 0xff, &var_118, arg3);
    return FPC_SHORTSTR_TO_SHORTSTR(arg3, arg4, &var_218);
}

char* FPC_SHORTSTR_CURRENCY(uint64_t arg1, int64_t arg2, int64_t arg3, char* arg4, int64_t arg5)
{
    uint64_t i_5 = arg1;
    int64_t r13 = arg2;
    void var_70;
    SYSTEM_$$_FILLCHAR$formal$INT64$CHAR(&var_70, 0x13, 0x30);
    
    if (r13 == -0x7fff)
        r13 = 0x19;
    
    int32_t result_1;
    uint64_t i_3;
    
    if (i_5 < 0)
    {
        result_1 = 1;
        i_3 = -(i_5);
    }
    else
    {
        i_3 = i_5;
        result_1 = 0;
    }
    
    int32_t rsi = 0;
    uint64_t i;
    
    do
    {
        rsi += 1;
        *(&*i_5[7] + rsi) = ((i_3 % 0xa) + 0x30);
        i = (i_3 / 0xa);
        i_3 = i;
    } while (i != 0);
    uint64_t var_40 = rsi;
    int32_t r12 = var_40;
    
    if (arg3 != 0)
        r12 += 1;
    
    uint64_t var_48;
    uint64_t var_30;
    int32_t i_4;
    
    if (arg3 >= 0)
    {
        int32_t r12_1 = (r12 + result_1);
        
        while (var_40 < 5)
        {
            r12_1 += 1;
            var_40 += 1;
            *(&*i_5[7] + var_40) = 0x30;
        }
        
        var_30 = (4 - arg3);
        var_48 = arg3;
        
        if (var_48 != 0)
        {
            if (var_48 > 4)
                var_48 = 4;
            
            var_48 += 1;
        }
        
        i_4 = (r12_1 - var_30);
    }
    else
    {
        i_4 = (r12 + 5);
        
        if (r13 < 8)
            r13 = 8;
        
        var_30 = (i_4 - r13);
        
        if (i_4 < r13)
            i_4 = r13;
        
        if (var_30 <= 0)
            var_48 = var_40;
        else
        {
            i_4 = r13;
            var_48 = (var_40 - var_30);
        }
    }
    
    if (var_30 > 0)
    {
        int32_t rbx_1 = 0;
        uint64_t var_38_1 = (var_30 + 2);
        
        if (var_40 < var_38_1)
            var_38_1 = (var_40 + 1);
        
        if (*(&*i_5[5] + var_38_1) >= 0x35)
        {
            if (*(&*i_5[6] + var_38_1) >= 0x39)
            {
                *(&*i_5[6] + var_38_1) = 0x30;
                rbx_1 = 1;
            }
            else
                *(&*i_5[7] + (var_38_1 - 1)) += 1;
        }
        
        if ((rbx_1 == 1 && *(&*i_5[6] + var_38_1) == 0x30))
        {
            while (*(&*i_5[7] + var_38_1) == 0x39)
            {
                *(&*i_5[7] + var_38_1) = 0x30;
                var_38_1 += 1;
            }
            
            *(&*i_5[7] + var_38_1) += 1;
            
            if (var_40 < var_38_1)
            {
                i_4 += 1;
                var_40 += 1;
            }
        }
    }
    
    if (i_4 < r13)
        i_4 = r13;
    
    if (i_4 > arg5)
    {
        if (var_30 < 0)
            var_30 += (i_4 - arg5);
        
        i_4 = arg5;
    }
    
    FPC_SHORTSTR_SETLENGTH(arg4, arg5, i_4);
    int32_t i_2 = i_4;
    
    if (arg3 < 0)
    {
        int32_t rbx_2;
        
        if (i_5 != 0)
            rbx_2 = (var_40 - 5);
        else
            rbx_2 = 0;
        
        if (rbx_2 < 0)
        {
            arg4[(i_2 - 2)] = 0x2d;
            rbx_2 = -(rbx_2);
        }
        else
            arg4[(i_2 - 2)] = 0x2b;
        
        arg4[i_2] = ((rbx_2 % 0xa) + 0x30);
        arg4[(i_2 - 1)] = ((rbx_2 / 0xa) + 0x30);
        arg4[(i_2 - 3)] = 0x45;
        i_2 -= 4;
    }
    
    while (var_30 < 0)
    {
        arg4[i_2] = 0x30;
        i_2 -= 1;
        var_30 += 1;
    }
    
    int32_t i_1 = var_40;
    
    if (i_1 >= (var_30 + 1))
    {
        int64_t var_38_3 = ((var_30 + 1) - 1);
        
        do
        {
            var_38_3 += 1;
            var_48 -= 1;
            
            if (var_48 == 0)
            {
                arg4[i_2] = 0x2e;
                i_2 -= 1;
            }
            
            uint64_t rsi_8;
            rsi_8 = *(&*i_5[7] + var_38_3);
            arg4[i_2] = rsi_8;
            i_2 -= 1;
        } while (i_1 > var_38_3);
    }
    
    char* result = result_1;
    
    if (result == 1)
    {
        result = arg4;
        result[i_2] = 0x2d;
        i_2 -= 1;
    }
    
    for (; i_2 > 0; i_2 -= 1)
    {
        result = arg4;
        result[i_2] = 0x20;
    }
    
    return result;
}

uint64_t fpc_chararray_sint(int64_t arg1, int64_t arg2, char* arg3, int64_t arg4)
{
    char var_108;
    SYSTEM_$$_INT_STR$INT64$OPENSTRING(arg1, &var_108, 0xff);
    
    if (var_108 < arg2)
    {
        void var_208;
        SYSTEM_$$_SPACE$BYTE$$SHORTSTRING(&var_208, (arg2 - var_108));
        fpc_shortstr_concat(&var_108, 0xff, &var_208, &var_108);
    }
    
    uint64_t rax_3;
    
    if (var_108 >= (arg4 + 1))
        rax_3 = (arg4 + 1);
    else
        rax_3 = var_108;
    
    return SYSTEM_$$_FPC_SHORTSTR_CHARARRAY_INTERN_CHARMOVE$SHORTSTRING$array_of_CHAR$INT64(&var_108, arg3, arg4, rax_3);
}

uint64_t fpc_chararray_uint(uint64_t arg1, int64_t arg2, char* arg3, int64_t arg4)
{
    char var_108;
    SYSTEM_$$_INT_STR_UNSIGNED$QWORD$OPENSTRING(arg1, &var_108, 0xff);
    
    if (var_108 < arg2)
    {
        void var_208;
        SYSTEM_$$_SPACE$BYTE$$SHORTSTRING(&var_208, (arg2 - var_108));
        fpc_shortstr_concat(&var_108, 0xff, &var_208, &var_108);
    }
    
    uint64_t rax_3;
    
    if (var_108 >= (arg4 + 1))
        rax_3 = (arg4 + 1);
    else
        rax_3 = var_108;
    
    return SYSTEM_$$_FPC_SHORTSTR_CHARARRAY_INTERN_CHARMOVE$SHORTSTRING$array_of_CHAR$INT64(&var_108, arg3, arg4, rax_3);
}

uint64_t fpc_chararray_float(int16_t arg1, int16_t arg2, int32_t arg3, char* arg4, int64_t arg5, uint64_t arg6, int16_t arg7, int16_t arg8)
{
    int16_t var_130 = arg8;
    char var_118;
    SYSTEM_$$_STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING(arg1, arg2, arg3, &var_118, 0xff, arg6, arg7);
    uint64_t rax_2;
    
    if (var_118 >= (arg5 + 1))
        rax_2 = (arg5 + 1);
    else
        rax_2 = var_118;
    
    return SYSTEM_$$_FPC_SHORTSTR_CHARARRAY_INTERN_CHARMOVE$SHORTSTRING$array_of_CHAR$INT64(&var_118, arg4, arg5, rax_2);
}

uint64_t fpc_chararray_enum(int64_t arg1, int64_t arg2, void* arg3, int32_t* arg4, char* arg5, int64_t arg6)
{
    char var_108;
    FPC_SHORTSTR_ENUM(arg1, arg2, arg3, arg4, &var_108, 0xff);
    uint64_t rax_1;
    
    if (var_108 >= (arg6 + 1))
        rax_1 = (arg6 + 1);
    else
        rax_1 = var_108;
    
    return SYSTEM_$$_FPC_SHORTSTR_CHARARRAY_INTERN_CHARMOVE$SHORTSTRING$array_of_CHAR$INT64(&var_108, arg5, arg6, rax_1);
}

uint64_t fpc_chararray_bool(char arg1, int64_t arg2, char* arg3, int64_t arg4)
{
    char var_108;
    FPC_SHORTSTR_BOOL(arg1, arg2, &var_108, 0xff);
    uint64_t rax_1;
    
    if (var_108 >= (arg4 + 1))
        rax_1 = (arg4 + 1);
    else
        rax_1 = var_108;
    
    return SYSTEM_$$_FPC_SHORTSTR_CHARARRAY_INTERN_CHARMOVE$SHORTSTRING$array_of_CHAR$INT64(&var_108, arg3, arg4, rax_1);
}

uint64_t fpc_chararray_currency(uint64_t arg1, int64_t arg2, int64_t arg3, char* arg4, int64_t arg5)
{
    char var_110;
    FPC_SHORTSTR_CURRENCY(arg1, arg2, arg3, &var_110, 0xff);
    uint64_t rax_1;
    
    if (var_110 >= (arg5 + 1))
        rax_1 = (arg5 + 1);
    else
        rax_1 = var_110;
    
    return SYSTEM_$$_FPC_SHORTSTR_CHARARRAY_INTERN_CHARMOVE$SHORTSTRING$array_of_CHAR$INT64(&var_110, arg4, arg5, rax_1);
}

int64_t SYSTEM_$$_INITVAL$SHORTSTRING$BOOLEAN$BYTE$$INT64(char* arg1, char* arg2, char* arg3)
{
    int64_t i = 1;
    *arg2 = 0;
    *arg3 = 0xa;
    
    if (*arg1 == 0)
        return 1;
    
    for (; *arg1 >= i; i += 1)
    {
        uint32_t r8_3 = arg1[i];
        
        if ((r8_3 != 9 && (r8_3 != 0x20 && r8_3 != 0x20)))
            break;
    }
    
    uint64_t r8_4;
    r8_4 = arg1[i];
    
    if (r8_4 >= 0x2b)
    {
        char temp0_1 = r8_4;
        r8_4 -= 0x2b;
        
        if (temp0_1 == 0x2b)
            i += 1;
        else
        {
            char temp1_1 = r8_4;
            r8_4 -= 2;
            
            if (temp1_1 == 2)
            {
                *arg2 = 1;
                i += 1;
            }
        }
    }
    
    if (*arg1 >= i)
    {
        uint64_t rsi_1;
        rsi_1 = arg1[i];
        
        if (rsi_1 >= 0x24)
        {
            char temp2_1 = rsi_1;
            rsi_1 -= 0x24;
            
            if (temp2_1 == 0x24)
            {
                *arg3 = 0x10;
                i += 1;
            }
            else
            {
                char temp3_1 = rsi_1;
                rsi_1 -= 1;
                
                if (temp3_1 == 1)
                {
                    *arg3 = 2;
                    i += 1;
                }
                else
                {
                    char temp4_1 = rsi_1;
                    rsi_1 -= 1;
                    
                    if (temp4_1 == 1)
                    {
                        *arg3 = 8;
                        i += 1;
                    }
                    else
                    {
                        char temp5_1 = rsi_1;
                        rsi_1 -= 0xa;
                        
                        if (temp5_1 != 0xa)
                        {
                            char temp6_1 = rsi_1;
                            rsi_1 -= 0x28;
                            
                            if (temp6_1 == 0x28)
                            {
                                *arg3 = 0x10;
                                i += 1;
                            }
                            else
                            {
                                char temp7_1 = rsi_1;
                                rsi_1 -= 0x20;
                                
                                if (temp7_1 == 0x20)
                                {
                                    *arg3 = 0x10;
                                    i += 1;
                                }
                            }
                        }
                        else if (*arg1 > i)
                        {
                            uint32_t rsi_5 = arg1[(i + 1)];
                            
                            if (((rsi_5 == 0x58 || rsi_5 == 0x78) || rsi_5 == 0x78))
                            {
                                i += 2;
                                *arg3 = 0x10;
                            }
                        }
                    }
                }
            }
        }
    }
    
    for (; *arg1 > i; i += 1)
    {
        if (arg1[i] != 0x30)
            break;
    }
    
    return i;
}

int64_t FPC_VAL_SINT_SHORTSTR(int64_t arg1, char* arg2, int64_t* arg3)
{
    int64_t result = 0;
    int64_t result_1 = 0;
    char var_38;
    char var_34;
    *arg3 = SYSTEM_$$_INITVAL$SHORTSTRING$BOOLEAN$BYTE$$INT64(arg2, &var_34, &var_38);
    
    if (*arg2 >= *arg3)
    {
        if (arg2[*arg3] != 0)
        {
            uint64_t rcx_1 = var_38;
            int64_t rdx_4;
            
            if (var_38 != 0xa)
                rdx_4 = -1;
            else
                rdx_4 = (var_34 + 0x7fffffffffffffff);
            
            while (*arg2 >= *arg3)
            {
                uint64_t rcx_2;
                rcx_2 = arg2[*arg3];
                
                if (rcx_2 == 0)
                    break;
                
                char temp3_1 = rcx_2;
                rcx_2 -= 0x30;
                char rsi_1;
                
                if (temp3_1 < 0x30)
                    rsi_1 = 0x10;
                else
                {
                    char temp4_1 = rcx_2;
                    rcx_2 -= 9;
                    
                    if (temp4_1 <= 9)
                        rsi_1 = (arg2[*arg3] - 0x30);
                    else
                    {
                        char temp5_1 = rcx_2;
                        rcx_2 -= 8;
                        
                        if (temp5_1 < 8)
                            rsi_1 = 0x10;
                        else
                        {
                            char temp6_1 = rcx_2;
                            rcx_2 -= 5;
                            
                            if (temp6_1 <= 5)
                                rsi_1 = (arg2[*arg3] - 0x37);
                            else
                            {
                                char temp8_1 = rcx_2;
                                rcx_2 -= 0x1b;
                                
                                if (temp8_1 < 0x1b)
                                    rsi_1 = 0x10;
                                else
                                {
                                    char temp10_1 = rcx_2;
                                    rcx_2 -= 5;
                                    
                                    if (temp10_1 <= 5)
                                        rsi_1 = (arg2[*arg3] - 0x57);
                                    else
                                        rsi_1 = 0x10;
                                }
                            }
                        }
                    }
                }
                
                int64_t rcx_13 = (var_38 * result_1);
                
                if (((rsi_1 >= var_38 || (rdx_4 - rsi_1) < rcx_13) || (COMBINE(0, -1) / rcx_1) < result_1))
                    return 0;
                
                result_1 = (rcx_13 + rsi_1);
                *arg3 += 1;
            }
            
            *arg3 = 0;
            result = result_1;
            
            if (var_34 != 0)
                result = -(result);
            
            if ((var_34 == 0 && (var_38 != 0xa && arg1 >= 1)))
            {
                if (arg1 == 1)
                    return result;
                
                if (arg1 == 2)
                    return result;
                
                if (arg1 == 4)
                    return result;
            }
        }
        else
        {
            int64_t rax_3 = *arg3;
            
            if ((rax_3 > 1 && arg2[(rax_3 - 1)] == 0x30))
                *arg3 = 0;
        }
    }
    
    return result;
}

int64_t FPC_VAL_UINT_SHORTSTR(char* arg1, int64_t* arg2)
{
    int64_t result = 0;
    char var_28;
    char var_24;
    int64_t rax;
    uint64_t rsi_1;
    rax = SYSTEM_$$_INITVAL$SHORTSTRING$BOOLEAN$BYTE$$INT64(arg1, &var_24, &var_28);
    *arg2 = rax;
    
    if ((var_24 == 0 && *arg1 >= *arg2))
    {
        if (arg1[*arg2] != 0)
        {
            while (*arg1 >= *arg2)
            {
                uint64_t rax_6;
                rax_6 = arg1[*arg2];
                
                if (rax_6 == 0)
                    break;
                
                char temp3_1 = rax_6;
                rax_6 -= 0x30;
                char rcx_1;
                
                if (temp3_1 < 0x30)
                    rcx_1 = 0x10;
                else
                {
                    char temp4_1 = rax_6;
                    rax_6 -= 9;
                    
                    if (temp4_1 <= 9)
                        rcx_1 = (arg1[*arg2] - 0x30);
                    else
                    {
                        char temp5_1 = rax_6;
                        rax_6 -= 8;
                        
                        if (temp5_1 < 8)
                            rcx_1 = 0x10;
                        else
                        {
                            char temp6_1 = rax_6;
                            rax_6 -= 5;
                            
                            if (temp6_1 <= 5)
                                rcx_1 = (arg1[*arg2] - 0x37);
                            else
                            {
                                char temp7_1 = rax_6;
                                rax_6 -= 0x1b;
                                
                                if (temp7_1 < 0x1b)
                                    rcx_1 = 0x10;
                                else
                                {
                                    char temp8_1 = rax_6;
                                    rax_6 -= 5;
                                    
                                    if (temp8_1 <= 5)
                                        rcx_1 = (arg1[*arg2] - 0x57);
                                    else
                                        rcx_1 = 0x10;
                                }
                            }
                        }
                    }
                }
                
                rsi_1 = var_28;
                
                if ((rsi_1 <= rcx_1 || (COMBINE(0, (-1 - rcx_1)) / (rsi_1 & 0xff)) < result))
                    return 0;
                
                result = ((var_28 * result) + rcx_1);
                *arg2 += 1;
            }
            
            *arg2 = 0;
        }
        else
        {
            int64_t rax_3 = *arg2;
            
            if ((rax_3 > 1 && arg1[(rax_3 - 1)] == 0x30))
                *arg2 = 0;
        }
    }
    
    return result;
}

int80_t FPC_VAL_REAL_SHORTSTR(char* arg1, int64_t* arg2)
{
    return SYSTEM_$$_VAL_REAL$SHORTSTRING$INT64$$EXTENDED(arg1, arg2);
}

uint64_t FPC_VAL_ENUM_SHORTSTR(int32_t* arg1, char* arg2, int64_t* arg3)
{
    int64_t* var_238 = arg3;
    char var_30 = 1;
    *var_238 = 1;
    
    while (true)
    {
        int64_t* rax;
        rax = var_30;
        
        if (rax > *arg2)
            break;
        
        if (*(arg2 + var_30) != 0x20)
            break;
        
        var_30 += 1;
    }
    
    void var_130;
    int64_t rcx;
    char r8;
    rcx = fpc_shortstr_copy(&var_130, arg2, var_30, 0xff);
    void var_230;
    SYSTEM_$$_UPCASE$SHORTSTRING$$SHORTSTRING(&var_230, &var_130);
    int32_t r14 = 1;
    int32_t r12 = *arg1;
    
    do
    {
        uint32_t rax_2 = ((r14 + r12) >> 1);
        SYSTEM_$$_UPCASE$SHORTSTRING$$SHORTSTRING(&var_130, *(((arg1 + 4) + (rax_2 * 0xc)) - 8));
        uint64_t rax_5;
        rax_5 = SYSTEM$_$fpc_val_enum_shortstr$POINTER$SHORTSTRING$INT64$$LONGINT_$$_STRING_COMPARE$crc097F67B1(&var_238, &var_230, &var_130, rcx, r8);
        
        if (rax_5 <= 0)
        {
            if (rax_5 >= 0)
            {
                *var_238 = 0;
                return arg1[((rax_2 * 3) - 2)];
            }
            
            r12 = (rax_2 - 1);
        }
        else
            r14 = (rax_2 + 1);
    } while (r12 >= r14);
    
    uint64_t result = (var_30 - 1);
    int64_t* rdx_2 = var_238;
    *rdx_2 += result;
    return result;
}

uint64_t SYSTEM$_$fpc_val_enum_shortstr$POINTER$SHORTSTRING$INT64$$LONGINT_$$_STRING_COMPARE$crc097F67B1(int64_t* arg1, char* arg2, char* arg3, int64_t arg4, char arg5)
{
    int64_t* var_8 = arg1;
    char i = *arg2;
    char rax = *arg2;
    
    if (rax > *arg3)
        i = *arg3;
    
    arg1 = 1;
    
    while (i >= arg1)
    {
        rax = arg2[arg1];
        arg5 = arg3[arg1];
        
        if (arg5 != rax)
            break;
        
        arg1 += 1;
    }
    
    if (arg1 > **var_8)
        **var_8 = arg1;
    
    if (i < arg1)
        return (*arg2 - *arg3);
    
    return (rax - arg5);
}

long double FPC_VAL_CURRENCY_SHORTSTR(char* arg1, int64_t* arg2)
{
    int64_t var_28 = 0;
    int64_t var_20 = 0;
    uint32_t rcx = *arg1;
    *arg2 = 1;
    int32_t r10 = -1;
    int32_t r11 = 0;
    
    while (rcx >= *arg2)
    {
        uint32_t rax_3 = arg1[*arg2];
        
        if ((rax_3 != 9 && (rax_3 != 0x20 && rax_3 != 0x20)))
        {
            uint64_t rax_4;
            rax_4 = arg1[*arg2];
            
            if (rax_4 >= 0x2b)
            {
                char temp0_1 = rax_4;
                rax_4 -= 0x2b;
                
                if (temp0_1 == 0x2b)
                    *arg2 += 1;
                else
                {
                    char temp1_1 = rax_4;
                    rax_4 -= 2;
                    
                    if (temp1_1 == 2)
                    {
                        r10 = 1;
                        *arg2 += 1;
                    }
                }
            }
            
            int64_t r12;
            r12 = 0;
            int32_t rbx_1 = 0;
            
            while (true)
            {
                if (rcx >= *arg2)
                {
                    uint64_t rax_5;
                    rax_5 = arg1[*arg2];
                    
                    if (rax_5 >= 0x2e)
                    {
                        char temp2_1 = rax_5;
                        rax_5 -= 0x2e;
                        
                        if (temp2_1 == 0x2e)
                        {
                            if (r11 != 0)
                                break;
                            
                            r11 = 1;
                            rbx_1 = 0;
                            *arg2 += 1;
                            continue;
                        }
                        else
                        {
                            char temp3_1 = rax_5;
                            rax_5 -= 2;
                            
                            if (temp3_1 >= 2)
                            {
                                char temp4_1 = rax_5;
                                rax_5 -= 9;
                                
                                if (temp4_1 <= 9)
                                {
                                    int32_t rax_8 = (arg1[*arg2] - 0x30);
                                    int64_t rdx_1;
                                    int64_t r9_2;
                                    
                                    if (var_20 < *TC_$SYSTEM$_$fpc_val_currency_shortstr$SHORTSTRING$INT64$$CURRENCY_$$_MININT64EDGE)
                                    {
                                        r9_2 = (rax_8 + TC_$SYSTEM$_$fpc_val_currency_shortstr$SHORTSTRING$INT64$$CURRENCY_$$_MININT64);
                                        int64_t rax_9;
                                        rdx_1 = HIGHQ((0x6666666666666667 * r9_2));
                                        rax_9 = LOWQ((0x6666666666666667 * r9_2));
                                    }
                                    
                                    if ((var_20 < *TC_$SYSTEM$_$fpc_val_currency_shortstr$SHORTSTRING$INT64$$CURRENCY_$$_MININT64EDGE && ((rdx_1 >> 2) + (r9_2 >> 0x3f)) > var_20))
                                    {
                                        if (r11 == 0)
                                            break;
                                        
                                        if ((r12 == 0 && (rax_8 >= 5 && var_20 > TC_$SYSTEM$_$fpc_val_currency_shortstr$SHORTSTRING$INT64$$CURRENCY_$$_MININT64)))
                                            var_20 -= 1;
                                        
                                        r12 = 1;
                                    }
                                    else
                                    {
                                        var_20 = ((var_20 * 0xa) - rax_8);
                                        rbx_1 += 1;
                                    }
                                    
                                    *arg2 += 1;
                                    continue;
                                }
                            }
                        }
                    }
                }
                
                if ((rbx_1 == 0 && r11 == 0))
                    break;
                
                if (r11 != 0)
                    r11 = rbx_1;
                
                int32_t r9_4 = (4 - r11);
                
                if (rcx < *arg2)
                {
                label_40b2c3:
                    
                    if (r9_4 <= 0)
                    {
                        int32_t r9_6 = -(r9_4);
                        
                        if (r9_6 >= 1)
                        {
                            int32_t rbx_4 = 0;
                            
                            do
                            {
                                rbx_4 += 1;
                                
                                if ((TC_$SYSTEM$_$fpc_val_currency_shortstr$SHORTSTRING$INT64$$CURRENCY_$$_MININT64 + 5) <= var_20)
                                    var_20 -= 5;
                                
                                var_20 s/= 0xa;
                            } while (r9_6 > rbx_4);
                        }
                    }
                    else if (r9_4 >= 1)
                    {
                        int32_t rbx_3 = 0;
                        
                        do
                        {
                            rbx_3 += 1;
                            
                            if ((TC_$SYSTEM$_$fpc_val_currency_shortstr$SHORTSTRING$INT64$$CURRENCY_$$_MININT64 / 0xa) > var_20)
                                return var_28;
                            
                            var_20 *= 0xa;
                        } while (r9_4 > rbx_3);
                    }
                    
                    if (r10 == 1)
                    {
                        var_28 = var_20;
                        *arg2 = 0;
                    }
                    else if (var_20 > TC_$SYSTEM$_$fpc_val_currency_shortstr$SHORTSTRING$INT64$$CURRENCY_$$_MININT64)
                    {
                        var_28 = (r10 * var_20);
                        *arg2 = 0;
                    }
                }
                else
                {
                    uint32_t rax_16 = arg1[*arg2];
                    
                    if (((rax_16 == 0x45 || rax_16 == 0x65) || rax_16 == 0x65))
                    {
                        *arg2 += 1;
                        
                        if (rcx >= *arg2)
                        {
                            int32_t rbx_2 = 1;
                            uint64_t rax_18;
                            rax_18 = arg1[*arg2];
                            
                            if (rax_18 >= 0x2b)
                            {
                                char temp5_1 = rax_18;
                                rax_18 -= 0x2b;
                                
                                if (temp5_1 == 0x2b)
                                    *arg2 += 1;
                                else
                                {
                                    char temp6_1 = rax_18;
                                    rax_18 -= 2;
                                    
                                    if (temp6_1 == 2)
                                    {
                                        rbx_2 = -1;
                                        *arg2 += 1;
                                    }
                                }
                            }
                            
                            int32_t r8_2 = 0;
                            
                            while (rcx >= *arg2)
                            {
                                if ((arg1[*arg2] - 0x30) >= 0xa)
                                    return var_28;
                                
                                if (r8_2 > 0x1357)
                                    return var_28;
                                
                                r8_2 = ((r8_2 * 0xa) + (arg1[*arg2] - 0x30));
                                *arg2 += 1;
                            }
                            
                            r9_4 += (rbx_2 * r8_2);
                            goto label_40b2c3;
                        }
                    }
                }
                
                break;
            }
            
            break;
        }
        
        *arg2 += 1;
    }
    
    return var_28;
}

char* fpc_setstring_shortstr(char* arg1, uint64_t arg2, int64_t arg3, uint64_t arg4)
{
    uint64_t r13 = arg4;
    
    if (arg2 < r13)
        r13 = arg2;
    
    char* result = FPC_SHORTSTR_SETLENGTH(arg1, arg2, r13);
    
    if (arg3 == 0)
        return result;
    
    return FPC_MOVE(arg3, &arg1[1], r13);
}

uint64_t SYSTEM_$$_SHORTCOMPARETEXT$SHORTSTRING$SHORTSTRING$$INT64(char* arg1, char* arg2, int64_t arg3, int64_t arg4, uint64_t arg5, char arg6 @ rax, char arg7 @ r11)
{
    uint64_t rdx_1 = *arg1;
    uint64_t rcx = *arg2;
    
    if (rcx < rdx_1)
        arg5 = rcx;
    
    if (rcx >= rdx_1)
        arg5 = rdx_1;
    
    int64_t i = 0;
    void* rdi = &arg1[1];
    void* rsi = &arg2[1];
    
    for (; arg5 > i; i += 1)
    {
        arg6 = *rdi;
        arg7 = *rsi;
        
        if (arg7 != arg6)
        {
            if ((arg6 - 0x61) < 0x1a)
                arg6 -= 0x20;
            
            if ((arg7 - 0x61) < 0x1a)
                arg7 -= 0x20;
            
            if (arg7 != arg6)
                break;
        }
        
        rdi += 1;
        rsi += 1;
    }
    
    if (arg5 <= i)
        return (rdx_1 - rcx);
    
    return (arg6 - arg7);
}

int64_t FPC_DIV_QWORD(uint64_t arg1, uint64_t arg2)
{
    uint64_t r13 = arg2;
    
    if (((r13 >> 0x20) == 0 && (arg1 >> 0x20) == 0))
        return (r13 / arg1);
    
    int64_t result = 0;
    int64_t __saved_rbp;
    
    if (arg1 == 0)
        SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xc8, &data_40b4c5, &__saved_rbp);
    
    if (r13 != 0)
    {
        uint64_t rflags_1;
        int32_t rax_7;
        rax_7 = _bit_scan_reverse(r13);
        
        if (r13 == 0)
            rax_7 = 0xff;
        
        uint64_t rflags_2;
        int32_t rdx_4;
        rdx_4 = _bit_scan_reverse(arg1);
        
        if (r13 == 0)
            rdx_4 = 0xff;
        
        if (rax_7 >= rdx_4)
        {
            int32_t rax_8 = (rax_7 - rdx_4);
            uint64_t r12_1 = (arg1 << rax_8);
            
            if (rax_8 >= 0)
            {
                int32_t i = (rax_8 + 1);
                
                do
                {
                    i -= 1;
                    
                    if (r12_1 <= r13)
                    {
                        r13 -= r12_1;
                        result += (1 << i);
                    }
                    
                    r12_1 u>>= 1;
                } while (i > 0);
            }
        }
    }
    
    return result;
}

int64_t FPC_MOD_QWORD(uint64_t arg1, int64_t arg2)
{
    int64_t result = arg2;
    
    if (((result >> 0x20) == 0 && (arg1 >> 0x20) == 0))
        return (result % arg1);
    
    int64_t __saved_rbp;
    
    if (arg1 == 0)
        SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xc8, &data_40b595, &__saved_rbp);
    
    if (result == 0)
        return 0;
    
    uint64_t rflags_1;
    int32_t rax_7;
    rax_7 = _bit_scan_reverse(result);
    
    if (result == 0)
        rax_7 = 0xff;
    
    uint64_t rflags_2;
    int32_t rdx_4;
    rdx_4 = _bit_scan_reverse(arg1);
    
    if (result == 0)
        rdx_4 = 0xff;
    
    if (rax_7 < rdx_4)
        return result;
    
    int32_t rax_8 = (rax_7 - rdx_4);
    uint64_t r12_1 = (arg1 << rax_8);
    
    if (rax_8 >= 0)
    {
        int32_t i = (rax_8 + 1);
        
        do
        {
            i -= 1;
            
            if (r12_1 <= result)
                result -= r12_1;
            
            r12_1 u>>= 1;
        } while (i > 0);
    }
    
    return result;
}

int64_t FPC_DIV_INT64(int64_t arg1, int64_t arg2)
{
    int64_t __saved_rbp;
    
    if (arg1 == 0)
        SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xc8, &data_40b631, &__saved_rbp);
    bool rax = false;
    int64_t rsi_1;
    
    if (arg2 >= 0)
        rsi_1 = arg2;
    else
    {
        rax = true;
        rsi_1 = -(arg2);
    }
    
    int64_t rdi_1;
    
    if (arg1 >= 0)
        rdi_1 = arg1;
    else
    {
        rax = rax == 0;
        rdi_1 = -(arg1);
    }
    
    if (rax == 0)
        return (COMBINE(0, rsi_1) / rdi_1);
    
    return -((COMBINE(0, rsi_1) / rdi_1));
}

int64_t FPC_MOD_INT64(int64_t arg1, int64_t arg2)
{
    int64_t r12 = arg2;
    int64_t __saved_rbp;
    
    if (arg1 == 0)
        SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xc8, &data_40b6c1, &__saved_rbp);
    int64_t rcx_1;
    
    if (arg1 >= 0)
        rcx_1 = arg1;
    else
        rcx_1 = -(arg1);
    
    int64_t rax_1;
    
    if (r12 >= 0)
    {
        arg2 = 0;
        rax_1 = r12;
    }
    else
    {
        arg2 = 1;
        rax_1 = -(r12);
    }
    
    uint64_t result = (COMBINE(0, rax_1) % rcx_1);
    
    if (arg2 == 0)
        return result;
    
    return -(result);
}

int64_t FPC_MUL_QWORD(int64_t arg1, int64_t arg2) __pure
{
    int64_t result = 0;
    int64_t r8 = 1;
    
    for (int32_t i = -1; i < 0x3f; )
    {
        i += 1;
        
        if ((r8 & arg2) != 0)
            result += arg1;
        
        arg1 <<= 1;
        r8 <<= 1;
    }
    
    return result;
}

int64_t FPC_MUL_QWORD_CHECKOVERFLOW(int64_t arg1, int64_t arg2)
{
    int64_t r12 = arg1;
    int64_t result = 0;
    int64_t r13 = 1;
    int64_t rbx;
    rbx = 0;
    
    for (int32_t i = -1; i < 0x3f; )
    {
        i += 1;
        
        if ((r13 & arg2) != 0)
        {
            int64_t result_1 = result;
            result += r12;
            int64_t __saved_rbp;
            
            if (rbx != 0)
                SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xd7, &data_40b7bf, &__saved_rbp);
            else if ((result_1 != 0 && (r12 != 0 && (result < result_1 || result < r12))))
                SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xd7, &data_40b7bf, &__saved_rbp);
        }
        
        if ((rbx != 0 || (r12 & 0x8000000000000000) != 0))
            rbx = 1;
        else
            rbx = 0;
        
        r12 <<= 1;
        r13 <<= 1;
    }
    
    return result;
}

int64_t FPC_MUL_DWORD_TO_QWORD(int32_t arg1, int32_t arg2)
{
    return FPC_MUL_QWORD(arg1, arg2);
}

int64_t FPC_MUL_INT64(int64_t arg1, int64_t arg2) __pure
{
    return (arg2 * arg1);
}

int64_t FPC_MUL_INT64_CHECKOVERFLOW(int64_t arg1, int64_t arg2)
{
    int64_t r12;
    r12 = 0;
    int64_t rax_1;
    
    if (arg1 >= 0)
        rax_1 = arg1;
    else
    {
        r12 = true;
        rax_1 = -(arg1);
    }
    
    int64_t rdx_1;
    
    if (arg2 >= 0)
        rdx_1 = arg2;
    else
    {
        r12 = r12 == 0;
        rdx_1 = -(arg2);
    }
    
    int64_t result = (rdx_1 * rax_1);
    
    if ((rax_1 != 0 && rdx_1 != 0))
    {
        int64_t __saved_rbp;
        
        if ((result < rax_1 || result < rdx_1))
            SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xd7, &data_40b8cf, &__saved_rbp);
        else if (((result >> 0x3f) != 0 && (result != -0x8000000000000000 || r12 == 0)))
            SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xd7, &data_40b8cf, &__saved_rbp);
    }
    
    if (r12 == 0)
        return result;
    
    return -(result);
}

int64_t FPC_MUL_LONGINT_TO_INT64(int32_t arg1, int32_t arg2)
{
    return FPC_MUL_INT64(arg1, arg2);
}

long double FPC_DIV_CURRENCY(int64_t arg1, int64_t arg2) __pure
{
    int64_t var_20 = arg2;
    return (((arg2 * 0x2710) / arg1) * 0x2710);
}

long double FPC_MOD_CURRENCY(int64_t arg1, int64_t arg2) __pure
{
    int64_t var_20 = arg2;
    return ((arg2 % arg1) * 0x2710);
}

uint64_t SYSTEM_$$_TRANSLATEPLACEHOLDERCP$WORD$$WORD(uint16_t arg1)
{
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = arg1;
    
    if (arg1 <= 1)
        U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    return U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
}

uint64_t SYSTEM_$$_FPC_PCHAR_ANSISTR_INTERN_CHARMOVE$PCHAR$INT64$RAWBYTESTRING$INT64$INT64(int64_t arg1, int64_t arg2, int64_t* arg3, int64_t arg4, uint64_t arg5)
{
    return FPC_MOVE((arg2 + arg1), (*arg3 + arg4), arg5);
}

uint64_t SYSTEM_$$_FPC_PCHAR_PCHAR_INTERN_CHARMOVE$PCHAR$INT64$PCHAR$INT64$INT64(int64_t arg1, int64_t arg2, void* arg3, int64_t arg4, uint64_t arg5)
{
    return FPC_MOVE((arg2 + arg1), (arg3 + arg4), arg5);
}

uint64_t SYSTEM_$$_FPC_SHORTSTR_ANSISTR_INTERN_CHARMOVE$SHORTSTRING$INT64$RAWBYTESTRING$INT64$INT64(int64_t arg1, char arg2, int64_t* arg3, int64_t arg4, uint64_t arg5)
{
    return FPC_MOVE((arg2 + arg1), (*arg3 + arg4), arg5);
}

void* SYSTEM_$$_NEWANSISTRING$INT64$$POINTER(int64_t arg1)
{
    void* result;
    SYSTEM_$$_GETMEM$POINTER$QWORD(&result, (arg1 + 0x19));
    
    if (result != 0)
    {
        *(result + 8) = 1;
        *(result + 0x10) = 0;
        *result = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
        *(result + 2) = 1;
        result += 0x18;
        *result = 0;
    }
    
    return result;
}

void FPC_ANSISTR_DECR_REF(int64_t* arg1)
{
    if (*arg1 != 0)
    {
        void* rbx_1 = &*arg1[-6];
        *arg1 = 0;
        
        if ((*(rbx_1 + 8) >= 0 && SYSTEM_$$_DECLOCKED$INT64$$BOOLEAN((rbx_1 + 8)) != 0))
            SYSTEM_$$_FREEMEM$POINTER$$QWORD();
    }
}

void* FPC_ANSISTR_INCR_REF(void* arg1)
{
    if ((arg1 != 0 && *(arg1 - 0x10) >= 0))
        return SYSTEM_$$_INCLOCKED$INT64((arg1 - 0x10));
    
    return arg1;
}

void FPC_ANSISTR_ASSIGN(int64_t* arg1, int64_t arg2)
{
    if (arg2 != *arg1)
    {
        if ((arg2 != 0 && *(arg2 - 0x10) > 0))
            SYSTEM_$$_INCLOCKED$INT64((arg2 - 0x10));
        
        FPC_ANSISTR_DECR_REF(arg1);
        *arg1 = arg2;
    }
}

int64_t SYSTEM_$$_ANSISTR_CONCAT_COMPLEX$RAWBYTESTRING$RAWBYTESTRING$RAWBYTESTRING$WORD(int64_t arg1, uint16_t* arg2, uint16_t* arg3, int16_t arg4)
{
    int64_t r14;
    r14 = arg4;
    void* var_98 = nullptr;
    void* var_28 = nullptr;
    void* var_30 = nullptr;
    void var_90;
    void var_78;
    int64_t rbp;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_78, &var_90), arg1, rbp, arg2, arg3, r14, r15);
    int64_t result = 0;
    fpc_ansistr_to_unicodestr(&var_30, arg3);
    void* r13_1 = var_30;
    fpc_ansistr_to_unicodestr(&var_28, arg2);
    fpc_unicodestr_concat(&var_98, var_28, r13_1);
    void* rcx = var_98;
    
    if (rcx != 0)
        rcx = *(rcx - 8);
    
    data_434b68(var_98, arg1, r14, rcx);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_28);
    FPC_UNICODESTR_DECR_REF(&var_30);
    FPC_UNICODESTR_DECR_REF(&var_98);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t fpc_ansistr_concat(int64_t* arg1, uint64_t arg2, uint16_t* arg3, uint16_t arg4)
{
    uint16_t* var_30 = arg3;
    int64_t r13;
    r13 = arg4;
    arg3 = r13;
    
    if (arg3 == 0xffff)
        arg3 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    arg4 = arg3;
    int16_t temp0 = arg3;
    arg3 -= 1;
    
    if (temp0 <= 1)
        arg4 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    int64_t r15;
    r15 = arg4;
    int16_t rax;
    int64_t rbx;
    
    if (arg2 != 0)
    {
        rax = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg2);
        rbx = rax;
    }
    else
        rbx = r15;
    
    rax = rbx;
    arg3 = rax;
    
    if (rax <= 1)
        arg3 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    rbx = arg3;
    uint64_t rax_1;
    int64_t r12;
    
    if (var_30 != 0)
    {
        rax_1 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(var_30);
        r12 = rax_1;
    }
    else
        r12 = r15;
    
    rax_1 = r12;
    arg3 = rax_1;
    int16_t temp2 = rax_1;
    rax_1 -= 1;
    
    if (temp2 <= 1)
        arg3 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    if ((r13 == 0xffff && arg3 == rbx))
        r15 = rbx;
    
    if ((r15 != rbx || r15 != arg3))
        return SYSTEM_$$_ANSISTR_CONCAT_COMPLEX$RAWBYTESTRING$RAWBYTESTRING$RAWBYTESTRING$WORD(arg1, arg2, var_30, r15);
    
    if (arg2 == 0)
        return FPC_ANSISTR_ASSIGN(arg1, var_30);
    
    if (var_30 == 0)
        return FPC_ANSISTR_ASSIGN(arg1, arg2);
    
    uint64_t rax_4 = arg2;
    
    if (arg2 != 0)
        rax_4 = *(rax_4 - 8);
    
    uint64_t rax_5 = var_30;
    
    if (rax_5 != 0)
        rax_5 = *(rax_5 - 8);
    
    if (arg2 == *arg1)
    {
        rbx = var_30 == arg2;
        FPC_ANSISTR_SETLENGTH(arg1, (rax_5 + rax_4), 0);
        
        if (rbx == 0)
        {
            uint16_t* rdi_7 = var_30;
            
            if (rdi_7 == 0)
                rdi_7 = &FPC_EMPTYCHAR;
            
            SYSTEM_$$_FPC_PCHAR_ANSISTR_INTERN_CHARMOVE$PCHAR$INT64$RAWBYTESTRING$INT64$INT64(rdi_7, 0, arg1, rax_4, (rax_5 + 1));
        }
        else
        {
            uint16_t* rdi_6 = *arg1;
            
            if (rdi_6 == 0)
                rdi_6 = &FPC_EMPTYCHAR;
            
            SYSTEM_$$_FPC_PCHAR_ANSISTR_INTERN_CHARMOVE$PCHAR$INT64$RAWBYTESTRING$INT64$INT64(rdi_6, 0, arg1, rax_4, rax_5);
        }
    }
    else if (var_30 != *arg1)
    {
        FPC_ANSISTR_SETLENGTH(arg1, (rax_5 + rax_4), 0);
        uint64_t rdi_12 = arg2;
        
        if (arg2 == 0)
            rdi_12 = &FPC_EMPTYCHAR;
        
        SYSTEM_$$_FPC_PCHAR_ANSISTR_INTERN_CHARMOVE$PCHAR$INT64$RAWBYTESTRING$INT64$INT64(rdi_12, 0, arg1, 0, rax_4);
        uint16_t* rdi_13 = var_30;
        
        if (rdi_13 == 0)
            rdi_13 = &FPC_EMPTYCHAR;
        
        SYSTEM_$$_FPC_PCHAR_ANSISTR_INTERN_CHARMOVE$PCHAR$INT64$RAWBYTESTRING$INT64$INT64(rdi_13, 0, arg1, rax_4, (rax_5 + 1));
    }
    else
    {
        FPC_ANSISTR_SETLENGTH(arg1, (rax_5 + rax_4), 0);
        uint16_t* rdi_9 = *arg1;
        
        if (rdi_9 == 0)
            rdi_9 = &FPC_EMPTYCHAR;
        
        SYSTEM_$$_FPC_PCHAR_ANSISTR_INTERN_CHARMOVE$PCHAR$INT64$RAWBYTESTRING$INT64$INT64(rdi_9, 0, arg1, rax_4, (rax_5 + 1));
        uint64_t rdi_10 = arg2;
        
        if (arg2 == 0)
            rdi_10 = &FPC_EMPTYCHAR;
        
        SYSTEM_$$_FPC_PCHAR_ANSISTR_INTERN_CHARMOVE$PCHAR$INT64$RAWBYTESTRING$INT64$INT64(rdi_10, 0, arg1, 0, rax_4);
    }
    
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg1, r15, 0);
}

int64_t fpc_ansistr_concat_multi(int64_t* arg1, int64_t* arg2, int64_t arg3, int16_t arg4)
{
    int64_t rbx;
    int64_t var_d8 = rbx;
    int64_t r12;
    int64_t var_d0 = r12;
    int64_t r14;
    int64_t var_c0 = r14;
    int64_t r15;
    int64_t var_b8 = r15;
    int64_t r13;
    r13 = arg4;
    void* var_18 = nullptr;
    void* var_80 = nullptr;
    void var_70;
    void var_30;
    int64_t __saved_rbp;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_70, &var_30), rbx, &__saved_rbp, r12, r13, r14, r15);
    int64_t result = 0;
    
    if (arg3 != 0)
    {
        int16_t var_98_1 = r13;
        
        if (r13 == 0xffff)
        {
            int64_t rax_1;
            rax_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
            var_98_1 = rax_1;
        }
        
        uint64_t var_a8_1 = 0;
        
        while (true)
        {
            int64_t rax_2 = var_a8_1;
            
            if (arg3 < rax_2)
                break;
            
            if (*(arg2 + (rax_2 << 3)) != 0)
                break;
            
            var_a8_1 += 1;
        }
        
        if (var_a8_1 <= arg3)
        {
            uint16_t* rdx_1;
            rdx_1 = var_98_1;
            int64_t rax_3;
            rax_3 = var_98_1;
            int16_t temp0_1 = rax_3;
            rax_3 -= 1;
            
            if (temp0_1 <= 1)
                rdx_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
            
            int16_t var_98_2 = rdx_1;
            r12 = 1;
            uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_3 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg2[var_a8_1]);
            uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_3;
            
            if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_3 <= 1)
                U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
            
            int32_t rbx_1 = arg3;
            uint64_t rax_5;
            
            if (rbx_1 >= (var_a8_1 + 1))
            {
                int32_t r15_2 = var_a8_1;
                
                do
                {
                    r15_2 += 1;
                    
                    if (*(arg2 + (r15_2 << 3)) != 0)
                    {
                        rax_5 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg2[r15_2]);
                        uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 = rax_5;
                        int16_t temp2_1 = rax_5;
                        rax_5 -= 1;
                        
                        if (temp2_1 <= 1)
                            U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
                        
                        if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 != U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1)
                        {
                            r12 = 0;
                            break;
                        }
                    }
                } while (rbx_1 > r15_2);
            }
            
            if (r12 != 0)
            {
                if (r13 == 0xffff)
                {
                    rax_5 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
                    var_98_2 = rax_5;
                }
                
                int64_t var_10 = 0;
                int32_t r12_1 = var_a8_1;
                
                if (*arg1 != 0)
                {
                    if (arg2[var_a8_1] == *arg1)
                        var_a8_1 += 1;
                    
                    int32_t rbx_3 = arg3;
                    
                    if (rbx_3 >= var_a8_1)
                    {
                        int32_t r15_4 = (var_a8_1 - 1);
                        
                        do
                        {
                            r15_4 += 1;
                            
                            if (arg2[r15_4] == *arg1)
                            {
                                int64_t rdi_10 = *arg1;
                                var_10 = rdi_10;
                                FPC_ANSISTR_INCR_REF(rdi_10);
                                var_a8_1 = r12_1;
                                break;
                            }
                        } while (rbx_3 > r15_4);
                    }
                }
                
                if (r12_1 == var_a8_1)
                    FPC_ANSISTR_ASSIGN(arg1, 0);
                
                int64_t rdx_14 = *arg1;
                
                if (rdx_14 != 0)
                    rdx_14 = *(rdx_14 - 8);
                
                uint64_t rsi_4 = 0;
                int32_t rcx_4 = arg3;
                
                if (rcx_4 >= r12_1)
                {
                    int32_t r15_5 = (r12_1 - 1);
                    
                    do
                    {
                        r15_5 += 1;
                        void* rdx_16 = arg2[r15_5];
                        
                        if (rdx_16 != 0)
                            rdx_16 = *(rdx_16 - 8);
                        
                        rsi_4 += rdx_16;
                    } while (rcx_4 > r15_5);
                }
                
                FPC_ANSISTR_SETLENGTH(arg1, rsi_4, 0);
                char* r14_1 = (*arg1 + rdx_14);
                int32_t r13_1 = arg3;
                
                if (r13_1 >= var_a8_1)
                {
                    int32_t r15_6 = (var_a8_1 - 1);
                    
                    do
                    {
                        r15_6 += 1;
                        void* rbx_5 = arg2[r15_6];
                        
                        if (rbx_5 != 0)
                        {
                            void* rax_24 = rbx_5;
                            
                            if (rbx_5 != 0)
                                rax_24 = *(rax_24 - 8);
                            
                            FPC_MOVE(rbx_5, r14_1, (rax_24 + 1));
                            r14_1 += rax_24;
                        }
                    } while (r13_1 > r15_6);
                }
                
                int64_t* rdx_17;
                rdx_17 = 0;
                SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg1, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1, rdx_17);
                SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg1, var_98_2, 1);
                FPC_ANSISTR_DECR_REF(&var_10);
            }
            else
            {
                FPC_UNICODESTR_ASSIGN(&var_18, nullptr);
                int32_t rbx_2 = arg3;
                
                if (rbx_2 >= var_a8_1)
                {
                    int32_t r15_3 = (var_a8_1 - 1);
                    
                    do
                    {
                        r15_3 += 1;
                        
                        if (arg2[r15_3] != 0)
                        {
                            fpc_ansistr_to_unicodestr(&var_80, arg2[r15_3]);
                            fpc_unicodestr_concat(&var_18, var_18, var_80);
                        }
                    } while (rbx_2 > r15_3);
                }
                
                FPC_ANSISTR_ASSIGN(arg1, 0);
                void* rcx_1 = var_18;
                
                if (rcx_1 != 0)
                    rcx_1 = *(rcx_1 - 8);
                
                data_434b68(var_18, arg1, var_98_2, rcx_1);
            }
        }
        else
            FPC_ANSISTR_ASSIGN(arg1, 0);
    }
    else
        FPC_ANSISTR_ASSIGN(arg1, 0);
    
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_80);
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t FPC_ANSISTR_TO_ANSISTR(int64_t* arg1, uint16_t* arg2, int16_t arg3)
{
    int64_t r14;
    int64_t var_20 = r14;
    int64_t r13;
    r13 = arg3;
    void* var_88 = nullptr;
    void var_80;
    void var_68;
    int64_t rbp;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_80), arg2, rbp, arg1, r13, r14, r15);
    int64_t result = 0;
    FPC_ANSISTR_ASSIGN(arg1, 0);
    uint16_t* rax_1 = arg2;
    
    if (arg2 != 0)
        rax_1 = *(rax_1 - 8);
    
    uint64_t r14_1 = rax_1;
    
    if (r14_1 > 0)
    {
        rax_1 = r13;
        
        if (r13 <= 1)
            rax_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
        
        r13 = rax_1;
        uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg2);
        uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2;
        
        if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 <= 1)
            U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
        
        if ((r13 == U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 || U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 == 0xffff))
        {
            FPC_ANSISTR_SETLENGTH(arg1, r14_1, 0);
            FPC_MOVE(arg2, FPC_ANSISTR_UNIQUE(arg1), r14_1);
            *(*arg1 - 0x18) = r13;
        }
        else
        {
            fpc_ansistr_to_unicodestr(&var_88, arg2);
            void* rax_4 = var_88;
            
            if (rax_4 != 0)
                rax_4 = *(rax_4 - 8);
            
            data_434b68(var_88, arg1, r13, rax_4);
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_88);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

void FPC_ANSISTR_TO_SHORTSTR(char* arg1, uint64_t arg2, uint64_t arg3)
{
    if (arg3 == 0)
    {
        *arg1 = 0;
        return;
    }
    
    uint64_t rax_1 = arg3;
    
    if (arg3 != 0)
        rax_1 = *(rax_1 - 8);
    
    uint64_t rbx_1 = rax_1;
    
    if (arg2 < rbx_1)
        rbx_1 = arg2;
    
    FPC_MOVE(arg3, &arg1[1], rbx_1);
    *arg1 = rbx_1;
}

void* fpc_shortstr_to_ansistr(char** arg1, char* arg2, int16_t arg3)
{
    int64_t r13;
    r13 = arg3;
    
    if (arg3 <= 1)
        r13 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    uint64_t r14 = *arg2;
    void* result = FPC_ANSISTR_SETLENGTH(arg1, r14, 0);
    
    if (r14 <= 0)
        return result;
    
    FPC_MOVE(&arg2[1], *arg1, r14);
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg1, r13, 0);
}

int64_t fpc_char_to_ansistr(int64_t* arg1, char arg2, int16_t arg3)
{
    int64_t r12;
    r12 = arg2;
    int64_t r13;
    r13 = arg3;
    
    if (arg3 <= 1)
        r13 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    FPC_ANSISTR_SETLENGTH(arg1, 1, 0);
    uint16_t* rax = *arg1;
    
    if (rax == 0)
        rax = &FPC_EMPTYCHAR;
    
    *rax = r12;
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg1, r13, 0);
}

uint16_t fpc_pchar_to_ansistr(int64_t* arg1, char* arg2, int16_t arg3)
{
    int64_t r13;
    r13 = arg3;
    uint64_t r14;
    
    if ((arg2 == 0 || *arg2 == 0))
        r14 = 0;
    else
        r14 = SYSTEM_$$_INDEXCHAR$formal$INT64$CHAR$$INT64(arg2, -1, 0);
    
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = FPC_ANSISTR_SETLENGTH(arg1, r14, 0);
    
    if (r14 <= 0)
        return U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
    
    U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = r13;
    
    if (r13 <= 1)
        U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    r13 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
    FPC_MOVE(arg2, *arg1, r14);
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg1, r13, 0);
}

uint16_t fpc_chararray_to_ansistr(int64_t* arg1, char* arg2, int64_t arg3, int16_t arg4, char arg5)
{
    int64_t r15;
    r15 = arg4;
    uint64_t r13;
    
    if (arg5 == 0)
        r13 = (arg3 + 1);
    else if (*arg2 != 0)
    {
        r13 = SYSTEM_$$_INDEXCHAR$formal$INT64$CHAR$$INT64(arg2, (arg3 + 1), 0);
        
        if (r13 == -1)
            r13 = (arg3 + 1);
    }
    else
        r13 = 0;
    
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = FPC_ANSISTR_SETLENGTH(arg1, r13, 0);
    
    if (r13 <= 0)
        return U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
    
    U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = r15;
    
    if (r15 <= 1)
        U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    r15 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
    FPC_MOVE(arg2, *arg1, r13);
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg1, r15, 0);
}

int64_t fpc_ansistr_to_chararray(char* arg1, void* arg2, uint64_t arg3)
{
    uint64_t r13 = arg3;
    
    if (arg3 != 0)
        r13 = *(r13 - 8);
    
    if ((arg2 + 1) < r13)
        r13 = (arg2 + 1);
    
    if (r13 > 0)
        FPC_MOVE(arg3, arg1, r13);
    
    return SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(&arg1[r13], ((arg2 + 1) - r13), 0);
}

int64_t SYSTEM_$$_FPC_UTF8_COMPARE$RAWBYTESTRING$RAWBYTESTRING$$INT64(int64_t arg1, int64_t arg2)
{
    int64_t var_88 = 0;
    int64_t var_80 = 0;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t var_20 = 0;
    FPC_ANSISTR_ASSIGN(&var_88, arg1);
    FPC_ANSISTR_ASSIGN(&var_80, arg2);
    SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(&var_88, 0xfde9, 1);
    SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(&var_80, 0xfde9, 1);
    int64_t result = FPC_ANSISTR_COMPARE(var_88, var_80);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_88);
    FPC_ANSISTR_DECR_REF(&var_80);
    
    if (var_20 != 0)
        FPC_RERAISE();
    
    return result;
}

int64_t FPC_ANSISTR_COMPARE(int64_t arg1, int64_t arg2)
{
    if (arg2 == arg1)
        return 0;
    
    if (arg1 == 0)
    {
        int64_t rax_1 = arg2;
        
        if (arg2 != 0)
            rax_1 = *(rax_1 - 8);
        
        return -(rax_1);
    }
    
    if (arg2 == 0)
    {
        if (arg1 == 0)
            return arg1;
        
        return *(arg1 - 8);
    }
    
    int16_t rax_4 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg1);
    int64_t r14;
    r14 = rax_4;
    
    if (rax_4 <= 1)
        r14 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg2);
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2;
    
    if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 <= 1)
        U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 != r14)
        return SYSTEM_$$_FPC_UTF8_COMPARE$RAWBYTESTRING$RAWBYTESTRING$$INT64(arg1, arg2);
    
    int64_t rdx_1 = arg1;
    
    if (arg1 != 0)
        rdx_1 = *(rdx_1 - 8);
    
    int64_t rax_5 = arg2;
    
    if (arg2 != 0)
        rax_5 = *(rax_5 - 8);
    
    if (rax_5 < rdx_1)
        rdx_1 = rax_5;
    
    if (rdx_1 <= 0)
    {
        int64_t rax_9 = arg1;
        
        if (arg1 != 0)
            rax_9 = *(rax_9 - 8);
        
        int64_t rdx_3 = arg2;
        
        if (arg2 != 0)
            rdx_3 = *(rdx_3 - 8);
        
        return (rax_9 - rdx_3);
    }
    
    uint64_t rax_6 = SYSTEM_$$_COMPAREBYTE$formal$formal$INT64$$INT64(arg1, arg2, rdx_1);
    
    if (rax_6 != 0)
        return rax_6;
    
    int64_t rax_7 = arg1;
    
    if (arg1 != 0)
        rax_7 = *(rax_7 - 8);
    
    int64_t rdx_2 = arg2;
    
    if (arg2 != 0)
        rdx_2 = *(rdx_2 - 8);
    
    return (rax_7 - rdx_2);
}

uint64_t SYSTEM_$$_FPC_UTF8_COMPARE_EQUAL$RAWBYTESTRING$RAWBYTESTRING$$INT64(uint64_t arg1, int64_t arg2)
{
    void* var_88 = nullptr;
    void* var_80 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t var_20 = 0;
    FPC_ANSISTR_ASSIGN(&var_88, arg1);
    FPC_ANSISTR_ASSIGN(&var_80, arg2);
    SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(&var_88, 0xfde9, 1);
    SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(&var_80, 0xfde9, 1);
    void* rdx_3 = var_88;
    
    if (rdx_3 != 0)
        rdx_3 = *(rdx_3 - 8);
    
    void* rcx_1 = var_80;
    
    if (rcx_1 != 0)
        rcx_1 = *(rcx_1 - 8);
    
    void* result_1 = (rdx_3 - rcx_1);
    uint64_t result = result_1;
    
    if ((result_1 == 0 && rdx_3 > 0))
        result = SYSTEM_$$_COMPAREBYTE$formal$formal$INT64$$INT64(var_88, var_80, rdx_3);
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_88);
    FPC_ANSISTR_DECR_REF(&var_80);
    
    if (var_20 != 0)
        FPC_RERAISE();
    
    return result;
}

uint64_t FPC_ANSISTR_COMPARE_EQUAL(uint64_t arg1, void* arg2)
{
    if (arg2 == arg1)
        return 0;
    
    if ((arg1 == 0 || arg2 == 0))
        return -1;
    
    int16_t rax_1 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg1);
    int64_t r14;
    r14 = rax_1;
    
    if (rax_1 <= 1)
        r14 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg2);
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2;
    
    if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 <= 1)
        U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 != r14)
        return SYSTEM_$$_FPC_UTF8_COMPARE_EQUAL$RAWBYTESTRING$RAWBYTESTRING$$INT64(arg1, arg2);
    
    uint64_t rdx_1 = arg1;
    
    if (arg1 != 0)
        rdx_1 = *(rdx_1 - 8);
    
    void* rax_2 = arg2;
    
    if (arg2 != 0)
        rax_2 = *(rax_2 - 8);
    
    void* result = (rdx_1 - rax_2);
    
    if ((result == 0 && rdx_1 > 0))
        return SYSTEM_$$_COMPAREBYTE$formal$formal$INT64$$INT64(arg1, arg2, rdx_1);
    
    return result;
}

void* FPC_ANSISTR_RANGECHECK(void* arg1, int64_t arg2)
{
    if ((arg1 != 0 && (arg2 <= *(arg1 - 8) && arg2 >= 1)))
        return arg1;
    
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xc9, &data_40cb9d, &__saved_rbp);
}

void* FPC_ANSISTR_SETLENGTH(int64_t* arg1, uint64_t arg2, int16_t arg3)
{
    int64_t rbx;
    rbx = arg3;
    
    if (arg2 <= 0)
        return FPC_ANSISTR_DECR_REF(arg1);
    
    if (*arg1 == 0)
    {
        *arg1 = SYSTEM_$$_NEWANSISTRING$INT64$$POINTER(arg2);
        void* rax;
        rax = rbx;
        
        if (rbx <= 1)
            rax = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
        
        rbx = rax;
        *(*arg1 - 0x18) = rbx;
    }
    else if (*(*arg1 - 0x10) != 1)
    {
        void* rax_12 = SYSTEM_$$_NEWANSISTRING$INT64$$POINTER(arg2);
        uint64_t rdx_3 = rax_12;
        int64_t rax_13;
        rax_13 = *(*arg1 - 0x18);
        *(rdx_3 - 0x18) = rax_13;
        int64_t rax_14 = *arg1;
        
        if (rax_14 != 0)
            rax_14 = *(rax_14 - 8);
        
        if ((rax_14 + 1) > arg2)
            rdx_3 = arg2;
        
        if ((rax_14 + 1) <= arg2)
            rdx_3 = (rax_14 + 1);
        
        FPC_MOVE(*arg1, rax_12, rdx_3);
        FPC_ANSISTR_DECR_REF(arg1);
        *arg1 = rax_12;
    }
    else
    {
        int64_t rax_4 = (*arg1 - 0x18);
        int64_t rax_5 = SYSTEM_$$_MEMSIZE$POINTER$$QWORD();
        
        if (rax_5 < (arg2 + 0x19))
        {
            SYSTEM_$$_REALLOCMEM$POINTER$QWORD$$POINTER();
            *arg1 = (rax_4 + 0x18);
        }
        else if ((rax_5 > 0x20 && ((rax_5 + (rax_5 >> 0x3f)) >> 1) >= (arg2 + 0x19)))
        {
            SYSTEM_$$_REALLOCMEM$POINTER$QWORD$$POINTER();
            *arg1 = (rax_4 + 0x18);
        }
    }
    
    *(*arg1 + arg2) = 0;
    void* result = *arg1;
    *(result - 8) = arg2;
    return result;
}

void* SYSTEM_$$_FPC_TRUELY_ANSISTR_UNIQUE$POINTER$$POINTER(int64_t* arg1)
{
    int64_t r12 = *(*arg1 - 8);
    void* result = SYSTEM_$$_NEWANSISTRING$INT64$$POINTER(r12);
    FPC_MOVE(*arg1, result, (r12 + 1));
    *(result - 8) = r12;
    void* rax_1;
    rax_1 = *(*arg1 - 0x18);
    *(result - 0x18) = rax_1;
    FPC_ANSISTR_DECR_REF(arg1);
    *arg1 = result;
    return result;
}

void* FPC_ANSISTR_UNIQUE(int64_t* arg1)
{
    if ((*arg1 != 0 && *(*arg1 - 0x10) != 1))
        return SYSTEM_$$_FPC_TRUELY_ANSISTR_UNIQUE$POINTER$$POINTER(arg1);
    
    return *arg1;
}

int64_t fpc_ansistr_copy(void** arg1, void* arg2, int64_t arg3, void* arg4)
{
    void* r12 = arg4;
    void* r13 = nullptr;
    void* rbx_1 = (arg3 - 1);
    
    if (rbx_1 < 0)
        rbx_1 = nullptr;
    
    void* rax = arg2;
    
    if (arg2 != 0)
        rax = *(rax - 8);
    
    if ((rax < r12 || (rbx_1 + r12) > rax))
    {
        void* rax_1 = arg2;
        
        if (arg2 != 0)
            rax_1 = *(rax_1 - 8);
        
        r12 = (rax_1 - rbx_1);
    }
    
    if (r12 > 0)
    {
        void* rax_3 = SYSTEM_$$_NEWANSISTRING$INT64$$POINTER(r12);
        r13 = rax_3;
        
        if (rax_3 != 0)
        {
            FPC_MOVE((arg2 + rbx_1), r13, r12);
            *(r12 + r13) = 0;
            *(r13 - 8) = r12;
            char* rax_4;
            rax_4 = *(arg2 - 0x18);
            *(r13 - 0x18) = rax_4;
        }
    }
    
    int64_t result = FPC_ANSISTR_DECR_REF(arg1);
    *arg1 = r13;
    return result;
}

int64_t SYSTEM_$$_POS$SHORTSTRING$RAWBYTESTRING$INT64$$INT64(char* arg1, void* arg2, int64_t arg3)
{
    if ((*arg1 > 0 && arg3 > 0))
    {
        void* rax_1 = arg2;
        
        if (arg2 != 0)
            rax_1 = *(rax_1 - 8);
        
        if (rax_1 >= arg3)
        {
            void* rax_2 = arg2;
            
            if (arg2 != 0)
                rax_2 = *(rax_2 - 8);
            
            uint64_t rbx_1 = (rax_2 - *arg1);
            int64_t result = (arg3 - 1);
            void* r13_1 = ((arg2 + arg3) - 1);
            
            while (rbx_1 >= result)
            {
                result += 1;
                uint64_t rax_3;
                rax_3 = arg1[1];
                
                if ((rax_3 == *r13_1 && SYSTEM_$$_COMPAREBYTE$formal$formal$INT64$$INT64(&arg1[1], r13_1, *arg1) == 0))
                    return result;
                
                r13_1 += 1;
            }
        }
    }
    
    return 0;
}

int64_t SYSTEM_$$_POS$RAWBYTESTRING$RAWBYTESTRING$INT64$$INT64(char* arg1, void* arg2, int64_t arg3)
{
    char* rax = arg1;
    
    if (arg1 != 0)
        rax = *(rax - 8);
    
    if ((rax > 0 && arg3 > 0))
    {
        void* rax_1 = arg2;
        
        if (arg2 != 0)
            rax_1 = *(rax_1 - 8);
        
        if (rax_1 >= arg3)
        {
            void* rax_2 = arg2;
            
            if (arg2 != 0)
                rax_2 = *(rax_2 - 8);
            
            char* rcx_1 = arg1;
            
            if (arg1 != 0)
                rcx_1 = *(rcx_1 - 8);
            
            int64_t i = (arg3 - 1);
            char* r13_1 = ((arg2 + arg3) - 1);
            
            while ((rax_2 - rcx_1) >= i)
            {
                i += 1;
                void* rax_3;
                rax_3 = *r13_1;
                
                if (rax_3 == *arg1)
                {
                    char* rdx = arg1;
                    
                    if (arg1 != 0)
                        rdx = *(rdx - 8);
                    
                    if (SYSTEM_$$_COMPAREBYTE$formal$formal$INT64$$INT64(arg1, r13_1, rdx) == 0)
                        return i;
                }
                
                r13_1 = &r13_1[1];
            }
        }
    }
    
    return 0;
}

int64_t SYSTEM_$$_POS$CHAR$RAWBYTESTRING$INT64$$INT64(char arg1, void* arg2, int64_t arg3)
{
    if (arg3 >= 1)
    {
        void* rcx_1 = arg2;
        
        if (arg2 != 0)
            rcx_1 = *(rcx_1 - 8);
        
        if (rcx_1 >= arg3)
        {
            void* rcx_2 = ((arg2 + arg3) - 1);
            
            if (arg2 != 0)
                arg2 = *(arg2 - 8);
            
            if (arg2 >= arg3)
            {
                int64_t result = (arg3 - 1);
                
                do
                {
                    result += 1;
                    
                    if (arg1 == *rcx_2)
                        return result;
                    
                    rcx_2 += 1;
                } while (arg2 > result);
            }
        }
    }
    
    return 0;
}

long double FPC_VAL_REAL_ANSISTR(uint64_t arg1, int64_t* arg2)
{
    uint64_t rdx = arg1;
    
    if (arg1 != 0)
        rdx = *(rdx - 8);
    
    if (rdx > 0xff)
    {
        *arg2 = 0x100;
        return 0;
    }
    
    void var_108;
    FPC_ANSISTR_TO_SHORTSTR(&var_108, 0xff, arg1);
    return FPC_VAL_REAL_SHORTSTR(&var_108, arg2);
}

long double FPC_VAL_CURRENCY_ANSISTR(uint64_t arg1, int64_t* arg2)
{
    uint64_t rdx = arg1;
    
    if (arg1 != 0)
        rdx = *(rdx - 8);
    
    int64_t var_118;
    
    if (rdx <= 0xff)
    {
        void var_110;
        FPC_ANSISTR_TO_SHORTSTR(&var_110, 0xff, arg1);
        var_118 = (FPC_VAL_REAL_SHORTSTR(&var_110, arg2) * _$SYSTEM$_Ld29);
    }
    else
    {
        var_118 = 0;
        *arg2 = 0x100;
    }
    
    return var_118;
}

int64_t FPC_VAL_UINT_ANSISTR(uint64_t arg1, int64_t* arg2)
{
    uint64_t rax = arg1;
    
    if (arg1 != 0)
        rax = *(rax - 8);
    
    if (rax > 0xff)
    {
        *arg2 = 0x100;
        return 0;
    }
    
    void var_118;
    FPC_ANSISTR_TO_SHORTSTR(&var_118, 0xff, arg1);
    return FPC_VAL_UINT_SHORTSTR(&var_118, arg2);
}

int64_t FPC_VAL_SINT_ANSISTR(int64_t arg1, uint64_t arg2, int64_t* arg3)
{
    uint64_t rax = arg2;
    
    if (arg2 != 0)
        rax = *(rax - 8);
    
    if (rax > 0xff)
    {
        *arg3 = 0x100;
        return 0;
    }
    
    void var_118;
    FPC_ANSISTR_TO_SHORTSTR(&var_118, 0xff, arg2);
    return FPC_VAL_SINT_SHORTSTR(arg1, &var_118, arg3);
}

int64_t FPC_ANSISTR_FLOAT(int16_t arg1, int16_t arg2, int32_t arg3, int64_t* arg4, int16_t arg5, uint64_t arg6, int16_t arg7, int16_t arg8)
{
    int64_t r12;
    r12 = arg5;
    *arg4 = 0;
    int16_t var_130 = arg8;
    void var_118;
    SYSTEM_$$_STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING(arg1, arg2, arg3, &var_118, 0xff, arg6, arg7);
    fpc_shortstr_to_ansistr(arg4, &var_118, 0);
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg4, r12, 0);
}

int64_t FPC_ANSISTR_ENUM(int64_t arg1, int64_t arg2, void* arg3, int32_t* arg4, int64_t* arg5, int16_t arg6)
{
    int64_t r12;
    r12 = arg6;
    *arg5 = 0;
    void var_118;
    FPC_SHORTSTR_ENUM(arg1, arg2, arg3, arg4, &var_118, 0xff);
    fpc_shortstr_to_ansistr(arg5, &var_118, 0);
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg5, r12, 0);
}

int64_t FPC_ANSISTR_BOOL(char arg1, int64_t arg2, int64_t* arg3, int16_t arg4)
{
    int64_t r12;
    r12 = arg4;
    *arg3 = 0;
    void var_118;
    FPC_SHORTSTR_BOOL(arg1, arg2, &var_118, 0xff);
    fpc_shortstr_to_ansistr(arg3, &var_118, 0);
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg3, r12, 0);
}

uint64_t FPC_VAL_ENUM_ANSISTR(int32_t* arg1, uint64_t arg2, int64_t* arg3)
{
    void var_110;
    FPC_ANSISTR_TO_SHORTSTR(&var_110, 0xff, arg2);
    return FPC_VAL_ENUM_SHORTSTR(arg1, &var_110, arg3);
}

int64_t FPC_ANSISTR_CURRENCY(uint64_t arg1, int64_t arg2, int64_t arg3, int64_t* arg4, int16_t arg5)
{
    int64_t r12;
    r12 = arg5;
    *arg4 = 0;
    void var_110;
    FPC_SHORTSTR_CURRENCY(arg1, arg2, arg3, &var_110, 0xff);
    fpc_shortstr_to_ansistr(arg4, &var_110, 0);
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg4, r12, 0);
}

int64_t FPC_ANSISTR_VALUINT(uint64_t arg1, int64_t arg2, int64_t* arg3, int16_t arg4)
{
    int64_t r12;
    r12 = arg4;
    *arg3 = 0;
    void var_118;
    FPC_SHORTSTR_UINT(arg1, arg2, &var_118, 0xff);
    fpc_shortstr_to_ansistr(arg3, &var_118, 0);
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg3, r12, 0);
}

int64_t FPC_ANSISTR_VALSINT(int64_t arg1, int64_t arg2, int64_t* arg3, int16_t arg4)
{
    int64_t r12;
    r12 = arg4;
    *arg3 = 0;
    void var_118;
    FPC_SHORTSTR_SINT(arg1, arg2, &var_118, 0xff);
    fpc_shortstr_to_ansistr(arg3, &var_118, 0);
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg3, r12, 0);
}

void fpc_ansistr_delete(int64_t* arg1, int64_t arg2, void* arg3)
{
    void* r13 = arg3;
    void* r14 = *arg1;
    
    if (r14 != 0)
        r14 = *(r14 - 8);
    
    if ((r14 >= arg2 && (arg2 > 0 && r13 > 0)))
    {
        FPC_ANSISTR_UNIQUE(arg1);
        
        if ((r14 - arg2) < r13)
            r13 = ((r14 - arg2) + 1);
        
        if ((r14 - arg2) >= r13)
        {
            uint16_t* rdi_1 = *arg1;
            
            if (rdi_1 == 0)
                rdi_1 = &FPC_EMPTYCHAR;
            
            SYSTEM_$$_FPC_PCHAR_ANSISTR_INTERN_CHARMOVE$PCHAR$INT64$RAWBYTESTRING$INT64$INT64(rdi_1, ((arg2 - 1) + r13), arg1, (arg2 - 1), (((r14 - (arg2 - 1)) - r13) + 1));
        }
        
        FPC_ANSISTR_SETLENGTH(arg1, (r14 - r13), 0);
    }
}

int64_t fpc_ansistr_insert(uint16_t* arg1, int64_t* arg2, void* arg3)
{
    int64_t r12;
    int64_t var_10 = r12;
    int64_t r13;
    int64_t var_18 = r13;
    void* rbx = arg3;
    int64_t var_98 = 0;
    void var_90;
    void var_78;
    int64_t rbp;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_78, &var_90), rbx, rbp, r12, r13, arg1, arg2);
    int64_t result = 0;
    uint16_t* rax_1 = arg1;
    
    if (arg1 != 0)
        rax_1 = *(rax_1 - 8);
    
    if (rax_1 != 0)
    {
        if (rbx <= 0)
            rbx = 1;
        
        void* rax_2 = *arg2;
        
        if (rax_2 != 0)
            rax_2 = *(rax_2 - 8);
        
        if (rax_2 < rbx)
            rbx = (rax_2 + 1);
        
        uint16_t* rax_3 = arg1;
        
        if (arg1 != 0)
            rax_3 = *(rax_3 - 8);
        
        FPC_ANSISTR_SETLENGTH(&var_98, (rax_3 + rax_2), 0);
        void* rax_4 = *arg2;
        
        if (rax_4 != 0)
            rax_4 = *(rax_4 - 8);
        
        uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
        
        if (rax_4 == 0)
        {
            uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_3 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg1);
            U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_3;
            
            if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_3 <= 1)
                U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
            
            r13 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
        }
        else
        {
            uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(*arg2);
            U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2;
            
            if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 <= 1)
                U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
            
            r13 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
        }
        
        U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = 0;
        SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(&var_98, r13, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1);
        
        if ((rbx - 1) > 0)
        {
            uint16_t* rdi_5 = *arg2;
            
            if (rdi_5 == 0)
                rdi_5 = &FPC_EMPTYCHAR;
            
            SYSTEM_$$_FPC_PCHAR_ANSISTR_INTERN_CHARMOVE$PCHAR$INT64$RAWBYTESTRING$INT64$INT64(rdi_5, 0, &var_98, 0, (rbx - 1));
        }
        
        uint64_t r8_2 = arg1;
        
        if (arg1 != 0)
            r8_2 = *(r8_2 - 8);
        
        uint16_t* rdi_6 = arg1;
        
        if (arg1 == 0)
            rdi_6 = &FPC_EMPTYCHAR;
        
        SYSTEM_$$_FPC_PCHAR_ANSISTR_INTERN_CHARMOVE$PCHAR$INT64$RAWBYTESTRING$INT64$INT64(rdi_6, 0, &var_98, (rbx - 1), r8_2);
        
        if ((rax_2 - (rbx - 1)) > 0)
        {
            uint16_t* rax_7 = arg1;
            
            if (arg1 != 0)
                rax_7 = *(rax_7 - 8);
            
            uint16_t* rdi_7 = *arg2;
            
            if (rdi_7 == 0)
                rdi_7 = &FPC_EMPTYCHAR;
            
            SYSTEM_$$_FPC_PCHAR_ANSISTR_INTERN_CHARMOVE$PCHAR$INT64$RAWBYTESTRING$INT64$INT64(rdi_7, (rbx - 1), &var_98, (rax_7 + (rbx - 1)), (rax_2 - (rbx - 1)));
        }
        
        FPC_ANSISTR_ASSIGN(arg2, var_98);
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_98);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_STRINGOFCHAR$CHAR$INT64$$ANSISTRING(int64_t* arg1, char arg2, uint64_t arg3)
{
    int64_t r12;
    r12 = arg2;
    FPC_ANSISTR_SETLENGTH(arg1, arg3, 0);
    void* rsi_1 = *arg1;
    
    if (rsi_1 != 0)
        rsi_1 = *(rsi_1 - 8);
    
    return SYSTEM_$$_FILLCHAR$formal$INT64$CHAR(*arg1, rsi_1, r12);
}

uint64_t fpc_setstring_ansistr_pansichar(int64_t* arg1, int64_t arg2, uint64_t arg3, int16_t arg4)
{
    int64_t r14;
    r14 = arg4;
    *arg1 = 0;
    FPC_ANSISTR_SETLENGTH(arg1, arg3, 0);
    uint64_t result = SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg1, r14, 0);
    
    if (arg2 == 0)
        return result;
    
    return FPC_MOVE(arg2, *arg1, arg3);
}

int64_t fpc_setstring_ansistr_pwidechar(int64_t* arg1, int64_t arg2, uint64_t arg3, int16_t arg4)
{
    int64_t r13;
    r13 = arg4;
    *arg1 = 0;
    
    if ((arg2 != 0 && arg3 > 0))
        return U_$SYSTEM_$$_WIDESTRINGMANAGER(arg2, arg1, r13, arg3);
    
    FPC_ANSISTR_SETLENGTH(arg1, arg3, 0);
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg1, r13, 0);
}

uint64_t SYSTEM_$$_UPCASE$ANSISTRING$$ANSISTRING(int64_t* arg1, uint64_t arg2)
{
    uint64_t result_2 = arg2;
    
    if (arg2 != 0)
        arg2 = *(arg2 - 8);
    
    FPC_ANSISTR_SETLENGTH(arg1, arg2, 0);
    uint64_t result = result_2;
    
    if (result_2 != 0)
        result = *(result - 8);
    
    uint64_t result_1 = result;
    
    if (result_1 >= 1)
    {
        int64_t r12_1 = 0;
        
        do
        {
            r12_1 += 1;
            void* rax = FPC_ANSISTR_UNIQUE(arg1);
            result = SYSTEM_$$_UPCASE$CHAR$$CHAR(*((result_2 + r12_1) - 1));
            *((rax + r12_1) - 1) = result;
        } while (result_1 > r12_1);
    }
    
    return result;
}

uint64_t SYSTEM_$$_LOWERCASE$ANSISTRING$$ANSISTRING(int64_t* arg1, uint64_t arg2)
{
    uint64_t result_2 = arg2;
    
    if (arg2 != 0)
        arg2 = *(arg2 - 8);
    
    FPC_ANSISTR_SETLENGTH(arg1, arg2, 0);
    uint64_t result = result_2;
    
    if (result_2 != 0)
        result = *(result - 8);
    
    uint64_t result_1 = result;
    
    if (result_1 >= 1)
    {
        int64_t r12_1 = 0;
        
        do
        {
            r12_1 += 1;
            void* rax = FPC_ANSISTR_UNIQUE(arg1);
            result = SYSTEM_$$_LOWERCASE$CHAR$$CHAR(*((result_2 + r12_1) - 1));
            *((rax + r12_1) - 1) = result;
        } while (result_1 > r12_1);
    }
    
    return result;
}

uint64_t SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(void* arg1)
{
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
    
    if (arg1 == 0)
        U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    else
        U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = *(arg1 - 0x18);
    
    return U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
}

uint64_t SYSTEM_$$_STRINGELEMENTSIZE$RAWBYTESTRING$$WORD(void* arg1)
{
    int16_t rax;
    
    if (arg1 == 0)
        rax = 1;
    else
        rax = *(arg1 - 0x16);
    
    return rax;
}

int64_t SYSTEM_$$_STRINGREFCOUNT$RAWBYTESTRING$$INT64(void* arg1)
{
    if (arg1 == 0)
        return 0;
    
    return *(arg1 - 0x10);
}

int64_t SYSTEM_$$_INTERNALSETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(int64_t* arg1, int16_t arg2, char arg3)
{
    int64_t r12;
    r12 = arg2;
    int64_t r13;
    r13 = arg3;
    int64_t var_28 = 0;
    void var_88;
    void var_70;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_70, &var_88), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    
    if (r13 == 0)
    {
        FPC_ANSISTR_UNIQUE(arg1);
        *(*arg1 - 0x18) = r12;
    }
    else
    {
        FPC_ANSISTR_TO_ANSISTR(&var_28, *arg1, r12);
        FPC_ANSISTR_ASSIGN(arg1, var_28);
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_28);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

void SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(int64_t* arg1, int16_t arg2, char arg3)
{
    if (*arg1 != 0)
    {
        uint16_t* rax;
        rax = *arg1[-0xc];
        
        if (arg2 != rax)
        {
            uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = rax;
            int16_t temp0_1 = rax;
            rax -= 1;
            
            if (temp0_1 <= 1)
                U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
            
            rax = arg2;
            
            if (arg2 <= 1)
                rax = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
            
            if ((arg3 == 0 || rax == U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1))
                arg3 = 0;
            else
                arg3 = 1;
            
            if ((arg3 != 0 || *(*arg1 - 0x10) != 1))
                SYSTEM_$$_INTERNALSETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg1, arg2, arg3);
            else
                *arg1[-0xc] = arg2;
        }
    }
}

uint16_t SYSTEM_$$_SETMULTIBYTECONVERSIONCODEPAGE$WORD(uint16_t arg1)
{
    U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE = arg1;
    return arg1;
}

uint16_t SYSTEM_$$_SETMULTIBYTEFILESYSTEMCODEPAGE$WORD(uint16_t arg1)
{
    U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE = arg1;
    return arg1;
}

uint16_t SYSTEM_$$_SETMULTIBYTERTLFILESYSTEMCODEPAGE$WORD(uint16_t arg1)
{
    U_$SYSTEM_$$_DEFAULTRTLFILESYSTEMCODEPAGE = arg1;
    return arg1;
}

void* SYSTEM_$$_DEFAULTUNICODE2ANSIMOVE$PUNICODECHAR$RAWBYTESTRING$WORD$INT64(int16_t* arg1, int64_t* arg2, int16_t arg3, uint64_t arg4)
{
    int16_t* rbx = arg1;
    int64_t r13;
    r13 = arg3;
    void* result = FPC_ANSISTR_SETLENGTH(arg2, arg4, 0);
    
    if (*arg2 != 0)
    {
        result = SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg2, r13, 0);
        char* rcx = *arg2;
        
        if (arg4 >= 1)
        {
            result = nullptr;
            
            do
            {
                result += 1;
                
                if (*rbx >= 0x100)
                    *rcx = 0x3f;
                else
                    *rcx = *rbx;
                
                rbx = &rbx[1];
                rcx = &rcx[1];
            } while (arg4 > result);
        }
    }
    
    return result;
}

int64_t SYSTEM_$$_DEFAULTANSI2UNICODEMOVE$PCHAR$WORD$UNICODESTRING$INT64(char* arg1, int64_t arg2, int64_t* arg3, int64_t arg4)
{
    char* rbx = arg1;
    int64_t result = FPC_UNICODESTR_SETLENGTH(arg3, arg4);
    uint16_t* rcx = *arg3;
    
    if (arg4 >= 1)
    {
        result = 0;
        
        do
        {
            result += 1;
            *rcx = *rbx;
            rbx = &rbx[1];
            rcx = &rcx[1];
        } while (arg4 > result);
    }
    
    return result;
}

void* SYSTEM_$$_DEFAULTCHARLENGTHPCHAR$PCHAR$$INT64(char (* arg1)[0x10])
{
    return FPC_PCHAR_LENGTH(arg1);
}

int64_t SYSTEM_$$_DEFAULTCODEPOINTLENGTH$PCHAR$INT64$$INT64(char* arg1)
{
    if (*arg1 == 0)
        return 0;
    
    return 1;
}

uint64_t SYSTEM_$$_DEFAULTGETSTANDARDCODEPAGE$TSTANDARDCODEPAGEENUM$$WORD(int32_t arg1)
{
    uint16_t rax;
    
    if (arg1 == 3)
        rax = U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE;
    else
        rax = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    return rax;
}

int64_t SYSTEM_$$_GETUNICODESTRINGMANAGER$TUNICODESTRINGMANAGER(int64_t arg1)
{
    __builtin_memcpy(arg1, &U_$SYSTEM_$$_WIDESTRINGMANAGER, 0x19);
    return arg1;
}

int64_t SYSTEM_$$_SETUNICODESTRINGMANAGER$TUNICODESTRINGMANAGER$TUNICODESTRINGMANAGER(int64_t arg1, int64_t arg2)
{
    __builtin_memcpy(arg2, &U_$SYSTEM_$$_WIDESTRINGMANAGER, 0x19);
    __builtin_memcpy(&U_$SYSTEM_$$_WIDESTRINGMANAGER, arg1, 0x19);
    return arg1;
}

int64_t SYSTEM_$$_SETUNICODESTRINGMANAGER$TUNICODESTRINGMANAGER(int64_t arg1)
{
    __builtin_memcpy(&U_$SYSTEM_$$_WIDESTRINGMANAGER, arg1, 0x19);
    return arg1;
}

int64_t SYSTEM_$$_GETWIDESTRINGMANAGER$TUNICODESTRINGMANAGER(int64_t arg1)
{
    __builtin_memcpy(arg1, &U_$SYSTEM_$$_WIDESTRINGMANAGER, 0x19);
    return arg1;
}

int64_t SYSTEM_$$_SETWIDESTRINGMANAGER$TUNICODESTRINGMANAGER$TUNICODESTRINGMANAGER(int64_t arg1, int64_t arg2)
{
    __builtin_memcpy(arg2, &U_$SYSTEM_$$_WIDESTRINGMANAGER, 0x19);
    __builtin_memcpy(&U_$SYSTEM_$$_WIDESTRINGMANAGER, arg1, 0x19);
    return arg1;
}

int64_t SYSTEM_$$_SETWIDESTRINGMANAGER$TUNICODESTRINGMANAGER(int64_t arg1)
{
    __builtin_memcpy(&U_$SYSTEM_$$_WIDESTRINGMANAGER, arg1, 0x19);
    return arg1;
}

int64_t SYSTEM_$$_UNICODESTRINGERROR()
{
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xcc, &data_40dc49, &__saved_rbp);
}

void* SYSTEM_$$_NEWUNICODESTRING$INT64$$POINTER(int64_t arg1)
{
    void* result;
    SYSTEM_$$_GETMEM$POINTER$QWORD(&result, ((arg1 << 1) + 0x1a));
    
    if (result == 0)
        SYSTEM_$$_UNICODESTRINGERROR();
    else
    {
        *(result + 0x10) = arg1;
        *(result + 8) = 1;
        *result = U_$SYSTEM_$$_DEFAULTUNICODECODEPAGE;
        *(result + 2) = 2;
        result += 0x18;
        *result = 0;
    }
    
    return result;
}

void FPC_UNICODESTR_DECR_REF(int64_t* arg1)
{
    if (*arg1 != 0)
    {
        void* rbx_1 = &*arg1[-6];
        *arg1 = 0;
        
        if ((*(rbx_1 + 8) >= 0 && SYSTEM_$$_DECLOCKED$INT64$$BOOLEAN((rbx_1 + 8)) != 0))
            SYSTEM_$$_FREEMEM$POINTER$$QWORD();
    }
}

void* FPC_UNICODESTR_INCR_REF(void* arg1)
{
    if ((arg1 != 0 && *(arg1 - 0x10) >= 0))
        return SYSTEM_$$_INCLOCKED$INT64((arg1 - 0x10));
    
    return arg1;
}

int64_t FPC_UNICODESTR_TO_SHORTSTR(char* arg1, uint64_t arg2, uint64_t arg3)
{
    uint64_t var_88 = 0;
    void var_80;
    void var_68;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_80), arg2, rbp, arg1, arg3, r14, r15);
    int64_t result = 0;
    *arg1 = 0;
    uint64_t rax_1 = arg3;
    
    if (arg3 != 0)
        rax_1 = *(rax_1 - 8);
    
    if (rax_1 > 0)
    {
        if (arg2 < rax_1)
            rax_1 = arg2;
        
        uint16_t* rdi_1 = arg3;
        
        if (arg3 == 0)
            rdi_1 = &FPC_EMPTYCHAR;
        
        data_434b68(rdi_1, &var_88, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE, rax_1);
        FPC_ANSISTR_TO_SHORTSTR(arg1, arg2, var_88);
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_88);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t fpc_shortstr_to_unicodestr(void** arg1, char* arg2)
{
    int64_t result = FPC_UNICODESTR_ASSIGN(arg1, nullptr);
    uint64_t rcx = *arg2;
    
    if (rcx <= 0)
        return result;
    
    return data_434b70(&arg2[1], U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE, arg1, rcx);
}

uint16_t fpc_unicodestr_to_ansistr(int64_t* arg1, void* arg2, int16_t arg3)
{
    int64_t r13;
    r13 = arg3;
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = FPC_ANSISTR_ASSIGN(arg1, 0);
    void* rcx = arg2;
    
    if (arg2 != 0)
        rcx = *(rcx - 8);
    
    if (rcx <= 0)
        return U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
    
    U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = r13;
    
    if (r13 <= 1)
        U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    r13 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
    return data_434b68(arg2, arg1, r13);
}

int64_t fpc_ansistr_to_unicodestr(void** arg1, uint16_t* arg2)
{
    int64_t result = FPC_UNICODESTR_ASSIGN(arg1, nullptr);
    uint16_t* r13 = arg2;
    
    if (arg2 != 0)
        r13 = *(r13 - 8);
    
    if (r13 <= 0)
        return result;
    
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg2);
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2;
    
    if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 <= 1)
        U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    uint16_t* rdi_2 = arg2;
    
    if (arg2 == 0)
        rdi_2 = &FPC_EMPTYCHAR;
    
    return data_434b70(rdi_2, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1, arg1, r13);
}

uint64_t fpc_unicodestr_to_widestr(int64_t* arg1, void* arg2)
{
    void* r12 = arg2;
    
    if (arg2 != 0)
        arg2 = *(arg2 - 8);
    
    FPC_UNICODESTR_SETLENGTH(arg1, arg2);
    void* rdx = r12;
    
    if (r12 != 0)
        rdx = *(rdx - 8);
    
    return FPC_MOVE(r12, *arg1, (rdx << 1));
}

uint64_t fpc_widestr_to_unicodestr(int64_t* arg1, void* arg2)
{
    void* r12 = arg2;
    
    if (arg2 != 0)
        arg2 = *(arg2 - 8);
    
    FPC_UNICODESTR_SETLENGTH(arg1, arg2);
    void* rdx = r12;
    
    if (r12 != 0)
        rdx = *(rdx - 8);
    
    return FPC_MOVE(r12, *arg1, (rdx << 1));
}

uint64_t fpc_pwidechar_to_unicodestr(void** arg1, int16_t (* arg2)[0x8])
{
    uint64_t result = FPC_UNICODESTR_ASSIGN(arg1, nullptr);
    
    if (arg2 != 0)
    {
        int64_t rax = SYSTEM_$$_INDEXWORD$formal$INT64$WORD$$INT64(arg2, -1, 0);
        result = FPC_UNICODESTR_SETLENGTH(arg1, rax);
        
        if (rax > 0)
            return FPC_MOVE(arg2, *arg1, (rax << 1));
    }
    
    return result;
}

int64_t fpc_pwidechar_to_ansistr(int64_t* arg1, int16_t (* arg2)[0x8], int16_t arg3)
{
    int64_t r13;
    r13 = arg3;
    int64_t result = FPC_ANSISTR_ASSIGN(arg1, 0);
    
    if (arg2 != 0)
    {
        result = SYSTEM_$$_INDEXWORD$formal$INT64$WORD$$INT64(arg2, -1, 0);
        
        if (result > 0)
        {
            result = r13;
            
            if (r13 <= 1)
                result = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
            
            r13 = result;
            return U_$SYSTEM_$$_WIDESTRINGMANAGER(arg2, arg1, r13);
        }
    }
    
    return result;
}

int64_t fpc_pwidechar_to_shortstr(char* arg1, uint64_t arg2, int16_t (* arg3)[0x8])
{
    uint64_t var_88 = 0;
    void var_80;
    void var_68;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_80), arg1, rbp, arg2, arg3, r14, r15);
    int64_t result = 0;
    *arg1 = 0;
    
    if (arg3 != 0)
    {
        int64_t rax_1 = SYSTEM_$$_INDEXWORD$formal$INT64$WORD$$INT64(arg3, 0x7fffffffffffffff, 0);
        
        if (rax_1 > 0)
        {
            U_$SYSTEM_$$_WIDESTRINGMANAGER(arg3, &var_88, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE, rax_1);
            FPC_ANSISTR_TO_SHORTSTR(arg1, arg2, var_88);
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_88);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t FPC_UNICODESTR_ASSIGN(void** arg1, void* arg2)
{
    if ((arg2 != 0 && *(arg2 - 0x10) > 0))
        SYSTEM_$$_INCLOCKED$INT64((arg2 - 0x10));
    
    int64_t result = FPC_UNICODESTR_DECR_REF(arg1);
    *arg1 = arg2;
    return result;
}

uint64_t fpc_unicodestr_concat(char** arg1, void* arg2, void* arg3)
{
    if (arg2 == 0)
        return FPC_UNICODESTR_ASSIGN(arg1, arg3);
    
    if (arg3 == 0)
        return FPC_UNICODESTR_ASSIGN(arg1, arg2);
    
    void* rax_2 = arg2;
    
    if (arg2 != 0)
        rax_2 = *(rax_2 - 8);
    
    void* rax_3 = arg3;
    
    if (rax_3 != 0)
        rax_3 = *(rax_3 - 8);
    
    if (arg2 == *arg1)
    {
        int64_t rbx;
        rbx = arg3 == arg2;
        FPC_UNICODESTR_SETLENGTH(arg1, (rax_2 + rax_3));
        
        if (rbx == 0)
            return FPC_MOVE(arg3, &*arg1[(rax_2 << 1)], ((rax_3 + 1) << 1));
        
        return FPC_MOVE(*arg1, &*arg1[(rax_2 << 1)], (rax_3 << 1));
    }
    
    if (arg3 == *arg1)
    {
        FPC_UNICODESTR_SETLENGTH(arg1, (rax_2 + rax_3));
        FPC_MOVE(*arg1, &*arg1[(rax_2 << 1)], ((rax_3 + 1) << 1));
        return FPC_MOVE(arg2, *arg1, (rax_2 << 1));
    }
    
    FPC_UNICODESTR_ASSIGN(arg1, nullptr);
    FPC_UNICODESTR_SETLENGTH(arg1, (rax_2 + rax_3));
    FPC_MOVE(arg2, *arg1, (rax_2 << 1));
    return FPC_MOVE(arg3, &*arg1[(rax_2 << 1)], ((rax_3 + 1) << 1));
}

int64_t fpc_unicodestr_concat_multi(void** arg1, void* arg2, int64_t arg3)
{
    int32_t i = arg3;
    
    if (arg3 == 0)
        return FPC_UNICODESTR_ASSIGN(arg1, nullptr);
    
    void* var_10 = nullptr;
    int64_t r15_1 = 0;
    
    if (*arg2 == *arg1)
        r15_1 = 1;
    
    if (i >= r15_1)
    {
        uint64_t var_20_1 = (r15_1 - 1);
        
        do
        {
            var_20_1 += 1;
            
            if (*(arg2 + (var_20_1 << 3)) == *arg1)
            {
                void* rdi_1 = *arg1;
                var_10 = rdi_1;
                FPC_UNICODESTR_INCR_REF(rdi_1);
                r15_1 = 0;
                break;
            }
        } while (i > var_20_1);
    }
    
    if (r15_1 == 0)
        FPC_UNICODESTR_ASSIGN(arg1, nullptr);
    
    void* rax_6 = *arg1;
    
    if (rax_6 != 0)
        rax_6 = *(rax_6 - 8);
    
    void* rsi = nullptr;
    
    if (i >= 0)
    {
        int64_t var_20_2 = 0xffffffff;
        
        do
        {
            var_20_2 += 1;
            void* rcx_2 = *(arg2 + (var_20_2 << 3));
            
            if (rcx_2 != 0)
                rcx_2 = *(rcx_2 - 8);
            
            rsi += rcx_2;
        } while (i > var_20_2);
    }
    
    FPC_UNICODESTR_SETLENGTH(arg1, rsi);
    void* r14_1 = ((rax_6 << 1) + *arg1);
    
    if (i >= r15_1)
    {
        uint64_t var_20_3 = (r15_1 - 1);
        
        do
        {
            var_20_3 += 1;
            void* rbx_3 = *(arg2 + (var_20_3 << 3));
            
            if (rbx_3 != 0)
            {
                void* rax_13 = rbx_3;
                
                if (rbx_3 != 0)
                    rax_13 = *(rax_13 - 8);
                
                FPC_MOVE(rbx_3, r14_1, ((rax_13 + 1) << 1));
                r14_1 += (rax_13 << 1);
            }
        } while (i > var_20_3);
    }
    
    return FPC_UNICODESTR_DECR_REF(&var_10);
}

uint64_t fpc_char_to_uchar(char arg1, int64_t arg2 @ rbx)
{
    int64_t var_8 = arg2;
    char var_78 = arg1;
    int16_t* var_70 = nullptr;
    void var_68;
    void var_50;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_50, &var_68), arg2, rbp, r12, r13, r14, r15);
    int64_t var_10 = 0;
    data_434b70(&var_78, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE, &var_70, 1);
    arg2 = *var_70;
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_70);
    
    if (var_10 != 0)
        FPC_RERAISE();
    
    return arg2;
}

int64_t fpc_char_to_unicodestr(int64_t arg1, char arg2)
{
    char var_8 = arg2;
    return data_434b70(&var_8, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE, arg1, 1);
}

uint64_t fpc_uchar_to_char(int16_t arg1, int64_t arg2 @ rbx)
{
    int64_t var_8 = arg2;
    int16_t var_78 = arg1;
    char* var_70 = nullptr;
    void var_68;
    void var_50;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_50, &var_68), arg2, rbp, r12, r13, r14, r15);
    int64_t var_10 = 0;
    data_434b68(&var_78, &var_70, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE, 1);
    char* rax_1 = var_70;
    
    if (rax_1 != 0)
        rax_1 = *(rax_1 - 8);
    
    if (rax_1 != 1)
        arg2 = 0x3f;
    else
        arg2 = *var_70;
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_70);
    
    if (var_10 != 0)
        FPC_RERAISE();
    
    return arg2;
}

int64_t fpc_uchar_to_shortstr(char* arg1, int16_t arg2)
{
    int16_t var_78 = arg2;
    uint64_t var_70 = 0;
    void var_68;
    void var_50;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_50, &var_68), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    U_$SYSTEM_$$_WIDESTRINGMANAGER(&var_78, &var_70, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE, 1);
    FPC_ANSISTR_TO_SHORTSTR(arg1, 0xff, var_70);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_70);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

void* fpc_uchar_to_unicodestr(int64_t* arg1, int16_t arg2)
{
    int64_t r12;
    r12 = arg2;
    FPC_UNICODESTR_SETLENGTH(arg1, 1);
    void* result = FPC_UNICODESTR_UNIQUE(arg1);
    *result = r12;
    return result;
}

int64_t fpc_uchar_to_ansistr(int64_t arg1, int16_t arg2, uint16_t arg3)
{
    int16_t var_8 = arg2;
    
    if (arg3 <= 1)
        arg3 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    return data_434b68(&var_8, arg1, arg3, 1);
}

int64_t fpc_pchar_to_unicodestr(void** arg1, char* arg2)
{
    if ((arg2 == 0 || *arg2 == 0))
        return FPC_UNICODESTR_ASSIGN(arg1, nullptr);
    
    void* rax_1 = SYSTEM_$$_INDEXCHAR$formal$INT64$CHAR$$INT64(arg2, -1, 0);
    return data_434b70(arg2, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE, arg1, rax_1);
}

int64_t fpc_chararray_to_unicodestr(void** arg1, char* arg2, void* arg3, char arg4)
{
    void* rax_1;
    
    if (arg4 == 0)
        rax_1 = (arg3 + 1);
    else
    {
        if (*arg2 == 0)
            return FPC_UNICODESTR_ASSIGN(arg1, nullptr);
        
        rax_1 = SYSTEM_$$_INDEXCHAR$formal$INT64$CHAR$$INT64(arg2, (arg3 + 1), 0);
        
        if (rax_1 == -1)
            rax_1 = (arg3 + 1);
    }
    
    return data_434b70(arg2, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE, arg1, rax_1);
}

uint64_t fpc_widechararray_to_unicodestr(char** arg1, int16_t (* arg2)[0x8], int64_t arg3, char arg4)
{
    int64_t rax;
    
    if (arg4 == 0)
        rax = (arg3 + 1);
    else
    {
        rax = SYSTEM_$$_INDEXWORD$formal$INT64$WORD$$INT64(arg2, (arg3 + 1), 0);
        
        if (rax == -1)
            rax = (arg3 + 1);
    }
    
    FPC_UNICODESTR_SETLENGTH(arg1, rax);
    return FPC_MOVE(arg2, *arg1, (rax << 1));
}

int64_t FPC_WIDECHARARRAY_TO_SHORTSTR(char* arg1, uint64_t arg2, int16_t (* arg3)[0x8], int64_t arg4, char arg5)
{
    int64_t r13;
    r13 = arg5;
    uint64_t var_10 = 0;
    void var_68;
    void var_28;
    int64_t __saved_rbp;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_28), arg1, &__saved_rbp, arg3, r13, arg4, arg2);
    int32_t r14_1 = (arg4 + 1);
    
    if ((arg4 + 1) >= (arg2 + 1))
        r14_1 = arg2;
    else if (r14_1 < 0)
        r14_1 = 0;
    
    char rcx;
    
    if (r13 == 0)
        rcx = r14_1;
    else
    {
        int64_t rax_3 = SYSTEM_$$_INDEXWORD$formal$INT64$WORD$$INT64(arg3, r14_1, 0);
        
        if (rax_3 >= 0)
            rcx = rax_3;
        else
            rcx = r14_1;
    }
    
    U_$SYSTEM_$$_WIDESTRINGMANAGER(arg3, &var_10, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE, rcx);
    FPC_ANSISTR_TO_SHORTSTR(arg1, arg2, var_10);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_10);
    return 0;
}

int64_t fpc_widechararray_to_ansistr(int64_t* arg1, int16_t (* arg2)[0x8], int64_t arg3, int16_t arg4, char arg5)
{
    int64_t r13 = arg3;
    int64_t r14;
    r14 = arg4;
    int64_t rax;
    
    if (arg5 == 0)
        rax = (r13 + 1);
    else
    {
        rax = SYSTEM_$$_INDEXWORD$formal$INT64$WORD$$INT64(arg2, (r13 + 1), 0);
        
        if (rax == -1)
            rax = (r13 + 1);
    }
    
    if (rax <= 0)
        return FPC_ANSISTR_ASSIGN(arg1, 0);
    
    arg3 = r14;
    
    if (r14 <= 1)
        arg3 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    r14 = arg3;
    return U_$SYSTEM_$$_WIDESTRINGMANAGER(arg2, arg1, r14, rax);
}

uint64_t fpc_widechararray_to_widestr(char** arg1, int16_t (* arg2)[0x8], int64_t arg3, char arg4)
{
    int64_t rax;
    
    if (arg4 == 0)
        rax = (arg3 + 1);
    else
    {
        rax = SYSTEM_$$_INDEXWORD$formal$INT64$WORD$$INT64(arg2, (arg3 + 1), 0);
        
        if (rax == -1)
            rax = (arg3 + 1);
    }
    
    FPC_UNICODESTR_SETLENGTH(arg1, rax);
    return FPC_MOVE(arg2, *arg1, (rax << 1));
}

int64_t fpc_unicodestr_to_chararray(char* arg1, void* arg2, void* arg3)
{
    int64_t r14;
    int64_t var_78 = r14;
    void* var_10 = nullptr;
    void var_68;
    void var_28;
    int64_t __saved_rbp;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_28), arg2, &__saved_rbp, arg1, arg3, r14, r15);
    void* rax_1 = arg3;
    
    if (arg3 != 0)
        rax_1 = *(rax_1 - 8);
    
    if (rax_1 > 0)
        data_434b68(arg3, &var_10, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE, rax_1);
    
    void* rax_2 = var_10;
    
    if (rax_2 != 0)
        rax_2 = *(rax_2 - 8);
    
    void* r14_2 = rax_2;
    
    if ((arg2 + 1) < r14_2)
        r14_2 = (arg2 + 1);
    
    FPC_MOVE(var_10, arg1, r14_2);
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE((arg1 + r14_2), ((arg2 + 1) - r14_2), 0);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_10);
    return 0;
}

int64_t fpc_ansistr_to_widechararray(char* arg1, void* arg2, void* arg3)
{
    int64_t r14;
    int64_t var_78 = r14;
    void* var_10 = nullptr;
    void var_68;
    void var_28;
    int64_t __saved_rbp;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_28), arg2, &__saved_rbp, arg1, arg3, r14, r15);
    void* rax_1 = arg3;
    
    if (arg3 != 0)
        rax_1 = *(rax_1 - 8);
    
    if (rax_1 > 0)
    {
        uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg3);
        uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2;
        
        if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 <= 1)
            U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
        
        data_434ad8(arg3, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1, &var_10, rax_1);
    }
    
    void* rax_2 = var_10;
    
    if (rax_2 != 0)
        rax_2 = *(rax_2 - 8);
    
    void* r14_2 = rax_2;
    
    if ((arg2 + 1) < r14_2)
        r14_2 = (arg2 + 1);
    
    FPC_MOVE(var_10, arg1, (r14_2 << 1));
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(&arg1[(r14_2 << 1)], (((arg2 + 1) - r14_2) << 1), 0);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_10);
    return 0;
}

int64_t fpc_shortstr_to_widechararray(char* arg1, int64_t arg2, char* arg3)
{
    int64_t r14;
    int64_t var_78 = r14;
    void* var_10 = nullptr;
    void var_68;
    void var_28;
    int64_t __saved_rbp;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_28), arg2, &__saved_rbp, arg1, arg3, r14, r15);
    uint32_t rax_1 = *arg3;
    
    if (rax_1 > 0)
        data_434ad8(&arg3[1], U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE, &var_10, rax_1);
    
    void* rax_2 = var_10;
    
    if (rax_2 != 0)
        rax_2 = *(rax_2 - 8);
    
    int32_t r14_2 = rax_2;
    
    if (rax_2 > (arg2 + 1))
        r14_2 = (arg2 + 1);
    
    FPC_MOVE(var_10, arg1, (r14_2 << 1));
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(&arg1[(r14_2 << 1)], (((arg2 + 1) - r14_2) << 1), 0);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_10);
    return 0;
}

int64_t fpc_unicodestr_to_widechararray(char* arg1, void* arg2, void* arg3)
{
    void* r13 = arg3;
    
    if (arg3 != 0)
        r13 = *(r13 - 8);
    
    if ((arg2 + 1) < r13)
        r13 = (arg2 + 1);
    
    if (r13 > 0)
        FPC_MOVE(arg3, arg1, (r13 << 1));
    
    return SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(&arg1[(r13 << 1)], (((arg2 + 1) - r13) << 1), 0);
}

int64_t FPC_UNICODESTR_COMPARE(int16_t* arg1, int16_t* arg2)
{
    int16_t* rbx = arg1;
    int16_t* r12 = arg2;
    
    if (r12 == rbx)
        return 0;
    
    uint64_t rdx_1 = rbx;
    
    if (rbx != 0)
        rdx_1 = *(rdx_1 - 8);
    
    uint64_t rax_1 = r12;
    
    if (r12 != 0)
        rax_1 = *(rax_1 - 8);
    
    if (rax_1 < rdx_1)
        rdx_1 = rax_1;
    
    int64_t result = SYSTEM_$$_COMPAREWORD$formal$formal$INT64$$INT64(rbx, r12, rdx_1);
    
    if (result != 0)
        return result;
    
    if (rbx != 0)
        rbx = *(rbx - 8);
    
    if (r12 != 0)
        r12 = *(r12 - 8);
    
    return (rbx - r12);
}

int64_t FPC_UNICODESTR_COMPARE_EQUAL(int16_t* arg1, int16_t* arg2)
{
    if (arg2 == arg1)
        return 0;
    
    uint64_t rdx_1 = arg1;
    
    if (arg1 != 0)
        rdx_1 = *(rdx_1 - 8);
    
    int16_t* rax_1 = arg2;
    
    if (arg2 != 0)
        rax_1 = *(rax_1 - 8);
    
    if (rax_1 == rdx_1)
        return SYSTEM_$$_COMPAREWORD$formal$formal$INT64$$INT64(arg1, arg2, rdx_1);
    
    return -1;
}

void* FPC_UNICODESTR_RANGECHECK(void* arg1, int64_t arg2)
{
    if ((arg1 != 0 && (arg2 <= *(arg1 - 8) && arg2 >= 1)))
        return arg1;
    
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xc9, &data_40ef8d, &__saved_rbp);
}

int64_t FPC_UNICODESTR_SETLENGTH(int64_t* arg1, int64_t arg2)
{
    if (arg2 <= 0)
        return FPC_UNICODESTR_DECR_REF(arg1);
    
    if (*arg1 == 0)
        *arg1 = SYSTEM_$$_NEWUNICODESTRING$INT64$$POINTER(arg2);
    else if (*(*arg1 - 0x10) != 1)
    {
        char* rax_8 = SYSTEM_$$_NEWUNICODESTRING$INT64$$POINTER(arg2);
        int64_t rax_9 = *arg1;
        
        if (rax_9 != 0)
            rax_9 = *(rax_9 - 8);
        
        if (rax_9 > 0)
        {
            int64_t rax_10 = *arg1;
            
            if (rax_10 != 0)
                rax_10 = *(rax_10 - 8);
            
            int64_t rax_12;
            
            if ((rax_10 + 1) <= arg2)
            {
                int64_t rdx_3 = *arg1;
                
                if (rdx_3 != 0)
                    rdx_3 = *(rdx_3 - 8);
                
                rax_12 = (rdx_3 + 1);
            }
            else
                rax_12 = arg2;
            
            FPC_MOVE(*arg1, rax_8, (rax_12 << 1));
        }
        
        FPC_UNICODESTR_DECR_REF(arg1);
        *arg1 = rax_8;
    }
    else
    {
        int64_t rax_3 = (*arg1 - 0x18);
        int64_t rax_4 = SYSTEM_$$_MEMSIZE$POINTER$$QWORD();
        
        if (rax_4 < ((arg2 << 1) + 0x1a))
        {
            SYSTEM_$$_REALLOCMEM$POINTER$QWORD$$POINTER();
            *arg1 = (rax_3 + 0x18);
        }
        else if ((rax_4 > 0x20 && (rax_4 >> 1) >= ((arg2 << 1) + 0x1a)))
        {
            SYSTEM_$$_REALLOCMEM$POINTER$QWORD$$POINTER();
            *arg1 = (rax_3 + 0x18);
        }
    }
    
    *((arg2 << 1) + *arg1) = 0;
    int64_t result = *arg1;
    *(result - 8) = arg2;
    return result;
}

int64_t SYSTEM_$$_UNICODECHARTOSTRING$PUNICODECHAR$$UNICODESTRING(int64_t* arg1, int16_t (* arg2)[0x8])
{
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_pwidechar_to_unicodestr(&var_18, arg2);
    void* rdx_1 = var_18;
    
    if (rdx_1 != 0)
        rdx_1 = *(rdx_1 - 8);
    
    SYSTEM_$$_UNICODECHARLENTOSTRING$PUNICODECHAR$INT64$$UNICODESTRING(arg1, arg2, rdx_1);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

char* SYSTEM_$$_STRINGTOUNICODECHAR$RAWBYTESTRING$PUNICODECHAR$INT64$$PUNICODECHAR(uint16_t* arg1, char* arg2, void* arg3)
{
    return SYSTEM_$$_STRINGTOWIDECHAR$RAWBYTESTRING$PWIDECHAR$INT64$$PWIDECHAR(arg1, arg2, arg3);
}

int64_t SYSTEM_$$_WIDECHARTOSTRING$PWIDECHAR$$UNICODESTRING(int64_t* arg1, int16_t (* arg2)[0x8])
{
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_pwidechar_to_unicodestr(&var_18, arg2);
    void* rdx_1 = var_18;
    
    if (rdx_1 != 0)
        rdx_1 = *(rdx_1 - 8);
    
    SYSTEM_$$_WIDECHARLENTOSTRING$PWIDECHAR$INT64$$UNICODESTRING(arg1, arg2, rdx_1);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

char* SYSTEM_$$_STRINGTOWIDECHAR$RAWBYTESTRING$PWIDECHAR$INT64$$PWIDECHAR(uint16_t* arg1, char* arg2, void* arg3)
{
    void* var_88 = nullptr;
    void var_80;
    void var_68;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_80), arg2, rbp, arg1, arg3, r14, r15);
    int64_t var_28 = 0;
    SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg1);
    uint16_t* rdi_2 = arg1;
    
    if (arg1 == 0)
        rdi_2 = &FPC_EMPTYCHAR;
    
    data_434ad8(rdi_2);
    void* r12_1 = var_88;
    
    if (r12_1 != 0)
        r12_1 = *(r12_1 - 8);
    
    if (r12_1 >= arg3)
        r12_1 = (arg3 - 1);
    
    FPC_MOVE(var_88, arg2, (r12_1 << 1));
    *(arg2 + (r12_1 << 1)) = 0;
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_88);
    
    if (var_28 != 0)
        FPC_RERAISE();
    
    return arg2;
}

uint64_t SYSTEM_$$_UNICODECHARLENTOSTRING$PUNICODECHAR$INT64$$UNICODESTRING(int64_t* arg1, int64_t arg2, int64_t arg3)
{
    FPC_UNICODESTR_SETLENGTH(arg1, arg3);
    return FPC_MOVE(arg2, *arg1, (arg3 << 1));
}

int64_t SYSTEM_$$_UNICODECHARLENTOSTRVAR$PUNICODECHAR$INT64$UNICODESTRING(int64_t arg1, int64_t arg2, int64_t* arg3)
{
    *arg3 = 0;
    void* var_28 = nullptr;
    void var_88;
    void var_70;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_70, &var_88), arg1, rbp, arg2, arg3, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_UNICODECHARLENTOSTRING$PUNICODECHAR$INT64$$UNICODESTRING(&var_28, arg1, arg2);
    FPC_UNICODESTR_ASSIGN(arg3, var_28);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_28);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_UNICODECHARLENTOSTRVAR$PUNICODECHAR$INT64$ANSISTRING(int64_t arg1, int64_t arg2, int64_t* arg3)
{
    *arg3 = 0;
    void* var_28 = nullptr;
    void var_88;
    void var_70;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_70, &var_88), arg1, rbp, arg2, arg3, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_UNICODECHARLENTOSTRING$PUNICODECHAR$INT64$$UNICODESTRING(&var_28, arg1, arg2);
    fpc_unicodestr_to_ansistr(arg3, var_28, 0);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_28);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_UNICODECHARTOSTRVAR$PUNICODECHAR$ANSISTRING(int16_t (* arg1)[0x8], int64_t* arg2)
{
    *arg2 = 0;
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_UNICODECHARTOSTRING$PUNICODECHAR$$UNICODESTRING(&var_18, arg1);
    fpc_unicodestr_to_ansistr(arg2, var_18, 0);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

uint64_t SYSTEM_$$_WIDECHARLENTOSTRING$PWIDECHAR$INT64$$UNICODESTRING(int64_t* arg1, int64_t arg2, int64_t arg3)
{
    FPC_UNICODESTR_SETLENGTH(arg1, arg3);
    return FPC_MOVE(arg2, *arg1, (arg3 << 1));
}

int64_t SYSTEM_$$_WIDECHARLENTOSTRVAR$PWIDECHAR$INT64$UNICODESTRING(int64_t arg1, int64_t arg2, int64_t* arg3)
{
    *arg3 = 0;
    void* var_28 = nullptr;
    void var_88;
    void var_70;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_70, &var_88), arg1, rbp, arg2, arg3, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_WIDECHARLENTOSTRING$PWIDECHAR$INT64$$UNICODESTRING(&var_28, arg1, arg2);
    FPC_UNICODESTR_ASSIGN(arg3, var_28);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_28);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_WIDECHARLENTOSTRVAR$PWIDECHAR$INT64$ANSISTRING(int64_t arg1, int64_t arg2, int64_t* arg3)
{
    *arg3 = 0;
    void* var_28 = nullptr;
    void var_88;
    void var_70;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_70, &var_88), arg1, rbp, arg2, arg3, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_WIDECHARLENTOSTRING$PWIDECHAR$INT64$$UNICODESTRING(&var_28, arg1, arg2);
    fpc_unicodestr_to_ansistr(arg3, var_28, 0);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_28);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_WIDECHARTOSTRVAR$PWIDECHAR$UNICODESTRING(int16_t (* arg1)[0x8], int64_t* arg2)
{
    *arg2 = 0;
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_WIDECHARTOSTRING$PWIDECHAR$$UNICODESTRING(&var_18, arg1);
    FPC_UNICODESTR_ASSIGN(arg2, var_18);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_WIDECHARTOSTRVAR$PWIDECHAR$ANSISTRING(int16_t (* arg1)[0x8], int64_t* arg2)
{
    *arg2 = 0;
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_WIDECHARTOSTRING$PWIDECHAR$$UNICODESTRING(&var_18, arg1);
    fpc_unicodestr_to_ansistr(arg2, var_18, 0);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

void* FPC_UNICODESTR_UNIQUE(int64_t* arg1)
{
    if ((*arg1 == 0 || *(*arg1 - 0x10) == 1))
        return *arg1;
    
    int64_t r12_1 = *(*arg1 - 8);
    void* result = SYSTEM_$$_NEWUNICODESTRING$INT64$$POINTER(r12_1);
    FPC_MOVE(*arg1, result, ((r12_1 + 1) << 1));
    *(result - 8) = r12_1;
    FPC_UNICODESTR_DECR_REF(arg1);
    *arg1 = result;
    return result;
}

int64_t fpc_unicodestr_copy(void** arg1, uint16_t* arg2, int64_t arg3, void* arg4)
{
    void* r12 = arg4;
    void* r13 = nullptr;
    void* rbx_1 = (arg3 - 1);
    
    if (rbx_1 < 0)
        rbx_1 = nullptr;
    
    uint16_t* rax = arg2;
    
    if (arg2 != 0)
        rax = *(rax - 8);
    
    if ((rax < r12 || (rbx_1 + r12) > rax))
    {
        uint16_t* rax_1 = arg2;
        
        if (arg2 != 0)
            rax_1 = *(rax_1 - 8);
        
        r12 = (rax_1 - rbx_1);
    }
    
    if (r12 > 0)
    {
        r13 = SYSTEM_$$_NEWUNICODESTRING$INT64$$POINTER(r12);
        uint16_t* rax_4 = arg2;
        
        if (arg2 == 0)
            rax_4 = &FPC_EMPTYCHAR;
        
        FPC_MOVE(&rax_4[rbx_1], r13, (r12 << 1));
        *(r13 - 8) = r12;
        *((r12 << 1) + r13) = 0;
    }
    
    int64_t result = FPC_UNICODESTR_DECR_REF(arg1);
    *arg1 = r13;
    return result;
}

int64_t SYSTEM_$$_POS$UNICODESTRING$UNICODESTRING$INT64$$INT64(uint64_t arg1, void* arg2, int64_t arg3)
{
    uint64_t rax = arg1;
    
    if (arg1 != 0)
        rax = *(rax - 8);
    
    if ((rax > 0 && arg3 > 0))
    {
        void* rax_1 = arg2;
        
        if (arg2 != 0)
            rax_1 = *(rax_1 - 8);
        
        if (rax_1 >= arg3)
        {
            void* rdx = arg2;
            
            if (arg2 != 0)
                rdx = *(rdx - 8);
            
            uint64_t rax_2 = arg1;
            
            if (arg1 != 0)
                rax_2 = *(rax_2 - 8);
            
            int64_t i = 0;
            void* rbx_1 = ((arg2 + (arg3 << 1)) - 2);
            
            while (((rdx - rax_2) - (arg3 - 1)) >= i)
            {
                i += 1;
                int64_t rax_3;
                rax_3 = *rbx_1;
                
                if (rax_3 == *arg1)
                {
                    uint64_t rdx_3 = arg1;
                    
                    if (arg1 != 0)
                        rdx_3 = *(rdx_3 - 8);
                    
                    if (SYSTEM_$$_COMPAREWORD$formal$formal$INT64$$INT64(arg1, rbx_1, rdx_3) == 0)
                        return ((arg3 + i) - 1);
                }
                
                rbx_1 += 2;
            }
        }
    }
    
    return 0;
}

int64_t SYSTEM_$$_POS$WIDECHAR$UNICODESTRING$INT64$$INT64(int16_t arg1, void* arg2, int64_t arg3)
{
    if (arg3 > 0)
    {
        void* rax_1 = arg2;
        
        if (arg2 != 0)
            rax_1 = *(rax_1 - 8);
        
        if (rax_1 >= arg3)
        {
            void* rcx_1 = ((arg2 + (arg3 << 1)) - 2);
            
            if (arg2 != 0)
                arg2 = *(arg2 - 8);
            
            if (arg2 >= arg3)
            {
                int64_t result = (arg3 - 1);
                
                do
                {
                    result += 1;
                    
                    if (arg1 == *rcx_1)
                        return result;
                    
                    rcx_1 += 2;
                } while (arg2 > result);
            }
        }
    }
    
    return 0;
}

uint16_t* SYSTEM_$$_POS$RAWBYTESTRING$UNICODESTRING$INT64$$INT64(uint16_t* arg1, void* arg2, int64_t arg3)
{
    uint64_t var_28 = 0;
    void var_88;
    void var_70;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_70, &var_88), arg1, rbp, arg2, arg3, r14, r15);
    int64_t var_30 = 0;
    fpc_ansistr_to_unicodestr(&var_28, arg1);
    uint16_t* result = SYSTEM_$$_POS$UNICODESTRING$UNICODESTRING$INT64$$INT64(var_28, arg2, arg3);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_28);
    
    if (var_30 != 0)
        FPC_RERAISE();
    
    return result;
}

char* SYSTEM_$$_POS$SHORTSTRING$UNICODESTRING$INT64$$INT64(char* arg1, void* arg2, int64_t arg3)
{
    uint64_t var_28 = 0;
    void var_88;
    void var_70;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_70, &var_88), arg1, rbp, arg2, arg3, r14, r15);
    int64_t var_30 = 0;
    fpc_shortstr_to_unicodestr(&var_28, arg1);
    char* result = SYSTEM_$$_POS$UNICODESTRING$UNICODESTRING$INT64$$INT64(var_28, arg2, arg3);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_28);
    
    if (var_30 != 0)
        FPC_RERAISE();
    
    return result;
}

uint64_t SYSTEM_$$_POS$UNICODESTRING$RAWBYTESTRING$INT64$$INT64(uint64_t arg1, uint16_t* arg2, int64_t arg3)
{
    void* var_28 = nullptr;
    void var_88;
    void var_70;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_70, &var_88), arg1, rbp, arg2, arg3, r14, r15);
    int64_t var_30 = 0;
    fpc_ansistr_to_unicodestr(&var_28, arg2);
    uint64_t result = SYSTEM_$$_POS$UNICODESTRING$UNICODESTRING$INT64$$INT64(arg1, var_28, arg3);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_28);
    
    if (var_30 != 0)
        FPC_RERAISE();
    
    return result;
}

int64_t SYSTEM_$$_POS$CHAR$UNICODESTRING$INT64$$INT64(char arg1, void* arg2, int64_t arg3)
{
    void* rbx = arg2;
    
    if (arg3 > 0)
    {
        void* rax_1 = rbx;
        
        if (rbx != 0)
            rax_1 = *(rax_1 - 8);
        
        if (rax_1 >= arg3)
        {
            int16_t rax_2 = fpc_char_to_uchar(arg1, rbx);
            void* rcx_1 = ((rbx + (arg3 << 1)) - 2);
            
            if (rbx != 0)
                rbx = *(rbx - 8);
            
            if (rbx >= arg3)
            {
                int64_t result = (arg3 - 1);
                
                do
                {
                    result += 1;
                    
                    if (rax_2 == *rcx_1)
                        return result;
                    
                    rcx_1 += 2;
                } while (rbx > result);
            }
        }
    }
    
    return 0;
}

void fpc_unicodestr_delete(int64_t* arg1, int64_t arg2, void* arg3)
{
    void* r13 = arg3;
    void* r14 = *arg1;
    
    if (r14 != 0)
        r14 = *(r14 - 8);
    
    if ((r14 >= arg2 && (arg2 > 0 && r13 > 0)))
    {
        FPC_UNICODESTR_UNIQUE(arg1);
        
        if ((r14 - arg2) < r13)
            r13 = ((r14 - arg2) + 1);
        
        if ((r14 - arg2) >= r13)
        {
            uint16_t* rax_11 = *arg1;
            
            if (rax_11 == 0)
                rax_11 = &FPC_EMPTYCHAR;
            
            uint16_t* rax_12 = *arg1;
            
            if (rax_12 == 0)
                rax_12 = &FPC_EMPTYCHAR;
            
            FPC_MOVE(&rax_11[((arg2 - 1) + r13)], &rax_12[(arg2 - 1)], ((((r14 - (arg2 - 1)) - r13) + 1) << 1));
        }
        
        FPC_UNICODESTR_SETLENGTH(arg1, (r14 - r13));
    }
}

int64_t fpc_unicodestr_insert(uint16_t* arg1, int64_t* arg2, void* arg3)
{
    int64_t r14;
    int64_t var_20 = r14;
    uint16_t* r12 = arg1;
    void* r13 = arg3;
    char* var_88 = nullptr;
    void var_80;
    void var_68;
    int64_t rbp;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_80), arg2, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    uint16_t* rax_1 = r12;
    
    if (r12 != 0)
        rax_1 = *(rax_1 - 8);
    
    if (rax_1 != 0)
    {
        if (r13 <= 0)
            r13 = 1;
        
        void* rax_2 = *arg2;
        
        if (rax_2 != 0)
            rax_2 = *(rax_2 - 8);
        
        if (rax_2 < r13)
            r13 = (rax_2 + 1);
        
        uint16_t* rax_3 = r12;
        
        if (r12 != 0)
            rax_3 = *(rax_3 - 8);
        
        FPC_UNICODESTR_SETLENGTH(&var_88, (rax_3 + rax_2));
        
        if ((r13 - 1) > 0)
        {
            uint16_t* rdi_2 = *arg2;
            
            if (rdi_2 == 0)
                rdi_2 = &FPC_EMPTYCHAR;
            
            char* rsi_2 = var_88;
            
            if (rsi_2 == 0)
                rsi_2 = &FPC_EMPTYCHAR;
            
            FPC_MOVE(rdi_2, rsi_2, ((r13 - 1) << 1));
        }
        
        uint16_t* rdx_3 = r12;
        
        if (r12 != 0)
            rdx_3 = *(rdx_3 - 8);
        
        char* rax_4 = var_88;
        
        if (rax_4 == 0)
            rax_4 = &FPC_EMPTYCHAR;
        
        uint16_t* rdi_3 = r12;
        
        if (r12 == 0)
            rdi_3 = &FPC_EMPTYCHAR;
        
        FPC_MOVE(rdi_3, &rax_4[((r13 - 1) << 1)], (rdx_3 << 1));
        
        if ((rax_2 - (r13 - 1)) > 0)
        {
            char* rdx_5 = var_88;
            
            if (rdx_5 == 0)
                rdx_5 = &FPC_EMPTYCHAR;
            
            if (r12 != 0)
                r12 = *(r12 - 8);
            
            uint16_t* rax_8 = *arg2;
            
            if (rax_8 == 0)
                rax_8 = &FPC_EMPTYCHAR;
            
            FPC_MOVE(&rax_8[(r13 - 1)], &rdx_5[((r12 + (r13 - 1)) << 1)], ((rax_2 - (r13 - 1)) << 1));
        }
        
        FPC_UNICODESTR_ASSIGN(arg2, var_88);
    }
    
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_88);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

uint64_t SYSTEM_$$_UPCASE$WIDECHAR$$WIDECHAR(int16_t arg1, int64_t arg2 @ rbx)
{
    int64_t var_8 = arg2;
    int64_t r12;
    r12 = arg1;
    int64_t var_20 = 0;
    int16_t* var_28 = nullptr;
    void var_88;
    void var_70;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_70, &var_88), arg2, rbp, r12, r13, r14, r15);
    int64_t var_30 = 0;
    
    if ((r12 >= 0x61 && r12 <= 0x7a))
        arg2 = (r12 - 0x20);
    else if (r12 < 0x80)
        arg2 = r12;
    else
    {
        fpc_uchar_to_unicodestr(&var_20, r12);
        data_434b78(&var_28, var_20);
        arg2 = *var_28;
    }
    
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_20);
    FPC_UNICODESTR_DECR_REF(&var_28);
    
    if (var_30 != 0)
        FPC_RERAISE();
    
    return arg2;
}

int64_t SYSTEM_$$_UPCASE$UNICODESTRING$$UNICODESTRING()
{
    return data_434b78();
}

uint64_t SYSTEM_$$_LOWERCASE$WIDECHAR$$WIDECHAR(int16_t arg1, int64_t arg2 @ rbx)
{
    int64_t var_8 = arg2;
    int64_t r12;
    r12 = arg1;
    int64_t var_20 = 0;
    int16_t* var_28 = nullptr;
    void var_88;
    void var_70;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_70, &var_88), arg2, rbp, r12, r13, r14, r15);
    int64_t var_30 = 0;
    
    if ((r12 >= 0x41 && r12 <= 0x5a))
        arg2 = (r12 + 0x20);
    else if (r12 < 0x80)
        arg2 = r12;
    else
    {
        fpc_uchar_to_unicodestr(&var_20, r12);
        data_434b80(&var_28, var_20);
        arg2 = *var_28;
    }
    
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_20);
    FPC_UNICODESTR_DECR_REF(&var_28);
    
    if (var_30 != 0)
        FPC_RERAISE();
    
    return arg2;
}

int64_t SYSTEM_$$_LOWERCASE$UNICODESTRING$$UNICODESTRING()
{
    return data_434b80();
}

uint64_t fpc_setstring_unicodestr_pwidechar(int64_t* arg1, int64_t arg2, int64_t arg3)
{
    *arg1 = 0;
    uint64_t result = FPC_UNICODESTR_SETLENGTH(arg1, arg3);
    
    if ((arg2 != 0 && arg3 > 0))
        return FPC_MOVE(arg2, FPC_UNICODESTR_UNIQUE(arg1), (arg3 << 1));
    
    return result;
}

int64_t fpc_setstring_unicodestr_pansichar(int64_t* arg1, int64_t arg2, int64_t arg3)
{
    *arg1 = 0;
    
    if ((arg2 != 0 && arg3 > 0))
        return data_434b70(arg2, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE, arg1, arg3);
    
    return FPC_UNICODESTR_SETLENGTH(arg1, arg3);
}

long double FPC_VAL_REAL_UNICODESTR(uint64_t arg1, int64_t* arg2)
{
    uint64_t rax = arg1;
    
    if (rax != 0)
        rax = *(rax - 8);
    
    if (rax > 0xff)
    {
        *arg2 = 0x100;
        return 0;
    }
    
    void var_108;
    FPC_UNICODESTR_TO_SHORTSTR(&var_108, 0xff, arg1);
    void var_208;
    FPC_SHORTSTR_TO_SHORTSTR(&var_208, 0xff, &var_108);
    return FPC_VAL_REAL_SHORTSTR(&var_208, arg2);
}

int64_t fpc_val_enum_unicodestr(int64_t arg1, int64_t arg2, int64_t* arg3)
{
    int64_t result = arg2;
    
    if (result != 0)
        result = *(result - 8);
    
    if (result > 0xff)
    {
        *arg3 = 0x100;
        return result;
    }
    
    void var_110;
    FPC_UNICODESTR_TO_SHORTSTR(&var_110, 0xff, arg2);
    void var_210;
    FPC_SHORTSTR_TO_SHORTSTR(&var_210, 0xff, &var_110);
    return FPC_VAL_SINT_SHORTSTR(4, &var_210, arg3);
}

long double FPC_VAL_CURRENCY_UNICODESTR(uint64_t arg1, int64_t* arg2)
{
    uint64_t rax = arg1;
    
    if (rax != 0)
        rax = *(rax - 8);
    
    int64_t var_210;
    
    if (rax <= 0xff)
    {
        void var_108;
        FPC_UNICODESTR_TO_SHORTSTR(&var_108, 0xff, arg1);
        void var_208;
        FPC_SHORTSTR_TO_SHORTSTR(&var_208, 0xff, &var_108);
        var_210 = (FPC_VAL_REAL_SHORTSTR(&var_208, arg2) * _$SYSTEM$_Ld29);
    }
    else
    {
        var_210 = 0;
        *arg2 = 0x100;
    }
    
    return var_210;
}

int64_t FPC_VAL_UINT_UNICODESTR(uint64_t arg1, int64_t* arg2)
{
    uint64_t rax = arg1;
    
    if (rax != 0)
        rax = *(rax - 8);
    
    if (rax > 0xff)
    {
        *arg2 = 0x100;
        return 0;
    }
    
    void var_110;
    FPC_UNICODESTR_TO_SHORTSTR(&var_110, 0xff, arg1);
    void var_210;
    FPC_SHORTSTR_TO_SHORTSTR(&var_210, 0xff, &var_110);
    return FPC_VAL_UINT_SHORTSTR(&var_210, arg2);
}

int64_t FPC_VAL_SINT_UNICODESTR(int64_t arg1, uint64_t arg2, int64_t* arg3)
{
    uint64_t rax = arg2;
    
    if (rax != 0)
        rax = *(rax - 8);
    
    if (rax > 0xff)
    {
        *arg3 = 0x100;
        return 0;
    }
    
    void var_120;
    FPC_UNICODESTR_TO_SHORTSTR(&var_120, 0xff, arg2);
    void var_220;
    FPC_SHORTSTR_TO_SHORTSTR(&var_220, 0xff, &var_120);
    return FPC_VAL_SINT_SHORTSTR(arg1, &var_220, arg3);
}

int64_t fpc_unicodestr_float(int16_t arg1, int16_t arg2, int32_t arg3, int64_t* arg4, int16_t arg5, int16_t arg6)
{
    *arg4 = 0;
    int16_t var_130 = arg6;
    void var_118;
    uint64_t r9;
    SYSTEM_$$_STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING(arg1, arg2, arg3, &var_118, 0xff, r9, arg5);
    return fpc_shortstr_to_unicodestr(arg4, &var_118);
}

int64_t fpc_unicodestr_enum(int64_t arg1, int64_t arg2, void* arg3, int32_t* arg4, int64_t* arg5)
{
    *arg5 = 0;
    void var_108;
    FPC_SHORTSTR_ENUM(arg1, arg2, arg3, arg4, &var_108, 0xff);
    return fpc_shortstr_to_unicodestr(arg5, &var_108);
}

int64_t fpc_unicodestr_bool(char arg1, int64_t arg2, int64_t* arg3)
{
    *arg3 = 0;
    void var_108;
    FPC_SHORTSTR_BOOL(arg1, arg2, &var_108, 0xff);
    return fpc_shortstr_to_unicodestr(arg3, &var_108);
}

int64_t fpc_unicodestr_currency(uint64_t arg1, int64_t arg2, int64_t arg3, int64_t* arg4)
{
    *arg4 = 0;
    void var_110;
    FPC_SHORTSTR_CURRENCY(arg1, arg2, arg3, &var_110, 0xff);
    return fpc_shortstr_to_unicodestr(arg4, &var_110);
}

int64_t fpc_unicodestr_sint(int64_t arg1, int64_t arg2, int64_t* arg3)
{
    *arg3 = 0;
    void var_108;
    FPC_SHORTSTR_SINT(arg1, arg2, &var_108, 0xff);
    return fpc_shortstr_to_unicodestr(arg3, &var_108);
}

int64_t fpc_unicodestr_uint(uint64_t arg1, int64_t arg2, int64_t* arg3)
{
    *arg3 = 0;
    void var_108;
    FPC_SHORTSTR_UINT(arg1, arg2, &var_108, 0xff);
    return fpc_shortstr_to_unicodestr(arg3, &var_108);
}

int64_t SYSTEM_$$_UNICODETOUTF8$PCHAR$PUNICODECHAR$INT64$$INT64(char* arg1, int64_t arg2, int64_t arg3)
{
    if (arg2 == 0)
        return 0;
    
    return SYSTEM_$$_UNICODETOUTF8$PCHAR$QWORD$PUNICODECHAR$QWORD$$QWORD(arg1, arg3, arg2, FPC_PWIDECHAR_LENGTH(arg2));
}

int64_t SYSTEM_$$_UNICODETOUTF8$PCHAR$QWORD$PUNICODECHAR$QWORD$$QWORD(char* arg1, int64_t arg2, int64_t arg3, int64_t arg4)
{
    if (arg3 == 0)
        return 0;
    
    int64_t i = 0;
    int64_t r10_1 = 0;
    
    if (arg1 == 0)
    {
        for (; arg4 > i; i += 1)
        {
            arg2 = *(arg3 + (i << 1));
            int16_t temp0_1 = arg2;
            arg2 -= 0x7f;
            
            if (temp0_1 <= 0x7f)
                r10_1 += 1;
            else
            {
                int16_t temp1_1 = arg2;
                arg2 -= 0x780;
                
                if (temp1_1 <= 0x780)
                    r10_1 += 2;
                else
                {
                    int16_t temp2_1 = arg2;
                    arg2 -= 0xd000;
                    
                    if (temp2_1 <= 0xd000)
                        r10_1 += 3;
                    else
                    {
                        int16_t temp4_1 = arg2;
                        arg2 -= 0x400;
                        
                        if (temp4_1 > 0x400)
                        {
                            int16_t temp6_1 = arg2;
                            arg2 -= 0x401;
                            
                            if (temp6_1 >= 0x401)
                            {
                                int16_t temp8_1 = arg2;
                                arg2 -= 0x1fff;
                                
                                if (temp8_1 <= 0x1fff)
                                    r10_1 += 3;
                            }
                        }
                        else if (arg4 > (i + 1))
                        {
                            arg2 = *(arg3 + ((i + 1) << 1));
                            
                            if ((arg2 >= 0xdc00 && arg2 <= 0xdfff))
                            {
                                r10_1 += 4;
                                i += 1;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        for (; arg4 > i; i += 1)
        {
            if (arg2 <= r10_1)
                break;
            
            uint32_t r9_1 = *(arg3 + (i << 1));
            
            if (r9_1 <= 0x7f)
            {
                arg1[r10_1] = r9_1;
                r10_1 += 1;
            }
            else if ((r9_1 - 0x7f) <= 0x780)
            {
                if ((r10_1 + 1) >= arg2)
                    break;
                
                arg1[r10_1] = ((r9_1 >> 6) | 0xc0);
                arg1[(r10_1 + 1)] = ((r9_1 & 0x3f) | 0x80);
                r10_1 += 2;
            }
            else if ((r9_1 - 0x7ff) <= 0xd000)
            {
            label_410604:
                
                if ((r10_1 + 2) >= arg2)
                    break;
                
                arg1[r10_1] = ((r9_1 >> 0xc) | 0xe0);
                arg1[(r10_1 + 1)] = (((r9_1 >> 6) & 0x3f) | 0x80);
                arg1[(r10_1 + 2)] = ((r9_1 & 0x3f) | 0x80);
                r10_1 += 3;
            }
            else if ((r9_1 - 0xd7ff) <= 0x400)
            {
                if ((r10_1 + 3) >= arg2)
                    break;
                
                if (arg4 > (i + 1))
                {
                    int64_t r9_27;
                    r9_27 = *(arg3 + ((i + 1) << 1));
                    
                    if ((r9_27 >= 0xdc00 && r9_27 <= 0xdfff))
                    {
                        r9_27 = *((arg3 + (i << 1)) + 2);
                        r9_27 ^= 0xdc00;
                        int32_t r8_2 = ((r9_27 & 0xffff) + ((r9_1 - 0xd7c0) << 0xa));
                        arg1[r10_1] = ((r8_2 >> 0x12) | 0xf0);
                        arg1[(r10_1 + 1)] = (((r8_2 >> 0xc) & 0x3f) | 0x80);
                        arg1[(r10_1 + 2)] = (((r8_2 >> 6) & 0x3f) | 0x80);
                        arg1[(r10_1 + 3)] = ((r8_2 & 0x3f) | 0x80);
                        r10_1 += 4;
                        i += 1;
                    }
                }
            }
            else if (((r9_1 - 0xdbff) >= 0x401 && (r9_1 - 0xe000) <= 0x1fff))
                goto label_410604;
        }
        
        if ((arg2 - 1) < r10_1)
            r10_1 = (arg2 - 1);
        
        arg1[r10_1] = 0;
    }
    
    return (r10_1 + 1);
}

int64_t SYSTEM_$$_UTF8TOUNICODE$PUNICODECHAR$PCHAR$INT64$$INT64(int64_t arg1, char* arg2, int64_t arg3)
{
    if (arg2 == 0)
        return 0;
    
    return SYSTEM_$$_UTF8TOUNICODE$PUNICODECHAR$QWORD$PCHAR$QWORD$$QWORD(arg1, arg3, arg2, FPC_PCHAR_LENGTH(arg2));
}

int64_t SYSTEM_$$_UTF8TOUNICODE$PUNICODECHAR$QWORD$PCHAR$QWORD$$QWORD(int64_t arg1, int64_t arg2, char* arg3, int64_t arg4)
{
    int64_t r12;
    int64_t var_10 = r12;
    
    if (arg3 == 0)
        return 0;
    
    int64_t var_38_1 = -1;
    int64_t r9_1 = 0;
    int64_t r14_1 = 0;
    char rax;
    
    if (arg1 == 0)
    {
        while (arg4 > r9_1)
        {
            r12 = arg3[r9_1];
            char* rsi_1;
            rsi_1 = r12;
            rsi_1 &= 0x80;
            
            if (rsi_1 != 0)
            {
                rax = r12;
                int64_t rdx_1 = 0;
                
                while (true)
                {
                    rsi_1 = rax;
                    rsi_1 &= 0x80;
                    
                    if (rsi_1 == 0)
                        break;
                    
                    rax = ((rax << 1) & 0xfe);
                    rdx_1 += 1;
                }
                
                if (((r9_1 + rdx_1) - 1) > arg4)
                    rdx_1 = 1;
                
                if ((rdx_1 - 1) >= 1)
                {
                    int64_t r8_2 = 0;
                    
                    while (true)
                    {
                        r8_2 += 1;
                        int64_t r10_50;
                        r10_50 = arg3[(r9_1 + r8_2)];
                        char* rsi_8;
                        rsi_8 = r10_50;
                        rsi_8 &= 0x80;
                        
                        if (rsi_8 == 0x80)
                        {
                            rsi_8 = r10_50;
                            rsi_8 &= 0x40;
                            
                            if (rsi_8 == 0)
                            {
                                if ((rdx_1 - 1) <= r8_2)
                                    break;
                                
                                continue;
                            }
                        }
                        
                        rdx_1 = r8_2;
                        break;
                    }
                }
                
                if ((rdx_1 >= 1 && rdx_1 != 1))
                {
                    int64_t rdi;
                    
                    if (rdx_1 == 2)
                    {
                        rdi = *(arg3 + r9_1);
                        rdi &= 0x1f;
                        int64_t rdi_3;
                        rdi_3 = *((arg3 + r9_1) + 1);
                        rdi_3 &= 0x3f;
                    }
                    else if (rdx_1 == 3)
                    {
                        rdi = *(arg3 + r9_1);
                        rdi &= 0xf;
                        int64_t rdi_8;
                        rdi_8 = *((arg3 + r9_1) + 1);
                        rdi_8 &= 0x3f;
                        int64_t rdi_12;
                        rdi_12 = *((arg3 + r9_1) + 2);
                        rdi_12 &= 0x3f;
                    }
                    else if (rdx_1 == 4)
                    {
                        rdi = *(arg3 + r9_1);
                        rdi &= 7;
                        int64_t rdi_17;
                        rdi_17 = *((arg3 + r9_1) + 1);
                        rdi_17 &= 0x3f;
                        int64_t rdi_21;
                        rdi_21 = *((arg3 + r9_1) + 2);
                        rdi_21 &= 0x3f;
                        int64_t rdi_25;
                        rdi_25 = *((arg3 + r9_1) + 3);
                        rdi_25 &= 0x3f;
                        int64_t r13_9 = (rdi_25 | ((rdi_21 << 6) | ((rdi_17 << 0xc) | (rdi << 0x12))));
                        
                        if ((r13_9 >= 0x10000 && r13_9 <= 0x10ffff))
                            r14_1 += 1;
                    }
                }
                
                if (rdx_1 > 0)
                    r14_1 += 1;
                
                r9_1 += rdx_1;
            }
            else
            {
                if (r12 != 0xa)
                    r14_1 += 1;
                else
                    r14_1 += 1;
                
                r9_1 += 1;
            }
        }
        
        return (r14_1 + 1);
    }
    
    while (arg2 > r14_1)
    {
        if (arg4 <= r9_1)
            break;
        
        r12 = arg3[r9_1];
        char* r10_1;
        r10_1 = r12;
        r10_1 &= 0x80;
        
        if (r10_1 != 0)
        {
            rax = r12;
            int64_t rdx = 0;
            
            while (true)
            {
                r10_1 = rax;
                r10_1 &= 0x80;
                
                if (r10_1 == 0)
                    break;
                
                rax = ((rax << 1) & 0xfe);
                rdx += 1;
            }
            
            if (((r9_1 + rdx) - 1) > arg4)
                rdx = 1;
            
            if ((rdx - 1) >= 1)
            {
                int64_t r8_1 = 0;
                
                while (true)
                {
                    r8_1 += 1;
                    int64_t r10_8;
                    r10_8 = arg3[(r9_1 + r8_1)];
                    char* r11_1;
                    r11_1 = r10_8;
                    r11_1 &= 0x80;
                    
                    if (r11_1 == 0x80)
                    {
                        r10_8 &= 0x40;
                        
                        if (r10_8 == 0)
                        {
                            if ((rdx - 1) <= r8_1)
                                break;
                            
                            continue;
                        }
                    }
                    
                    rdx = r8_1;
                    break;
                }
            }
            
            int64_t r13_1 = 0xffff;
            
            if (rdx >= 1)
            {
                if (rdx == 1)
                    r13_1 = 0x3f;
                else if (rdx == 2)
                {
                    int64_t r10_11;
                    r10_11 = *(arg3 + r9_1);
                    r10_11 &= 0x1f;
                    int64_t r10_18;
                    r10_18 = *((arg3 + r9_1) + 1);
                    r10_18 &= 0x3f;
                    r13_1 = (r10_18 | (r10_11 << 6));
                    
                    if (r13_1 <= 0x7f)
                        r13_1 = 0x3f;
                }
                else if (rdx == 3)
                {
                    int64_t r10_12;
                    r10_12 = *(arg3 + r9_1);
                    r10_12 &= 0xf;
                    int64_t r10_23;
                    r10_23 = *((arg3 + r9_1) + 1);
                    r10_23 &= 0x3f;
                    int64_t r10_27;
                    r10_27 = *((arg3 + r9_1) + 2);
                    r10_27 &= 0x3f;
                    r13_1 = (r10_27 | ((r10_23 << 6) | (r10_12 << 0xc)));
                    
                    if ((r13_1 <= 0x7ff || r13_1 >= 0xfffe))
                        r13_1 = 0x3f;
                    else if ((r13_1 >= 0xd800 && r13_1 <= 0xdfff))
                        r13_1 = 0x3f;
                }
                else if (rdx == 4)
                {
                    int64_t r10_13;
                    r10_13 = *(arg3 + r9_1);
                    r10_13 &= 7;
                    int64_t r10_32;
                    r10_32 = *((arg3 + r9_1) + 1);
                    r10_32 &= 0x3f;
                    int64_t r10_36;
                    r10_36 = *((arg3 + r9_1) + 2);
                    r10_36 &= 0x3f;
                    int64_t r10_40;
                    r10_40 = *((arg3 + r9_1) + 3);
                    r10_40 &= 0x3f;
                    int64_t r10_42 = (r10_40 | ((r10_36 << 6) | ((r10_32 << 0xc) | (r10_13 << 0x12))));
                    
                    if ((r10_42 < 0x10000 || r10_42 > 0x10ffff))
                        r13_1 = 0x3f;
                    else
                    {
                        r13_1 = (r10_42 - 0x10000);
                        
                        if ((arg2 - 1) <= r14_1)
                        {
                            r9_1 += rdx;
                            rdx = 0;
                        }
                        else
                        {
                            *(arg1 + (r14_1 << 1)) = ((r13_1 >> 0xa) - 0x2800);
                            r14_1 += 1;
                            r13_1 = ((r13_1 & 0x3ff) + 0xdc00);
                        }
                    }
                }
                else if (((rdx - 4) >= 1 && (rdx - 5) <= 2))
                    r13_1 = 0x3f;
            }
            
            if (rdx > 0)
            {
                *(arg1 + (r14_1 << 1)) = r13_1;
                r14_1 += 1;
            }
            
            r9_1 += rdx;
        }
        else
        {
            if (r12 != 0xa)
            {
                r10_1 = r12;
                *(arg1 + (r14_1 << 1)) = r10_1;
                r14_1 += 1;
            }
            else
            {
                r10_1 = r12;
                *(arg1 + (r14_1 << 1)) = r10_1;
                r14_1 += 1;
            }
            
            r9_1 += 1;
        }
    }
    
    return (r14_1 + 1);
}

int64_t SYSTEM_$$_UTF8ENCODE$RAWBYTESTRING$$RAWBYTESTRING(int64_t* arg1, uint16_t* arg2)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_ansistr_to_unicodestr(&var_18, arg2);
    SYSTEM_$$_UTF8ENCODE$UNICODESTRING$$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_UTF8ENCODE$UNICODESTRING$$RAWBYTESTRING(int64_t* arg1, uint16_t* arg2)
{
    char* var_78 = nullptr;
    void var_70;
    void var_58;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_58, &var_70), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    FPC_ANSISTR_ASSIGN(arg1, 0);
    
    if (arg2 != 0)
    {
        uint16_t* rsi_1 = arg2;
        
        if (arg2 != 0)
            rsi_1 = *(rsi_1 - 8);
        
        FPC_ANSISTR_SETLENGTH(&var_78, (rsi_1 * 3), 0xfde9);
        char* rax_1 = var_78;
        
        if (rax_1 != 0)
            rax_1 = *(rax_1 - 8);
        
        uint16_t* rcx_1 = arg2;
        
        if (arg2 != 0)
            rcx_1 = *(rcx_1 - 8);
        
        uint16_t* rdx_1 = arg2;
        
        if (arg2 == 0)
            rdx_1 = &FPC_EMPTYCHAR;
        
        char* rdi_3 = var_78;
        
        if (rdi_3 == 0)
            rdi_3 = &FPC_EMPTYCHAR;
        
        int64_t rax_2 = SYSTEM_$$_UNICODETOUTF8$PCHAR$QWORD$PUNICODECHAR$QWORD$$QWORD(rdi_3, &rax_1[1], rdx_1, rcx_1);
        
        if (rax_2 > 0)
        {
            FPC_ANSISTR_SETLENGTH(&var_78, (rax_2 - 1), 0xfde9);
            FPC_ANSISTR_ASSIGN(arg1, var_78);
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_78);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_UTF8DECODE$RAWBYTESTRING$$UNICODESTRING(void** arg1, char* arg2)
{
    uint16_t* var_78 = nullptr;
    void var_70;
    void var_58;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_58, &var_70), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    FPC_UNICODESTR_ASSIGN(arg1, nullptr);
    
    if (arg2 != 0)
    {
        char* rsi_1 = arg2;
        
        if (arg2 != 0)
            rsi_1 = *(rsi_1 - 8);
        
        FPC_UNICODESTR_SETLENGTH(&var_78, rsi_1);
        uint16_t* rax_1 = var_78;
        
        if (rax_1 != 0)
            rax_1 = *(rax_1 - 8);
        
        char* rcx_1 = arg2;
        
        if (arg2 != 0)
            rcx_1 = *(rcx_1 - 8);
        
        char* rdx_1 = arg2;
        
        if (arg2 == 0)
            rdx_1 = &FPC_EMPTYCHAR;
        
        uint16_t* rdi_3 = var_78;
        
        if (rdi_3 == 0)
            rdi_3 = &FPC_EMPTYCHAR;
        
        int64_t rax_2 = SYSTEM_$$_UTF8TOUNICODE$PUNICODECHAR$QWORD$PCHAR$QWORD$$QWORD(rdi_3, (rax_1 + 1), rdx_1, rcx_1);
        
        if (rax_2 > 0)
        {
            FPC_UNICODESTR_SETLENGTH(&var_78, (rax_2 - 1));
            FPC_UNICODESTR_ASSIGN(arg1, var_78);
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_78);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_ANSITOUTF8$RAWBYTESTRING$$RAWBYTESTRING(int64_t* arg1, uint16_t* arg2)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_ansistr_to_unicodestr(&var_18, arg2);
    SYSTEM_$$_UTF8ENCODE$UNICODESTRING$$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_UTF8TOANSI$RAWBYTESTRING$$RAWBYTESTRING(int64_t* arg1, char* arg2)
{
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_UTF8DECODE$RAWBYTESTRING$$UNICODESTRING(&var_18, arg2);
    fpc_unicodestr_to_ansistr(arg1, var_18, 0);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_UCS4ENCODE$PWIDECHAR$INT64$UCS4STRING(int64_t arg1, int64_t arg2, int64_t* arg3)
{
    *arg3 = 0;
    int64_t rcx = 0;
    int64_t rsi = 0;
    
    while (arg2 > rsi)
    {
        int64_t rax;
        rax = *(arg1 + (rsi << 1));
        
        if ((rax <= 0xd7ff || rax >= 0xe000))
            rsi += 1;
        else
        {
            if ((*(arg1 + (rsi << 1)) <= 0xdbff && arg2 > (rsi + 1)))
                rax = *(arg1 + ((rsi + 1) << 1));
            
            if ((((*(arg1 + (rsi << 1)) > 0xdbff || arg2 <= (rsi + 1)) || rax < 0xdc00) || rax > 0xdfff))
                rsi += 1;
            else
                rsi += 2;
        }
        
        rcx += 1;
    }
    
    int64_t var_28 = (rcx + 1);
    FPC_DYNARR_SETLENGTH(arg3, &RTTI_$SYSTEM_$$_UCS4STRING, 1, &var_28);
    int64_t rsi_1 = 0;
    int64_t rcx_2 = 0;
    
    while (arg2 > rcx_2)
    {
        uint32_t rdx_1 = *(arg1 + (rcx_2 << 1));
        
        if ((rdx_1 <= 0xd7ff || rdx_1 >= 0xe000))
            *(*arg3 + (rsi_1 << 2)) = rdx_1;
        else
        {
            int64_t rdx_2;
            
            if ((rdx_1 <= 0xdbff && arg2 > (rcx_2 + 1)))
                rdx_2 = *(arg1 + ((rcx_2 + 1) << 1));
            
            if ((((rdx_1 > 0xdbff || arg2 <= (rcx_2 + 1)) || rdx_2 < 0xdc00) || rdx_2 > 0xdfff))
                *(*arg3 + (rsi_1 << 2)) = rdx_1;
            else
            {
                *(*arg3 + (rsi_1 << 2)) = ((*((arg1 + (rcx_2 << 1)) + 2) ^ 0xdc00) + ((rdx_1 - 0xd7c0) << 0xa));
                rcx_2 += 1;
            }
        }
        
        rcx_2 += 1;
        rsi_1 += 1;
    }
    
    int64_t result = *arg3;
    *(result + (rsi_1 << 2)) = 0;
    return result;
}

int64_t SYSTEM_$$_UNICODESTRINGTOUCS4STRING$UNICODESTRING$$UCS4STRING(int64_t* arg1, uint16_t* arg2)
{
    FPC_FINALIZE(arg1, &RTTI_$SYSTEM_$$_UCS4STRING);
    uint16_t* rsi = arg2;
    
    if (arg2 != 0)
        rsi = *(rsi - 8);
    
    uint16_t* rdi_1 = arg2;
    
    if (arg2 == 0)
        rdi_1 = &FPC_EMPTYCHAR;
    
    return SYSTEM_$$_UCS4ENCODE$PWIDECHAR$INT64$UCS4STRING(rdi_1, rsi, arg1);
}

int64_t SYSTEM_$$_WIDESTRINGTOUCS4STRING$WIDESTRING$$UCS4STRING(int64_t* arg1, uint16_t* arg2)
{
    FPC_FINALIZE(arg1, &RTTI_$SYSTEM_$$_UCS4STRING);
    uint16_t* rsi = arg2;
    
    if (arg2 != 0)
        rsi = *(rsi - 8);
    
    uint16_t* rdi_1 = arg2;
    
    if (arg2 == 0)
        rdi_1 = &FPC_EMPTYCHAR;
    
    return SYSTEM_$$_UCS4ENCODE$PWIDECHAR$INT64$UCS4STRING(rdi_1, rsi, arg1);
}

void* SYSTEM_$$_UCS4DECODE$UCS4STRING$PWIDECHAR(void* arg1, int16_t* arg2)
{
    void* rax_1 = arg1;
    
    if (arg1 != 0)
        rax_1 = (*(rax_1 - 8) + 1);
    
    if ((rax_1 - 2) >= 0)
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            int32_t r8_1 = *(arg1 + (i << 2));
            
            if (r8_1 <= 0xffff)
                *arg2 = r8_1;
            else if (r8_1 > 0x10ffff)
                *arg2 = 0x3f;
            else
            {
                *arg2 = ((r8_1 >> 0xa) - 0x2840);
                arg2[1] = ((r8_1 & 0x3ff) - 0x2400);
                arg2 = &arg2[1];
            }
            
            arg2 = &arg2[1];
        } while ((rax_1 - 2) > i);
    }
    
    return (rax_1 - 2);
}

void* SYSTEM_$$_UCS4STRINGTOUNICODESTRING$UCS4STRING$$UNICODESTRING(int16_t** arg1, void* arg2)
{
    int64_t rsi = 0;
    void* rax = arg2;
    
    if (arg2 != 0)
        rax = (*(rax - 8) + 1);
    
    if ((rax - 2) >= 0)
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            int64_t rcx;
            rcx = *(arg2 + (i << 2)) > 0xffff;
            rsi += ((rcx & 0xff) + 1);
        } while ((rax - 2) > i);
    }
    
    FPC_UNICODESTR_SETLENGTH(arg1, rsi);
    return SYSTEM_$$_UCS4DECODE$UCS4STRING$PWIDECHAR(arg2, *arg1);
}

void* SYSTEM_$$_UCS4STRINGTOWIDESTRING$UCS4STRING$$WIDESTRING(int16_t** arg1, void* arg2)
{
    int64_t rsi = 0;
    void* rax = arg2;
    
    if (arg2 != 0)
        rax = (*(rax - 8) + 1);
    
    if ((rax - 2) >= 0)
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            int64_t rcx;
            rcx = *(arg2 + (i << 2)) > 0xffff;
            rsi += ((rcx & 0xff) + 1);
        } while ((rax - 2) > i);
    }
    
    FPC_UNICODESTR_SETLENGTH(arg1, rsi);
    return SYSTEM_$$_UCS4DECODE$UCS4STRING$PWIDECHAR(arg2, *arg1);
}

int64_t SYSTEM_$$_UNIMPLEMENTEDUNICODESTRING()
{
    if (operatingsystem_isconsole != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        void* rsi_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rsi_1 = &data_4346f8;
        else
            rsi_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_STDERR);
        
        FPC_WRITE_TEXT_SHORTSTR(0, rsi_1, "9This binary has no string conve…");
        uint64_t FPC_THREADVAR_RELOCATE_4 = FPC_THREADVAR_RELOCATE;
        void* rdi_3;
        
        if (FPC_THREADVAR_RELOCATE_4 == 0)
            rdi_3 = &data_4346f8;
        else
            rdi_3 = FPC_THREADVAR_RELOCATE_4(U_$SYSTEM_$$_STDERR);
        
        fpc_writeln_end(rdi_3);
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        void* rsi_2;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            rsi_2 = &data_4346f8;
        else
            rsi_2 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_STDERR);
        
        FPC_WRITE_TEXT_SHORTSTR(0, rsi_2, "gRecompile the application with …");
        uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
        void* rdi_6;
        
        if (FPC_THREADVAR_RELOCATE_3 == 0)
            rdi_6 = &data_4346f8;
        else
            rdi_6 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_STDERR);
        
        fpc_writeln_end(rdi_6);
    }
    
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xea, &data_411577, &__saved_rbp);
}

uint64_t SYSTEM_$$_STRINGELEMENTSIZE$UNICODESTRING$$WORD(void* arg1)
{
    int16_t rax;
    
    if (arg1 == 0)
        rax = 2;
    else
        rax = *(arg1 - 0x16);
    
    return rax;
}

int64_t SYSTEM_$$_STRINGREFCOUNT$UNICODESTRING$$INT64(void* arg1)
{
    if (arg1 == 0)
        return 0;
    
    return *(arg1 - 0x10);
}

uint64_t SYSTEM_$$_STRINGCODEPAGE$UNICODESTRING$$WORD(void* arg1)
{
    uint16_t U_$SYSTEM_$$_DEFAULTUNICODECODEPAGE_1;
    
    if (arg1 == 0)
        U_$SYSTEM_$$_DEFAULTUNICODECODEPAGE_1 = U_$SYSTEM_$$_DEFAULTUNICODECODEPAGE;
    else
        U_$SYSTEM_$$_DEFAULTUNICODECODEPAGE_1 = *(arg1 - 0x18);
    
    return U_$SYSTEM_$$_DEFAULTUNICODECODEPAGE_1;
}

int64_t SYSTEM_$$_STUBUNICODECASE$UNICODESTRING$$UNICODESTRING()
{
    return SYSTEM_$$_UNIMPLEMENTEDUNICODESTRING();
}

int64_t SYSTEM_$$_STUBCOMPAREUNICODESTRING$UNICODESTRING$UNICODESTRING$TCOMPAREOPTIONS$$INT64()
{
    return SYSTEM_$$_UNIMPLEMENTEDUNICODESTRING();
}

int64_t SYSTEM_$$_STUBWIDECASE$WIDESTRING$$WIDESTRING()
{
    return SYSTEM_$$_UNIMPLEMENTEDUNICODESTRING();
}

int64_t SYSTEM_$$_STUBCOMPAREWIDESTRING$WIDESTRING$WIDESTRING$TCOMPAREOPTIONS$$INT64()
{
    return SYSTEM_$$_UNIMPLEMENTEDUNICODESTRING();
}

void SYSTEM_$$_INITUNICODESTRINGMANAGER()
{
    data_434ad8 = SYSTEM_$$_DEFAULTANSI2UNICODEMOVE$PCHAR$WORD$UNICODESTRING$INT64;
    U_$SYSTEM_$$_WIDESTRINGMANAGER = SYSTEM_$$_DEFAULTUNICODE2ANSIMOVE$PUNICODECHAR$RAWBYTESTRING$WORD$INT64;
    data_434ae0 = SYSTEM_$$_STUBWIDECASE$WIDESTRING$$WIDESTRING;
    data_434ae8 = SYSTEM_$$_STUBWIDECASE$WIDESTRING$$WIDESTRING;
    data_434b68 = SYSTEM_$$_DEFAULTUNICODE2ANSIMOVE$PUNICODECHAR$RAWBYTESTRING$WORD$INT64;
    data_434b70 = SYSTEM_$$_DEFAULTANSI2UNICODEMOVE$PCHAR$WORD$UNICODESTRING$INT64;
    data_434b78 = SYSTEM_$$_STUBUNICODECASE$UNICODESTRING$$UNICODESTRING;
    data_434b80 = SYSTEM_$$_STUBUNICODECASE$UNICODESTRING$$UNICODESTRING;
    data_434af0 = SYSTEM_$$_STUBCOMPAREWIDESTRING$WIDESTRING$WIDESTRING$TCOMPAREOPTIONS$$INT64;
    data_434b88 = SYSTEM_$$_STUBCOMPAREUNICODESTRING$UNICODESTRING$UNICODESTRING$TCOMPAREOPTIONS$$INT64;
    data_434af8 = SYSTEM_$$_DEFAULTCHARLENGTHPCHAR$PCHAR$$INT64;
    data_434b00 = SYSTEM_$$_DEFAULTCODEPOINTLENGTH$PCHAR$INT64$$INT64;
    data_434b90 = SYSTEM_$$_DEFAULTGETSTANDARDCODEPAGE$TSTANDARDCODEPAGEENUM$$WORD;
}

int64_t SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$UNICODESTRING$$RAWBYTESTRING(int64_t arg1, uint16_t* arg2)
{
    uint16_t* rdi = arg2;
    uint16_t* rcx = rdi;
    
    if (rdi != 0)
        rcx = *(rcx - 8);
    
    if (rdi == 0)
        rdi = &FPC_EMPTYCHAR;
    
    return data_434b68(rdi, arg1, U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE, rcx);
}

int64_t SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$array_of_WIDECHAR$$RAWBYTESTRING(int64_t arg1, int64_t arg2)
{
    int64_t rax = FPC_PWIDECHAR_LENGTH(arg2);
    return data_434b68(arg2, arg1, U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE, rax);
}

int64_t SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$RAWBYTESTRING$$RAWBYTESTRING(int64_t* arg1, int64_t arg2)
{
    FPC_ANSISTR_ASSIGN(arg1, arg2);
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg1, U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE, 1);
}

int64_t SYSTEM_$$_UTF8TOSTRING$RAWBYTESTRING$$UNICODESTRING(void** arg1, char* arg2)
{
    return SYSTEM_$$_UTF8DECODE$RAWBYTESTRING$$UNICODESTRING(arg1, arg2);
}

int64_t SYSTEM_$$_UTF8TOSTRING$SHORTSTRING$$UNICODESTRING(void** arg1, char* arg2)
{
    char* var_78 = nullptr;
    void var_70;
    void var_58;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_58, &var_70), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_shortstr_to_ansistr(&var_78, arg2, 0);
    SYSTEM_$$_UTF8DECODE$RAWBYTESTRING$$UNICODESTRING(arg1, var_78);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_78);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_UTF8TOSTRING$PCHAR$$UNICODESTRING(void** arg1, char (* arg2)[0x10])
{
    int64_t rbx;
    int64_t var_8 = rbx;
    char* var_88 = nullptr;
    void var_80;
    void var_68;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_80), rbx, rbp, arg1, arg2, r14, r15);
    int64_t result = 0;
    int16_t rax_1 = FPC_PCHAR_LENGTH(arg2);
    rbx = rax_1;
    FPC_ANSISTR_SETLENGTH(&var_88, rax_1, 0);
    
    if (rbx > 0)
        FPC_MOVE(arg2, var_88, rbx);
    
    SYSTEM_$$_UTF8DECODE$RAWBYTESTRING$$UNICODESTRING(arg1, var_88);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_88);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_UTF8TOSTRING$array_of_CHAR$$UNICODESTRING(void** arg1, int64_t arg2, int64_t arg3)
{
    char* var_10 = nullptr;
    void var_68;
    void var_28;
    int64_t __saved_rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_28), arg3, &__saved_rbp, arg1, arg2, r14, r15);
    int64_t rbx;
    rbx = (arg3 + 1);
    FPC_ANSISTR_SETLENGTH(&var_10, (arg3 + 1), 0);
    
    if (rbx > 0)
        FPC_MOVE(arg2, var_10, rbx);
    
    SYSTEM_$$_UTF8DECODE$RAWBYTESTRING$$UNICODESTRING(arg1, var_10);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_10);
    return 0;
}

int64_t SYSTEM_$$_UTF8TOSTRING$array_of_BYTE$$UNICODESTRING(void** arg1, int64_t arg2, int64_t arg3)
{
    char* var_10 = nullptr;
    void var_68;
    void var_28;
    int64_t __saved_rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_28), arg3, &__saved_rbp, arg1, arg2, r14, r15);
    int64_t rbx;
    rbx = (arg3 + 1);
    FPC_ANSISTR_SETLENGTH(&var_10, (arg3 + 1), 0);
    
    if (rbx > 0)
        FPC_MOVE(arg2, var_10, rbx);
    
    SYSTEM_$$_UTF8DECODE$RAWBYTESTRING$$UNICODESTRING(arg1, var_10);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_10);
    return 0;
}

void* FPC_DYNARRAY_RANGECHECK(void* arg1, int64_t arg2)
{
    if ((arg1 != 0 && (arg2 >= 0 && arg2 <= *(arg1 - 8))))
        return arg1;
    
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xc9, &data_411adc, &__saved_rbp);
}

int64_t FPC_DYNARRAY_LENGTH(void* arg1)
{
    if (arg1 == 0)
        return 0;
    
    return (*(arg1 - 8) + 1);
}

int64_t FPC_DYNARRAY_HIGH(void* arg1)
{
    if (arg1 == 0)
        return -1;
    
    return *(arg1 - 8);
}

void FPC_DYNARRAY_CLEAR(int64_t* arg1, void* arg2)
{
    if (*arg1 != 0)
    {
        int64_t* r13_1 = &*arg1[-4];
        int64_t __saved_rbp;
        
        if (*r13_1 == 0)
            SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xcc, &data_411b78, &__saved_rbp);
        
        if ((*r13_1 > 0 && SYSTEM_$$_DECLOCKED$INT64$$BOOLEAN(r13_1) != 0))
        {
            void* r12_1 = ((arg2 + 2) + *(arg2 + 1));
            
            if (*(r12_1 + 0x14) != 0)
                FPC_FINALIZE_ARRAY(*arg1, **(r12_1 + 0x14), (r13_1[1] + 1));
            
            SYSTEM_$$_FREEMEM$POINTER$$QWORD();
        }
        
        *arg1 = 0;
    }
}

void FPC_DYNARRAY_INCR_REF(void* arg1)
{
    if (arg1 != 0)
    {
        int64_t __saved_rbp;
        
        if (*(arg1 - 0x10) == 0)
            SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xcc, &data_411c11, &__saved_rbp);
        else if (*(arg1 - 0x10) > 0)
            SYSTEM_$$_INCLOCKED$INT64((arg1 - 0x10));
    }
}

int64_t FPC_DYNARRAY_ASSIGN(void** arg1, void* arg2, void* arg3)
{
    FPC_DYNARRAY_INCR_REF(arg2);
    int64_t result = FPC_DYNARRAY_CLEAR(arg1, arg3);
    *arg1 = arg2;
    return result;
}

int64_t* FPC_DYNARR_SETLENGTH(void** arg1, void* arg2, int64_t arg3, int64_t* arg4)
{
    int64_t __saved_rbp;
    
    if (*arg4 < 0)
        SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xc9, &data_411caa, &__saved_rbp);
    
    int64_t* rdx_2 = (*(arg2 + 1) + (arg2 + 2));
    int64_t rax_2 = *rdx_2;
    char* rax_3 = *rdx_2[1];
    char* r15;
    
    if (*(rdx_2 + 0x14) == 0)
        r15 = nullptr;
    else
        r15 = **(rdx_2 + 0x14);
    
    int64_t rax_7 = ((*arg4 * rax_2) + 0x10);
    char var_48 = 0;
    int64_t* var_18;
    
    if (*arg1 == 0)
    {
        int64_t* result = arg4;
        
        if (*result != 0)
        {
            SYSTEM_$$_GETMEM$POINTER$QWORD(&var_18, rax_7);
            SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(var_18, rax_7, 0);
            
            if (r15 != 0)
            {
                result = *rax_3;
                
                if (((result == 0xd || result == 0x10) || result == 0x10))
                    FPC_INITIALIZE_ARRAY(&var_18[2], rax_3, *arg4);
            }
            
            var_48 = 1;
        label_411ff7:
            
            if (arg3 > 1)
            {
                int64_t rbx_3 = (*arg4 - 1);
                
                if (rbx_3 >= 0)
                {
                    int64_t r12_2 = -1;
                    
                    do
                    {
                        r12_2 += 1;
                        FPC_DYNARR_SETLENGTH(((rax_2 * r12_2) + &var_18[2]), rax_3, (arg3 - 1), &arg4[1]);
                    } while (rbx_3 > r12_2);
                }
            }
            
            result = var_48;
            
            if (result != 0)
            {
                *arg1 = &var_18[2];
                *var_18 = 1;
                result = (*arg4 - 1);
                var_18[1] = result;
            }
        }
        
        return result;
    }
    
    if (*arg4 == 0)
        return FPC_DYNARRAY_CLEAR(arg1, arg2);
    
    void* rax_13 = (*arg1 - 0x10);
    var_18 = rax_13;
    
    if (*rax_13 != 1)
    {
        var_48 = 1;
        SYSTEM_$$_GETMEM$POINTER$QWORD(&var_18, rax_7);
        SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(var_18, 0x10, 0);
        int64_t r12_1;
        
        if (*(rax_13 + 8) >= *arg4)
            r12_1 = *arg4;
        else
            r12_1 = (*(rax_13 + 8) + 1);
        
        uint64_t rax_22 = (r12_1 * rax_2);
        FPC_MOVE(*arg1, &var_18[2], rax_22);
        
        if ((rax_7 - 0x10) > rax_22)
            SYSTEM_$$_FILLCHAR$formal$INT64$BYTE((&var_18[2] + rax_22), ((rax_7 - 0x10) - rax_22), 0);
        
        if ((r15 != 0 && (r12_1 - 1) >= 0))
        {
            int64_t i = -1;
            
            do
            {
                i += 1;
                FPC_ADDREF(((i * rax_2) + &var_18[2]), r15);
            } while ((r12_1 - 1) > i);
        }
        
        FPC_DYNARRAY_CLEAR(arg1, arg2);
    }
    else if ((*(rax_13 + 8) + 1) != *arg4)
    {
        if (rax_7 < 0x10)
            SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xc9, &data_411eb7, &__saved_rbp);
        else if ((rax_2 > 0 && rax_2 > rax_7))
            SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xc9, &data_411eb7, &__saved_rbp);
        
        if (*rax_13 == 1)
        {
            if ((*(rax_13 + 8) + 1) > *arg4)
            {
                if (r15 != 0)
                    FPC_FINALIZE_ARRAY(((*arg4 * rax_2) + (rax_13 + 0x10)), r15, ((*(rax_13 + 8) - *arg4) + 1));
                
                SYSTEM_$$_REALLOCMEM$POINTER$QWORD$$POINTER();
            }
            else if ((*(rax_13 + 8) + 1) < *arg4)
            {
                SYSTEM_$$_REALLOCMEM$POINTER$QWORD$$POINTER();
                SYSTEM_$$_FILLCHAR$formal$INT64$BYTE((((*(rax_13 + 8) + 1) * rax_2) + (rax_13 + 0x10)), (((*arg4 - *(rax_13 + 8)) - 1) * rax_2), 0);
                
                if (r15 != 0)
                {
                    uint32_t rdx_22 = *rax_3;
                    
                    if (((rdx_22 == 0xd || rdx_22 == 0x10) || rdx_22 == 0x10))
                        FPC_INITIALIZE_ARRAY((((*(rax_13 + 8) + 1) * rax_2) + (rax_13 + 0x10)), rax_3, ((*arg4 - *(rax_13 + 8)) - 1));
                }
            }
            
            var_18 = rax_13;
            var_48 = 1;
        }
    }
    
    goto label_411ff7;
}

uint64_t FPC_DYNARR_COPY(int64_t* arg1, void* arg2, void* arg3, int64_t arg4, uint64_t arg5)
{
    int64_t r12 = arg4;
    uint64_t result_1 = arg5;
    uint64_t result = FPC_DYNARRAY_CLEAR(arg1, arg3);
    
    if (arg2 != 0)
    {
        if (r12 >= 0)
            goto label_4120f9;
        
        if (result_1 > 0)
        {
            result_1 += r12;
            r12 = 0;
        label_4120f9:
            result = ((*(arg2 - 8) - r12) + 1);
            
            if (result < result_1)
            {
                result = ((*(arg2 - 8) - r12) + 1);
                result_1 = result;
            }
            
            if (result_1 > 0)
            {
                void* rax_5 = (*(arg3 + 1) + (arg3 + 2));
                int64_t r14_1 = *rax_5;
                char* r13_1;
                
                if (*(rax_5 + 0x14) == 0)
                    r13_1 = nullptr;
                else
                    r13_1 = **(rax_5 + 0x14);
                
                uint64_t rax_8 = (result_1 * r14_1);
                SYSTEM_$$_GETMEM$POINTER$QWORD(arg1, (rax_8 + 0x10));
                **arg1 = 1;
                *(*arg1 + 8) = (result_1 - 1);
                *arg1 += 0x10;
                result = FPC_MOVE(((r12 * r14_1) + arg2), *arg1, rax_8);
                
                if ((r13_1 != 0 && (result_1 - 1) >= 0))
                {
                    int64_t i = -1;
                    
                    do
                    {
                        i += 1;
                        result = FPC_ADDREF(((i * r14_1) + *arg1), r13_1);
                    } while ((result_1 - 1) > i);
                }
            }
        }
    }
    
    return result;
}

int64_t* fpc_dynarray_delete(int64_t* arg1, int64_t* arg2, void* arg3, void* arg4)
{
    void* var_48 = arg3;
    int64_t* result = arg1;
    void* rdx = *result;
    
    if (rdx != 0)
    {
        result = arg2;
        
        if ((result <= *(rdx - 8) && (var_48 > 0 && arg2 >= 0)))
        {
            if (((arg2 + var_48) - 1) > *(*arg1 - 8))
                var_48 = ((*(*arg1 - 8) - arg2) + 1);
            
            if ((arg2 == 0 && (*(*arg1 - 8) + 1) == var_48))
                return FPC_DYNARRAY_CLEAR(arg1, arg4);
            
            void* rdx_6 = ((arg4 + 2) + *(arg4 + 1));
            int64_t rax_12 = *rdx_6;
            char* r15_1 = **(rdx_6 + 8);
            char* r13_1;
            
            if (*(rdx_6 + 0x14) == 0)
                r13_1 = nullptr;
            else
                r13_1 = **(rdx_6 + 0x14);
            
            char* result_3 = (*arg1 - 0x10);
            int64_t* result_2 = result_3;
            char* result_1 = result_3;
            void* rax_18 = (result_2[1] - var_48);
            
            if (*result_2 == 1)
            {
                if ((r13_1 != 0 && ((arg2 + var_48) - 1) >= arg2))
                {
                    void* i = (arg2 - 1);
                    
                    do
                    {
                        i += 1;
                        FPC_FINALIZE(((rax_12 * i) + *arg1), r15_1);
                    } while (((arg2 + var_48) - 1) > i);
                }
                
                FPC_MOVE((((arg2 + var_48) * rax_12) + *arg1), ((rax_12 * arg2) + *arg1), (((result_2[1] - (arg2 + var_48)) + 1) * rax_12));
                SYSTEM_$$_REALLOCMEM$POINTER$QWORD$$POINTER();
                result_1 = result_2;
            }
            else
            {
                SYSTEM_$$_GETMEM$POINTER$QWORD(&result_1, (((rax_18 + 1) * rax_12) + 0x10));
                SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(result_1, 0x10, 0);
                
                if (arg2 > 0)
                    FPC_MOVE(*arg1, &result_1[0x10], (rax_12 * arg2));
                
                if (((arg2 + var_48) - 1) < result_2[1])
                    FPC_MOVE((((arg2 + var_48) * rax_12) + *arg1), ((rax_12 * arg2) + &result_1[0x10]), (((result_2[1] - (arg2 + var_48)) + 1) * rax_12));
                
                if ((r13_1 != 0 && rax_18 >= 0))
                {
                    int64_t r12_1 = -1;
                    
                    do
                    {
                        r12_1 += 1;
                        FPC_ADDREF(((r12_1 * rax_12) + &result_1[0x10]), r13_1);
                    } while (rax_18 > r12_1);
                }
                
                FPC_DYNARRAY_CLEAR(arg1, arg4);
            }
            
            *arg1 = &result_1[0x10];
            *result_1 = 1;
            result = result_1;
            result[1] = rax_18;
        }
    }
    
    return result;
}

char* fpc_dynarray_insert(int64_t* arg1, void* arg2, char* arg3, char* arg4, void* arg5)
{
    void* r15 = arg2;
    char* result = arg3;
    
    if (result != 0)
    {
        result = arg4;
        
        if (result != 0)
        {
            int64_t* result_2;
            
            if (*arg1 == 0)
                result_2 = nullptr;
            else
                result_2 = (*arg1 - 0x10);
            
            char* result_1 = result_2;
            
            if (*arg1 == 0)
                r15 = nullptr;
            else if (r15 < 0)
                r15 = nullptr;
            else if ((result_2[1] + 1) < r15)
                r15 = (result_2[1] + 1);
            
            void* rdx_2 = ((arg5 + 2) + *(arg5 + 1));
            int64_t rax_12 = *rdx_2;
            **(rdx_2 + 8);
            char* var_30_1;
            
            if (*(rdx_2 + 0x14) == 0)
                var_30_1 = nullptr;
            else
                var_30_1 = **(rdx_2 + 0x14);
            
            void* var_38_1;
            
            if (*arg1 == 0)
                var_38_1 = &arg4[-1];
            else
                var_38_1 = &arg4[result_2[1]];
            
            if (*arg1 == 0)
            {
                SYSTEM_$$_GETMEM$POINTER$QWORD(&result_1, (((var_38_1 + 1) * rax_12) + 0x10));
                SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(result_1, 0x10, 0);
                FPC_MOVE(arg3, &result_1[0x10], (rax_12 * arg4));
                
                if ((var_30_1 != 0 && &arg4[-1] >= 0))
                {
                    int64_t i = -1;
                    
                    do
                    {
                        i += 1;
                        FPC_ADDREF(((rax_12 * i) + &result_1[0x10]), var_30_1);
                    } while (&arg4[-1] > i);
                }
            }
            else if (*result_2 == 1)
            {
                SYSTEM_$$_REALLOCMEM$POINTER$QWORD$$POINTER();
                *arg1 = &result_2[2];
                
                if (r15 <= result_2[1])
                    FPC_MOVE(((rax_12 * r15) + *arg1), (((r15 + arg4) * rax_12) + *arg1), (((result_2[1] - r15) + 1) * rax_12));
                
                FPC_MOVE(arg3, ((rax_12 * r15) + *arg1), (rax_12 * arg4));
                
                if ((var_30_1 != 0 && ((r15 + arg4) - 1) >= r15))
                {
                    void* i_1 = (r15 - 1);
                    
                    do
                    {
                        i_1 += 1;
                        FPC_ADDREF(((rax_12 * i_1) + *arg1), var_30_1);
                    } while (((r15 + arg4) - 1) > i_1);
                }
                
                result_1 = result_2;
            }
            else
            {
                SYSTEM_$$_GETMEM$POINTER$QWORD(&result_1, (((var_38_1 + 1) * rax_12) + 0x10));
                SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(result_1, 0x10, 0);
                
                if (r15 > 0)
                    FPC_MOVE(*arg1, &result_1[0x10], (rax_12 * r15));
                
                FPC_MOVE(arg3, ((rax_12 * r15) + &result_1[0x10]), (rax_12 * arg4));
                
                if (((result_2[1] - r15) + 1) > 0)
                    FPC_MOVE(((rax_12 * r15) + *arg1), (((r15 + arg4) * rax_12) + &result_1[0x10]), (((result_2[1] - r15) + 1) * rax_12));
                
                if ((var_30_1 != 0 && var_38_1 >= 0))
                {
                    int64_t r12_1 = -1;
                    
                    do
                    {
                        r12_1 += 1;
                        FPC_ADDREF(((r12_1 * rax_12) + &result_1[0x10]), var_30_1);
                    } while (var_38_1 > r12_1);
                }
                
                FPC_DYNARRAY_CLEAR(arg1, arg5);
            }
            
            *arg1 = &result_1[0x10];
            *result_1 = 1;
            result = result_1;
            *(result + 8) = var_38_1;
        }
    }
    
    return result;
}

int64_t* fpc_dynarray_concat_multi(int64_t* arg1, void* arg2, int64_t arg3, void* arg4)
{
    int64_t* result = (arg4 + 1);
    
    if (result != 0)
    {
        int64_t var_18_1 = 0;
        
        if (arg4 >= 0)
        {
            int64_t var_30_1 = -1;
            
            do
            {
                int64_t rax = (var_30_1 + 1);
                var_30_1 = rax;
                
                if (*(arg3 + (rax << 3)) != 0)
                    var_18_1 += (*(*(arg3 + (var_30_1 << 3)) - 8) + 1);
            } while (arg4 > var_30_1);
        }
        
        if (var_18_1 == 0)
            return FPC_DYNARRAY_CLEAR(arg1, arg2);
        
        void* rax_8 = (*(arg2 + 1) + (arg2 + 2));
        int64_t r14_1 = *rax_8;
        char* r13_1;
        
        if (*(rax_8 + 0x14) == 0)
            r13_1 = nullptr;
        else
            r13_1 = **(rax_8 + 0x14);
        
        int64_t r12_1 = 0;
        int64_t* result_1;
        SYSTEM_$$_GETMEM$POINTER$QWORD(&result_1, ((r14_1 * var_18_1) + 0x10));
        
        if (arg4 >= 0)
        {
            int64_t var_30_2 = -1;
            
            do
            {
                int64_t rax_12 = (var_30_2 + 1);
                var_30_2 = rax_12;
                
                if (*(arg3 + (rax_12 << 3)) != 0)
                {
                    void* rbx_1 = (*(arg3 + (var_30_2 << 3)) - 0x10);
                    
                    if (*(rbx_1 + 8) >= 0)
                    {
                        FPC_MOVE(*(arg3 + (var_30_2 << 3)), ((r14_1 * r12_1) + &result_1[2]), ((*(rbx_1 + 8) + 1) * r14_1));
                        r12_1 += (*(rbx_1 + 8) + 1);
                    }
                }
            } while (arg4 > var_30_2);
        }
        
        if ((r13_1 != 0 && (var_18_1 - 1) >= 0))
        {
            int64_t i = -1;
            
            do
            {
                i += 1;
                FPC_ADDREF(((r14_1 * i) + &result_1[2]), r13_1);
            } while ((var_18_1 - 1) > i);
        }
        
        FPC_DYNARRAY_CLEAR(arg1, arg2);
        *arg1 = &result_1[2];
        *result_1 = 1;
        result = result_1;
        result[1] = (var_18_1 - 1);
    }
    
    return result;
}

int64_t* fpc_dynarray_concat(int64_t* arg1, void* arg2, void* arg3, void* arg4)
{
    int64_t var_50 = 0;
    
    if (arg3 != 0)
        var_50 = (*(arg3 - 8) + 1);
    
    if (arg4 != 0)
        var_50 += (*(arg4 - 8) + 1);
    
    if (var_50 == 0)
        return FPC_DYNARRAY_CLEAR(arg1, arg2);
    
    void* rdx_1 = (*(arg2 + 1) + (arg2 + 2));
    int64_t rax_8 = *rdx_1;
    char* r14_1;
    
    if (*(rdx_1 + 0x14) == 0)
        r14_1 = nullptr;
    else
        r14_1 = **(rdx_1 + 0x14);
    
    int64_t* result_1;
    SYSTEM_$$_GETMEM$POINTER$QWORD(&result_1, ((rax_8 * var_50) + 0x10));
    int64_t rbx_1 = 0;
    
    if ((arg3 != 0 && *(arg3 - 8) >= 0))
    {
        FPC_MOVE(arg3, &result_1[2], ((*(arg3 - 8) + 1) * rax_8));
        rbx_1 = (*(arg3 - 8) + 1);
    }
    
    if ((arg4 != 0 && *(arg4 - 8) >= 0))
        FPC_MOVE(arg4, ((rax_8 * rbx_1) + &result_1[2]), ((*(arg4 - 8) + 1) * rax_8));
    
    if ((r14_1 != 0 && (var_50 - 1) >= 0))
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            FPC_ADDREF(((rax_8 * i) + &result_1[2]), r14_1);
        } while ((var_50 - 1) > i);
    }
    
    FPC_DYNARRAY_CLEAR(arg1, arg2);
    *arg1 = &result_1[2];
    *result_1 = 1;
    int64_t* result = result_1;
    result[1] = (var_50 - 1);
    return result;
}

int64_t* SYSTEM_$$_DYNARRAYSETLENGTH$POINTER$POINTER$INT64$PSIZEINT(void** arg1, void* arg2, int64_t arg3, int64_t* arg4)
{
    /* tailcall */
    return FPC_DYNARR_SETLENGTH(arg1, arg2, arg3, arg4);
}

int64_t SYSTEM_$$_DYNARRAYSIZE$POINTER$$INT64(void* arg1)
{
    /* tailcall */
    return FPC_DYNARRAY_LENGTH(arg1);
}

void SYSTEM_$$_DYNARRAYCLEAR$POINTER$POINTER(int64_t* arg1, void* arg2)
{
    /* tailcall */
    return FPC_DYNARRAY_CLEAR(arg1, arg2);
}

uint64_t SYSTEM_$$_DYNARRAYDIM$POINTER$$SMALLINT(char* arg1)
{
    int16_t rax = 0;
    
    while (arg1 != 0)
    {
        if (*arg1 != 0x15)
            break;
        
        arg1 = **(((arg1 + 2) + arg1[1]) + 8);
        rax += 1;
    }
    
    return rax;
}

int64_t* SYSTEM_$$_DYNARRAYBOUNDS$POINTER$POINTER$$TBOUNDARRAY(void** arg1, void** arg2, char* arg3)
{
    void** r12 = arg2;
    int64_t r13 = SYSTEM_$$_DYNARRAYDIM$POINTER$$SMALLINT(arg3);
    int64_t var_28 = r13;
    int64_t* result = FPC_DYNARR_SETLENGTH(arg1, &RTTI_$SYSTEM_$$_TBOUNDARRAY, 1, &var_28);
    
    if ((r13 - 1) >= 0)
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            
            if (r12 == 0)
                break;
            
            result = (SYSTEM_$$_DYNARRAYSIZE$POINTER$$INT64(r12) - 1);
            *(*arg1 + (i << 3)) = result;
            r12 = *r12;
        } while ((r13 - 1) > i);
    }
    
    return result;
}

int64_t* SYSTEM_$$_ISDYNARRAYRECTANGULAR$POINTER$POINTER$$BOOLEAN(int64_t* arg1, char* arg2)
{
    int64_t* var_38 = arg1;
    int64_t* result = (SYSTEM_$$_DYNARRAYDIM$POINTER$$SMALLINT(arg2) - 1);
    int64_t r14;
    
    if (result < 1)
    {
    label_412ea2:
        r14 = 1;
    }
    else
    {
        int64_t r15_1 = 0;
        
        while (true)
        {
            r15_1 += 1;
            int64_t rax_3 = SYSTEM_$$_DYNARRAYSIZE$POINTER$$INT64(*var_38);
            int64_t rax_5 = (SYSTEM_$$_DYNARRAYSIZE$POINTER$$INT64(var_38) - 1);
            
            if (rax_5 >= 1)
            {
                int64_t rbx_1 = 0;
                
                while (true)
                {
                    rbx_1 += 1;
                    
                    if (SYSTEM_$$_DYNARRAYSIZE$POINTER$$INT64(var_38[rbx_1]) != rax_3)
                    {
                        r14 = 0;
                        break;
                    }
                    
                    if (rax_5 <= rbx_1)
                        goto label_412e97;
                }
                
                break;
            }
            
        label_412e97:
            var_38 = *var_38;
            
            if (result <= r15_1)
                goto label_412ea2;
        }
    }
    
    result = r14;
    return result;
}

int64_t SYSTEM_$$_DYNARRAYINDEX$POINTER$array_of_INT64$POINTER$$POINTER(int64_t arg1, int64_t arg2, int64_t arg3, void* arg4, int64_t arg5 @ r11)
{
    if (arg3 >= 0)
    {
        int64_t r9_1 = -1;
        
        do
        {
            r9_1 += 1;
            
            if (arg3 > r9_1)
                arg1 = *(arg1 + (*(arg2 + (r9_1 << 3)) << 3));
            
            int64_t* rcx = ((arg4 + 2) + *(arg4 + 1));
            arg5 = *rcx;
            arg4 = *rcx[1];
            
            if (arg4 == 0)
                return 0;
        } while (arg3 > r9_1);
    }
    
    *(arg4 + 1);
    return (arg1 + (arg5 * *(arg2 + (arg3 << 3))));
}

int64_t FPC_DYNARRAY_DECR_REF(int64_t* arg1, void* arg2)
{
    return FPC_DYNARRAY_CLEAR(arg1, arg2);
}

int64_t SYSTEM_$$_DODISPCALLBYIDERROR$POINTER$IDISPATCH$PDISPDESC$POINTER()
{
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(data_426fa1, &data_412f5c, &__saved_rbp);
}

int64_t fpc_dispatch_by_id()
{
    return U_$SYSTEM_$$_DISPCALLBYIDPROC();
}

void* FPC_DO_IS(void* arg1, int64_t* arg2)
{
    void* result;
    
    if ((arg2 != 0 && arg1 != 0))
        result = SYSTEM$_$TOBJECT_$__$$_INHERITSFROM$TCLASS$$BOOLEAN(*arg2, arg1);
    
    if (((arg2 == 0 || arg1 == 0) || result == 0))
        result = 0;
    else
        result = 1;
    
    return result;
}

int64_t* FPC_DO_AS(int64_t arg1, int64_t* arg2)
{
    int64_t __saved_rbp;
    
    if ((arg2 != 0 && SYSTEM$_$TOBJECT_$__$$_INHERITSFROM$TCLASS$$BOOLEAN(*arg2, arg1) == 0))
        SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xdb, &data_412ffc, &__saved_rbp);
    return arg2;
}

void FPC_INTF_DECR_REF(int64_t* arg1)
{
    if (*arg1 != 0)
    {
        *(**arg1 + 0x10)(*arg1);
        *arg1 = 0;
    }
}

int64_t* FPC_INTF_INCR_REF(int64_t* arg1)
{
    if (arg1 == 0)
        return arg1;
    
    return *(*arg1 + 8)(arg1);
}

void FPC_INTF_ASSIGN(int64_t** arg1, int64_t* arg2)
{
    if (arg2 != 0)
        *(*arg2 + 8)(arg2);
    
    if (*arg1 != 0)
        *(**arg1 + 0x10)(*arg1);
    
    *arg1 = arg2;
}

int64_t* FPC_INTF_IS(int64_t* arg1, int64_t arg2)
{
    int64_t var_28 = arg2;
    int64_t rdx;
    int64_t var_20 = rdx;
    int64_t* var_18 = nullptr;
    int64_t* result;
    
    if (arg1 != 0)
        result = **arg1(arg1, &var_28, &var_18);
    
    int64_t rbx;
    
    if ((arg1 == 0 || result != 0))
        rbx = 0;
    else
        rbx = 1;
    
    if (var_18 != 0)
        *(*var_18 + 0x10)(var_18);
    
    result = rbx;
    return result;
}

int64_t* FPC_INTF_IS_CLASS(int64_t* arg1, int64_t arg2)
{
    int64_t* result;
    int64_t* var_18;
    
    if (arg1 == 0)
        result = 0;
    else if (**arg1(arg1, (&TC_$SYSTEM_$$_IOBJECTINSTANCE), &var_18) != 0)
        result = 0;
    else if (SYSTEM$_$TOBJECT_$__$$_INHERITSFROM$TCLASS$$BOOLEAN(*var_18, arg2) == 0)
        result = 0;
    else
        result = 1;
    return result;
}

int64_t FPC_CLASS_IS_INTF(int64_t* arg1, int64_t arg2, int64_t arg3)
{
    int64_t var_28 = arg2;
    int64_t* var_18 = nullptr;
    int64_t* var_10 = nullptr;
    int32_t result;
    int64_t* rbx;
    
    if (arg1 == 0)
        rbx = 0;
    else
    {
        char rax = SYSTEM$_$TOBJECT_$__$$_GETINTERFACEWEAK$TGUID$formal$$BOOLEAN(arg1, 0, 0x46000000000000c0, &var_10);
        
        if (rax != 0)
            result = **var_10(var_10, &var_28, &var_18);
        
        if ((rax != 0 && result == 0))
            rbx = 1;
        else if (SYSTEM$_$TOBJECT_$__$$_GETINTERFACE$TGUID$formal$$BOOLEAN(arg1, var_28, arg3, &var_18) == 0)
            rbx = 0;
        else
            rbx = 1;
    }
    
    if (var_18 != 0)
        *(*var_18 + 0x10)(var_18);
    
    result = rbx;
    return result;
}

void* FPC_CLASS_IS_CORBAINTF(int64_t* arg1, char* arg2)
{
    void* result;
    
    if (arg1 != 0)
        result = SYSTEM$_$TOBJECT_$__$$_GETINTERFACEENTRYBYSTR$SHORTSTRING$$PINTERFACEENTRY(*arg1, arg2);
    
    if ((arg1 == 0 || result == 0))
        result = 0;
    else
        result = 1;
    
    return result;
}

int64_t FPC_INTF_CAST(int64_t* arg1, int64_t* arg2, int64_t arg3)
{
    int64_t var_28 = arg3;
    int64_t rcx;
    int64_t var_20 = rcx;
    int64_t result_1 = 0;
    
    if ((arg2 != 0 && **arg2(arg2, &var_28, &result_1) == 0))
    {
        int64_t result = result_1;
        *arg1 = result;
        return result;
    }
    
    return FPC_INTF_ASSIGN(arg1, nullptr);
}

int64_t* FPC_INTF_CAST_CLASS(int64_t* arg1, int64_t arg2)
{
    int64_t* result;
    
    if (((arg1 != 0 && **arg1(arg1, &TC_$SYSTEM_$$_IOBJECTINSTANCE, &result) == 0) && SYSTEM$_$TOBJECT_$__$$_INHERITSFROM$TCLASS$$BOOLEAN(*result, arg2) != 0))
        return result;
    
    return nullptr;
}

int64_t* FPC_CLASS_CAST_INTF(int64_t** arg1, int64_t* arg2, int64_t arg3, int64_t arg4)
{
    int64_t var_38 = arg3;
    int64_t* result_1 = nullptr;
    int64_t* var_20 = nullptr;
    
    if (arg2 != 0)
    {
        char rax_1 = SYSTEM$_$TOBJECT_$__$$_GETINTERFACEWEAK$TGUID$formal$$BOOLEAN(arg2, 0, 0x46000000000000c0, &var_20);
        int32_t rax_4;
        
        if (rax_1 != 0)
            rax_4 = **var_20(var_20, &var_38, &result_1);
        
        char rax_5;
        
        if ((rax_1 == 0 || rax_4 != 0))
            rax_5 = SYSTEM$_$TOBJECT_$__$$_GETINTERFACE$TGUID$formal$$BOOLEAN(arg2, var_38, arg4, &result_1);
        
        if (((rax_1 != 0 && rax_4 == 0) || rax_5 != 0))
        {
            FPC_INTF_ASSIGN(arg1, nullptr);
            int64_t* result = result_1;
            *arg1 = result;
            return result;
        }
    }
    
    return FPC_INTF_ASSIGN(arg1, nullptr);
}

int64_t FPC_CLASS_CAST_CORBAINTF(int64_t* arg1, char* arg2)
{
    int64_t result;
    
    if ((arg1 != 0 && SYSTEM$_$TOBJECT_$__$$_GETINTERFACE$SHORTSTRING$formal$$BOOLEAN(arg1, arg2, &result) != 0))
        return result;
    
    return 0;
}

int64_t* FPC_INTF_AS(int64_t** arg1, int64_t* arg2, int64_t arg3)
{
    int64_t var_28 = arg3;
    int64_t rcx;
    int64_t var_20 = rcx;
    
    if (arg2 == 0)
        return FPC_INTF_ASSIGN(arg1, nullptr);
    
    int64_t* result_1 = nullptr;
    
    if (**arg2(arg2, &var_28, &result_1) != 0)
        FPC_HANDLEERROR(0xdb);
    
    FPC_INTF_ASSIGN(arg1, nullptr);
    int64_t* result = result_1;
    *arg1 = result;
    return result;
}

int64_t* FPC_INTF_AS_CLASS(int64_t* arg1, int64_t arg2)
{
    if (arg1 == 0)
        return nullptr;
    
    int64_t* result;
    int32_t rax_2 = **arg1(arg1, &TC_$SYSTEM_$$_IOBJECTINSTANCE, &result);
    char rax_4;
    
    if (rax_2 == 0)
        rax_4 = SYSTEM$_$TOBJECT_$__$$_INHERITSFROM$TCLASS$$BOOLEAN(*result, arg2);
    
    if ((rax_2 != 0 || rax_4 == 0))
        FPC_HANDLEERROR(0xdb);
    
    return result;
}

int64_t* FPC_CLASS_AS_INTF(int64_t** arg1, int64_t* arg2, int64_t arg3, int64_t arg4)
{
    int64_t var_38 = arg3;
    
    if (arg2 == 0)
        return FPC_INTF_ASSIGN(arg1, nullptr);
    
    int64_t* result_1 = nullptr;
    int64_t* var_20 = nullptr;
    char rax = SYSTEM$_$TOBJECT_$__$$_GETINTERFACEWEAK$TGUID$formal$$BOOLEAN(arg2, 0, 0x46000000000000c0, &var_20);
    int32_t rax_3;
    
    if (rax != 0)
        rax_3 = **var_20(var_20, &var_38, &result_1);
    
    if (((rax == 0 || rax_3 != 0) && SYSTEM$_$TOBJECT_$__$$_GETINTERFACE$TGUID$formal$$BOOLEAN(arg2, var_38, arg4, &result_1) == 0))
        FPC_HANDLEERROR(0xdb);
    
    FPC_INTF_ASSIGN(arg1, nullptr);
    int64_t* result = result_1;
    *arg1 = result;
    return result;
}

int64_t FPC_CLASS_AS_CORBAINTF(int64_t* arg1, char* arg2)
{
    if (arg1 == 0)
        return 0;
    
    int64_t result = 0;
    
    if (SYSTEM$_$TOBJECT_$__$$_GETINTERFACE$SHORTSTRING$formal$$BOOLEAN(arg1, arg2, &result) == 0)
        FPC_HANDLEERROR(0xdb);
    
    return result;
}

int64_t SYSTEM$_$TVMT_$__$$_GETVPARENT$$PVMT(void* arg1)
{
    if (*(arg1 + 0x10) == 0)
        return 0;
    
    return **(arg1 + 0x10);
}

int64_t SYSTEM$_$TINTERFACEENTRY_$__$$_GETIID$$PGUID(int64_t* arg1)
{
    if (*arg1 == 0)
        return 0;
    
    return **arg1;
}

int64_t SYSTEM$_$TINTERFACEENTRY_$__$$_GETIIDSTR$$PSHORTSTRING(void* arg1)
{
    if (*(arg1 + 0x18) == 0)
        return 0;
    
    return **(arg1 + 0x18);
}

int64_t* SYSTEM$_$TOBJECT_$__$$_CREATE$$TOBJECT(int64_t* arg1, int64_t arg2)
{
    int64_t* result = arg1;
    
    if (arg2 == 1)
        result = result[0xd](result);
    
    if (result != 0)
    {
        void var_c0;
        void var_a8;
        int64_t rbx;
        int64_t rbp;
        int64_t r12;
        int64_t r13;
        int64_t r14;
        int64_t r15;
        FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_a8, &var_c0), rbx, rbp, r12, r13, r14, r15);
        int64_t var_68_1 = 0;
        int64_t var_c8_1 = -1;
        
        if ((result != 0 && arg2 != 0))
            *(*result + 0x88)(result);
        
        FPC_POPADDRSTACK();
        
        if (var_68_1 != 0)
        {
            void var_60;
            void var_48;
            FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_48, &var_60), rbx, rbp, r12, r13, r14, r15);
            int64_t var_8_1 = 0;
            
            if (arg2 != 0)
                *(*result + 0x60)(result, 1);
            
            FPC_POPADDRSTACK();
            FPC_RERAISE();
            FPC_POPADDRSTACK();
            
            if (var_8_1 != 0)
                FPC_RAISE_NESTED();
            
            FPC_DONEEXCEPTION();
        }
    }
    
    return result;
}

void SYSTEM$_$TOBJECT_$__$$_DESTROY(int64_t* arg1, int64_t arg2)
{
    if (arg2 > 0)
        *(*arg1 + 0x90)(arg1);
    
    if ((arg1 != 0 && arg2 != 0))
        *(*arg1 + 0x70)(arg1);
}

int64_t* SYSTEM$_$TOBJECT_$__$$_FREE(int64_t* arg1)
{
    if (arg1 == 0)
        return arg1;
    
    return *(*arg1 + 0x60)(arg1, 1);
}

int64_t SYSTEM$_$TOBJECT_$__$$_INSTANCESIZE$$INT64(int64_t* arg1)
{
    return *arg1;
}

void SYSTEM_$$_INITINTERFACEPOINTERS$TCLASS$POINTER(void* const arg1, int64_t arg2)
{
    void* const rdx_4;
    
    for (; arg1 != 0; arg1 = rdx_4)
    {
        if (*(arg1 + 0x50) == 0)
            break;
        
        int32_t* r9_1 = *(arg1 + 0x50);
        int32_t j = *r9_1;
        void* rax = &r9_1[2];
        
        for (; j > 0; j -= 1)
        {
            if (*(rax + 0x20) == 0)
                *(*(rax + 0x10) + arg2) = *(rax + 8);
            
            rax += 0x28;
        }
        
        if (*(arg1 + 0x10) == 0)
            rdx_4 = nullptr;
        else
            rdx_4 = **(arg1 + 0x10);
    }
}

int64_t** SYSTEM$_$TOBJECT_$__$$_INITINSTANCE$POINTER$$TOBJECT(int64_t* arg1, int64_t** arg2)
{
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(arg2, *arg1, 0);
    *arg2 = arg1;
    
    if (arg1[0xa] != 0)
        SYSTEM_$$_INITINTERFACEPOINTERS$TCLASS$POINTER(arg1, arg2);
    
    if (arg1 != 0)
    {
        void* rdi_2 = arg1[8];
        
        if (rdi_2 != 0)
        {
            int32_t* rax_1 = SYSTEM_$$_RTTIRECORDMOPINITTABLE$POINTER$$PRTTIRECORDOPOFFSETTABLE(rdi_2);
            
            if (rax_1 != 0)
            {
                int32_t r13_1 = (*rax_1 - 1);
                
                if (r13_1 >= 0)
                {
                    int32_t r14_1 = -1;
                    
                    do
                    {
                        r14_1 += 1;
                        *((rax_1 + (r14_1 << 4)) + 4)((*((rax_1 + (r14_1 << 4)) + 0xc) + arg2));
                    } while (r13_1 > r14_1);
                }
            }
        }
    }
    
    return arg2;
}

int64_t SYSTEM$_$TOBJECT_$__$$_CLASSPARENT$$TCLASS(void* arg1)
{
    if (*(arg1 + 0x10) == 0)
        return 0;
    
    return **(arg1 + 0x10);
}

int64_t** SYSTEM$_$TOBJECT_$__$$_NEWINSTANCE$$TOBJECT(int64_t* arg1)
{
    int64_t** result;
    SYSTEM_$$_GETMEM$POINTER$QWORD(&result, *arg1);
    
    if (result != 0)
    {
        int64_t** result_1 = result;
        SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(result_1, *arg1, 0);
        *result_1 = arg1;
        
        if (arg1[0xa] != 0)
            SYSTEM_$$_INITINTERFACEPOINTERS$TCLASS$POINTER(arg1, result_1);
        
        if (arg1 != 0)
        {
            void* rdi_3 = arg1[8];
            
            if (rdi_3 != 0)
            {
                int32_t* rax_1 = SYSTEM_$$_RTTIRECORDMOPINITTABLE$POINTER$$PRTTIRECORDOPOFFSETTABLE(rdi_3);
                
                if (rax_1 != 0)
                {
                    int32_t r13_1 = (*rax_1 - 1);
                    
                    if (r13_1 >= 0)
                    {
                        int32_t r14_1 = -1;
                        
                        do
                        {
                            r14_1 += 1;
                            *((rax_1 + (r14_1 << 4)) + 4)((result_1 + *((rax_1 + (r14_1 << 4)) + 0xc)));
                        } while (r13_1 > r14_1);
                    }
                }
            }
        }
    }
    
    return result;
}

int64_t SYSTEM$_$TOBJECT_$__$$_FREEINSTANCE(int64_t* arg1)
{
    SYSTEM$_$TOBJECT_$__$$_CLEANUPINSTANCE(arg1);
    return SYSTEM_$$_FREEMEM$POINTER$$QWORD();
}

int64_t SYSTEM$_$TOBJECT_$__$$_CLASSTYPE$$TCLASS(int64_t arg1) __pure
{
    return arg1;
}

int64_t SYSTEM$_$TOBJECT_$__$$_METHODADDRESS$SHORTSTRING$$POINTER(void* arg1, char* arg2)
{
    void* const i_1;
    
    for (void* const i = arg1; i != 0; i = i_1)
    {
        int32_t* r13_1 = *(i + 0x28);
        
        if (r13_1 != 0)
        {
            int32_t rax_2 = (*r13_1 - 1);
            int32_t r12_1 = -1;
            
            do
            {
                r12_1 += 1;
                uint64_t rax_4 = (r12_1 << 4);
                uint64_t rax_5;
                int64_t rcx;
                int64_t rdx;
                uint64_t r8;
                char r11;
                rax_5 = SYSTEM_$$_SHORTCOMPARETEXT$SHORTSTRING$SHORTSTRING$$INT64(*((r13_1 + rax_4) + 4), arg2, rdx, rcx, r8, rax_4, r11);
                
                if (rax_5 == 0)
                    return *((r13_1 + (r12_1 << 4)) + 0xc);
            } while (rax_2 > r12_1);
        }
        
        if (*(i + 0x10) == 0)
            i_1 = nullptr;
        else
            i_1 = **(i + 0x10);
    }
    
    return 0;
}

char* SYSTEM$_$TOBJECT_$__$$_METHODNAME$POINTER$$SHORTSTRING(void* arg1, char* arg2, int64_t arg3)
{
    void* const i_1;
    
    for (void* const i = arg1; i != 0; i = i_1)
    {
        int32_t* r13_1 = *(i + 0x28);
        
        if (r13_1 != 0)
        {
            int32_t j = -1;
            
            do
            {
                j += 1;
                
                if (arg3 == *((r13_1 + (j << 4)) + 0xc))
                    return FPC_SHORTSTR_TO_SHORTSTR(arg2, 0xff, *((r13_1 + (j << 4)) + 4));
            } while ((*r13_1 - 1) > j);
        }
        
        if (*(i + 0x10) == 0)
            i_1 = nullptr;
        else
            i_1 = **(i + 0x10);
    }
    
    char* result = arg2;
    *result = 0;
    return result;
}

void* SYSTEM$_$TOBJECT_$__$$_FIELDADDRESS$SHORTSTRING$$POINTER(int64_t* arg1, char* arg2)
{
    if (*arg2 > 0)
    {
        int64_t* rdx_1 = arg1;
        void* const i_1;
        
        for (void* const i = *rdx_1; i != 0; i = i_1)
        {
            int16_t* r15_1 = *(i + 0x30);
            
            if (r15_1 != 0)
            {
                void* r12_1 = &r15_1[5];
                uint64_t rax_2 = (*r15_1 - 1);
                int32_t rbx_1 = rax_2;
                
                if (rbx_1 >= 0)
                {
                    int32_t r13_1 = -1;
                    
                    do
                    {
                        r13_1 += 1;
                        uint64_t rax_3;
                        int64_t rcx;
                        uint64_t r8;
                        char r11;
                        rax_3 = SYSTEM_$$_SHORTCOMPARETEXT$SHORTSTRING$SHORTSTRING$$INT64((r12_1 + 0xa), arg2, rdx_1, rcx, r8, rax_2, r11);
                        
                        if (rax_3 == 0)
                            return (*r12_1 + arg1);
                        
                        rdx_1 = (r12_1 + 0xb);
                        rax_2 = *(r12_1 + 0xa);
                        r12_1 = (rdx_1 + rax_2);
                    } while (rbx_1 > r13_1);
                }
            }
            
            if (*(i + 0x10) == 0)
                i_1 = nullptr;
            else
                i_1 = **(i + 0x10);
        }
    }
    
    return nullptr;
}

int64_t SYSTEM$_$TOBJECT_$__$$_SAFECALLEXCEPTION$TOBJECT$POINTER$$HRESULT() __pure
{
    return 0x8000ffff;
}

int64_t SYSTEM$_$TOBJECT_$__$$_CLASSINFO$$POINTER(void* arg1)
{
    return *(arg1 + 0x38);
}

uint64_t SYSTEM$_$TOBJECT_$__$$_CLASSNAME$$SHORTSTRING(void* arg1, char* arg2)
{
    return FPC_SHORTSTR_TO_SHORTSTR(arg2, 0xff, *(arg1 + 0x18));
}

uint64_t SYSTEM$_$TOBJECT_$__$$_CLASSNAMEIS$SHORTSTRING$$BOOLEAN(void* arg1, char* arg2, int64_t arg3, int64_t arg4, uint64_t arg5)
{
    char rax;
    uint64_t result;
    char r11;
    result = SYSTEM_$$_SHORTCOMPARETEXT$SHORTSTRING$SHORTSTRING$$INT64(*(arg1 + 0x18), arg2, arg3, arg4, arg5, rax, r11) == 0;
    return result;
}

void* const SYSTEM$_$TOBJECT_$__$$_INHERITSFROM$TCLASS$$BOOLEAN(void* const arg1, int64_t arg2)
{
    void* const result;
    
    if (arg2 == 0)
    {
        result = 0;
        return result;
    }
    
    for (; arg1 != 0; arg1 = result)
    {
        if (arg2 == arg1)
            break;
        
        if (*(arg1 + 0x10) == 0)
            result = nullptr;
        else
            result = **(arg1 + 0x10);
    }
    
    result = arg2 == arg1;
    return result;
}

int64_t SYSTEM$_$TOBJECT_$__$$_STRINGMESSAGETABLE$$PSTRINGMESSAGETABLE(void* arg1)
{
    return *(arg1 + 0x58);
}

int64_t SYSTEM$_$TOBJECT_$__$$_DISPATCH$formal(int64_t* arg1, int32_t* arg2, void* arg3 @ r13)
{
    void* var_18 = arg3;
    int64_t* i_2 = arg1;
    int64_t* i_1;
    
    for (int64_t* i = *i_2; i != 0; i = i_1)
    {
        int32_t* rax_3 = i[4];
        int32_t i_3;
        
        if (rax_3 == 0)
            i_3 = 0;
        else
        {
            arg3 = &rax_3[2];
            i_3 = *rax_3;
        }
        
        i_2 = i_3;
        int32_t rbx_1 = (i_2 - 1);
        
        if (rbx_1 >= 0)
        {
            int32_t r12_1 = -1;
            
            do
            {
                r12_1 += 1;
                i_2 = (r12_1 << 4);
                
                if (*arg2 == *(i_2 + arg3))
                    return *((arg3 + (r12_1 << 4)) + 8)(arg1, arg2, i_2);
            } while (rbx_1 > r12_1);
        }
        
        if (i[2] == 0)
            i_1 = nullptr;
        else
        {
            i_2 = i;
            i_1 = *i_2[2];
        }
    }
    
    return *(*arg1 + 0x80)(arg1, arg2, i_2);
}

int64_t SYSTEM$_$TOBJECT_$__$$_DISPATCHSTR$formal(int64_t* arg1, char* arg2, void* arg3 @ r13)
{
    void* var_18 = arg3;
    void var_158;
    FPC_SHORTSTR_TO_SHORTSTR(&var_158, 0xff, arg2);
    void* const i_1;
    
    for (void* const i = *arg1; i != 0; i = i_1)
    {
        int32_t* rax_2 = *(i + 0x58);
        int32_t var_48_1;
        
        if ((rax_2 == 0 || *rax_2 == 0))
            var_48_1 = 0;
        else
        {
            var_48_1 = *rax_2;
            arg3 = &rax_2[2];
        }
        
        if ((var_48_1 - 1) >= 0)
        {
            int32_t j = -1;
            
            do
            {
                j += 1;
                
                if (FPC_SHORTSTR_COMPARE_EQUAL(&var_158, *((j << 4) + arg3)) == 0)
                    return *((arg3 + (j << 4)) + 8)(arg1, arg2);
            } while ((var_48_1 - 1) > j);
        }
        
        if (*(i + 0x10) == 0)
            i_1 = nullptr;
        else
            i_1 = **(i + 0x10);
    }
    
    return *(*arg1 + 0x98)(arg1, arg2);
}

int64_t SYSTEM$_$TOBJECT_$__$$_DEFAULTHANDLER$formal(int64_t arg1) __pure
{
    return arg1;
}

int64_t SYSTEM$_$TOBJECT_$__$$_DEFAULTHANDLERSTR$formal(int64_t arg1) __pure
{
    return arg1;
}

void SYSTEM$_$TOBJECT_$__$$_CLEANUPINSTANCE(int64_t* arg1)
{
    void* const i_1;
    
    for (void* const i = *arg1; i != 0; i = i_1)
    {
        void* r13_1 = *(i + 0x40);
        
        if (r13_1 != 0)
            SYSTEM_$$_RECORDRTTI$POINTER$POINTER$TRTTIPROC(arg1, r13_1, FPC_FINALIZE);
        
        if (*(i + 0x10) == 0)
            i_1 = nullptr;
        else
            i_1 = **(i + 0x10);
    }
}

int64_t SYSTEM$_$TOBJECT_$__$$_AFTERCONSTRUCTION(int64_t arg1) __pure
{
    return arg1;
}

int64_t SYSTEM$_$TOBJECT_$__$$_BEFOREDESTRUCTION(int64_t arg1) __pure
{
    return arg1;
}

int64_t SYSTEM_$$_ISGUIDEQUAL$TGUID$TGUID$$BOOLEAN(int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4) __pure
{
    int64_t var_20 = arg2;
    int32_t result;
    
    if ((((arg1 != arg3 || *arg1[4] != *arg3[4]) || var_20 != arg4) || *var_20[4] != *arg4[4]))
        result = 0;
    else
        result = 1;
    
    return result;
}

uint64_t SYSTEM_$$_GETINTERFACEBYENTRY$POINTER$PINTERFACEENTRY$formal$$BOOLEAN(int64_t* arg1, void* arg2, int64_t* arg3)
{
    *arg3 = 0;
    
    if ((arg2 != 0 && arg1 != 0))
        switch (*(arg2 + 0x20))
        {
            case 0:
            {
                *arg3 = (*(arg2 + 0x10) + arg1);
                break;
            }
            case 1:
            {
                *(*(arg2 + 0x10) + *arg1)(arg1, arg3);
                break;
            }
            case 2:
            {
                *(arg2 + 0x10)(arg1, arg3);
                break;
            }
            case 3:
            {
                *arg3 = *(*(arg2 + 0x10) + arg1);
                break;
            }
            case 4:
            {
                *arg3 = *(*arg1 + *(arg2 + 0x10))(arg1);
                break;
            }
            case 5:
            {
                *arg3 = *(arg2 + 0x10)(arg1);
                break;
            }
            case 6:
            {
                *arg3 = *(*(arg2 + 0x10) + arg1);
                break;
            }
        }
    
    uint64_t result;
    result = *arg3 != 0;
    return result;
}

int64_t* SYSTEM$_$TOBJECT_$__$$_GETINTERFACE$TGUID$formal$$BOOLEAN(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t* arg4)
{
    int64_t r13;
    int64_t var_18 = r13;
    int64_t* result;
    
    if (SYSTEM_$$_ISGUIDEQUAL$TGUID$TGUID$$BOOLEAN(TC_$SYSTEM_$$_IOBJECTINSTANCE, data_427058, arg2, arg3) == 0)
    {
        int64_t* r12_1 = arg1;
        void* rax_1;
        
        while (true)
        {
            rax_1 = SYSTEM$_$TOBJECT_$__$$_GETINTERFACEENTRY$TGUID$$PINTERFACEENTRY(*r12_1, arg2, arg3);
            result = SYSTEM_$$_GETINTERFACEBYENTRY$POINTER$PINTERFACEENTRY$formal$$BOOLEAN(r12_1, rax_1, arg4);
            r13 = result;
            
            if (result == 0)
                break;
            
            if (*(rax_1 + 0x20) < 4)
                break;
            
            r12_1 = *arg4;
        }
        
        if (r13 != 0)
        {
            result = *(rax_1 + 0x20);
            
            if (((result == 0 || result == 3) || result == 3))
                *(**arg4 + 8)(*arg4);
        }
    }
    else
    {
        *arg4 = arg1;
        r13 = 1;
    }
    
    result = r13;
    return result;
}

int64_t* SYSTEM$_$TOBJECT_$__$$_GETINTERFACEWEAK$TGUID$formal$$BOOLEAN(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t* arg4)
{
    int64_t r13;
    int64_t var_18 = r13;
    int64_t* result;
    
    if (SYSTEM_$$_ISGUIDEQUAL$TGUID$TGUID$$BOOLEAN(TC_$SYSTEM_$$_IOBJECTINSTANCE, data_427058, arg2, arg3) == 0)
    {
        int64_t* r12_1 = arg1;
        void* rax_1;
        
        while (true)
        {
            rax_1 = SYSTEM$_$TOBJECT_$__$$_GETINTERFACEENTRY$TGUID$$PINTERFACEENTRY(*r12_1, arg2, arg3);
            result = SYSTEM_$$_GETINTERFACEBYENTRY$POINTER$PINTERFACEENTRY$formal$$BOOLEAN(r12_1, rax_1, arg4);
            r13 = result;
            
            if (result == 0)
                break;
            
            if (*(rax_1 + 0x20) < 4)
                break;
            
            r12_1 = *arg4;
        }
        
        if (r13 != 0)
        {
            result = *(rax_1 + 0x20);
            
            if ((result != 0 && (result != 3 && result != 3)))
                *(**arg4 + 0x10)(*arg4);
        }
    }
    else
    {
        *arg4 = arg1;
        r13 = 1;
    }
    
    result = r13;
    return result;
}

uint64_t SYSTEM$_$TOBJECT_$__$$_GETINTERFACEBYSTR$SHORTSTRING$formal$$BOOLEAN(int64_t* arg1, char* arg2, int64_t* arg3)
{
    int64_t r13;
    int64_t var_18 = r13;
    int64_t* rbx = arg1;
    void* rax_1;
    uint64_t result;
    
    while (true)
    {
        rax_1 = SYSTEM$_$TOBJECT_$__$$_GETINTERFACEENTRYBYSTR$SHORTSTRING$$PINTERFACEENTRY(*rbx, arg2);
        result = SYSTEM_$$_GETINTERFACEBYENTRY$POINTER$PINTERFACEENTRY$formal$$BOOLEAN(rbx, rax_1, arg3);
        r13 = result;
        
        if (result == 0)
            break;
        
        if (*(rax_1 + 0x20) < 4)
            break;
        
        rbx = *arg3;
    }
    
    if (r13 != 0)
    {
        if (*rax_1 == 0)
            result = 0;
        else
            result = **rax_1;
        
        if (result != 0)
        {
            result = *(rax_1 + 0x20);
            
            if (((result == 0 || result == 3) || result == 3))
                *(**arg3 + 8)(*arg3);
        }
    }
    
    result = r13;
    return result;
}

uint64_t SYSTEM$_$TOBJECT_$__$$_GETINTERFACE$SHORTSTRING$formal$$BOOLEAN(int64_t* arg1, char* arg2, int64_t* arg3)
{
    return SYSTEM$_$TOBJECT_$__$$_GETINTERFACEBYSTR$SHORTSTRING$formal$$BOOLEAN(arg1, arg2, arg3);
}

void* SYSTEM$_$TOBJECT_$__$$_GETINTERFACEENTRY$TGUID$$PINTERFACEENTRY(void* arg1, int64_t arg2, int64_t arg3)
{
    void* const i_1;
    
    for (void* const i = arg1; i != 0; i = i_1)
    {
        if (*(i + 0x50) == 0)
            break;
        
        int64_t* r14_1 = *(i + 0x50);
        int32_t rax_2 = (*r14_1 - 1);
        
        if (rax_2 >= 0)
        {
            int32_t r12_1 = -1;
            
            do
            {
                r12_1 += 1;
                void* result = &r14_1[((r12_1 * 5) + 1)];
                int64_t rax_6;
                
                if (*result == 0)
                    rax_6 = 0;
                else
                    rax_6 = **result;
                
                if (rax_6 != 0)
                {
                    int64_t* rax_8;
                    
                    if (*result == 0)
                        rax_8 = nullptr;
                    else
                        rax_8 = **result;
                    
                    if (SYSTEM_$$_ISGUIDEQUAL$TGUID$TGUID$$BOOLEAN(*rax_8, rax_8[1], arg2, arg3) != 0)
                        return result;
                }
            } while (rax_2 > r12_1);
        }
        
        if (*(i + 0x10) == 0)
            i_1 = nullptr;
        else
            i_1 = **(i + 0x10);
    }
    
    return nullptr;
}

void* SYSTEM$_$TOBJECT_$__$$_GETINTERFACEENTRYBYSTR$SHORTSTRING$$PINTERFACEENTRY(void* arg1, char* arg2)
{
    void* const i_1;
    
    for (void* const i = arg1; i != 0; i = i_1)
    {
        if (*(i + 0x50) == 0)
            break;
        
        int64_t* r14_1 = *(i + 0x50);
        int32_t rax_2 = (*r14_1 - 1);
        
        if (rax_2 >= 0)
        {
            int32_t r12_1 = -1;
            
            do
            {
                r12_1 += 1;
                void* result = &r14_1[((r12_1 * 5) + 1)];
                int64_t rax_6;
                
                if (*(result + 0x18) == 0)
                    rax_6 = 0;
                else
                    rax_6 = **(result + 0x18);
                
                if (rax_6 != 0)
                {
                    char* rdi;
                    
                    if (*(result + 0x18) == 0)
                        rdi = nullptr;
                    else
                        rdi = **(result + 0x18);
                    
                    if (FPC_SHORTSTR_COMPARE_EQUAL(rdi, arg2) == 0)
                        return result;
                }
            } while (rax_2 > r12_1);
        }
        
        if (*(i + 0x10) == 0)
            i_1 = nullptr;
        else
            i_1 = **(i + 0x10);
    }
    
    return nullptr;
}

int64_t SYSTEM$_$TOBJECT_$__$$_GETINTERFACETABLE$$PINTERFACETABLE(void* arg1)
{
    return *(arg1 + 0x50);
}

void* SYSTEM$_$TOBJECT_$__$$_UNITNAME$$ANSISTRING(void* arg1, char** arg2)
{
    void* rax = SYSTEM$_$TOBJECT_$__$$_CLASSINFO$$POINTER(arg1);
    
    if (rax == 0)
        return FPC_ANSISTR_ASSIGN(arg2, 0);
    
    return fpc_shortstr_to_ansistr(arg2, ((rax + (*(rax + 1) + 2)) + 0x12), 0);
}

int64_t SYSTEM$_$TOBJECT_$__$$_QUALIFIEDCLASSNAME$$ANSISTRING(void* arg1, char** arg2)
{
    int64_t var_288 = 0;
    char* var_120 = nullptr;
    void var_280;
    void var_268;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_268, &var_280), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    SYSTEM$_$TOBJECT_$__$$_UNITNAME$$ANSISTRING(arg1, &var_288);
    int64_t var_220;
    
    if (var_288 != 0)
    {
        var_220 = var_288;
        void* const var_218_1 = &.Ld33;
        void var_118;
        SYSTEM$_$TOBJECT_$__$$_CLASSNAME$$SHORTSTRING(arg1, &var_118);
        fpc_shortstr_to_ansistr(&var_120, &var_118, 0);
        char* var_210_1 = var_120;
        fpc_ansistr_concat_multi(arg2, &var_220, 2, 0);
    }
    else
    {
        SYSTEM$_$TOBJECT_$__$$_CLASSNAME$$SHORTSTRING(arg1, &var_220);
        fpc_shortstr_to_ansistr(arg2, &var_220, 0);
    }
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_120);
    FPC_ANSISTR_DECR_REF(&var_288);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM$_$TOBJECT_$__$$_EQUALS$TOBJECT$$BOOLEAN(int64_t arg1, int64_t arg2) __pure
{
    int64_t result;
    result = arg1 == arg2;
    return result;
}

int64_t SYSTEM$_$TOBJECT_$__$$_GETHASHCODE$$INT64(int64_t arg1) __pure
{
    return arg1;
}

void* SYSTEM$_$TOBJECT_$__$$_TOSTRING$$ANSISTRING(int64_t* arg1, char** arg2)
{
    void var_108;
    SYSTEM$_$TOBJECT_$__$$_CLASSNAME$$SHORTSTRING(*arg1, &var_108);
    return fpc_shortstr_to_ansistr(arg2, &var_108, 0);
}

int64_t SYSTEM$_$TINTERFACEDOBJECT_$__$$_QUERYINTERFACE$TGUID$formal$$LONGINT(int64_t* arg1, int64_t* arg2, int64_t* arg3)
{
    if (SYSTEM$_$TOBJECT_$__$$_GETINTERFACE$TGUID$formal$$BOOLEAN(arg1, *arg2, arg2[1], arg3) == 0)
        return 0x80004002;
    
    return 0;
}

uint64_t SYSTEM$_$TINTERFACEDOBJECT_$__$$__ADDREF$$LONGINT(void* arg1)
{
    return FPC_INTERLOCKEDINCREMENT((arg1 + 8));
}

uint64_t SYSTEM$_$TINTERFACEDOBJECT_$__$$__RELEASE$$LONGINT(int64_t* arg1)
{
    int32_t rax = FPC_INTERLOCKEDDECREMENT(&arg1[1]);
    
    if ((rax == 0 && FPC_INTERLOCKEDINCREMENT((arg1 + 0xc)) == 1))
        *(*arg1 + 0x60)(arg1, 1);
    
    return rax;
}

int64_t SYSTEM$_$TINTERFACEDOBJECT_$__$$_DESTROY(int64_t* arg1, int64_t arg2)
{
    if (arg2 > 0)
        *(*arg1 + 0x90)(arg1);
    
    arg1[1] = 0;
    *(arg1 + 0xc) = 0;
    int64_t result = SYSTEM$_$TOBJECT_$__$$_DESTROY(arg1, 0);
    
    if ((arg1 != 0 && arg2 != 0))
        return *(*arg1 + 0x70)(arg1);
    
    return result;
}

uint32_t* SYSTEM$_$TINTERFACEDOBJECT_$__$$_AFTERCONSTRUCTION(void* arg1)
{
    return SYSTEM_$$_DECLOCKED$LONGINT$$BOOLEAN((arg1 + 8));
}

void* SYSTEM$_$TINTERFACEDOBJECT_$__$$_BEFOREDESTRUCTION(void* arg1)
{
    if (*(arg1 + 8) == 0)
        return arg1;
    
    return FPC_HANDLEERROR(0xcc);
}

int64_t** SYSTEM$_$TINTERFACEDOBJECT_$__$$_NEWINSTANCE$$TOBJECT(int64_t* arg1)
{
    int64_t** result = SYSTEM$_$TOBJECT_$__$$_NEWINSTANCE$$TOBJECT(arg1);
    
    if (result != 0)
        result[1] = 1;
    
    return result;
}

int64_t* SYSTEM$_$TAGGREGATEDOBJECT_$__$$_CREATE$IUNKNOWN$$TAGGREGATEDOBJECT(int64_t* arg1, int64_t arg2, int64_t arg3)
{
    int64_t* result = arg1;
    
    if (arg2 == 1)
        result = result[0xd](result);
    
    if (result != 0)
    {
        void var_c8;
        void var_b0;
        int64_t rbx;
        int64_t rbp;
        int64_t r12;
        int64_t r13;
        int64_t r14;
        int64_t r15;
        FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_b0, &var_c8), rbx, rbp, r12, r13, r14, r15);
        int64_t var_70_1 = 0;
        int64_t var_d0_1 = -1;
        SYSTEM$_$TOBJECT_$__$$_CREATE$$TOBJECT(result, 0);
        result[1] = arg3;
        
        if ((result != 0 && arg2 != 0))
            *(*result + 0x88)(result);
        
        FPC_POPADDRSTACK();
        
        if (var_70_1 != 0)
        {
            void var_68;
            void var_50;
            FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_50, &var_68), rbx, rbp, r12, r13, r14, r15);
            int64_t var_10_1 = 0;
            
            if (arg2 != 0)
                *(*result + 0x60)(result, 1);
            
            FPC_POPADDRSTACK();
            FPC_RERAISE();
            FPC_POPADDRSTACK();
            
            if (var_10_1 != 0)
                FPC_RAISE_NESTED();
            
            FPC_DONEEXCEPTION();
        }
    }
    
    return result;
}

int64_t SYSTEM$_$TAGGREGATEDOBJECT_$__$$_QUERYINTERFACE$TGUID$formal$$LONGINT(void* arg1)
{
    return ***(arg1 + 8)(*(arg1 + 8));
}

int64_t SYSTEM$_$TAGGREGATEDOBJECT_$__$$__ADDREF$$LONGINT(void* arg1)
{
    return *(**(arg1 + 8) + 8)(*(arg1 + 8));
}

int64_t SYSTEM$_$TAGGREGATEDOBJECT_$__$$__RELEASE$$LONGINT(void* arg1)
{
    return *(**(arg1 + 8) + 0x10)(*(arg1 + 8));
}

int64_t SYSTEM$_$TAGGREGATEDOBJECT_$__$$_GETCONTROLLER$$IUNKNOWN(void* arg1, int64_t** arg2)
{
    return FPC_INTF_ASSIGN(arg2, *(arg1 + 8));
}

int64_t SYSTEM$_$TCONTAINEDOBJECT_$__$$_QUERYINTERFACE$TGUID$formal$$LONGINT(int64_t* arg1, int64_t* arg2, int64_t* arg3)
{
    if (SYSTEM$_$TOBJECT_$__$$_GETINTERFACE$TGUID$formal$$BOOLEAN(arg1, *arg2, arg2[1], arg3) == 0)
        return 0x80004002;
    
    return 0;
}

int64_t SYSTEM_$$_RAISELIST$$PEXCEPTOBJECT()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434cc8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTOBJECTSTACK);
    
    return *rax;
}

int64_t SYSTEM_$$_ACQUIREEXCEPTIONOBJECT$$POINTER(int64_t arg1 @ rbx)
{
    int64_t var_8 = arg1;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434cc8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTOBJECTSTACK);
    
    int64_t* rax_1 = *rax;
    
    if (rax_1 != 0)
    {
        rax_1[3] += 1;
        return *rax_1;
    }
    
    FPC_RUNERROR(0xe7);
    return arg1;
}

void* SYSTEM_$$_RELEASEEXCEPTIONOBJECT()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434cc8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTOBJECTSTACK);
    
    void* result = *rax;
    
    if (result == 0)
        return FPC_RUNERROR(0xe7);
    
    if (*(result + 0x18) > 0)
        *(result + 0x18) -= 1;
    
    return result;
}

int64_t FPC_PUSHEXCEPTADDR(int32_t arg1, int64_t arg2, int64_t* arg3)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434cb8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTADDRSTACK);
    
    arg3[1] = *rax;
    *rax = arg3;
    *arg3 = arg2;
    arg3[2] = arg1;
    return arg2;
}

int64_t SYSTEM_$$_PUSHEXCEPTOBJECT$TOBJECT$POINTER$POINTER(int64_t arg1, int64_t arg2, int64_t* arg3)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* r12;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        r12 = &data_434cc8;
    else
        r12 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTOBJECTSTACK);
    
    int64_t* rax_1 = FPC_GETMEM();
    rax_1[2] = *r12;
    *r12 = rax_1;
    *rax_1 = arg1;
    rax_1[1] = arg2;
    rax_1[3] = 0;
    int64_t* var_18 = arg3;
    int64_t var_20 = arg2;
    int64_t result = 0;
    int32_t r14_1 = 0;
    int32_t i = 0;
    int64_t __saved_rbp;
    int64_t* r13_1 = &__saved_rbp;
    
    for (; i < TC_$SYSTEM_$$_RAISEMAXFRAMECOUNT; i += 1)
    {
        if (r13_1 >= var_18)
            break;
        
        if (SYSTEM_$$_STACKTOP$$POINTER() <= var_18)
            break;
        
        r13_1 = var_18;
        SYSTEM_$$_GET_CALLER_STACKINFO$POINTER$POINTER(&var_18, &var_20);
        
        if (var_20 == 0)
            break;
        
        if (var_18 == 0)
            break;
        
        if (r14_1 <= i)
        {
            r14_1 += 0x10;
            SYSTEM_$$_REALLOCMEM$POINTER$QWORD$$POINTER();
        }
        
        *(result + (i << 3)) = var_20;
    }
    
    *(rax_1 + 0x1c) = i;
    rax_1[4] = result;
    return result;
}

int64_t SYSTEM_$$_DOUNHANDLEDEXCEPTION()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434cc8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTOBJECTSTACK);
    
    int64_t* rax_1 = *rax;
    
    if ((TC_$SYSTEM_$$_EXCEPTPROC != 0 && rax_1 != 0))
    {
        TC_$SYSTEM_$$_EXCEPTPROC(*rax_1, rax_1[1], *(rax_1 + 0x1c), rax_1[4]);
        SYSTEM_$$_HALT$LONGINT(0xd9);
    }
    
    if (TC_$SYSTEM_$$_ERRORADDR != 0)
        return SYSTEM_$$_HALT$LONGINT(TC_$SYSTEM_$$_ERRORCODE);
    
    return FPC_RUNERROR(0xd9);
}

int64_t FPC_RAISEEXCEPTION(int64_t arg1, int64_t arg2, int64_t* arg3)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int32_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434cd8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTTRYLEVEL);
    
    if (*rax != 0)
        SYSTEM_$$_HALT$LONGINT(0xd9);
    
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int32_t* rax_1;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        rax_1 = &data_434cd8;
    else
        rax_1 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_EXCEPTTRYLEVEL);
    
    *rax_1 = 1;
    SYSTEM_$$_PUSHEXCEPTOBJECT$TOBJECT$POINTER$POINTER(arg1, arg2, arg3);
    uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
    int32_t* rax_2;
    
    if (FPC_THREADVAR_RELOCATE_3 == 0)
        rax_2 = &data_434cd8;
    else
        rax_2 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_EXCEPTTRYLEVEL);
    
    *rax_2 = 0;
    uint64_t FPC_THREADVAR_RELOCATE_4 = FPC_THREADVAR_RELOCATE;
    int64_t* rax_3;
    
    if (FPC_THREADVAR_RELOCATE_4 == 0)
        rax_3 = &data_434cb8;
    else
        rax_3 = FPC_THREADVAR_RELOCATE_4(U_$SYSTEM_$$_EXCEPTADDRSTACK);
    
    int64_t* rbx_1 = *rax_3;
    
    if (rbx_1 == 0)
        SYSTEM_$$_DOUNHANDLEDEXCEPTION();
    
    uint64_t FPC_THREADVAR_RELOCATE_5 = FPC_THREADVAR_RELOCATE;
    int64_t* rax_4;
    
    if (FPC_THREADVAR_RELOCATE_5 == 0)
        rax_4 = &data_434cc8;
    else
        rax_4 = FPC_THREADVAR_RELOCATE_5(U_$SYSTEM_$$_EXCEPTOBJECTSTACK);
    
    int64_t* rax_5 = *rax_4;
    
    if ((TC_$SYSTEM_$$_RAISEPROC != 0 && rax_5 != 0))
        TC_$SYSTEM_$$_RAISEPROC(*rax_5, rax_5[1], *(rax_5 + 0x1c), rax_5[4]);
    
    return FPC_LONGJMP(*rbx_1, 1);
}

int64_t FPC_POPADDRSTACK()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rbx;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rbx = &data_434cb8;
    else
        rbx = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTADDRSTACK);
    
    if (*rbx == 0)
        return SYSTEM_$$_HALT$LONGINT(0xff);
    
    int64_t result = *(*rbx + 8);
    *rbx = result;
    return result;
}

int64_t FPC_POPOBJECTSTACK(int64_t arg1 @ r12)
{
    int64_t var_10 = arg1;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434cc8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTOBJECTSTACK);
    
    int64_t* rbx = *rax;
    
    if (rbx != 0)
    {
        if (rbx[3] != 0)
            arg1 = 0;
        else
            arg1 = *rbx;
        
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        int64_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            rax_1 = &data_434cc8;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_EXCEPTOBJECTSTACK);
        
        *rax_1 = rbx[2];
        
        if (rbx[4] != 0)
        {
            rbx[4];
            SYSTEM_$$_FREEMEM$POINTER$$QWORD();
        }
        
        FPC_FREEMEM();
        TC_$SYSTEM_$$_ERRORADDR = 0;
    }
    else
        SYSTEM_$$_HALT$LONGINT(1);
    
    return arg1;
}

int64_t FPC_POPSECONDOBJECTSTACK(int64_t arg1 @ r12)
{
    int64_t var_10 = arg1;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434cc8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTOBJECTSTACK);
    
    void* r13 = *rax;
    
    if ((r13 == 0 || *(r13 + 0x10) == 0))
        SYSTEM_$$_HALT$LONGINT(1);
    else
    {
        if (*(*(r13 + 0x10) + 0x18) != 0)
            arg1 = 0;
        else
            arg1 = **(r13 + 0x10);
        
        void* rbx_1 = *(r13 + 0x10);
        *(r13 + 0x10) = *(rbx_1 + 0x10);
        
        if (*(rbx_1 + 0x20) != 0)
        {
            *(rbx_1 + 0x20);
            SYSTEM_$$_FREEMEM$POINTER$$QWORD();
        }
        
        FPC_FREEMEM();
    }
    
    return arg1;
}

int64_t FPC_RERAISE()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434cb8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTADDRSTACK);
    
    int64_t* rbx = *rax;
    
    if (rbx == 0)
        SYSTEM_$$_DOUNHANDLEDEXCEPTION();
    
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int64_t* rax_1;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        rax_1 = &data_434cc8;
    else
        rax_1 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_EXCEPTOBJECTSTACK);
    
    *(*rax_1 + 0x18) = 0;
    return FPC_LONGJMP(*rbx, 1);
}

int64_t FPC_CATCHES(void* arg1)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434cc8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTOBJECTSTACK);
    
    int64_t* r12 = *rax;
    
    if (r12 == 0)
        SYSTEM_$$_HALT$LONGINT(0xff);
    
    if ((arg1 != -1 && FPC_DO_IS(arg1, *r12) == 0))
        return 0;
    
    return *r12;
}

int64_t* SYSTEM_$$_SYSINITEXCEPTIONS()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434cc8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTOBJECTSTACK);
    
    *rax = 0;
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int64_t* result;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        result = &data_434cb8;
    else
        result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_EXCEPTADDRSTACK);
    
    *result = 0;
    return result;
}

int64_t* FPC_DONEEXCEPTION()
{
    int64_t r12;
    return SYSTEM$_$TOBJECT_$__$$_FREE(FPC_POPOBJECTSTACK(r12));
}

int64_t FPC_RAISE_NESTED()
{
    int64_t r12;
    SYSTEM$_$TOBJECT_$__$$_FREE(FPC_POPSECONDOBJECTSTACK(r12));
    return FPC_RERAISE();
}

uint64_t FPC_SAFECALLHANDLER(int64_t* arg1)
{
    int64_t r12;
    int64_t var_10 = r12;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434cc8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTOBJECTSTACK);
    
    void* rax_1 = *rax;
    int64_t r13;
    
    if (rax_1 == 0)
        r13 = 0;
    else
        r13 = *(rax_1 + 8);
    
    int64_t* rax_2 = FPC_POPOBJECTSTACK(r12);
    int32_t rbx_1;
    
    if ((arg1 == 0 || rax_2 == 0))
        rbx_1 = -0x7fff0001;
    else
        rbx_1 = *(*arg1 + 0x78)(arg1, rax_2, r13);
    
    SYSTEM$_$TOBJECT_$__$$_FREE(rax_2);
    return rbx_1;
}

int64_t FPC_VARIANT_INIT(char* arg1)
{
    return SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(arg1, 0x18, 0);
}

int64_t FPC_VARIANT_CLEAR(int64_t arg1, int64_t arg2)
{
    if (TC_$SYSTEM_$$_VARCLEARPROC == 0)
        return arg1;
    
    return TC_$SYSTEM_$$_VARCLEARPROC(arg1, arg2, &TC_$SYSTEM_$$_VARCLEARPROC);
}

int64_t FPC_VARIANT_ADDREF(int64_t arg1, int64_t arg2)
{
    if (TC_$SYSTEM_$$_VARADDREFPROC == 0)
        return arg1;
    
    return TC_$SYSTEM_$$_VARADDREFPROC(arg1, arg2, &TC_$SYSTEM_$$_VARADDREFPROC);
}

int64_t FPC_VARIANT_COPY(int64_t arg1, int64_t arg2)
{
    if (TC_$SYSTEM_$$_VARCOPYPROC == 0)
        return arg1;
    
    return TC_$SYSTEM_$$_VARCOPYPROC(arg1, arg2, &TC_$SYSTEM_$$_VARCOPYPROC);
}

int64_t FPC_VARIANT_COPY_OVERWRITE(int64_t arg1, int16_t* arg2)
{
    *arg2 = 0;
    
    if (TC_$SYSTEM_$$_VARCOPYPROC == 0)
        return arg1;
    
    return TC_$SYSTEM_$$_VARCOPYPROC();
}

int16_t* FPC_WRITE_TEXT_VARIANT(int32_t arg1, void* arg2, int64_t arg3)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = *(arg2 + 4);
        
        if (rax < 0xd7b1)
        {
        label_415382:
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            if (rax != 0xd7b1)
            {
                if (rax != 0xd7b2)
                    goto label_415382;
                
                if (arg1 != 0xffffffff)
                    return data_434e40(arg2, arg3, arg1);
                
                return data_434e48(arg2, arg3);
            }
            
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x69;
        }
    }
    
    return result;
}

int64_t fpc_vararray_get(int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4)
{
    void var_38;
    FPC_VARIANT_INIT(&var_38);
    void var_98;
    void var_80;
    int64_t rbp;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_80, &var_98), arg1, rbp, arg2, arg3, arg4, r15);
    int64_t result = 0;
    data_434e30(&var_38, arg2, arg4, arg3);
    FPC_VARIANT_COPY(arg1, &var_38);
    FPC_VARIANT_CLEAR(&var_38, FPC_POPADDRSTACK());
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t fpc_vararray_put(int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4)
{
    return data_434e38(arg1, arg2, arg4, arg3);
}

int64_t fpc_variant_to_dynarray(int64_t* arg1, int64_t arg2, void* arg3)
{
    FPC_DYNARRAY_CLEAR(arg1, arg3);
    return data_434d40(arg1, arg2, arg3);
}

int64_t fpc_dynarray_to_variant()
{
    return data_434da8();
}

int64_t fpc_variant_to_interface()
{
    return data_434d30();
}

int64_t fpc_interface_to_variant()
{
    return data_434d98();
}

int64_t fpc_variant_to_idispatch()
{
    return data_434d38();
}

int64_t fpc_idispatch_to_variant()
{
    return data_434da0();
}

int64_t fpc_dispinvoke_variant()
{
    return data_434e20();
}

int64_t SYSTEM_$$_$assign$BYTE$$VARIANT(int64_t arg1, char arg2)
{
    return data_434d50(arg1, arg2, 1);
}

int64_t SYSTEM_$$_$assign$SHORTINT$$VARIANT(int64_t arg1, char arg2)
{
    return data_434d50(arg1, arg2, 0xffffffff);
}

int64_t SYSTEM_$$_$assign$WORD$$VARIANT(int64_t arg1, int16_t arg2)
{
    return data_434d50(arg1, arg2, 2);
}

int64_t SYSTEM_$$_$assign$SMALLINT$$VARIANT(int64_t arg1, int16_t arg2)
{
    return data_434d50(arg1, arg2, 0xfffffffe);
}

int64_t SYSTEM_$$_$assign$LONGWORD$$VARIANT(int64_t arg1, int64_t arg2)
{
    return data_434d50(arg1, arg2, 4);
}

int64_t SYSTEM_$$_$assign$LONGINT$$VARIANT(int64_t arg1, int64_t arg2)
{
    return data_434d50(arg1, arg2, 0xfffffffc);
}

int64_t SYSTEM_$$_$assign$QWORD$$VARIANT()
{
    return data_434d60();
}

int64_t SYSTEM_$$_$assign$INT64$$VARIANT()
{
    return data_434d58();
}

int64_t SYSTEM_$$_$assign$BOOLEAN$$VARIANT()
{
    return data_434d48();
}

int64_t SYSTEM_$$_$assign$WORDBOOL$$VARIANT(int64_t arg1, int16_t arg2)
{
    arg2 = arg2 != 0;
    return data_434d48(arg1, arg2);
}

int64_t SYSTEM_$$_$assign$LONGBOOL$$VARIANT(int64_t arg1, int32_t arg2)
{
    int32_t rsi;
    rsi = arg2 != 0;
    return data_434d48(arg1, rsi);
}

int64_t SYSTEM_$$_$assign$CHAR$$VARIANT(int64_t arg1, char arg2)
{
    int16_t var_108 = ((arg2 << 8) | 1);
    return data_434d80(arg1, &var_108);
}

int64_t SYSTEM_$$_$assign$WIDECHAR$$VARIANT(int64_t arg1, int16_t arg2)
{
    int64_t r12;
    r12 = arg2;
    int64_t var_78 = 0;
    void var_70;
    void var_58;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_58, &var_70), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    fpc_uchar_to_unicodestr(&var_78, r12);
    data_434d90(arg1, var_78);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_78);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_$assign$SHORTSTRING$$VARIANT()
{
    return data_434d80();
}

int64_t SYSTEM_$$_$assign$ANSISTRING$$VARIANT()
{
    return data_434d88();
}

int64_t SYSTEM_$$_$assign$WIDESTRING$$VARIANT()
{
    return data_434d90();
}

int64_t SYSTEM_$$_$assign$UTF8STRING$$VARIANT(int64_t arg1, char* arg2)
{
    int64_t var_18 = 0;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_UTF8DECODE$RAWBYTESTRING$$UNICODESTRING(&var_18, arg2);
    data_434d90(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_$assign$UCS4STRING$$VARIANT(int64_t arg1, void* arg2)
{
    int64_t var_18 = 0;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_UCS4STRINGTOWIDESTRING$UCS4STRING$$WIDESTRING(&var_18, arg2);
    data_434d90(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_$assign$SINGLE$$VARIANT(int64_t arg1, float arg2)
{
    long double var_18 = arg2;
    return data_434d68(arg1);
}

int64_t SYSTEM_$$_$assign$DOUBLE$$VARIANT(int64_t arg1, double arg2)
{
    long double var_18 = arg2;
    return data_434d68(arg1);
}

int64_t SYSTEM_$$_$assign$EXTENDED$$VARIANT(int64_t arg1, int64_t arg2, int16_t arg3)
{
    int64_t var_28 = arg2;
    int64_t rdx;
    rdx = arg3;
    int16_t var_20 = rdx;
    return data_434d68(arg1);
}

int64_t SYSTEM_$$_$assign$COMP$$VARIANT(int64_t arg1, int64_t arg2)
{
    long double var_18 = arg2;
    return data_434d68(arg1);
}

int64_t SYSTEM_$$_$assign$REAL$$VARIANT(int64_t arg1, double arg2)
{
    long double var_18 = arg2;
    return data_434d68(arg1);
}

int64_t SYSTEM_$$_$assign$CURRENCY$$VARIANT(int64_t arg1, int64_t arg2)
{
    return data_434d78(arg1, arg2);
}

int64_t SYSTEM_$$_$assign$TDATETIME$$VARIANT()
{
    return data_434d70();
}

int64_t SYSTEM_$$_$assign$TERROR$$VARIANT(int64_t arg1, int64_t arg2)
{
    return data_434d50(arg1, arg2, 0xfffffffc);
}

uint64_t SYSTEM_$$_$assign$VARIANT$$BYTE()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

uint64_t SYSTEM_$$_$assign$VARIANT$$SHORTINT()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

uint64_t SYSTEM_$$_$assign$VARIANT$$WORD()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

uint64_t SYSTEM_$$_$assign$VARIANT$$SMALLINT()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

int64_t SYSTEM_$$_$assign$VARIANT$$LONGWORD()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

int64_t SYSTEM_$$_$assign$VARIANT$$LONGINT()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

int64_t SYSTEM_$$_$assign$VARIANT$$QWORD()
{
    return data_434cf0();
}

int64_t SYSTEM_$$_$assign$VARIANT$$INT64()
{
    return data_434ce8();
}

int64_t SYSTEM_$$_$assign$VARIANT$$BOOLEAN()
{
    return data_434cf8();
}

uint64_t SYSTEM_$$_$assign$VARIANT$$WORDBOOL()
{
    int16_t rax;
    rax = data_434cf8();
    rax = rax != 0;
    return -((rax & 0xff));
}

uint64_t SYSTEM_$$_$assign$VARIANT$$LONGBOOL()
{
    return -(data_434cf8() != 0);
}

uint64_t SYSTEM_$$_$assign$VARIANT$$CHAR(int64_t arg1)
{
    char var_108;
    char rax = data_434d18(&var_108, arg1);
    char var_107;
    
    if (var_108 > 0)
        rax = var_107;
    return rax;
}

uint64_t SYSTEM_$$_$assign$VARIANT$$WIDECHAR(int64_t arg1)
{
    int64_t rbx = arg1;
    int16_t* var_78 = nullptr;
    void var_70;
    void var_58;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_58, &var_70), rbx, rbp, r12, r13, r14, r15);
    int64_t var_18 = 0;
    data_434d28(&var_78, rbx, 0);
    int16_t* rax_1 = var_78;
    
    if (rax_1 != 0)
        rax_1 = *(rax_1 - 8);
    
    if (rax_1 > 0)
        rbx = *var_78;
    
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_78);
    
    if (var_18 != 0)
        FPC_RERAISE();
    
    return rbx;
}

int64_t SYSTEM_$$_$assign$VARIANT$$SHORTSTRING()
{
    return data_434d18();
}

int64_t SYSTEM_$$_$assign$VARIANT$$ANSISTRING()
{
    return data_434d20();
}

int64_t SYSTEM_$$_$assign$VARIANT$$WIDESTRING()
{
    return data_434d28();
}

int64_t SYSTEM_$$_$assign$VARIANT$$UTF8STRING(int64_t* arg1, int64_t arg2)
{
    uint16_t* var_78 = nullptr;
    void var_70;
    void var_58;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_58, &var_70), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    data_434d28(&var_78, arg2, 0);
    SYSTEM_$$_UTF8ENCODE$UNICODESTRING$$RAWBYTESTRING(arg1, var_78);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_78);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int512_t SYSTEM_$$_$assign$VARIANT$$SINGLE(long double arg1 @ st0)
{
    data_434d00();
    int512_t result;
    result = arg1;
    return result;
}

int512_t SYSTEM_$$_$assign$VARIANT$$DOUBLE(long double arg1 @ st0)
{
    data_434d00();
    int512_t result;
    result = arg1;
    return result;
}

int64_t SYSTEM_$$_$assign$VARIANT$$EXTENDED()
{
    return data_434d00();
}

long double SYSTEM_$$_$assign$VARIANT$$COMP(long double arg1 @ st0)
{
    data_434d00();
    return arg1;
}

int512_t SYSTEM_$$_$assign$VARIANT$$REAL(long double arg1 @ st0)
{
    data_434d00();
    int512_t result;
    result = arg1;
    return result;
}

long double SYSTEM_$$_$assign$VARIANT$$CURRENCY(long double arg1 @ st0)
{
    data_434d10();
    return arg1;
}

int64_t SYSTEM_$$_$assign$VARIANT$$TDATETIME()
{
    return data_434d08();
}

int64_t SYSTEM_$$_$assign$VARIANT$$OLEVARIANT()
{
    return data_434dc0();
}

int64_t SYSTEM_$$_$assign$VARIANT$$TERROR()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

int64_t SYSTEM_$$_$or$VARIANT$VARIANT$$VARIANT(int64_t arg1, int64_t arg2, int64_t arg3)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434dd0(arg1, arg3, 9);
}

int64_t SYSTEM_$$_$and$VARIANT$VARIANT$$VARIANT(int64_t arg1, int64_t arg2, int64_t arg3)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434dd0(arg1, arg3, 8);
}

int64_t SYSTEM_$$_$xor$VARIANT$VARIANT$$VARIANT(int64_t arg1, int64_t arg2, int64_t arg3)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434dd0(arg1, arg3, 0xa);
}

int64_t SYSTEM_$$_$not$VARIANT$$VARIANT(int64_t arg1, int64_t arg2)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434de8(arg1);
}

int64_t SYSTEM_$$_$shl$VARIANT$VARIANT$$VARIANT(int64_t arg1, int64_t arg2, int64_t arg3)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434dd0(arg1, arg3, 6);
}

int64_t SYSTEM_$$_$shr$VARIANT$VARIANT$$VARIANT(int64_t arg1, int64_t arg2, int64_t arg3)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434dd0(arg1, arg3, 7);
}

int64_t SYSTEM_$$_$plus$VARIANT$VARIANT$$VARIANT(int64_t arg1, int64_t arg2, int64_t arg3)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434dd0(arg1, arg3, 0);
}

int64_t SYSTEM_$$_$minus$VARIANT$VARIANT$$VARIANT(int64_t arg1, int64_t arg2, int64_t arg3)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434dd0(arg1, arg3, 1);
}

int64_t SYSTEM_$$_$star$VARIANT$VARIANT$$VARIANT(int64_t arg1, int64_t arg2, int64_t arg3)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434dd0(arg1, arg3, 2);
}

int64_t SYSTEM_$$_$slash$VARIANT$VARIANT$$VARIANT(int64_t arg1, int64_t arg2, int64_t arg3)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434dd0(arg1, arg3, 3);
}

int64_t SYSTEM_$$_$starstar$VARIANT$VARIANT$$VARIANT(int64_t arg1, int64_t arg2, int64_t arg3)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434dd0(arg1, arg3, 0x14);
}

int64_t SYSTEM_$$_$div$VARIANT$VARIANT$$VARIANT(int64_t arg1, int64_t arg2, int64_t arg3)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434dd0(arg1, arg3, 4);
}

int64_t SYSTEM_$$_$mod$VARIANT$VARIANT$$VARIANT(int64_t arg1, int64_t arg2, int64_t arg3)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434dd0(arg1, arg3, 5);
}

int64_t SYSTEM_$$_$minus$VARIANT$$VARIANT(int64_t arg1, int64_t arg2)
{
    FPC_VARIANT_COPY(arg1, arg2);
    return data_434de0(arg1);
}

int64_t SYSTEM_$$_$equal$VARIANT$VARIANT$$BOOLEAN(int64_t arg1, int64_t arg2)
{
    return data_434dd8(arg1, arg2, 0xe);
}

int64_t SYSTEM_$$_$lower$VARIANT$VARIANT$$BOOLEAN(int64_t arg1, int64_t arg2)
{
    return data_434dd8(arg1, arg2, 0x10);
}

int64_t SYSTEM_$$_$greater$VARIANT$VARIANT$$BOOLEAN(int64_t arg1, int64_t arg2)
{
    return data_434dd8(arg1, arg2, 0x12);
}

int64_t SYSTEM_$$_$greater_or_equal$VARIANT$VARIANT$$BOOLEAN(int64_t arg1, int64_t arg2)
{
    return data_434dd8(arg1, arg2, 0x13);
}

int64_t SYSTEM_$$_$lower_or_equal$VARIANT$VARIANT$$BOOLEAN(int64_t arg1, int64_t arg2)
{
    return data_434dd8(arg1, arg2, 0x11);
}

int64_t SYSTEM_$$_VARARRAYREDIM$VARIANT$INT64()
{
    return data_434e28();
}

int64_t SYSTEM_$$_VARARRAYPUT$VARIANT$VARIANT$array_of_LONGINT(int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4)
{
    if ((arg4 + 1) <= 0)
        return data_434e38(arg1, arg2, 0, 0);
    
    return data_434e38(arg1, arg2, (arg4 + 1), arg3);
}

int64_t SYSTEM_$$_VARARRAYGET$VARIANT$array_of_LONGINT$$VARIANT(int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4)
{
    if ((arg4 + 1) <= 0)
        return data_434e30(arg1, arg2, 0, 0);
    
    return data_434e30(arg1, arg2, (arg4 + 1), arg3);
}

int64_t SYSTEM_$$_VARCAST$VARIANT$VARIANT$LONGINT()
{
    return data_434e10();
}

uint64_t SYSTEM_$$_$assign$OLEVARIANT$$BYTE()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

uint64_t SYSTEM_$$_$assign$OLEVARIANT$$SHORTINT()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

uint64_t SYSTEM_$$_$assign$OLEVARIANT$$WORD()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

uint64_t SYSTEM_$$_$assign$OLEVARIANT$$SMALLINT()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

int64_t SYSTEM_$$_$assign$OLEVARIANT$$LONGWORD()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

int64_t SYSTEM_$$_$assign$OLEVARIANT$$LONGINT()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

int64_t SYSTEM_$$_$assign$OLEVARIANT$$QWORD()
{
    return data_434ce8();
}

int64_t SYSTEM_$$_$assign$OLEVARIANT$$INT64()
{
    return data_434cf0();
}

int64_t SYSTEM_$$_$assign$OLEVARIANT$$BOOLEAN()
{
    return data_434cf8();
}

uint64_t SYSTEM_$$_$assign$OLEVARIANT$$WORDBOOL()
{
    int16_t rax;
    rax = data_434cf8();
    rax = rax != 0;
    return -((rax & 0xff));
}

uint64_t SYSTEM_$$_$assign$OLEVARIANT$$LONGBOOL()
{
    return -(data_434cf8() != 0);
}

uint64_t SYSTEM_$$_$assign$OLEVARIANT$$CHAR(int64_t arg1)
{
    char var_108;
    data_434d18(&var_108, arg1);
    char rax;
    char var_107;
    
    if (var_108 <= 0)
        rax = 0;
    else
        rax = var_107;
    return rax;
}

uint64_t SYSTEM_$$_$assign$OLEVARIANT$$WIDECHAR(int64_t arg1)
{
    int16_t* var_78 = nullptr;
    void var_70;
    void var_58;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_58, &var_70), arg1, rbp, r12, r13, r14, r15);
    int64_t var_18 = 0;
    data_434d28(&var_78, arg1, 0);
    int16_t* rax_1 = var_78;
    
    if (rax_1 != 0)
        rax_1 = *(rax_1 - 8);
    
    int64_t rbx;
    
    if (rax_1 <= 0)
        rbx = 0;
    else
        rbx = *var_78;
    
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_78);
    
    if (var_18 != 0)
        FPC_RERAISE();
    
    return rbx;
}

int64_t SYSTEM_$$_$assign$OLEVARIANT$$SHORTSTRING()
{
    return data_434d18();
}

int64_t SYSTEM_$$_$assign$OLEVARIANT$$ANSISTRING()
{
    return data_434d20();
}

int64_t SYSTEM_$$_$assign$OLEVARIANT$$WIDESTRING()
{
    return data_434d28();
}

int512_t SYSTEM_$$_$assign$OLEVARIANT$$SINGLE(long double arg1 @ st0)
{
    data_434d00();
    int512_t result;
    result = arg1;
    return result;
}

int512_t SYSTEM_$$_$assign$OLEVARIANT$$DOUBLE(long double arg1 @ st0)
{
    data_434d00();
    int512_t result;
    result = arg1;
    return result;
}

int64_t SYSTEM_$$_$assign$OLEVARIANT$$EXTENDED()
{
    return data_434d00();
}

long double SYSTEM_$$_$assign$OLEVARIANT$$COMP(long double arg1 @ st0)
{
    data_434d00();
    return arg1;
}

int512_t SYSTEM_$$_$assign$OLEVARIANT$$REAL(long double arg1 @ st0)
{
    data_434d00();
    int512_t result;
    result = arg1;
    return result;
}

long double SYSTEM_$$_$assign$OLEVARIANT$$CURRENCY(long double arg1 @ st0)
{
    data_434d10();
    return arg1;
}

int64_t SYSTEM_$$_$assign$OLEVARIANT$$TDATETIME()
{
    return data_434d08();
}

int64_t SYSTEM_$$_$assign$OLEVARIANT$$TERROR()
{
    return U_$SYSTEM_$$_VARIANTMANAGER();
}

int64_t SYSTEM_$$_$assign$BYTE$$OLEVARIANT(int64_t arg1, char arg2)
{
    return data_434dc8(arg1, arg2, 1);
}

int64_t SYSTEM_$$_$assign$SHORTINT$$OLEVARIANT(int64_t arg1, char arg2)
{
    return data_434dc8(arg1, arg2, 0xffffffff);
}

int64_t SYSTEM_$$_$assign$WORD$$OLEVARIANT(int64_t arg1, int16_t arg2)
{
    return data_434dc8(arg1, arg2, 2);
}

int64_t SYSTEM_$$_$assign$SMALLINT$$OLEVARIANT(int64_t arg1, int16_t arg2)
{
    return data_434dc8(arg1, arg2, 0xfffffffe);
}

int64_t SYSTEM_$$_$assign$LONGWORD$$OLEVARIANT(int64_t arg1, int32_t arg2)
{
    return data_434dc8(arg1, arg2, 4);
}

int64_t SYSTEM_$$_$assign$LONGINT$$OLEVARIANT(int64_t arg1, int32_t arg2)
{
    return data_434dc8(arg1, arg2, 0xfffffffc);
}

int64_t SYSTEM_$$_$assign$QWORD$$OLEVARIANT(int64_t arg1, int64_t arg2)
{
    return data_434dc8(arg1, arg2, 8);
}

int64_t SYSTEM_$$_$assign$INT64$$OLEVARIANT(int64_t arg1, int64_t arg2)
{
    return data_434dc8(arg1, arg2, 0xfffffff8);
}

int64_t SYSTEM_$$_$assign$BOOLEAN$$OLEVARIANT()
{
    return data_434d48();
}

int64_t SYSTEM_$$_$assign$WORDBOOL$$OLEVARIANT(int64_t arg1, int16_t arg2)
{
    arg2 = arg2 != 0;
    return data_434d48(arg1, arg2);
}

int64_t SYSTEM_$$_$assign$LONGBOOL$$OLEVARIANT(int64_t arg1, int32_t arg2)
{
    int32_t rsi;
    rsi = arg2 != 0;
    return data_434d48(arg1, rsi);
}

int64_t SYSTEM_$$_$assign$CHAR$$OLEVARIANT(int64_t arg1, char arg2)
{
    int16_t var_108 = ((arg2 << 8) | 1);
    return data_434db0(arg1, &var_108);
}

int64_t SYSTEM_$$_$assign$WIDECHAR$$OLEVARIANT(int64_t arg1, int16_t arg2)
{
    int64_t r12;
    r12 = arg2;
    int64_t var_18 = 0;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    fpc_uchar_to_unicodestr(&var_18, r12);
    data_434d90(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_$assign$SHORTSTRING$$OLEVARIANT()
{
    return data_434db0();
}

int64_t SYSTEM_$$_$assign$ANSISTRING$$OLEVARIANT()
{
    return data_434db8();
}

int64_t SYSTEM_$$_$assign$WIDESTRING$$OLEVARIANT()
{
    return data_434d90();
}

int64_t SYSTEM_$$_$assign$SINGLE$$OLEVARIANT(int64_t arg1, float arg2)
{
    long double var_18 = arg2;
    return data_434d68(arg1);
}

int64_t SYSTEM_$$_$assign$DOUBLE$$OLEVARIANT(int64_t arg1, double arg2)
{
    long double var_18 = arg2;
    return data_434d68(arg1);
}

int64_t SYSTEM_$$_$assign$EXTENDED$$OLEVARIANT(int64_t arg1, int64_t arg2, int16_t arg3)
{
    int64_t var_28 = arg2;
    int64_t rdx;
    rdx = arg3;
    int16_t var_20 = rdx;
    return data_434d68(arg1);
}

int64_t SYSTEM_$$_$assign$COMP$$OLEVARIANT(int64_t arg1, int64_t arg2)
{
    long double var_18 = arg2;
    return data_434d68(arg1);
}

int64_t SYSTEM_$$_$assign$REAL$$OLEVARIANT(int64_t arg1, double arg2)
{
    long double var_18 = arg2;
    return data_434d68(arg1);
}

int64_t SYSTEM_$$_$assign$CURRENCY$$OLEVARIANT(int64_t arg1, int64_t arg2)
{
    return data_434d78(arg1, arg2);
}

int64_t SYSTEM_$$_$assign$TDATETIME$$OLEVARIANT()
{
    return data_434d70();
}

int64_t SYSTEM_$$_$assign$TERROR$$OLEVARIANT(int64_t arg1, int32_t arg2)
{
    return data_434dc8(arg1, arg2, 0xfffffffc);
}

int64_t SYSTEM_$$_UNASSIGNED$$VARIANT(int16_t* arg1)
{
    int64_t result = TC_$SYSTEM_$$_VARCLEARPROC();
    *arg1 = 0;
    return result;
}

int64_t SYSTEM_$$_NULL$$VARIANT(int16_t* arg1)
{
    int64_t result = TC_$SYSTEM_$$_VARCLEARPROC();
    *arg1 = 1;
    return result;
}

int64_t SYSTEM_$$_GETVARIANTMANAGER$TVARIANTMANAGER()
{
    int64_t rdi;
    __builtin_memcpy(rdi, &U_$SYSTEM_$$_VARIANTMANAGER, 0x2e);
}

int64_t SYSTEM_$$_SETVARIANTMANAGER$TVARIANTMANAGER(int64_t arg1)
{
    __builtin_memcpy(&U_$SYSTEM_$$_VARIANTMANAGER, arg1, 0x2e);
    return arg1;
}

int64_t SYSTEM_$$_POS$CHAR$VARIANT$$INT64(char arg1)
{
    int64_t rbx;
    rbx = arg1;
    void var_108;
    data_434d18(&var_108);
    return SYSTEM_$$_POS$CHAR$SHORTSTRING$INT64$$INT64(rbx, &var_108, 1);
}

int64_t SYSTEM_$$_POS$SHORTSTRING$VARIANT$$INT64(char* arg1, int64_t arg2)
{
    void var_208;
    FPC_SHORTSTR_TO_SHORTSTR(&var_208, 0xff, arg1);
    void var_108;
    data_434d18(&var_108, arg2);
    return SYSTEM_$$_POS$SHORTSTRING$SHORTSTRING$INT64$$INT64(&var_208, &var_108, 1);
}

char* SYSTEM_$$_POS$ANSISTRING$VARIANT$$INT64(char* arg1, int64_t arg2)
{
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t var_20 = 0;
    data_434d20(&var_18, arg2, 0);
    char* result = SYSTEM_$$_POS$RAWBYTESTRING$RAWBYTESTRING$INT64$$INT64(arg1, var_18, 1);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (var_20 != 0)
        FPC_RERAISE();
    
    return result;
}

uint64_t SYSTEM_$$_POS$WIDESTRING$VARIANT$$INT64(uint64_t arg1, int64_t arg2)
{
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t var_20 = 0;
    data_434d28(&var_18, arg2, 0);
    uint64_t result = SYSTEM_$$_POS$UNICODESTRING$UNICODESTRING$INT64$$INT64(arg1, var_18, 1);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (var_20 != 0)
        FPC_RERAISE();
    
    return result;
}

int64_t SYSTEM_$$_POS$VARIANT$CHAR$$INT64(int64_t arg1, char arg2)
{
    int64_t rbx;
    rbx = arg2;
    void var_108;
    data_434d18(&var_108, arg1);
    return SYSTEM_$$_POS$SHORTSTRING$CHAR$INT64$$INT64(&var_108, rbx, 1);
}

int64_t SYSTEM_$$_POS$VARIANT$SHORTSTRING$$INT64(int64_t arg1, char* arg2)
{
    void var_108;
    data_434d18(&var_108, arg1);
    return SYSTEM_$$_POS$SHORTSTRING$SHORTSTRING$INT64$$INT64(&var_108, arg2, 1);
}

int64_t SYSTEM_$$_POS$VARIANT$ANSISTRING$$INT64(int64_t arg1, void* arg2)
{
    char* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t var_20 = 0;
    data_434d20(&var_18, arg1, 0);
    int64_t result = SYSTEM_$$_POS$RAWBYTESTRING$RAWBYTESTRING$INT64$$INT64(var_18, arg2, 1);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (var_20 != 0)
        FPC_RERAISE();
    
    return result;
}

int64_t SYSTEM_$$_POS$VARIANT$WIDESTRING$$INT64(int64_t arg1, void* arg2)
{
    uint64_t var_18 = 0;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t var_20 = 0;
    data_434d28(&var_18, arg1, 0);
    int64_t result = SYSTEM_$$_POS$UNICODESTRING$UNICODESTRING$INT64$$INT64(var_18, arg2, 1);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_18);
    
    if (var_20 != 0)
        FPC_RERAISE();
    
    return result;
}

int64_t SYSTEM_$$_POS$VARIANT$VARIANT$$INT64(int64_t arg1, int64_t arg2)
{
    uint64_t var_20 = 0;
    void* var_28 = nullptr;
    void var_88;
    void var_70;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_70, &var_88), arg1, rbp, arg2, r13, r14, r15);
    int64_t var_30 = 0;
    data_434d28(&var_28, arg2, 0);
    void* r12_1 = var_28;
    data_434d28(&var_20, arg1);
    int64_t result = SYSTEM_$$_POS$UNICODESTRING$UNICODESTRING$INT64$$INT64(var_20, r12_1, 1);
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_20);
    FPC_UNICODESTR_DECR_REF(&var_28);
    
    if (var_30 != 0)
        FPC_RERAISE();
    
    return result;
}

int64_t SYSTEM_$$_RTTIARRAYSIZE$POINTER$$INT64(void* arg1)
{
    return *(*(arg1 + 1) + (arg1 + 2));
}

int64_t SYSTEM_$$_RTTIRECORDSIZE$POINTER$$INT64(void* arg1)
{
    return *((*(arg1 + 1) + (arg1 + 2)) + 8);
}

int64_t* SYSTEM_$$_RTTIRECORDOP$POINTER$POINTER$$PRECORDINFOINIT(void* arg1, int64_t* arg2)
{
    int64_t* result = (*(arg1 + 1) + (arg1 + 2));
    
    if (*result == 0)
        return result;
    
    int64_t rdx = *result;
    *arg2 = rdx;
    return ((rdx + 2) + *(rdx + 1));
}

int64_t SYSTEM_$$_RTTISIZEANDOP$POINTER$TRTTIRECOPTYPE$BOOLEAN$$INT64(char* arg1, char arg2, char* arg3)
{
    int64_t rbx;
    rbx = arg2;
    *arg3 = 0;
    char* rax;
    rax = *arg1;
    
    if (rax >= 9)
    {
        char temp0_1 = rax;
        rax -= 0xa;
        
        if (temp0_1 <= 0xa)
            return 8;
        
        char temp1_1 = rax;
        rax -= 1;
        
        if (temp1_1 == 1)
            return 0x18;
        
        char temp2_1 = rax;
        rax -= 1;
        
        if (temp2_1 == 1)
            return SYSTEM_$$_RTTIARRAYSIZE$POINTER$$INT64(arg1);
        
        char temp3_1 = rax;
        rax -= 1;
        
        if (temp3_1 == 1)
        {
            int64_t* rdx_1 = &arg1[(2 + arg1[1])];
            
            if (*rdx_1 != 0)
            {
                void* rax_4 = *rdx_1;
                rdx_1 = (*(rax_4 + 1) + (rax_4 + 2));
            }
            
            int64_t result = rdx_1[1];
            *arg3 = *(rdx_1 + 0x14) != 0;
            
            if ((*arg3 != 0 && rbx >= 1))
            {
                char temp7_1 = rbx;
                rbx -= 1;
                
                if (temp7_1 == 1)
                    *arg3 = **(rdx_1 + 0x14) != 0;
                else
                {
                    char temp9_1 = rbx;
                    rbx -= 1;
                    
                    if (temp9_1 == 1)
                        *arg3 = *(*(rdx_1 + 0x14) + 8) != 0;
                    else
                    {
                        char temp10_1 = rbx;
                        rbx -= 1;
                        
                        if (temp10_1 == 1)
                            *arg3 = *(*(rdx_1 + 0x14) + 0x10) != 0;
                        else
                        {
                            char temp11_1 = rbx;
                            rbx -= 1;
                            
                            if (temp11_1 == 1)
                                *arg3 = *(*(rdx_1 + 0x14) + 0x18) != 0;
                        }
                    }
                }
            }
            
            return result;
        }
        
        char temp4_1 = rax;
        rax -= 1;
        
        if (temp4_1 == 1)
            return 8;
        
        char temp5_1 = rax;
        rax -= 2;
        
        if (temp5_1 == 2)
            return SYSTEM_$$_RTTIRECORDSIZE$POINTER$$INT64(arg1);
        
        char temp6_1 = rax;
        rax -= 5;
        
        if (temp6_1 == 5)
            return 8;
        
        char temp8_1 = rax;
        rax -= 3;
        
        if (temp8_1 == 3)
            return 8;
    }
    
    return -1;
}

int64_t SYSTEM_$$_RECORDRTTI$POINTER$POINTER$TRTTIPROC(int64_t arg1, void* arg2, int64_t arg3)
{
    void* rbx = ((arg2 + 2) + *(arg2 + 1));
    int32_t result = *(rbx + 0x1c);
    void* rbx_1 = (rbx + 0x20);
    int32_t result_1 = result;
    
    if (result_1 >= 1)
    {
        int32_t r13_1 = 0;
        
        do
        {
            r13_1 += 1;
            result = arg3((*(rbx_1 + 8) + arg1), **rbx_1);
            rbx_1 += 0x10;
        } while (result_1 > r13_1);
    }
    
    return result;
}

int64_t SYSTEM_$$_RTTIRECORDMOPINITTABLE$POINTER$$PRTTIRECORDOPOFFSETTABLE(void* arg1)
{
    return *((*(arg1 + 1) + (arg1 + 2)) + 0xc);
}

uint64_t SYSTEM_$$_ARRAYRTTI$POINTER$POINTER$TRTTIPROC(int64_t arg1, void* arg2, int64_t arg3)
{
    uint64_t result = *(arg2 + 1);
    int64_t* rsi = ((arg2 + 2) + result);
    int64_t rcx = rsi[1];
    
    if (rcx != 0)
    {
        int64_t rax_1;
        int64_t rdx_1;
        rdx_1 = HIGHQ(*rsi);
        rax_1 = LOWQ(*rsi);
        result = rsi[2];
        int64_t r13_1 = *result;
        
        if ((rcx - 1) >= 0)
        {
            int64_t i = -1;
            
            do
            {
                i += 1;
                result = arg3((((COMBINE(rdx_1, rax_1) / rcx) * i) + arg1), r13_1);
            } while ((rcx - 1) > i);
        }
    }
    
    return result;
}

uint64_t FPC_INITIALIZE(int64_t* arg1, char* arg2)
{
    char* var_18 = arg2;
    uint64_t result;
    result = *arg2;
    
    if (result >= 9)
    {
        char temp0_1 = result;
        result -= 0xa;
        
        if (temp0_1 <= 0xa)
            *arg1 = 0;
        else
        {
            char temp1_1 = result;
            result -= 1;
            
            if (temp1_1 == 1)
                return FPC_VARIANT_INIT(arg1);
            
            char temp2_1 = result;
            result -= 1;
            
            if (temp2_1 == 1)
                return SYSTEM_$$_ARRAYRTTI$POINTER$POINTER$TRTTIPROC(arg1, var_18, FPC_INITIALIZE);
            
            char temp3_1 = result;
            result -= 1;
            
            if (temp3_1 == 1)
            {
            label_417161:
                void* r12_2 = &var_18[(2 + var_18[1])];
                
                if (*r12_2 != 0)
                {
                    char* rax_1 = *r12_2;
                    var_18 = rax_1;
                    r12_2 = &var_18[(2 + rax_1[1])];
                }
                
                SYSTEM_$$_RECORDRTTI$POINTER$POINTER$TRTTIPROC(arg1, var_18, FPC_INITIALIZE);
                result = *(r12_2 + 0x14);
                
                if ((result != 0 && *result != 0))
                    return **(r12_2 + 0x14)(arg1);
            }
            else
            {
                char temp4_1 = result;
                result -= 1;
                
                if (temp4_1 == 1)
                    *arg1 = 0;
                else
                {
                    char temp5_1 = result;
                    result -= 2;
                    
                    if (temp5_1 == 2)
                        goto label_417161;
                    
                    char temp6_1 = result;
                    result -= 5;
                    
                    if (temp6_1 == 5)
                        *arg1 = 0;
                    else
                    {
                        char temp7_1 = result;
                        result -= 3;
                        
                        if (temp7_1 == 3)
                            *arg1 = 0;
                    }
                }
            }
        }
    }
    
    return result;
}

int64_t FPC_FINALIZE(int64_t* arg1, char* arg2)
{
    char* var_18 = arg2;
    char result = *arg2;
    
    if (result >= 9)
    {
        switch (result)
        {
            case 9:
            {
                return FPC_ANSISTR_DECR_REF(arg1);
                break;
            }
            case 0xb:
            {
                return FPC_VARIANT_CLEAR(arg1, arg2);
                break;
            }
            case 0xc:
            {
                return SYSTEM_$$_ARRAYRTTI$POINTER$POINTER$TRTTIPROC(arg1, var_18, FPC_FINALIZE);
                break;
            }
            case 0xd:
            {
            label_417256:
                void* rdx_2 = &var_18[(2 + var_18[1])];
                
                if (*rdx_2 != 0)
                {
                    char* rax_1 = *rdx_2;
                    var_18 = rax_1;
                    rdx_2 = &var_18[(2 + rax_1[1])];
                }
                
                void* rax_4 = *(rdx_2 + 0x14);
                
                if ((rax_4 != 0 && *(rax_4 + 8) != 0))
                    *(*(rdx_2 + 0x14) + 8)(arg1);
                
                return SYSTEM_$$_RECORDRTTI$POINTER$POINTER$TRTTIPROC(arg1, var_18, FPC_FINALIZE);
                break;
            }
            case 0xe:
            {
                return FPC_INTF_DECR_REF(arg1);
                break;
            }
            case 0x10:
            {
                goto label_417256;
            }
            case 0x15:
            {
                return FPC_DYNARRAY_CLEAR(arg1, var_18);
                break;
            }
        }
        
        char temp7_1 = (result - 0x15);
        result -= 0x18;
        
        if (temp7_1 == 3)
            return FPC_UNICODESTR_DECR_REF(arg1);
    }
    
    return result;
}

uint64_t FPC_ADDREF(int64_t* arg1, char* arg2)
{
    char* var_18 = arg2;
    uint64_t result;
    result = *arg2;
    
    if (result >= 9)
    {
        char temp0_1 = result;
        result -= 9;
        
        if (temp0_1 == 9)
            return FPC_ANSISTR_INCR_REF(*arg1);
        
        char temp1_1 = result;
        result -= 2;
        
        if (temp1_1 == 2)
            return FPC_VARIANT_ADDREF(arg1, arg2);
        
        char temp2_1 = result;
        result -= 1;
        
        if (temp2_1 == 1)
            return SYSTEM_$$_ARRAYRTTI$POINTER$POINTER$TRTTIPROC(arg1, var_18, FPC_ADDREF);
        
        char temp3_1 = result;
        result -= 1;
        
        if (temp3_1 == 1)
        {
        label_41735b:
            void* r12_2 = &var_18[(2 + var_18[1])];
            
            if (*r12_2 != 0)
            {
                char* rax_1 = *r12_2;
                var_18 = rax_1;
                r12_2 = &var_18[(2 + rax_1[1])];
            }
            
            SYSTEM_$$_RECORDRTTI$POINTER$POINTER$TRTTIPROC(arg1, var_18, FPC_ADDREF);
            result = *(r12_2 + 0x14);
            
            if ((result != 0 && *(result + 0x10) != 0))
                return *(*(r12_2 + 0x14) + 0x10)(arg1);
        }
        else
        {
            char temp4_1 = result;
            result -= 1;
            
            if (temp4_1 == 1)
                return FPC_INTF_INCR_REF(*arg1);
            
            char temp5_1 = result;
            result -= 2;
            
            if (temp5_1 == 2)
                goto label_41735b;
            
            char temp6_1 = result;
            result -= 5;
            
            if (temp6_1 == 5)
                return FPC_DYNARRAY_INCR_REF(*arg1);
            
            char temp7_1 = result;
            result -= 3;
            
            if (temp7_1 == 3)
                return FPC_UNICODESTR_INCR_REF(*arg1);
        }
    }
    
    return result;
}

int64_t FPC_COPY(void** arg1, void** arg2, char* arg3)
{
    char* var_58 = arg3;
    int64_t result = 8;
    char* rax;
    rax = *var_58;
    
    if (rax >= 9)
    {
        char temp2_1 = rax;
        rax -= 9;
        
        if (temp2_1 == 9)
            FPC_ANSISTR_ASSIGN(arg2, *arg1);
        else
        {
            char temp3_1 = rax;
            rax -= 2;
            
            if (temp3_1 == 2)
            {
                TC_$SYSTEM_$$_VARCOPYPROC(arg2, arg1);
                return 0x18;
            }
            
            char temp4_1 = rax;
            rax -= 1;
            
            if (temp4_1 == 1)
            {
                int64_t* rax_5 = &var_58[(2 + var_58[1])];
                result = *rax_5;
                int64_t rcx_1 = rax_5[1];
                
                if (rcx_1 != 0)
                {
                    int64_t rax_9 = *rax_5[2];
                    int64_t r14_1 = 0;
                    
                    if (rcx_1 >= 1)
                    {
                        int64_t r13_1 = 0;
                        
                        do
                        {
                            r13_1 += 1;
                            FPC_COPY((arg1 + r14_1), (arg2 + r14_1), rax_9);
                            r14_1 += (result / rcx_1);
                        } while (rcx_1 > r13_1);
                    }
                }
            }
            else
            {
                char temp5_1 = rax;
                rax -= 1;
                
                if (temp5_1 == 1)
                {
                label_417519:
                    void* rcx_3 = &var_58[(2 + var_58[1])];
                    
                    if (*rcx_3 != 0)
                    {
                        char* rax_16 = *rcx_3;
                        var_58 = rax_16;
                        rcx_3 = &var_58[(2 + rax_16[1])];
                    }
                    
                    void* rax_21 = &var_58[(2 + var_58[1])];
                    void* rax_22 = *(rcx_3 + 0x14);
                    
                    if ((rax_22 != 0 && *(rax_22 + 0x18) != 0))
                    {
                        *(*(rcx_3 + 0x14) + 0x18)(arg1, arg2);
                        return *(rax_21 + 8);
                    }
                    
                    result = *(rcx_3 + 8);
                    void* var_38_3 = (rax_21 + 0x20);
                    int64_t r12_1 = 0;
                    int64_t rax_26 = *(rcx_3 + 0x1c);
                    
                    if (rax_26 >= 1)
                    {
                        int64_t r13_2 = 0;
                        
                        do
                        {
                            r13_2 += 1;
                            int64_t rax_28 = **var_38_3;
                            int64_t r14_2 = *(var_38_3 + 8);
                            var_38_3 += 0x10;
                            
                            if (r12_1 < r14_2)
                                FPC_MOVE((arg1 + r12_1), (arg2 + r12_1), (r14_2 - r12_1));
                            
                            r12_1 = (r14_2 + FPC_COPY((arg1 + r14_2), (arg2 + r14_2), rax_28));
                        } while (rax_26 > r13_2);
                    }
                    
                    if (r12_1 < result)
                        FPC_MOVE((arg1 + r12_1), (arg2 + r12_1), (result - r12_1));
                }
                else
                {
                    char temp6_1 = rax;
                    rax -= 1;
                    
                    if (temp6_1 == 1)
                        FPC_INTF_ASSIGN(arg2, *arg1);
                    else
                    {
                        char temp7_1 = rax;
                        rax -= 2;
                        
                        if (temp7_1 == 2)
                            goto label_417519;
                        
                        char temp8_1 = rax;
                        rax -= 5;
                        
                        if (temp8_1 == 5)
                            FPC_DYNARRAY_ASSIGN(arg2, *arg1, var_58);
                        else
                        {
                            char temp9_1 = rax;
                            rax -= 3;
                            
                            if (temp9_1 == 3)
                                FPC_UNICODESTR_ASSIGN(arg2, *arg1);
                        }
                    }
                }
            }
        }
    }
    
    return result;
}

int64_t fpc_copy_proc(void** arg1, void** arg2, char* arg3)
{
    return FPC_COPY(arg1, arg2, arg3);
}

int64_t FPC_INITIALIZE_ARRAY(int64_t arg1, char* arg2, int64_t arg3)
{
    char var_38;
    int64_t result = SYSTEM_$$_RTTISIZEANDOP$POINTER$TRTTIRECOPTYPE$BOOLEAN$$INT64(arg2, 1, &var_38);
    int64_t result_1 = result;
    
    if (((result_1 > 0 || var_38 != 0) && (arg3 - 1) >= 0))
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            result = FPC_INITIALIZE(((i * result_1) + arg1), arg2);
        } while ((arg3 - 1) > i);
    }
    
    return result;
}

int64_t FPC_FINALIZE_ARRAY(int64_t arg1, char* arg2, int64_t arg3)
{
    char var_38;
    int64_t result = SYSTEM_$$_RTTISIZEANDOP$POINTER$TRTTIRECOPTYPE$BOOLEAN$$INT64(arg2, 2, &var_38);
    int64_t result_1 = result;
    
    if (((result_1 > 0 || var_38 != 0) && (arg3 - 1) >= 0))
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            result = FPC_FINALIZE(((i * result_1) + arg1), arg2);
        } while ((arg3 - 1) > i);
    }
    
    return result;
}

int64_t FPC_ADDREF_ARRAY(int64_t arg1, char* arg2, int64_t arg3)
{
    char var_38;
    int64_t result = SYSTEM_$$_RTTISIZEANDOP$POINTER$TRTTIRECOPTYPE$BOOLEAN$$INT64(arg2, 3, &var_38);
    int64_t result_1 = result;
    
    if (((result_1 > 0 || var_38 != 0) && (arg3 - 1) >= 0))
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            result = FPC_ADDREF(((i * result_1) + arg1), arg2);
        } while ((arg3 - 1) > i);
    }
    
    return result;
}

int64_t FPC_DECREF(int64_t* arg1, char* arg2)
{
    return FPC_FINALIZE(arg1, arg2);
}

int64_t FPC_DECREF_ARRAY(int64_t arg1, char* arg2, int64_t arg3)
{
    return FPC_FINALIZE_ARRAY(arg1, arg2, arg3);
}

int64_t SYSTEM_$$_INITIALIZEARRAY$POINTER$POINTER$INT64(int64_t arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return FPC_INITIALIZE_ARRAY(arg1, arg2, arg3);
}

int64_t SYSTEM_$$_FINALIZEARRAY$POINTER$POINTER$INT64(int64_t arg1, char* arg2, int64_t arg3)
{
    /* tailcall */
    return FPC_FINALIZE_ARRAY(arg1, arg2, arg3);
}

int64_t SYSTEM_$$_COPYARRAY$POINTER$POINTER$POINTER$INT64(int64_t arg1, int64_t arg2, char* arg3, int64_t arg4)
{
    char var_38;
    int64_t result = SYSTEM_$$_RTTISIZEANDOP$POINTER$TRTTIRECOPTYPE$BOOLEAN$$INT64(arg3, 4, &var_38);
    int64_t result_1 = result;
    
    if (((result_1 > 0 || var_38 != 0) && (arg4 - 1) >= 0))
    {
        int64_t i = -1;
        
        do
        {
            i += 1;
            result = FPC_COPY(((i * result_1) + arg2), ((i * result_1) + arg1), arg3);
        } while ((arg4 - 1) > i);
    }
    
    return result;
}

uint64_t SYSTEM_$$_MTWIST_MIXBITS$LONGWORD$LONGWORD$$LONGWORD(int32_t arg1, int32_t arg2) __pure
{
    return ((arg1 & 0x80000000) | (arg2 & 0x7fffffff));
}

uint64_t SYSTEM_$$_MTWIST_TWIST$LONGWORD$LONGWORD$$LONGWORD(int32_t arg1, int32_t arg2) __pure
{
    return ((-((arg2 & 1)) & 0x9908b0df) ^ (((arg1 & 0x80000000) | (arg2 & 0x7fffffff)) >> 1));
}

int64_t SYSTEM_$$_MTWIST_INIT$LONGWORD(int32_t arg1)
{
    U_$SYSTEM_$$_MT_STATE = arg1;
    int32_t i;
    
    for (i = 0; i < 0x26f; )
    {
        i += 1;
        int32_t rsi_1 = *((i << 2) + &*(data_434e48 + 4));
        &U_$SYSTEM_$$_MT_STATE[i] = (i + (((rsi_1 >> 0x1e) ^ rsi_1) * 0x6c078965));
    }
    
    TC_$SYSTEM_$$_MT_INDEX = 0x270;
    return i;
}

int64_t SYSTEM_$$_MTWIST_UPDATE_STATE()
{
    for (int32_t i = -1; i < 0xe2; )
    {
        i += 1;
        int32_t rcx_1 = *((i << 2) + 0x434e54);
        &U_$SYSTEM_$$_MT_STATE[i] = (((-((rcx_1 & 1)) & 0x9908b0df) ^ (((&U_$SYSTEM_$$_MT_STATE[i] & 0x80000000) | (rcx_1 & 0x7fffffff)) >> 1)) ^ *((i << 2) + 0x435484));
    }
    
    for (int32_t i_1 = 0xe2; i_1 < 0x26e; )
    {
        i_1 += 1;
        int32_t rcx_5 = *((i_1 << 2) + 0x434e54);
        &U_$SYSTEM_$$_MT_STATE[i_1] = (((-((rcx_5 & 1)) & 0x9908b0df) ^ (((&U_$SYSTEM_$$_MT_STATE[i_1] & 0x80000000) | (rcx_5 & 0x7fffffff)) >> 1)) ^ *((i_1 << 2) + 0x434ac4));
    }
    
    int32_t U_$SYSTEM_$$_MT_STATE_1 = U_$SYSTEM_$$_MT_STATE;
    int32_t result = (((-((U_$SYSTEM_$$_MT_STATE_1 & 1)) & 0x9908b0df) ^ (((data_43580c & 0x80000000) | (U_$SYSTEM_$$_MT_STATE_1 & 0x7fffffff)) >> 1)) ^ data_435480);
    data_43580c = result;
    TC_$SYSTEM_$$_MT_INDEX = 0;
    return result;
}

uint64_t SYSTEM_$$_MTWIST_U32RAND$$LONGWORD()
{
    uint32_t TC_$SYSTEM_$$_MT_INDEX_1 = TC_$SYSTEM_$$_MT_INDEX;
    TC_$SYSTEM_$$_MT_INDEX += 1;
    
    if ((U_$SYSTEM_$$_RANDSEED != TC_$SYSTEM_$$_OLDRANDSEED || TC_$SYSTEM_$$_MT_INDEX_1 >= 0x271))
    {
        SYSTEM_$$_MTWIST_INIT$LONGWORD(U_$SYSTEM_$$_RANDSEED);
        U_$SYSTEM_$$_RANDSEED = !(U_$SYSTEM_$$_RANDSEED);
        TC_$SYSTEM_$$_OLDRANDSEED = U_$SYSTEM_$$_RANDSEED;
        TC_$SYSTEM_$$_MT_INDEX_1 = 0x270;
    }
    
    if (TC_$SYSTEM_$$_MT_INDEX_1 == 0x270)
    {
        SYSTEM_$$_MTWIST_UPDATE_STATE();
        TC_$SYSTEM_$$_MT_INDEX_1 = 0;
        TC_$SYSTEM_$$_MT_INDEX = 1;
    }
    
    int32_t rdx = &U_$SYSTEM_$$_MT_STATE[TC_$SYSTEM_$$_MT_INDEX_1];
    int32_t rax_6 = ((rdx >> 0xb) ^ rdx);
    int32_t rdx_4 = (((rax_6 << 7) & 0x9d2c5680) ^ rax_6);
    int32_t rcx_3 = (((rdx_4 << 0xf) & 0xefc60000) ^ rdx_4);
    return ((rcx_3 >> 0x12) ^ rcx_3);
}

uint64_t SYSTEM_$$_RANDOM$LONGINT$$LONGINT(int32_t arg1)
{
    int32_t rbx = arg1;
    
    if (rbx < 0)
        rbx += 1;
    
    return ((SYSTEM_$$_MTWIST_U32RAND$$LONGWORD() * rbx) >> 0x20);
}

int64_t SYSTEM_$$_RANDOM$INT64$$INT64(int64_t arg1)
{
    uint64_t r12 = SYSTEM_$$_MTWIST_U32RAND$$LONGWORD();
    int64_t rcx_3 = (((SYSTEM_$$_MTWIST_U32RAND$$LONGWORD() << 0x20) & 0x7fffffffffffffff) | r12);
    
    if (arg1 == 0)
        return 0;
    
    return (rcx_3 % arg1);
}

long double SYSTEM_$$_RANDOM$$EXTENDED()
{
    int32_t rax = SYSTEM_$$_MTWIST_U32RAND$$LONGWORD();
    int32_t var_18 = rax;
    int32_t var_c = 0;
    return (rax * _$SYSTEM$_Ld34);
}

int64_t SYSTEM_$$_PTR$LONGINT$LONGINT$$POINTER(int32_t arg1, int32_t arg2) __pure
{
    return ((arg1 << 4) + arg2);
}

uint64_t SYSTEM_$$_CSEG$$WORD() __pure
{
    return 0;
}

uint64_t SYSTEM_$$_DSEG$$WORD() __pure
{
    return 0;
}

uint64_t SYSTEM_$$_SSEG$$WORD() __pure
{
    return 0;
}

int64_t SYSTEM_$$_STACKTOP$$POINTER()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rbx;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rbx = &data_434a88;
    else
        rbx = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_STACKBOTTOM);
    
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int64_t* rax_2;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        rax_2 = &data_434a98;
    else
        rax_2 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_STACKLENGTH);
    
    return (*rax_2 + *rbx);
}

int64_t SYSTEM_$$_GET_CALLER_STACKINFO$POINTER$POINTER(int64_t* arg1, int64_t* arg2)
{
    int64_t result = *arg1;
    
    if (*arg1 != 0)
        result = **arg1;
    
    int64_t rdx_2 = *arg1;
    
    if (*arg1 != 0)
        rdx_2 = *(*arg1 + 8);
    
    *arg1 = result;
    *arg2 = rdx_2;
    return result;
}

int64_t fpc_objecterror()
{
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xd2, &data_417cd9, &__saved_rbp);
}

int64_t FPC_RANGEERROR()
{
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xc9, &data_417cf9, &__saved_rbp);
}

int64_t FPC_DIVBYZERO()
{
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xc8, &data_417d19, &__saved_rbp);
}

int64_t FPC_OVERFLOW()
{
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xd7, &data_417d39, &__saved_rbp);
}

int64_t FPC_THREADERROR()
{
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xec, &data_417d59, &__saved_rbp);
}

int64_t FPC_INVALIDPOINTER()
{
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xd8, &data_417d79, &__saved_rbp);
}

int16_t* FPC_IOCHECK()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    int64_t rsi;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, rsi, &U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
        return result;
    
    uint32_t rdx_1 = *result;
    *result = 0;
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(rdx_1, &data_417dda, &__saved_rbp);
}

uint64_t SYSTEM_$$_IORESULT$$WORD()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    uint64_t rdx;
    int64_t rsi;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rdx = &data_434a78;
    else
        rdx = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, rsi, &U_$SYSTEM_$$_INOUTRES);
    FPC_THREADVAR_RELOCATE_1 = *rdx;
    *rdx = 0;
    return (FPC_THREADVAR_RELOCATE_1 & 0xffff);
}

int64_t SYSTEM_$$_GETTHREADID$$QWORD()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax;
    int64_t rsi;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_4338e8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_THREADID, rsi, &U_$SYSTEM_$$_THREADID);
    return *rax;
}

uint64_t FPC_SAFECALLCHECK(int32_t arg1)
{
    if (arg1 < 0)
    {
        int64_t __saved_rbp;
        
        if (TC_$SYSTEM_$$_SAFECALLERRORPROC != 0)
            TC_$SYSTEM_$$_SAFECALLERRORPROC(arg1, &__saved_rbp);
        
        SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xe5, &data_417eb3, &__saved_rbp);
    }
    
    return arg1;
}

void FPC_STACKCHECK()
{
    if (TC_$SYSTEM_$$_STACKERROR == 0)
    {
        int64_t rbx_2 = (SYSTEM_$$_SPTR$$POINTER() - 0x4000);
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int64_t* rax;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax = &data_434a88;
        else
            rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_STACKBOTTOM);
        
        if (rbx_2 <= *rax)
        {
            TC_$SYSTEM_$$_STACKERROR = 1;
            FPC_HANDLEERROR(0xca);
        }
    }
}

int64_t FPC_INITIALIZEUNITS()
{
    int64_t result = SYSTEM_$$_FPC_CPUINIT();
    int64_t* U_$SYSTEM_$$_ENTRYINFORMATION_1 = U_$SYSTEM_$$_ENTRYINFORMATION;
    int64_t r13 = *U_$SYSTEM_$$_ENTRYINFORMATION_1;
    
    if (r13 >= 1)
    {
        int64_t r12_1 = 0;
        
        do
        {
            r12_1 += 1;
            result = (r12_1 << 4);
            
            if (*(U_$SYSTEM_$$_ENTRYINFORMATION_1 + result) != 0)
                result = U_$SYSTEM_$$_ENTRYINFORMATION_1[(r12_1 * 2)]();
            
            U_$SYSTEM_$$_ENTRYINFORMATION_1[1] = r12_1;
        } while (r13 > r12_1);
    }
    
    if (TC_$SYSTEM_$$_INITPROC == 0)
        return result;
    
    return TC_$SYSTEM_$$_INITPROC();
}

int64_t FPC_LIBINITIALIZEUNITS()
{
    operatingsystem_islibrary = 1;
    TC_$SYSTEM_$$_MODULEISLIB = 1;
    return FPC_INITIALIZEUNITS();
}

void FPC_FINALIZEUNITS()
{
    void* U_$SYSTEM_$$_ENTRYINFORMATION_1 = U_$SYSTEM_$$_ENTRYINFORMATION;
    
    while (*(U_$SYSTEM_$$_ENTRYINFORMATION_1 + 8) > 0)
    {
        *(U_$SYSTEM_$$_ENTRYINFORMATION_1 + 8) -= 1;
        
        if (*((U_$SYSTEM_$$_ENTRYINFORMATION_1 + (*(U_$SYSTEM_$$_ENTRYINFORMATION_1 + 8) << 4)) + 0x18) != 0)
            *((U_$SYSTEM_$$_ENTRYINFORMATION_1 + (*(U_$SYSTEM_$$_ENTRYINFORMATION_1 + 8) << 4)) + 0x18)();
    }
}

int16_t* SYSTEM_$$_SYSFLUSHSTDIO()
{
    uint64_t FPC_THREADVAR_RELOCATE_6 = FPC_THREADVAR_RELOCATE;
    void* rax;
    
    if (FPC_THREADVAR_RELOCATE_6 == 0)
        rax = &data_433c78;
    else
        rax = FPC_THREADVAR_RELOCATE_6(U_$SYSTEM_$$_OUTPUT);
    
    if (*(rax + 4) == 0xd7b2)
    {
        uint64_t FPC_THREADVAR_RELOCATE_7 = FPC_THREADVAR_RELOCATE;
        void* rdi_3;
        
        if (FPC_THREADVAR_RELOCATE_7 == 0)
            rdi_3 = &data_433c78;
        else
            rdi_3 = FPC_THREADVAR_RELOCATE_7(U_$SYSTEM_$$_OUTPUT);
        
        SYSTEM_$$_FLUSH$TEXT(rdi_3);
    }
    
    uint64_t FPC_THREADVAR_RELOCATE_8 = FPC_THREADVAR_RELOCATE;
    void* rax_2;
    
    if (FPC_THREADVAR_RELOCATE_8 == 0)
        rax_2 = &data_4338f8;
    else
        rax_2 = FPC_THREADVAR_RELOCATE_8(U_$SYSTEM_$$_ERROUTPUT);
    
    if (*(rax_2 + 4) == 0xd7b2)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        void* rdi_6;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rdi_6 = &data_4338f8;
        else
            rdi_6 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_ERROUTPUT);
        
        SYSTEM_$$_FLUSH$TEXT(rdi_6);
    }
    
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    void* rax_4;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        rax_4 = &data_434378;
    else
        rax_4 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_STDOUT);
    
    if (*(rax_4 + 4) == 0xd7b2)
    {
        uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
        void* rdi_9;
        
        if (FPC_THREADVAR_RELOCATE_3 == 0)
            rdi_9 = &data_434378;
        else
            rdi_9 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_STDOUT);
        
        SYSTEM_$$_FLUSH$TEXT(rdi_9);
    }
    
    uint64_t FPC_THREADVAR_RELOCATE_4 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_4 == 0)
        result = &data_4346f8;
    else
        result = FPC_THREADVAR_RELOCATE_4(U_$SYSTEM_$$_STDERR);
    
    if (*(result + 4) != 0xd7b2)
        return result;
    
    uint64_t FPC_THREADVAR_RELOCATE_5 = FPC_THREADVAR_RELOCATE;
    void* rdi_12;
    
    if (FPC_THREADVAR_RELOCATE_5 == 0)
        rdi_12 = &data_4346f8;
    else
        rdi_12 = FPC_THREADVAR_RELOCATE_5(U_$SYSTEM_$$_STDERR);
    
    return SYSTEM_$$_FLUSH$TEXT(rdi_12);
}

uint16_t* SYSTEM_$$_INTERNALEXIT()
{
    while (TC_$SYSTEM_$$_EXITPROC != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_1 = &data_434a78;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *rax_1 = 0;
        uint64_t TC_$SYSTEM_$$_EXITPROC_1 = TC_$SYSTEM_$$_EXITPROC;
        TC_$SYSTEM_$$_EXITPROC = 0;
        TC_$SYSTEM_$$_EXITPROC_1();
    }
    
    int32_t* rbx_1;
    
    if (TC_$SYSTEM_$$_WRITEERRORSTOSTDERR == 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
        int32_t* rax_4;
        
        if (FPC_THREADVAR_RELOCATE_3 == 0)
            rax_4 = &data_434378;
        else
            rax_4 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_STDOUT);
        
        rbx_1 = rax_4;
    }
    else
    {
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            rbx_1 = &data_4346f8;
        else
            rbx_1 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_STDERR);
    }
    
    if (TC_$SYSTEM_$$_ERRORADDR != 0)
    {
        FPC_WRITE_TEXT_SHORTSTR(0, rbx_1, &_$SYSTEM$_Ld35);
        fpc_write_text_uint(0, rbx_1, TC_$SYSTEM_$$_ERRORCODE);
        FPC_WRITE_TEXT_SHORTSTR(0, rbx_1, &_$SYSTEM$_Ld36);
        void var_118;
        SYSTEM_$$_HEXSTR$POINTER$$SHORTSTRING(&var_118, TC_$SYSTEM_$$_ERRORADDR);
        FPC_WRITE_TEXT_SHORTSTR(0, rbx_1, &var_118);
        fpc_writeln_end(rbx_1);
        TC_$SYSTEM_$$_BACKTRACESTRFUNC(&var_118, TC_$SYSTEM_$$_ERRORADDR);
        FPC_WRITE_TEXT_SHORTSTR(0, rbx_1, &var_118);
        fpc_writeln_end(rbx_1);
        SYSTEM_$$_DUMP_STACK$TEXT$POINTER$POINTER(rbx_1, FPC_ERRORBASE, TC_$SYSTEM_$$_ERRORADDR);
        FPC_WRITE_TEXT_SHORTSTR(0, rbx_1, &_$SYSTEM$_Ld2);
        fpc_writeln_end(rbx_1);
    }
    
    SYSTEM_$$_SYSFLUSHSTDIO();
    FPC_FINALIZEUNITS();
    uint16_t TC_$SYSTEM_$$_ERRORCODE_1 = TC_$SYSTEM_$$_ERRORCODE;
    
    if ((TC_$SYSTEM_$$_ERRORCODE_1 != 0xcb && TC_$SYSTEM_$$_ERRORCODE_1 != 0xcc))
        SYSTEM_$$_SYSFREEMEM$POINTER$$QWORD(TC_$SYSTEM_$$_CALCULATED_CMDLINE);
    
    return SYSTEM_$$_FINALIZEHEAP();
}

int64_t FPC_DO_EXIT()
{
    SYSTEM_$$_INTERNALEXIT();
    return SYSTEM_$$_SYSTEM_EXIT();
}

uint16_t* FPC_LIB_EXIT()
{
    return SYSTEM_$$_INTERNALEXIT();
}

int64_t SYSTEM_$$_HALT$LONGINT(uint32_t arg1)
{
    if (arg1 <= 0xff)
        operatingsystem_result = arg1;
    else
        operatingsystem_result = 0xff;
    
    return FPC_DO_EXIT();
}

int64_t SYSTEM_$$_SYSBACKTRACESTR$POINTER$$SHORTSTRING(char* arg1, uint64_t arg2)
{
    void var_108;
    SYSTEM_$$_HEXSTR$POINTER$$SHORTSTRING(&var_108, arg2);
    return fpc_shortstr_concat(arg1, 0xff, &_$SYSTEM$_Ld37, &var_108);
}

int64_t SYSTEM_$$_CAPTUREBACKTRACE$INT64$INT64$PCODEPOINTER$$INT64(int64_t arg1, int64_t arg2, int64_t arg3)
{
    int64_t __saved_rbp;
    int64_t* var_10 = &__saved_rbp;
    void* const var_18 = &data_41845b;
    int64_t* r14 = var_10;
    SYSTEM_$$_GET_CALLER_STACKINFO$POINTER$POINTER(&var_10, &var_18);
    int64_t result = -(arg1);
    
    while (arg2 > result)
    {
        if (r14 >= var_10)
            break;
        
        if (SYSTEM_$$_STACKTOP$$POINTER() <= var_10)
            break;
        
        if (var_18 == 0)
            break;
        
        if (var_10 == 0)
            break;
        
        if (result >= 0)
            *(arg3 + (result << 3)) = var_18;
        
        result += 1;
        r14 = var_10;
        SYSTEM_$$_GET_CALLER_STACKINFO$POINTER$POINTER(&var_10, &var_18);
    }
    
    if (result >= 0)
        return result;
    
    return 0;
}

int64_t FPC_BREAK_ERROR(int32_t arg1, uint64_t arg2, uint64_t arg3)
{
    if (TC_$SYSTEM_$$_ERRORPROC != 0)
        TC_$SYSTEM_$$_ERRORPROC(arg1, arg2, arg3);
    
    TC_$SYSTEM_$$_ERRORCODE = arg1;
    TC_$SYSTEM_$$_ERRORADDR = arg2;
    FPC_ERRORBASE = arg3;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax_1;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax_1 = &data_434cb8;
    else
        rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_EXCEPTADDRSTACK);
    
    if (*rax_1 != 0)
        FPC_RAISEEXCEPTION(0, arg2, arg3);
    
    return SYSTEM_$$_HALT$LONGINT(TC_$SYSTEM_$$_ERRORCODE);
}

int64_t SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(int32_t arg1, uint64_t arg2, uint64_t arg3)
{
    uint64_t var_18 = arg2;
    uint64_t var_10 = arg3;
    SYSTEM_$$_GET_CALLER_STACKINFO$POINTER$POINTER(&var_10, &var_18);
    return FPC_BREAK_ERROR(arg1, var_18, var_10);
}

int64_t SYSTEM_$$_HANDLEERRORFRAME$LONGINT$POINTER(int32_t arg1, int64_t* arg2)
{
    uint64_t rdx = arg2;
    
    if (arg2 != 0)
        rdx = *arg2;
    
    int64_t* rsi = arg2;
    
    if (arg2 != 0)
        rsi = arg2[1];
    
    return FPC_BREAK_ERROR(arg1, rsi, rdx);
}

int64_t FPC_HANDLEERROR(int32_t arg1)
{
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(arg1, &data_418604, &__saved_rbp);
}

int64_t FPC_RUNERROR(uint16_t arg1)
{
    TC_$SYSTEM_$$_ERRORCODE = arg1;
    void* const var_18 = &data_41863b;
    int64_t __saved_rbp;
    int64_t* var_10 = &__saved_rbp;
    SYSTEM_$$_GET_CALLER_STACKINFO$POINTER$POINTER(&var_10, &var_18);
    TC_$SYSTEM_$$_ERRORADDR = var_18;
    FPC_ERRORBASE = var_10;
    return SYSTEM_$$_HALT$LONGINT(TC_$SYSTEM_$$_ERRORCODE);
}

int64_t SYSTEM_$$_RUNERROR()
{
    return FPC_RUNERROR(0);
}

int64_t SYSTEM_$$_HALT()
{
    return SYSTEM_$$_HALT$LONGINT(0);
}

int64_t SYSTEM_$$_ERROR$TRUNTIMEERROR(int32_t arg1)
{
    arg1 = *(&TC_$SYSTEM_$$_RUNTIMEERROREXITCODES + arg1);
    return FPC_RUNERROR((arg1 & 0xffff));
}

int64_t* SYSTEM_$$_DUMP_STACK$TEXT$POINTER$POINTER(int32_t* arg1, int64_t* arg2, int64_t arg3)
{
    int64_t* var_18 = arg2;
    int64_t var_20 = arg3;
    void var_90;
    void var_50;
    int64_t __saved_rbp;
    int64_t rbx;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_90, &var_50), rbx, &__saved_rbp, r12, r13, r14, r15);
    int64_t* result = nullptr;
    int64_t* var_30_1 = &__saved_rbp;
    int32_t var_24_1 = 0;
    char rax_2 = SYSTEM_$$_DO_ISDEVICE$LONGINT$$BOOLEAN(*arg1);
    
    while (var_18 > var_30_1)
    {
        if (SYSTEM_$$_STACKTOP$$POINTER() <= var_18)
            break;
        
        var_30_1 = var_18;
        SYSTEM_$$_GET_CALLER_STACKINFO$POINTER$POINTER(&var_18, &var_20);
        
        if (var_20 == 0)
            break;
        
        void var_198;
        TC_$SYSTEM_$$_BACKTRACESTRFUNC(&var_198, var_20);
        FPC_WRITE_TEXT_SHORTSTR(0, arg1, &var_198);
        fpc_writeln_end(arg1);
        
        if (var_18 == 0)
            break;
        
        var_24_1 += 1;
        
        if ((TC_$SYSTEM_$$_MAX_FRAME_DUMP < var_24_1 && rax_2 != 0))
            break;
        
        if (var_24_1 > 0x100)
            break;
    }
    
    FPC_POPADDRSTACK();
    
    if (result == 0)
        return result;
    
    return FPC_DONEEXCEPTION();
}

int64_t* SYSTEM_$$_DUMP_STACK$TEXT$LONGINT(int32_t* arg1, int32_t arg2)
{
    int64_t rbx;
    int64_t var_8 = rbx;
    uint32_t TC_$SYSTEM_$$_MAX_FRAME_DUMP_1;
    
    if (SYSTEM_$$_DO_ISDEVICE$LONGINT$$BOOLEAN(*arg1) == 0)
        TC_$SYSTEM_$$_MAX_FRAME_DUMP_1 = 0xff;
    else
        TC_$SYSTEM_$$_MAX_FRAME_DUMP_1 = TC_$SYSTEM_$$_MAX_FRAME_DUMP;
    
    void var_170;
    void var_158;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_158, &var_170), rbx, rbp, r12, r13, r14, r15);
    int64_t* result = nullptr;
    void var_970;
    int32_t rax_5 = SYSTEM_$$_CAPTUREBACKTRACE$INT64$INT64$PCODEPOINTER$$INT64((arg2 + 1), TC_$SYSTEM_$$_MAX_FRAME_DUMP_1, &var_970);
    int32_t var_974 = rax_5;
    
    if ((rax_5 - 1) >= 0)
    {
        int32_t i = 0xffffffff;
        
        do
        {
            uint64_t rax_7 = (i + 1);
            i = rax_7;
            void var_110;
            TC_$SYSTEM_$$_BACKTRACESTRFUNC(&var_110, *(&var_970 + (rax_7 << 3)));
            FPC_WRITE_TEXT_SHORTSTR(0, arg1, &var_110);
            fpc_writeln_end(arg1);
        } while ((rax_5 - 1) > i);
    }
    
    FPC_POPADDRSTACK();
    
    if (result == 0)
        return result;
    
    return FPC_DONEEXCEPTION();
}

int16_t* SYSTEM_$$_DUMPEXCEPTIONBACKTRACE$TEXT(void* arg1)
{
    int16_t* result = SYSTEM_$$_RAISELIST$$PEXCEPTOBJECT();
    
    if (result != 0)
    {
        void var_128;
        TC_$SYSTEM_$$_BACKTRACESTRFUNC(&var_128, *(SYSTEM_$$_RAISELIST$$PEXCEPTOBJECT() + 8));
        FPC_WRITE_TEXT_SHORTSTR(0, arg1, &var_128);
        fpc_writeln_end(arg1);
        int32_t r12_1 = *(SYSTEM_$$_RAISELIST$$PEXCEPTOBJECT() + 0x1c);
        result = SYSTEM_$$_RAISELIST$$PEXCEPTOBJECT();
        int64_t r13_1 = *(result + 0x20);
        
        if ((r12_1 - 1) >= 0)
        {
            int32_t i = -1;
            
            do
            {
                i += 1;
                TC_$SYSTEM_$$_BACKTRACESTRFUNC(&var_128, *(r13_1 + (i << 3)));
                FPC_WRITE_TEXT_SHORTSTR(0, arg1, &var_128);
                result = fpc_writeln_end(arg1);
            } while ((r12_1 - 1) > i);
        }
    }
    
    return result;
}

int64_t SYSTEM_$$_DOEXITPROC()
{
    uint64_t TC_$SYSTEM_$$_EXITPROCLIST_1 = TC_$SYSTEM_$$_EXITPROCLIST;
    TC_$SYSTEM_$$_EXITPROCLIST = *TC_$SYSTEM_$$_EXITPROCLIST_1;
    TC_$SYSTEM_$$_EXITPROC = *(TC_$SYSTEM_$$_EXITPROCLIST_1 + 8);
    int64_t rbx = *(TC_$SYSTEM_$$_EXITPROCLIST_1 + 0x10);
    FPC_FREEMEM();
    return rbx();
}

uint64_t* SYSTEM_$$_ADDEXITPROC$TPROCEDURE(int64_t arg1)
{
    uint64_t* result = FPC_GETMEM();
    *result = TC_$SYSTEM_$$_EXITPROCLIST;
    result[1] = TC_$SYSTEM_$$_EXITPROC;
    result[2] = arg1;
    TC_$SYSTEM_$$_EXITPROCLIST = result;
    TC_$SYSTEM_$$_EXITPROC = SYSTEM_$$_DOEXITPROC;
    return result;
}

int64_t SYSTEM_$$_ARRAYSTRINGTOPPCHAR$array_of_ANSISTRING$LONGINT$$PPCHAR(int64_t arg1, int64_t arg2, int32_t arg3)
{
    if (arg2 < 0)
        return 0;
    
    int64_t result;
    SYSTEM_$$_GETMEM$POINTER$QWORD(&result, (((arg3 + arg2) + 2) << 3));
    
    if (result == 0)
        return 0;
    
    int32_t rax_3 = arg2;
    
    if (rax_3 >= 0)
    {
        int32_t rdx = -1;
        
        do
        {
            rdx += 1;
            int64_t rsi_2 = rdx;
            uint16_t* rcx_2 = *(arg1 + (rsi_2 << 3));
            
            if (rcx_2 == 0)
                rcx_2 = &FPC_EMPTYCHAR;
            
            *(result + ((arg3 + rsi_2) << 3)) = rcx_2;
        } while (rax_3 > rdx);
    }
    
    *(result + (((arg2 + 1) + arg3) << 3)) = 0;
    return result;
}

char** SYSTEM_$$_STRINGTOPPCHAR$ANSISTRING$SMALLINT$$PPCHAR(int64_t* arg1, int16_t arg2)
{
    uint16_t* rdi = *arg1;
    
    if (rdi == 0)
        rdi = &FPC_EMPTYCHAR;
    
    return SYSTEM_$$_STRINGTOPPCHAR$PCHAR$SMALLINT$$PPCHAR(rdi, arg2);
}

char** SYSTEM_$$_STRINGTOPPCHAR$PCHAR$SMALLINT$$PPCHAR(char* arg1, int16_t arg2)
{
    char* rbx = arg1;
    int64_t r12;
    r12 = arg2;
    char* rax = rbx;
    int32_t rcx = 1;
    
    while (*rax != 0)
    {
        while (true)
        {
            int32_t rdx_2 = (*rax - 9);
            bool c_1 = rdx_2 < 2;
            
            if (!(c_1))
            {
                c_1 = true;
                
                if (rdx_2 != 0x17)
                    c_1 = false;
            }
            
            if (!(c_1))
                break;
            
            rax = &rax[1];
        }
        
        rcx += 1;
        
        if (*rax != 0x22)
        {
            while (true)
            {
                uint32_t rdx_4 = *rax;
                bool c_2 = true;
                
                if (rdx_4 != 0)
                {
                    c_2 = (rdx_4 - 9) < 2;
                    
                    if (!(c_2))
                    {
                        c_2 = true;
                        
                        if (rdx_4 != 0x20)
                            c_2 = false;
                    }
                }
                
                if (c_2)
                    break;
                
                rax = &rax[1];
            }
        }
        else
        {
            rax = &rax[1];
            
            while (true)
            {
                uint32_t rdx_3 = *rax;
                
                if (rdx_3 == 0)
                    break;
                
                if (rdx_3 == 0x22)
                    break;
                
                if (rdx_3 == 0x22)
                    break;
                
                rax = &rax[1];
            }
            
            if (*rax == 0x22)
                rax = &rax[1];
        }
    }
    
    char** result_1;
    SYSTEM_$$_GETMEM$POINTER$QWORD(&result_1, ((r12 + rcx) << 3));
    char** result = result_1;
    
    if (result_1 != 0)
    {
        int32_t r12_1 = r12;
        
        if (r12_1 >= 1)
        {
            int32_t rdx_6 = 0;
            
            do
            {
                rdx_6 += 1;
                result_1 = &result_1[1];
            } while (r12_1 > rdx_6);
        }
        
        while (*rbx != 0)
        {
            while (true)
            {
                int32_t rdx_8 = (*rbx - 9);
                bool c_3 = rdx_8 < 2;
                
                if (!(c_3))
                {
                    c_3 = true;
                    
                    if (rdx_8 != 0x17)
                        c_3 = false;
                }
                
                if (!(c_3))
                    break;
                
                *rbx = 0;
                rbx = &rbx[1];
            }
            
            if (*rbx != 0x22)
            {
                *result_1 = rbx;
                result_1 = &result_1[1];
                *result_1 = nullptr;
                
                while (true)
                {
                    uint32_t rdx_14 = *rbx;
                    bool c_4 = true;
                    
                    if (rdx_14 != 0)
                    {
                        c_4 = (rdx_14 - 9) < 2;
                        
                        if (!(c_4))
                        {
                            c_4 = true;
                            
                            if (rdx_14 != 0x20)
                                c_4 = false;
                        }
                    }
                    
                    if (c_4)
                        break;
                    
                    rbx = &rbx[1];
                }
            }
            else
            {
                rbx = &rbx[1];
                *result_1 = rbx;
                result_1 = &result_1[1];
                *result_1 = nullptr;
                
                while (true)
                {
                    uint32_t rdx_11 = *rbx;
                    
                    if (rdx_11 == 0)
                        break;
                    
                    if (rdx_11 == 0x22)
                        break;
                    
                    if (rdx_11 == 0x22)
                        break;
                    
                    rbx = &rbx[1];
                }
                
                if (*rbx == 0x22)
                {
                    *rbx = 0;
                    rbx = &rbx[1];
                }
            }
        }
    }
    
    return result;
}

int64_t FPC_EMPTYMETHOD() __pure
{
    return;
}

int64_t FPC_ABSTRACTERROR()
{
    if (TC_$SYSTEM_$$_ABSTRACTERRORPROC != 0)
        TC_$SYSTEM_$$_ABSTRACTERRORPROC();
    
    int64_t __saved_rbp;
    return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xd3, &data_418d0f, &__saved_rbp);
}

int64_t FPC_ASSERT(int64_t arg1)
{
    int64_t __saved_rbp;
    
    if (TC_$SYSTEM_$$_ASSERTERRORPROC == 0)
        return SYSTEM_$$_HANDLEERRORADDRFRAMEIND$LONGINT$POINTER$POINTER(0xe3, &data_418d57, &__saved_rbp);
    return TC_$SYSTEM_$$_ASSERTERRORPROC(arg1);
}

int64_t SYSTEM_$$_SYSASSERT$SHORTSTRING$SHORTSTRING$LONGINT$POINTER(char* arg1, char* arg2, int32_t arg3)
{
    if (*arg1 != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_9 = FPC_THREADVAR_RELOCATE;
        void* rsi_1;
        
        if (FPC_THREADVAR_RELOCATE_9 == 0)
            rsi_1 = &data_4346f8;
        else
            rsi_1 = FPC_THREADVAR_RELOCATE_9(U_$SYSTEM_$$_STDERR);
        
        FPC_WRITE_TEXT_SHORTSTR(0, rsi_1, arg1);
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        void* rdi_5;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            rdi_5 = &data_4346f8;
        else
            rdi_5 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_STDERR);
        
        fpc_write_end(rdi_5);
    }
    else
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        void* rsi;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rsi = &data_4346f8;
        else
            rsi = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_STDERR);
        
        FPC_WRITE_TEXT_SHORTSTR(0, rsi, &_$SYSTEM$_Ld38);
        uint64_t FPC_THREADVAR_RELOCATE_8 = FPC_THREADVAR_RELOCATE;
        void* rdi_2;
        
        if (FPC_THREADVAR_RELOCATE_8 == 0)
            rdi_2 = &data_4346f8;
        else
            rdi_2 = FPC_THREADVAR_RELOCATE_8(U_$SYSTEM_$$_STDERR);
        
        fpc_write_end(rdi_2);
    }
    
    uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
    void* rsi_2;
    
    if (FPC_THREADVAR_RELOCATE_3 == 0)
        rsi_2 = &data_4346f8;
    else
        rsi_2 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_STDERR);
    
    FPC_WRITE_TEXT_SHORTSTR(0, rsi_2, &_$SYSTEM$_Ld39);
    uint64_t FPC_THREADVAR_RELOCATE_10 = FPC_THREADVAR_RELOCATE;
    void* rsi_3;
    
    if (FPC_THREADVAR_RELOCATE_10 == 0)
        rsi_3 = &data_4346f8;
    else
        rsi_3 = FPC_THREADVAR_RELOCATE_10(U_$SYSTEM_$$_STDERR);
    
    FPC_WRITE_TEXT_SHORTSTR(0, rsi_3, arg2);
    uint64_t FPC_THREADVAR_RELOCATE_11 = FPC_THREADVAR_RELOCATE;
    void* rsi_4;
    
    if (FPC_THREADVAR_RELOCATE_11 == 0)
        rsi_4 = &data_4346f8;
    else
        rsi_4 = FPC_THREADVAR_RELOCATE_11(U_$SYSTEM_$$_STDERR);
    
    FPC_WRITE_TEXT_SHORTSTR(0, rsi_4, &_$SYSTEM$_Ld40);
    uint64_t FPC_THREADVAR_RELOCATE_4 = FPC_THREADVAR_RELOCATE;
    void* rsi_5;
    
    if (FPC_THREADVAR_RELOCATE_4 == 0)
        rsi_5 = &data_4346f8;
    else
        rsi_5 = FPC_THREADVAR_RELOCATE_4(U_$SYSTEM_$$_STDERR);
    
    fpc_write_text_sint(0, rsi_5, arg3);
    uint64_t FPC_THREADVAR_RELOCATE_5 = FPC_THREADVAR_RELOCATE;
    void* rsi_6;
    
    if (FPC_THREADVAR_RELOCATE_5 == 0)
        rsi_6 = &data_4346f8;
    else
        rsi_6 = FPC_THREADVAR_RELOCATE_5(U_$SYSTEM_$$_STDERR);
    
    FPC_WRITE_TEXT_SHORTSTR(0, rsi_6, &_$SYSTEM$_Ld41);
    uint64_t FPC_THREADVAR_RELOCATE_6 = FPC_THREADVAR_RELOCATE;
    void* rdi_12;
    
    if (FPC_THREADVAR_RELOCATE_6 == 0)
        rdi_12 = &data_4346f8;
    else
        rdi_12 = FPC_THREADVAR_RELOCATE_6(U_$SYSTEM_$$_STDERR);
    
    fpc_writeln_end(rdi_12);
    uint64_t FPC_THREADVAR_RELOCATE_12 = FPC_THREADVAR_RELOCATE;
    void* rsi_7;
    
    if (FPC_THREADVAR_RELOCATE_12 == 0)
        rsi_7 = &data_4346f8;
    else
        rsi_7 = FPC_THREADVAR_RELOCATE_12(U_$SYSTEM_$$_STDERR);
    
    FPC_WRITE_TEXT_SHORTSTR(0, rsi_7, &_$SYSTEM$_Ld2);
    uint64_t FPC_THREADVAR_RELOCATE_7 = FPC_THREADVAR_RELOCATE;
    void* rdi_15;
    
    if (FPC_THREADVAR_RELOCATE_7 == 0)
        rdi_15 = &data_4346f8;
    else
        rdi_15 = FPC_THREADVAR_RELOCATE_7(U_$SYSTEM_$$_STDERR);
    
    fpc_writeln_end(rdi_15);
    return SYSTEM_$$_HALT$LONGINT(0xe3);
}

int64_t SYSTEM_$$_SYSOSALLOC$QWORD$$POINTER(int64_t arg1)
{
    int64_t result = FPC_SYSC_MMAP(0, arg1, 3, 0x22, 0xffffffff, 0);
    
    if (result == -1)
        return 0;
    
    FPC_SYS_SETERRNO(0);
    return result;
}

int64_t SYSTEM_$$_SYSOSFREE$POINTER$QWORD(int64_t arg1, int64_t arg2)
{
    return FPC_SYSC_MUNMAP(arg1, arg2);
}

int64_t SYSTEM_$$_GETMEMORYMANAGER$TMEMORYMANAGER()
{
    int64_t rdi;
    __builtin_memcpy(rdi, &TC_$SYSTEM_$$_MEMORYMANAGER, 0xc);
}

int64_t SYSTEM_$$_SETMEMORYMANAGER$TMEMORYMANAGER(int64_t arg1)
{
    __builtin_memcpy(&TC_$SYSTEM_$$_MEMORYMANAGER, arg1, 0xc);
    return arg1;
}

int64_t SYSTEM_$$_ISMEMORYMANAGERSET$$BOOLEAN()
{
    void* rax;
    
    if ((SYSTEM_$$_SYSGETMEM$QWORD$$POINTER != data_428148 || SYSTEM_$$_SYSFREEMEM$POINTER$$QWORD != data_428150))
    {
        rax = 1;
        return &*(TC_$SYSTEM$_$fpc_val_currency_shortstr$SHORTSTRING$INT64$$CURRENCY_$$_MININT64 + 1);
    }
    
    rax = 0;
    return &TC_$SYSTEM$_$fpc_val_currency_shortstr$SHORTSTRING$INT64$$CURRENCY_$$_MININT64;
}

int64_t SYSTEM_$$_GETMEM$POINTER$QWORD(int64_t* arg1, int64_t arg2)
{
    int64_t result = data_428148(arg2);
    *arg1 = result;
    return result;
}

int64_t SYSTEM_$$_GETMEMORY$POINTER$QWORD(int64_t* arg1, int64_t arg2)
{
    return SYSTEM_$$_GETMEM$POINTER$QWORD(arg1, arg2);
}

int64_t SYSTEM_$$_FREEMEM$POINTER$QWORD()
{
    return data_428158();
}

int64_t SYSTEM_$$_FREEMEMORY$POINTER$QWORD()
{
    return SYSTEM_$$_FREEMEM$POINTER$QWORD();
}

int64_t SYSTEM_$$_GETHEAPSTATUS$$THEAPSTATUS()
{
    return data_428190();
}

int64_t SYSTEM_$$_GETFPCHEAPSTATUS$$TFPCHEAPSTATUS()
{
    return data_428198();
}

int64_t SYSTEM_$$_MEMSIZE$POINTER$$QWORD()
{
    return data_428170();
}

int64_t SYSTEM_$$_FREEMEM$POINTER$$QWORD()
{
    return data_428150();
}

int64_t SYSTEM_$$_FREEMEMORY$POINTER$$QWORD()
{
    return SYSTEM_$$_FREEMEM$POINTER$$QWORD();
}

int64_t SYSTEM_$$_GETMEM$QWORD$$POINTER()
{
    return data_428148();
}

int64_t SYSTEM_$$_GETMEMORY$QWORD$$POINTER()
{
    return SYSTEM_$$_GETMEM$QWORD$$POINTER();
}

int64_t SYSTEM_$$_ALLOCMEM$QWORD$$POINTER()
{
    return data_428160();
}

int64_t SYSTEM_$$_REALLOCMEM$POINTER$QWORD$$POINTER()
{
    return data_428168();
}

int64_t SYSTEM_$$_REALLOCMEMORY$POINTER$QWORD$$POINTER()
{
    int64_t rdi;
    int64_t var_8 = rdi;
    return SYSTEM_$$_REALLOCMEM$POINTER$QWORD$$POINTER();
}

int64_t FPC_GETMEM()
{
    return data_428148();
}

int64_t FPC_FREEMEM()
{
    return data_428150();
}

int64_t SYSTEM_$$_SYSGETFPCHEAPSTATUS$$TFPCHEAPSTATUS(int64_t arg1)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    void* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_435948;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_FREELISTS);
    
    int64_t result = *(rax + 0xd8);
    *(rax + 0xe0) = (*(rax + 0xd0) - result);
    __builtin_memcpy(arg1, (rax + 0xc0), 5);
    return result;
}

int64_t SYSTEM_$$_SYSGETHEAPSTATUS$$THEAPSTATUS(int32_t* arg1)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    void* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_435948;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_FREELISTS);
    
    *(rax + 0xe0) = (*(rax + 0xd0) - *(rax + 0xd8));
    arg1[3] = *(rax + 0xd8);
    arg1[4] = *(rax + 0xe0);
    int32_t result = *(rax + 0xd0);
    *arg1 = result;
    arg1[1] = 0;
    arg1[2] = 0;
    __builtin_memset(&arg1[5], 0, 0x14);
    return result;
}

int64_t* SYSTEM_$$_APPEND_TO_LIST_VAR$PMEMCHUNK_VAR(void* arg1)
{
    int64_t* result = (*(arg1 + 8) + 0xa8);
    *(arg1 + 0x20) = 0;
    *(arg1 + 0x18) = *result;
    
    if (*result != 0)
        *(*result + 0x20) = arg1;
    
    *result = arg1;
    return result;
}

void* SYSTEM_$$_REMOVE_FROM_LIST_FIXED$PMEMCHUNK_FIXED$PPMEMCHUNK_FIXED(void* arg1, int64_t* arg2)
{
    if (*(arg1 + 8) != 0)
        *(*(arg1 + 8) + 0x10) = *(arg1 + 0x10);
    
    if (*(arg1 + 0x10) != 0)
    {
        *(*(arg1 + 0x10) + 8) = *(arg1 + 8);
        return arg1;
    }
    
    int64_t rax = *(arg1 + 8);
    *arg2 = rax;
    return rax;
}

void* SYSTEM_$$_REMOVE_FROM_LIST_VAR$PMEMCHUNK_VAR(void* arg1)
{
    if (*(arg1 + 0x18) != 0)
        *(*(arg1 + 0x18) + 0x20) = *(arg1 + 0x20);
    
    if (*(arg1 + 0x20) != 0)
    {
        *(*(arg1 + 0x20) + 0x18) = *(arg1 + 0x18);
        return arg1;
    }
    
    int64_t rax = *(arg1 + 0x18);
    *(*(arg1 + 8) + 0xa8) = rax;
    return rax;
}

void SYSTEM_$$_REMOVE_FREED_FIXED_CHUNKS$POSCHUNK(int64_t* arg1)
{
    if (arg1[4] >= 0)
    {
        void* rax = &arg1[7];
        int64_t rdx_2 = (*rax & 0xfe0);
        void* rcx_4 = (((*arg1 & 0xffffffffffffffe0) + arg1) - rdx_2);
        int64_t* rsi_3 = (arg1[5] + ((rdx_2 >> 5) << 3));
        
        do
        {
            if (*(rax + 8) != 0)
                *(*(rax + 8) + 0x10) = *(rax + 0x10);
            
            if (*(rax + 0x10) == 0)
                *rsi_3 = *(rax + 8);
            else
                *(*(rax + 0x10) + 8) = *(rax + 8);
            
            rax += rdx_2;
        } while (rcx_4 >= rax);
    }
}

int64_t SYSTEM_$$_FREE_OSCHUNK$PFREELISTS$POSCHUNK(void* arg1, int64_t* arg2)
{
    SYSTEM_$$_REMOVE_FREED_FIXED_CHUNKS$POSCHUNK(arg2);
    
    if (arg2[2] == 0)
        *(arg1 + 0xa0) = arg2[3];
    else
        *(arg2[2] + 0x18) = arg2[3];
    
    if (arg2[3] != 0)
        *(arg2[3] + 0x10) = arg2[2];
    
    if (arg2[4] >= 0)
        *(arg1 + 0x94) -= 1;
    
    int64_t rsi_1 = (*arg2 & 0xffffffffffffffe0);
    *(arg1 + 0xd0) -= rsi_1;
    return SYSTEM_$$_SYSOSFREE$POINTER$QWORD(arg2, rsi_1);
}

void* SYSTEM_$$_APPEND_TO_OSLIST$POSCHUNK(int64_t* arg1)
{
    void** r12 = arg1[5];
    void* result = (*arg1 & 1);
    
    if (result == 0)
    {
        if ((r12[0x12] >= TC_$SYSTEM_$$_MAXKEPTOSCHUNKS || (*arg1 & 0xffffffffffffffe0) > TC_$SYSTEM_$$_GROWHEAPSIZE2))
            return SYSTEM_$$_FREE_OSCHUNK$PFREELISTS$POSCHUNK(r12, arg1);
        
        result = *r12;
        arg1[1] = result;
        *r12 = arg1;
        r12[0x12] += 1;
    }
    else
    {
        r12[0x12] += 1;
        *arg1 &= 0xfffffffffffffffe;
    }
    
    return result;
}

void* SYSTEM_$$_APPEND_TO_OSLIST_VAR$PMEMCHUNK_VAR(void* arg1)
{
    if (*(arg1 + 0x18) != 0)
        *(*(arg1 + 0x18) + 0x20) = *(arg1 + 0x20);
    
    if (*(arg1 + 0x20) == 0)
        *(*(arg1 + 8) + 0xa8) = *(arg1 + 0x18);
    else
        *(*(arg1 + 0x20) + 0x18) = *(arg1 + 0x18);
    
    return SYSTEM_$$_APPEND_TO_OSLIST$POSCHUNK((arg1 - 0x38));
}

void SYSTEM_$$_MODIFY_OSCHUNK_FREELISTS$POSCHUNK$PFREELISTS(void* arg1, int64_t arg2)
{
    *(arg1 + 0x28) = arg2;
    
    if (*(arg1 + 0x20) == -1)
    {
        void* rax = (arg1 + 0x38);
        
        while (true)
        {
            *(rax + 8) = arg2;
            
            if ((*(rax + 0x10) & 4) != 0)
                break;
            
            rax += (*(rax + 0x10) & 0xffffffffffffffe0);
        }
    }
}

void* const SYSTEM_$$_MODIFY_FREELISTS$PFREELISTS$PFREELISTS$$POSCHUNK(void* arg1, int64_t arg2)
{
    void* result = *(arg1 + 0xa0);
    
    if (result == 0)
        return nullptr;
    
    while (true)
    {
        SYSTEM_$$_MODIFY_OSCHUNK_FREELISTS$POSCHUNK$PFREELISTS(result, arg2);
        
        if (*(result + 0x18) == 0)
            break;
        
        result = *(result + 0x18);
    }
    
    return result;
}

int64_t SYSTEM_$$_SPLIT_BLOCK$PMEMCHUNK_VAR$QWORD$$QWORD(void* arg1, int64_t arg2)
{
    int64_t rax_6 = *(arg1 + 0x10);
    int64_t rdx_1 = (rax_6 & 0xffffffffffffffe0);
    int64_t rcx_1 = (rdx_1 - arg2);
    
    if (rcx_1 < 0x28)
        return rdx_1;
    
    void* r8 = (arg1 + arg2);
    
    if ((rax_6 & 4) == 0)
        *(arg1 + rdx_1) = rcx_1;
    
    *(r8 + 0x10) = ((rax_6 & 4) | rcx_1);
    *r8 = arg2;
    *(r8 + 8) = *(arg1 + 8);
    *(arg1 + 0x10) = ((rax_6 & 0x1b) | arg2);
    void** rax_3 = (*(r8 + 8) + 0xa8);
    *(r8 + 0x20) = 0;
    *(r8 + 0x18) = *rax_3;
    
    if (*rax_3 != 0)
        *(*rax_3 + 0x20) = r8;
    
    *rax_3 = r8;
    return arg2;
}

int64_t SYSTEM_$$_CONCAT_TWO_BLOCKS$PMEMCHUNK_VAR$PMEMCHUNK_VAR(void* arg1, void* arg2)
{
    if ((*(arg2 + 0x10) & 1) != 0)
        FPC_HANDLEERROR(0xcc);
    
    void* rax_3 = (*(arg2 + 0x10) & 0xffffffffffffffe0);
    *(arg1 + 0x10) += rax_3;
    
    if ((*(arg2 + 0x10) & 4) == 0)
        *(rax_3 + arg2) = (*(arg1 + 0x10) & 0xffffffffffffffe0);
    else
        *(arg1 + 0x10) |= 4;
    
    if (*(arg2 + 0x18) != 0)
        *(*(arg2 + 0x18) + 0x20) = *(arg2 + 0x20);
    
    int64_t result;
    
    if (*(arg2 + 0x20) == 0)
    {
        result = *(arg2 + 0x18);
        *(*(arg2 + 8) + 0xa8) = result;
    }
    else
    {
        result = *(arg2 + 0x18);
        *(*(arg2 + 0x20) + 0x18) = result;
    }
    
    return result;
}

int64_t SYSTEM_$$_TRY_CONCAT_FREE_CHUNK_FORWARD$PMEMCHUNK_VAR$$BOOLEAN(void* arg1)
{
    int64_t rbx;
    rbx = 0;
    
    if ((*(arg1 + 0x10) & 4) == 0)
    {
        void* rsi_1 = ((*(arg1 + 0x10) & 0xffffffffffffffe0) + arg1);
        
        if ((*(rsi_1 + 0x10) & 2) == 0)
        {
            SYSTEM_$$_CONCAT_TWO_BLOCKS$PMEMCHUNK_VAR$PMEMCHUNK_VAR(arg1, rsi_1);
            rbx = 1;
        }
    }
    
    int64_t result;
    result = rbx;
    return result;
}

int64_t* SYSTEM_$$_TRY_CONCAT_FREE_CHUNK$PMEMCHUNK_VAR$$PMEMCHUNK_VAR(int64_t* arg1)
{
    SYSTEM_$$_TRY_CONCAT_FREE_CHUNK_FORWARD$PMEMCHUNK_VAR$$BOOLEAN(arg1);
    
    if ((arg1[2] & 8) == 0)
    {
        void* r12_2 = (arg1 - *arg1);
        
        if ((*(r12_2 + 0x10) & 2) == 0)
        {
            SYSTEM_$$_CONCAT_TWO_BLOCKS$PMEMCHUNK_VAR$PMEMCHUNK_VAR(r12_2, arg1);
            return r12_2;
        }
    }
    
    return arg1;
}

int64_t* SYSTEM_$$_FIND_FREE_OSCHUNK$PFREELISTS$QWORD$QWORD$QWORD$$POSCHUNK(int64_t* arg1, int64_t arg2, int64_t arg3, int64_t* arg4)
{
    int64_t* i = *arg1;
    int64_t* i_1 = nullptr;
    
    while (i != 0)
    {
        if ((*i & 1) == 0)
        {
            int64_t rax_4 = (*i & 0xffffffffffffffe0);
            
            if ((arg2 <= rax_4 && arg3 >= rax_4))
            {
                *arg4 = rax_4;
                
                if (i_1 != 0)
                    i_1[1] = i[1];
                else
                    *arg1 = i[1];
                
                arg1[0x12] -= 1;
                SYSTEM_$$_REMOVE_FREED_FIXED_CHUNKS$POSCHUNK(i);
                break;
            }
            
            i_1 = i;
            i = i[1];
        }
        else
        {
            *i &= 0xfffffffffffffffe;
            i = i[1];
            
            if (i_1 != 0)
                i_1[1] = i;
            else
                *arg1 = i;
        }
    }
    
    return i;
}

int64_t* SYSTEM_$$_ALLOC_OSCHUNK$PFREELISTS$QWORD$QWORD$$POINTER(int64_t* arg1, int64_t arg2, uint64_t arg3)
{
    uint64_t var_38 = arg3;
    int64_t r14;
    
    if (arg2 == 0)
        r14 = -1;
    else
        r14 = 0x100000;
    
    int64_t* r12 = nullptr;
    
    if (arg1[0x12] >= TC_$SYSTEM_$$_MAXKEPTOSCHUNKS)
        r12 = SYSTEM_$$_FIND_FREE_OSCHUNK$PFREELISTS$QWORD$QWORD$QWORD$$POSCHUNK(arg1, (arg3 + 0x38), r14, &var_38);
    
    if ((r12 == 0 && ((data_4358c0 != 0 || data_4358c8 != 0) || data_4358a0 > 0)))
    {
        SYSTEM_$$_ENTERCRITICALSECTION$TRTLCRITICALSECTION();
        SYSTEM_$$_FINISH_WAITFIXEDLIST$PFREELISTS(&U_$SYSTEM_$$_ORPHANED_FREELISTS);
        SYSTEM_$$_FINISH_WAITVARLIST$PFREELISTS(&U_$SYSTEM_$$_ORPHANED_FREELISTS);
        
        if (data_4358a0 > 0)
        {
            int64_t* rax_4 = SYSTEM_$$_FIND_FREE_OSCHUNK$PFREELISTS$QWORD$QWORD$QWORD$$POSCHUNK(&U_$SYSTEM_$$_ORPHANED_FREELISTS, (arg3 + 0x38), r14, &var_38);
            r12 = rax_4;
            
            if (rax_4 != 0)
            {
                r12[5] = arg1;
                
                if (r12[2] == 0)
                    data_4358b0 = r12[3];
                else
                    *(r12[2] + 0x18) = r12[3];
                
                if (r12[3] != 0)
                    *(r12[3] + 0x10) = r12[2];
                
                r12[3] = arg1[0x14];
                
                if (arg1[0x14] != 0)
                    *(arg1[0x14] + 0x10) = r12;
                
                r12[2] = 0;
                arg1[0x14] = r12;
            }
        }
        
        SYSTEM_$$_LEAVECRITICALSECTION$TRTLCRITICALSECTION();
    }
    
    if (r12 == 0)
    {
        var_38 = ((var_38 + 0x10037) & 0xffffffffffff0000);
        
        if (arg2 != 0)
        {
            int64_t* rax_20 = SYSTEM_$$_SYSOSALLOC$QWORD$$POINTER(arg1[0x13]);
            r12 = rax_20;
            
            if (rax_20 != 0)
                var_38 = arg1[0x13];
        }
        else if (var_38 <= TC_$SYSTEM_$$_GROWHEAPSIZE1)
        {
            int64_t* rax_23 = SYSTEM_$$_SYSOSALLOC$QWORD$$POINTER(TC_$SYSTEM_$$_GROWHEAPSIZE1);
            r12 = rax_23;
            
            if (rax_23 != 0)
                var_38 = TC_$SYSTEM_$$_GROWHEAPSIZE1;
        }
        else if (var_38 > TC_$SYSTEM_$$_GROWHEAPSIZE2)
            r12 = SYSTEM_$$_SYSOSALLOC$QWORD$$POINTER(var_38);
        else
        {
            int64_t* rax_25 = SYSTEM_$$_SYSOSALLOC$QWORD$$POINTER(TC_$SYSTEM_$$_GROWHEAPSIZE2);
            r12 = rax_25;
            
            if (rax_25 != 0)
                var_38 = TC_$SYSTEM_$$_GROWHEAPSIZE2;
        }
        
        if (r12 == 0)
        {
            int64_t* rax_28 = SYSTEM_$$_SYSOSALLOC$QWORD$$POINTER(var_38);
            r12 = rax_28;
            
            if (rax_28 == 0)
            {
                if (U_$SYSTEM_$$_RETURNNILIFGROWHEAPFAILS != 0)
                    return nullptr;
                
                FPC_HANDLEERROR(0xcb);
            }
        }
        
        r12[5] = arg1;
        r12[2] = 0;
        r12[3] = arg1[0x14];
        
        if (arg1[0x14] != 0)
            *(arg1[0x14] + 0x10) = r12;
        
        arg1[0x14] = r12;
        arg1[0x1a] += var_38;
        
        if (arg1[0x1a] > arg1[0x18])
            arg1[0x18] = arg1[0x1a];
    }
    
    *r12 = var_38;
    int64_t* result;
    
    if (arg2 == 0)
    {
        r12[4] = -1;
        result = &r12[7];
        result[2] = (((var_38 - 0x38) & 0xffffffffffffffe0) | 0xc);
        *result = 0;
        result[1] = arg1;
        result[4] = 0;
        result[3] = arg1[0x15];
        
        if (arg1[0x15] != 0)
            *(arg1[0x15] + 0x20) = result;
        
        arg1[0x15] = result;
    }
    else
    {
        r12[4] = 0;
        int64_t rax_40 = (arg2 << 5);
        
        if ((var_38 - rax_40) > r14)
            FPC_HANDLEERROR(0xcc);
        
        int64_t rcx_4 = 0x38;
        result = &r12[7];
        int64_t* result_1 = result;
        result_1[2] = 0;
        
        while (true)
        {
            *result_1 = ((rax_40 | 1) | (rcx_4 << 0xc));
            rcx_4 += rax_40;
            
            if ((var_38 - rax_40) < rcx_4)
                break;
            
            int64_t* result_2 = (result_1 + rax_40);
            result_1[1] = result_2;
            result_2[2] = result_1;
            result_1 = result_2;
        }
        
        void* rdi_8 = arg1[arg2];
        result_1[1] = rdi_8;
        
        if (rdi_8 != 0)
            *(rdi_8 + 0x10) = result_1;
        
        arg1[arg2] = result;
        *(arg1 + 0x94) += 1;
        
        if (*(arg1 + 0x94) > 0x88)
        {
            if (arg1[0x13] < 0x40000)
                arg1[0x13] *= 2;
            
            *(arg1 + 0x94) = 0;
        }
    }
    
    return result;
}

void* SYSTEM_$$_SYSGETMEM_FIXED$QWORD$$POINTER(uint64_t arg1)
{
    uint64_t rax_1 = (arg1 >> 5);
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax_2;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax_2 = &data_435948;
    else
        rax_2 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_FREELISTS);
    
    int64_t* rbx = rax_2[rax_1];
    void* r12_1;
    
    if (rbx == 0)
    {
        if (SYSTEM_$$_TRY_FINISH_WAITFIXEDLIST$PFREELISTS$$BOOLEAN(rax_2) != 0)
            return SYSTEM_$$_SYSGETMEM_FIXED$QWORD$$POINTER(arg1);
        
        int64_t* rax_7 = SYSTEM_$$_ALLOC_OSCHUNK$PFREELISTS$QWORD$QWORD$$POINTER(rax_2, rax_1, arg1);
        rbx = rax_7;
        
        if (rax_7 == 0)
            return nullptr;
        
        r12_1 = &rbx[-7];
    }
    else
    {
        r12_1 = (rbx - (*rbx >> 0xc));
        
        if (*(r12_1 + 0x20) == 0)
        {
            *r12_1 |= 1;
            rax_2[0x12] -= 1;
        }
    }
    
    void* rcx_1 = rbx[1];
    rax_2[rax_1] = rcx_1;
    
    if (rcx_1 != 0)
        *(rcx_1 + 0x10) = 0;
    
    rax_2[0x1b] += arg1;
    
    if (rax_2[0x1b] > rax_2[0x19])
        rax_2[0x19] = rax_2[0x1b];
    
    *(r12_1 + 0x20) += 1;
    return &rbx[1];
}

void* SYSTEM_$$_SYSGETMEM_VAR$QWORD$$POINTER(uint64_t arg1)
{
    void* result = nullptr;
    
    if (arg1 <= -0x10000)
        goto label_419e7c;
    
    if (U_$SYSTEM_$$_RETURNNILIFGROWHEAPFAILS == 0)
    {
        FPC_HANDLEERROR(0xcc);
    label_419e7c:
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int64_t* r13_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            r13_1 = &data_435948;
        else
            r13_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_FREELISTS);
        
        SYSTEM_$$_TRY_FINISH_WAITVARLIST$PFREELISTS(r13_1);
        int64_t* i_1 = nullptr;
        int64_t* i = r13_1[0x15];
        int32_t rsi_1 = -1;
        
        while (i != 0)
        {
            if (rsi_1 <= 0)
                break;
            
            if ((arg1 <= i[2] && (i_1 == 0 || i[2] < i_1[2])))
            {
                i_1 = i;
                
                if (arg1 == i[2])
                    break;
                
                rsi_1 = 0xa;
            }
            
            i = i[3];
            rsi_1 -= 1;
        }
        
        int64_t* i_2 = i_1;
        int64_t* i_3;
        
        if (i_1 == 0)
        {
            i_3 = SYSTEM_$$_ALLOC_OSCHUNK$PFREELISTS$QWORD$QWORD$$POINTER(r13_1, 0, arg1);
            i_2 = i_3;
        }
        
        if ((i_1 != 0 || i_3 != 0))
        {
            result = &i_2[3];
            
            if (i_2[3] != 0)
                *(i_2[3] + 0x20) = i_2[4];
            
            if (i_2[4] == 0)
                *(i_2[1] + 0xa8) = i_2[3];
            else
                *(i_2[4] + 0x18) = i_2[3];
            
            int64_t rax_8 = SYSTEM_$$_SPLIT_BLOCK$PMEMCHUNK_VAR$QWORD$$QWORD(i_2, arg1);
            i_2[2] |= 2;
            r13_1[0x1b] += rax_8;
            
            if (r13_1[0x1b] > r13_1[0x19])
                r13_1[0x19] = r13_1[0x1b];
        }
    }
    
    return result;
}

void* SYSTEM_$$_SYSGETMEM$QWORD$$POINTER(uint64_t arg1)
{
    uint64_t r12 = arg1;
    
    if (arg1 == 0)
        r12 = 1;
    
    if (r12 <= 0x218)
        return SYSTEM_$$_SYSGETMEM_FIXED$QWORD$$POINTER(((r12 + 0x27) & 0xfe0));
    
    if (r12 < -0x38)
        r12 = ((r12 + 0x37) & 0xffffffffffffffe0);
    
    return SYSTEM_$$_SYSGETMEM_VAR$QWORD$$POINTER(r12);
}

int64_t SYSTEM_$$_WAITFREE_FIXED$PMEMCHUNK_FIXED$POSCHUNK(void* arg1, void* arg2)
{
    SYSTEM_$$_ENTERCRITICALSECTION$TRTLCRITICALSECTION();
    *(arg1 + 8) = *(*(arg2 + 0x28) + 0xb0);
    *(*(arg2 + 0x28) + 0xb0) = arg1;
    return SYSTEM_$$_LEAVECRITICALSECTION$TRTLCRITICALSECTION();
}

int64_t SYSTEM_$$_WAITFREE_VAR$PMEMCHUNK_VAR(void* arg1)
{
    SYSTEM_$$_ENTERCRITICALSECTION$TRTLCRITICALSECTION();
    *(arg1 + 0x18) = *(*(arg1 + 8) + 0xb8);
    *(*(arg1 + 8) + 0xb8) = arg1;
    return SYSTEM_$$_LEAVECRITICALSECTION$TRTLCRITICALSECTION();
}

int64_t SYSTEM_$$_SYSFREEMEM_FIXED$PFREELISTS$PMEMCHUNK_FIXED$$QWORD(void* arg1, int64_t* arg2)
{
    void* r12_1 = (arg2 - (*arg2 >> 0xc));
    int64_t result = (*arg2 & 0xfe0);
    
    if (*(r12_1 + 0x28) != arg1)
        SYSTEM_$$_WAITFREE_FIXED$PMEMCHUNK_FIXED$POSCHUNK(arg2, r12_1);
    else
    {
        *(r12_1 + 0x20) -= 1;
        uint64_t rax_4 = (result >> 5);
        void* rdx_1 = *(arg1 + (rax_4 << 3));
        arg2[2] = 0;
        arg2[1] = rdx_1;
        
        if (rdx_1 != 0)
            *(rdx_1 + 0x10) = arg2;
        
        *(arg1 + (rax_4 << 3)) = arg2;
        *(arg1 + 0xd8) -= result;
        
        if (*(r12_1 + 0x20) <= 0)
        {
            if (*(r12_1 + 0x20) < 0)
                FPC_HANDLEERROR(0xcc);
            
            SYSTEM_$$_APPEND_TO_OSLIST$POSCHUNK(r12_1);
        }
    }
    
    return result;
}

int64_t SYSTEM_$$_SYSFREEMEM_VAR$PFREELISTS$PMEMCHUNK_VAR$$QWORD(void* arg1, int64_t* arg2)
{
    int64_t result = (arg2[2] & 0xffffffffffffffe0);
    
    if (arg1 != arg2[1])
    {
        SYSTEM_$$_WAITFREE_VAR$PMEMCHUNK_VAR(arg2);
        return result;
    }
    
    arg2[2] &= 0xfffffffffffffffd;
    void** rax_2 = (arg2[1] + 0xa8);
    arg2[4] = 0;
    arg2[3] = *rax_2;
    
    if (*rax_2 != 0)
        *(*rax_2 + 0x20) = arg2;
    
    *rax_2 = arg2;
    int64_t* rax_3 = SYSTEM_$$_TRY_CONCAT_FREE_CHUNK$PMEMCHUNK_VAR$$PMEMCHUNK_VAR(arg2);
    
    if ((rax_3[2] & 0xc) == 0xc)
        SYSTEM_$$_APPEND_TO_OSLIST_VAR$PMEMCHUNK_VAR(rax_3);
    
    *(arg1 + 0xd8) -= result;
    return result;
}

int64_t SYSTEM_$$_SYSFREEMEM$POINTER$$QWORD(void* arg1)
{
    if (arg1 == 0)
        return 0;
    
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    void* r13_1;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        r13_1 = &data_435948;
    else
        r13_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_FREELISTS);
    
    if ((*(arg1 - 8) & 1) != 0)
        return SYSTEM_$$_SYSFREEMEM_FIXED$PFREELISTS$PMEMCHUNK_FIXED$$QWORD(r13_1, (arg1 - 8));
    
    return SYSTEM_$$_SYSFREEMEM_VAR$PFREELISTS$PMEMCHUNK_VAR$$QWORD(r13_1, (arg1 - 0x18));
}

void SYSTEM_$$_FINISH_WAITFIXEDLIST$PFREELISTS(void* arg1)
{
    while (*(arg1 + 0xb0) != 0)
    {
        int64_t* r12_1 = *(arg1 + 0xb0);
        *(arg1 + 0xb0) = r12_1[1];
        SYSTEM_$$_SYSFREEMEM_FIXED$PFREELISTS$PMEMCHUNK_FIXED$$QWORD(arg1, r12_1);
    }
}

int64_t SYSTEM_$$_TRY_FINISH_WAITFIXEDLIST$PFREELISTS$$BOOLEAN(void* arg1)
{
    int64_t r12;
    
    if (*(arg1 + 0xb0) != 0)
    {
        SYSTEM_$$_ENTERCRITICALSECTION$TRTLCRITICALSECTION();
        SYSTEM_$$_FINISH_WAITFIXEDLIST$PFREELISTS(arg1);
        SYSTEM_$$_LEAVECRITICALSECTION$TRTLCRITICALSECTION();
        r12 = 1;
    }
    else
        r12 = 0;
    
    int64_t result;
    result = r12;
    return result;
}

void SYSTEM_$$_FINISH_WAITVARLIST$PFREELISTS(void* arg1)
{
    while (*(arg1 + 0xb8) != 0)
    {
        int64_t* r12_1 = *(arg1 + 0xb8);
        *(arg1 + 0xb8) = r12_1[3];
        SYSTEM_$$_SYSFREEMEM_VAR$PFREELISTS$PMEMCHUNK_VAR$$QWORD(arg1, r12_1);
    }
}

void SYSTEM_$$_TRY_FINISH_WAITVARLIST$PFREELISTS(void* arg1)
{
    if (*(arg1 + 0xb8) != 0)
    {
        SYSTEM_$$_ENTERCRITICALSECTION$TRTLCRITICALSECTION();
        SYSTEM_$$_FINISH_WAITVARLIST$PFREELISTS(arg1);
        SYSTEM_$$_LEAVECRITICALSECTION$TRTLCRITICALSECTION();
    }
}

int64_t SYSTEM_$$_SYSFREEMEMSIZE$POINTER$QWORD$$QWORD(void* arg1, int64_t arg2)
{
    if (arg2 != 0)
        return SYSTEM_$$_SYSFREEMEM$POINTER$$QWORD(arg1);
    
    return 0;
}

int64_t SYSTEM_$$_SYSMEMSIZE$POINTER$$QWORD(void* arg1)
{
    int64_t rax_4 = *(arg1 - 8);
    
    if ((rax_4 & 1) != 0)
        return ((rax_4 & 0xfe0) - 8);
    
    return ((rax_4 & 0xffffffffffffffe0) - 0x18);
}

void* SYSTEM_$$_SYSALLOCMEM$QWORD$$POINTER()
{
    uint64_t rdi;
    void* result = SYSTEM_$$_SYSGETMEM$QWORD$$POINTER(rdi);
    
    if (result != 0)
        SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(result, SYSTEM_$$_SYSMEMSIZE$POINTER$$QWORD(result), 0);
    
    return result;
}

void* SYSTEM_$$_SYSTRYRESIZEMEM$POINTER$QWORD$$BOOLEAN(int64_t* arg1, int64_t arg2)
{
    char var_38 = 0;
    int64_t rcx = *(*arg1 - 8);
    void* result;
    
    if ((rcx & 1) == 0)
    {
        if (arg2 >= 0x110)
        {
            void* rbx_1 = (rcx & 0xffffffffffffffe0);
            int64_t rax_5 = ((arg2 + 0x37) & 0xffffffffffffffe0);
            
            if ((rax_5 > rbx_1 || (rbx_1 - 0x20) >= rax_5))
            {
                uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
                void* rax_6;
                
                if (FPC_THREADVAR_RELOCATE_1 == 0)
                    rax_6 = &data_435948;
                else
                    rax_6 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_FREELISTS);
                
                result = (*arg1 - 0x18);
                
                if (rax_6 == *(result + 8))
                {
                    void* r14_1 = rbx_1;
                    
                    if (SYSTEM_$$_TRY_CONCAT_FREE_CHUNK_FORWARD$PMEMCHUNK_VAR$$BOOLEAN(result) != 0)
                        rbx_1 = (*(result + 0x10) & 0xffffffffffffffe0);
                    
                    if (rbx_1 >= rax_5)
                    {
                        if (rax_5 < rbx_1)
                            rbx_1 = SYSTEM_$$_SPLIT_BLOCK$PMEMCHUNK_VAR$QWORD$$QWORD(result, rax_5);
                        
                        *(rax_6 + 0xd8) += (rbx_1 - r14_1);
                        
                        if (*(rax_6 + 0xd8) > *(rax_6 + 0xc8))
                            *(rax_6 + 0xc8) = *(rax_6 + 0xd8);
                        
                        var_38 = 1;
                    }
                    else
                    {
                        *(rax_6 + 0xd8) += (rbx_1 - r14_1);
                        
                        if (*(rax_6 + 0xd8) > *(rax_6 + 0xc8))
                            *(rax_6 + 0xc8) = *(rax_6 + 0xd8);
                    }
                }
            }
            else
                var_38 = 1;
        }
        else
            var_38 = 0;
    }
    else if ((arg2 <= 0x218 && ((arg2 + 0x27) & 0xffffffffffffffe0) <= (rcx & 0xfe0)))
        var_38 = 1;
    
    result = var_38;
    return result;
}

int64_t SYSTEM_$$_SYSREALLOCMEM$POINTER$QWORD$$POINTER(int64_t* arg1, uint64_t arg2)
{
    if (arg2 != 0)
    {
        if (*arg1 != 0)
        {
            if (SYSTEM_$$_SYSTRYRESIZEMEM$POINTER$QWORD$$BOOLEAN(arg1, arg2) == 0)
            {
                uint64_t r13_1 = SYSTEM_$$_SYSMEMSIZE$POINTER$$QWORD(*arg1);
                uint64_t rdi_4;
                
                if (r13_1 >= 0x220)
                    rdi_4 = arg2;
                else
                {
                    rdi_4 = ((r13_1 << 1) + 0x20);
                    
                    if (rdi_4 < arg2)
                        rdi_4 = arg2;
                }
                
                if (r13_1 > rdi_4)
                    r13_1 = rdi_4;
                
                void* rax_6 = SYSTEM_$$_SYSGETMEM$QWORD$$POINTER(rdi_4);
                
                if (rax_6 != 0)
                    FPC_MOVE(*arg1, rax_6, r13_1);
                
                SYSTEM_$$_SYSFREEMEM$POINTER$$QWORD(*arg1);
                *arg1 = rax_6;
            }
        }
        else
            *arg1 = SYSTEM_$$_SYSGETMEM$QWORD$$POINTER(arg2);
    }
    else if (*arg1 != 0)
    {
        SYSTEM_$$_SYSFREEMEM$POINTER$$QWORD(*arg1);
        *arg1 = 0;
    }
    
    return *arg1;
}

uint64_t SYSTEM_$$_INITHEAPTHREAD()
{
    if (U_$SYSTEM_$$_HEAP_LOCK_USE > 0)
    {
        SYSTEM_$$_ENTERCRITICALSECTION$TRTLCRITICALSECTION();
        U_$SYSTEM_$$_HEAP_LOCK_USE += 1;
        SYSTEM_$$_LEAVECRITICALSECTION$TRTLCRITICALSECTION();
    }
    
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    char* rbx;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rbx = &data_435948;
    else
        rbx = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_FREELISTS);
    
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(rbx, 0xe8, 0);
    uint64_t TC_$SYSTEM_$$_GROWHEAPSIZESMALL_1 = TC_$SYSTEM_$$_GROWHEAPSIZESMALL;
    *(rbx + 0x98) = TC_$SYSTEM_$$_GROWHEAPSIZESMALL_1;
    return TC_$SYSTEM_$$_GROWHEAPSIZESMALL_1;
}

int64_t SYSTEM_$$_INITHEAP()
{
    U_$SYSTEM_$$_HEAP_LOCK_USE = 0;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    char* rbx;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rbx = &data_435948;
    else
        rbx = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_FREELISTS);
    
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(rbx, 0xe8, 0);
    *(rbx + 0x98) = TC_$SYSTEM_$$_GROWHEAPSIZESMALL;
    return SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(&U_$SYSTEM_$$_ORPHANED_FREELISTS, 0xe8, 0);
}

void SYSTEM_$$_RELOCATEHEAP()
{
    if (U_$SYSTEM_$$_HEAP_LOCK_USE <= 0)
    {
        U_$SYSTEM_$$_HEAP_LOCK_USE = 1;
        SYSTEM_$$_INITCRITICALSECTION$TRTLCRITICALSECTION();
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        void* rdi_3;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rdi_3 = &data_435948;
        else
            rdi_3 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_FREELISTS);
        
        SYSTEM_$$_MODIFY_FREELISTS$PFREELISTS$PFREELISTS$$POSCHUNK(rdi_3, rdi_3);
        
        if (data_428188 != 0)
            data_428188();
    }
}

uint16_t* SYSTEM_$$_FINALIZEHEAP()
{
    uint16_t* FPC_THREADVAR_RELOCATE_1;
    FPC_THREADVAR_RELOCATE_1 = TC_$SYSTEM_$$_ERRORCODE;
    
    if ((FPC_THREADVAR_RELOCATE_1 != 0xcb && FPC_THREADVAR_RELOCATE_1 != 0xcc))
    {
        FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        uint16_t* FPC_THREADVAR_RELOCATE_2;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            FPC_THREADVAR_RELOCATE_2 = &data_435948;
        else
        {
            FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_FREELISTS);
            FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE_1;
        }
        
        if (U_$SYSTEM_$$_HEAP_LOCK_USE > 0)
        {
            SYSTEM_$$_ENTERCRITICALSECTION$TRTLCRITICALSECTION();
            SYSTEM_$$_FINISH_WAITFIXEDLIST$PFREELISTS(FPC_THREADVAR_RELOCATE_2);
            FPC_THREADVAR_RELOCATE_1 = SYSTEM_$$_FINISH_WAITVARLIST$PFREELISTS(FPC_THREADVAR_RELOCATE_2);
        }
        
        int64_t* i_1;
        
        for (int64_t* i = *FPC_THREADVAR_RELOCATE_2; i != 0; i = i_1)
        {
            i_1 = i[1];
            FPC_THREADVAR_RELOCATE_1 = (*i & 1);
            
            if (FPC_THREADVAR_RELOCATE_1 != 0)
                *i &= 0xfffffffffffffffe;
            else
                FPC_THREADVAR_RELOCATE_1 = SYSTEM_$$_FREE_OSCHUNK$PFREELISTS$POSCHUNK(FPC_THREADVAR_RELOCATE_2, i);
        }
        
        *FPC_THREADVAR_RELOCATE_2 = 0;
        *(FPC_THREADVAR_RELOCATE_2 + 0x90) = 0;
        
        if (U_$SYSTEM_$$_HEAP_LOCK_USE > 0)
        {
            void* rax_1 = SYSTEM_$$_MODIFY_FREELISTS$PFREELISTS$PFREELISTS$$POSCHUNK(FPC_THREADVAR_RELOCATE_2, &U_$SYSTEM_$$_ORPHANED_FREELISTS);
            
            if (rax_1 != 0)
            {
                *(rax_1 + 0x18) = data_4358b0;
                
                if (data_4358b0 != 0)
                    *(data_4358b0 + 0x10) = rax_1;
                
                data_4358b0 = *(FPC_THREADVAR_RELOCATE_2 + 0xa0);
            }
            
            U_$SYSTEM_$$_HEAP_LOCK_USE -= 1;
            FPC_THREADVAR_RELOCATE_2 = U_$SYSTEM_$$_HEAP_LOCK_USE == 0;
            FPC_THREADVAR_RELOCATE_1 = SYSTEM_$$_LEAVECRITICALSECTION$TRTLCRITICALSECTION();
            
            if (FPC_THREADVAR_RELOCATE_2 != 0)
                return SYSTEM_$$_DONECRITICALSECTION$TRTLCRITICALSECTION();
        }
    }
    
    return FPC_THREADVAR_RELOCATE_1;
}

int64_t SYSTEM_$$_GETCPUCOUNT$$LONGWORD() __pure
{
    return 1;
}

int64_t* SYSTEM_$$_INITTHREAD$QWORD(int64_t arg1)
{
    SYSTEM_$$_SYSRESETFPU();
    SYSTEM_$$_INITHEAPTHREAD();
    
    if (data_434b58 != 0)
        data_434b58();
    
    SYSTEM_$$_SYSINITEXCEPTIONS();
    SYSTEM_$$_SYSINITSTDIO();
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434a78;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    *rax = 0;
    int64_t rax_1 = SYSTEM_$$_CHECKINITIALSTKLEN$QWORD$$QWORD(arg1);
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int64_t* rax_2;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        rax_2 = &data_434a98;
    else
        rax_2 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_STACKLENGTH);
    
    *rax_2 = rax_1;
    int64_t rax_3 = SYSTEM_$$_SPTR$$POINTER();
    uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
    int64_t* rax_4;
    
    if (FPC_THREADVAR_RELOCATE_3 == 0)
        rax_4 = &data_434a98;
    else
        rax_4 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_STACKLENGTH);
    
    int64_t rbx_3 = (rax_3 - *rax_4);
    uint64_t FPC_THREADVAR_RELOCATE_4 = FPC_THREADVAR_RELOCATE;
    int64_t* rax_5;
    
    if (FPC_THREADVAR_RELOCATE_4 == 0)
        rax_5 = &data_434a88;
    else
        rax_5 = FPC_THREADVAR_RELOCATE_4(U_$SYSTEM_$$_STACKBOTTOM);
    
    *rax_5 = rbx_3;
    int64_t rax_6 = data_435a90();
    uint64_t FPC_THREADVAR_RELOCATE_5 = FPC_THREADVAR_RELOCATE;
    int64_t* result;
    
    if (FPC_THREADVAR_RELOCATE_5 == 0)
        result = &data_4338e8;
    else
        result = FPC_THREADVAR_RELOCATE_5(U_$SYSTEM_$$_THREADID);
    
    *result = rax_6;
    return result;
}

int64_t* SYSTEM_$$_DONETHREAD()
{
    if (data_434b60 != 0)
        data_434b60();
    
    SYSTEM_$$_FINALIZEHEAP();
    
    if (data_428180 != 0)
        data_428180();
    
    SYSTEM_$$_SYSFLUSHSTDIO();
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_4338e8;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_THREADID);
    
    *result = 0;
    
    if (data_435ae8 == 0)
        return result;
    
    return data_435ae8();
}

int64_t SYSTEM_$$_BEGINTHREAD$TTHREADFUNC$$QWORD()
{
    return SYSTEM_$$_BEGINTHREAD$POINTER$QWORD$TTHREADFUNC$POINTER$LONGWORD$QWORD$$QWORD();
}

int64_t SYSTEM_$$_BEGINTHREAD$TTHREADFUNC$POINTER$$QWORD()
{
    return SYSTEM_$$_BEGINTHREAD$POINTER$QWORD$TTHREADFUNC$POINTER$LONGWORD$QWORD$$QWORD();
}

int64_t SYSTEM_$$_BEGINTHREAD$TTHREADFUNC$POINTER$QWORD$$QWORD()
{
    return SYSTEM_$$_BEGINTHREAD$POINTER$QWORD$TTHREADFUNC$POINTER$LONGWORD$QWORD$$QWORD();
}

int64_t SYSTEM_$$_BEGINTHREAD$TTHREADFUNC$POINTER$QWORD$QWORD$$QWORD()
{
    return SYSTEM_$$_BEGINTHREAD$POINTER$QWORD$TTHREADFUNC$POINTER$LONGWORD$QWORD$$QWORD();
}

int64_t SYSTEM_$$_ENDTHREAD()
{
    return SYSTEM_$$_ENDTHREAD$LONGWORD();
}

int64_t SYSTEM_$$_BEGINTHREAD$POINTER$QWORD$TTHREADFUNC$POINTER$LONGWORD$QWORD$$QWORD()
{
    return data_435a40();
}

int16_t* SYSTEM_$$_FLUSHTHREAD()
{
    return SYSTEM_$$_SYSFLUSHSTDIO();
}

int64_t SYSTEM_$$_ENDTHREAD$LONGWORD()
{
    return data_435a48();
}

int64_t SYSTEM_$$_SUSPENDTHREAD$QWORD$$LONGWORD()
{
    return data_435a50();
}

int64_t SYSTEM_$$_RESUMETHREAD$QWORD$$LONGWORD()
{
    return data_435a58();
}

int64_t SYSTEM_$$_CLOSETHREAD$QWORD$$LONGWORD()
{
    return data_435a68();
}

int64_t SYSTEM_$$_THREADSWITCH()
{
    return data_435a70();
}

int64_t SYSTEM_$$_KILLTHREAD$QWORD$$LONGWORD()
{
    return data_435a60();
}

int64_t SYSTEM_$$_WAITFORTHREADTERMINATE$QWORD$LONGINT$$LONGWORD()
{
    return data_435a78();
}

int64_t SYSTEM_$$_THREADSETPRIORITY$QWORD$LONGINT$$BOOLEAN()
{
    return data_435a80();
}

int64_t SYSTEM_$$_THREADGETPRIORITY$QWORD$$LONGINT()
{
    return data_435a88();
}

int64_t SYSTEM_$$_GETCURRENTTHREADID$$QWORD()
{
    return data_435a90();
}

int64_t SYSTEM_$$_SETTHREADDEBUGNAME$QWORD$ANSISTRING()
{
    return data_435a98();
}

int64_t SYSTEM_$$_SETTHREADDEBUGNAME$QWORD$UNICODESTRING()
{
    return data_435aa0();
}

int64_t SYSTEM_$$_INITCRITICALSECTION$TRTLCRITICALSECTION()
{
    return data_435aa8();
}

int64_t SYSTEM_$$_DONECRITICALSECTION$TRTLCRITICALSECTION()
{
    return data_435ab0();
}

int64_t SYSTEM_$$_ENTERCRITICALSECTION$TRTLCRITICALSECTION()
{
    return data_435ab8();
}

int64_t SYSTEM_$$_TRYENTERCRITICALSECTION$TRTLCRITICALSECTION$$LONGINT()
{
    return data_435ac0();
}

int64_t SYSTEM_$$_LEAVECRITICALSECTION$TRTLCRITICALSECTION()
{
    return data_435ac8();
}

int64_t SYSTEM_$$_GETTHREADMANAGER$TTHREADMANAGER$$BOOLEAN()
{
    int64_t rdi;
    __builtin_memcpy(rdi, &U_$SYSTEM_$$_CURRENTTM, 0x23);
    int64_t result;
    result = 1;
    return result;
}

int64_t SYSTEM_$$_SETTHREADMANAGER$TTHREADMANAGER$TTHREADMANAGER$$BOOLEAN(int64_t arg1)
{
    SYSTEM_$$_GETTHREADMANAGER$TTHREADMANAGER$$BOOLEAN();
    return SYSTEM_$$_SETTHREADMANAGER$TTHREADMANAGER$$BOOLEAN(arg1);
}

int64_t SYSTEM_$$_SETTHREADMANAGER$TTHREADMANAGER$$BOOLEAN(int64_t arg1)
{
    int64_t r12;
    r12 = 1;
    
    if (data_435a38 != 0)
        r12 = data_435a38();
    
    if (r12 != 0)
    {
        int64_t rsi_2;
        int64_t rdi;
        rdi = __builtin_memcpy(&U_$SYSTEM_$$_CURRENTTM, arg1, 0x23);
        
        if (U_$SYSTEM_$$_CURRENTTM != 0)
            r12 = U_$SYSTEM_$$_CURRENTTM(rdi, rsi_2);
    }
    
    return r12;
}

int64_t SYSTEM_$$_BASICEVENTCREATE$POINTER$BOOLEAN$BOOLEAN$ANSISTRING$$POINTER()
{
    return data_435af0();
}

int64_t SYSTEM_$$_BASICEVENTDESTROY$POINTER()
{
    return data_435af8();
}

int64_t SYSTEM_$$_BASICEVENTRESETEVENT$POINTER()
{
    return data_435b00();
}

int64_t SYSTEM_$$_BASICEVENTSETEVENT$POINTER()
{
    return data_435b08();
}

int64_t SYSTEM_$$_BASICEVENTWAITFOR$LONGWORD$POINTER$$LONGINT()
{
    return data_435b10();
}

int64_t SYSTEM_$$_RTLEVENTCREATE$$PRTLEVENT()
{
    return data_435b18();
}

int64_t SYSTEM_$$_RTLEVENTDESTROY$PRTLEVENT()
{
    return data_435b20();
}

int64_t SYSTEM_$$_RTLEVENTSETEVENT$PRTLEVENT()
{
    return data_435b28();
}

int64_t SYSTEM_$$_RTLEVENTRESETEVENT$PRTLEVENT()
{
    return data_435b30();
}

int64_t SYSTEM_$$_RTLEVENTWAITFOR$PRTLEVENT()
{
    return data_435b38();
}

int64_t SYSTEM_$$_RTLEVENTWAITFOR$PRTLEVENT$LONGINT()
{
    return data_435b40();
}

int64_t SYSTEM_$$_NOTHREADERROR()
{
    if (operatingsystem_isconsole != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        void* rsi_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rsi_1 = &data_4346f8;
        else
            rsi_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_STDERR);
        
        FPC_WRITE_TEXT_SHORTSTR(0, rsi_1, ".This binary has no thread suppo…");
        uint64_t FPC_THREADVAR_RELOCATE_4 = FPC_THREADVAR_RELOCATE;
        void* rdi_3;
        
        if (FPC_THREADVAR_RELOCATE_4 == 0)
            rdi_3 = &data_4346f8;
        else
            rdi_3 = FPC_THREADVAR_RELOCATE_4(U_$SYSTEM_$$_STDERR);
        
        fpc_writeln_end(rdi_3);
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        void* rsi_2;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            rsi_2 = &data_4346f8;
        else
            rsi_2 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_STDERR);
        
        FPC_WRITE_TEXT_SHORTSTR(0, rsi_2, "jRecompile the application with …");
        uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
        void* rdi_6;
        
        if (FPC_THREADVAR_RELOCATE_3 == 0)
            rdi_6 = &data_4346f8;
        else
            rdi_6 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_STDERR);
        
        fpc_writeln_end(rdi_6);
    }
    
    return FPC_RUNERROR(0xe8);
}

int64_t SYSTEM_$$_NOBEGINTHREAD$POINTER$QWORD$TTHREADFUNC$POINTER$LONGWORD$QWORD$$QWORD()
{
    SYSTEM_$$_NOTHREADERROR();
    return -1;
}

int64_t SYSTEM_$$_NOENDTHREAD$LONGWORD(int32_t arg1)
{
    return SYSTEM_$$_NOTHREADERROR();
}

int64_t SYSTEM_$$_NOTHREADHANDLER$QWORD$$LONGWORD()
{
    SYSTEM_$$_NOTHREADERROR();
    return 0xffffffff;
}

int64_t SYSTEM_$$_NOWAITFORTHREADTERMINATE$QWORD$LONGINT$$LONGWORD()
{
    SYSTEM_$$_NOTHREADERROR();
    return 0xffffffff;
}

int64_t SYSTEM_$$_NOTHREADSETPRIORITY$QWORD$LONGINT$$BOOLEAN()
{
    SYSTEM_$$_NOTHREADERROR();
    int64_t result;
    result = 0;
    return result;
}

int64_t SYSTEM_$$_NOTHREADGETPRIORITY$QWORD$$LONGINT()
{
    SYSTEM_$$_NOTHREADERROR();
    return 0xffffffff;
}

int64_t SYSTEM_$$_NOGETCURRENTTHREADID$$QWORD()
{
    if (TC_$SYSTEM_$$_ISMULTITHREAD == 0)
        TC_$SYSTEM_$$_THREADINGALREADYUSED = 1;
    else
        SYSTEM_$$_NOTHREADERROR();
    
    return 1;
}

int64_t SYSTEM_$$_NOSETTHREADDEBUGNAMEA$QWORD$ANSISTRING()
{
    return SYSTEM_$$_NOTHREADERROR();
}

int64_t SYSTEM_$$_NOSETTHREADDEBUGNAMEU$QWORD$UNICODESTRING()
{
    return SYSTEM_$$_NOTHREADERROR();
}

void SYSTEM_$$_NOCRITICALSECTION$formal()
{
    if (TC_$SYSTEM_$$_ISMULTITHREAD == 0)
        TC_$SYSTEM_$$_THREADINGALREADYUSED = 1;
    else
        SYSTEM_$$_NOTHREADERROR();
}

int64_t SYSTEM_$$_NOTRYENTERCRITICALSECTION$formal$$LONGINT()
{
    if (TC_$SYSTEM_$$_ISMULTITHREAD == 0)
        TC_$SYSTEM_$$_THREADINGALREADYUSED = 1;
    else
        SYSTEM_$$_NOTHREADERROR();
    
    return 0xffffffff;
}

int64_t SYSTEM_$$_NOINITTHREADVAR$LONGWORD$LONGWORD()
{
    return SYSTEM_$$_NOTHREADERROR();
}

int64_t SYSTEM_$$_NORELOCATETHREADVAR$LONGWORD$$POINTER()
{
    SYSTEM_$$_NOTHREADERROR();
    return 0;
}

int64_t SYSTEM_$$_NOBASICEVENTCREATE$POINTER$BOOLEAN$BOOLEAN$ANSISTRING$$POINTER()
{
    if (TC_$SYSTEM_$$_ISMULTITHREAD == 0)
        TC_$SYSTEM_$$_THREADINGALREADYUSED = 1;
    else
        SYSTEM_$$_NOTHREADERROR();
    
    return 0;
}

void SYSTEM_$$_NOBASICEVENT$POINTER()
{
    if (TC_$SYSTEM_$$_ISMULTITHREAD == 0)
        TC_$SYSTEM_$$_THREADINGALREADYUSED = 1;
    else
        SYSTEM_$$_NOTHREADERROR();
}

int64_t SYSTEM_$$_NOBASICEVENTWAITFOR$LONGWORD$POINTER$$LONGINT()
{
    if (TC_$SYSTEM_$$_ISMULTITHREAD == 0)
        TC_$SYSTEM_$$_THREADINGALREADYUSED = 1;
    else
        SYSTEM_$$_NOTHREADERROR();
    
    return 0xffffffff;
}

int64_t SYSTEM_$$_NORTLEVENTCREATE$$PRTLEVENT()
{
    if (TC_$SYSTEM_$$_ISMULTITHREAD == 0)
        TC_$SYSTEM_$$_THREADINGALREADYUSED = 1;
    else
        SYSTEM_$$_NOTHREADERROR();
    
    return 0;
}

void SYSTEM_$$_NORTLEVENT$PRTLEVENT()
{
    if (TC_$SYSTEM_$$_ISMULTITHREAD == 0)
        TC_$SYSTEM_$$_THREADINGALREADYUSED = 1;
    else
        SYSTEM_$$_NOTHREADERROR();
}

void SYSTEM_$$_NORTLEVENTWAITFORTIMEOUT$PRTLEVENT$LONGINT()
{
    if (TC_$SYSTEM_$$_ISMULTITHREAD == 0)
        TC_$SYSTEM_$$_THREADINGALREADYUSED = 1;
    else
        SYSTEM_$$_NOTHREADERROR();
}

int64_t SYSTEM_$$_SETNOTHREADMANAGER()
{
    return SYSTEM_$$_SETTHREADMANAGER$TTHREADMANAGER$$BOOLEAN(&TC_$SYSTEM_$$_NOTHREADMANAGER);
}

int64_t SYSTEM_$$_INITSYSTEMTHREADS()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax;
    int64_t rsi;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_4338e8;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_THREADID, rsi, &U_$SYSTEM_$$_THREADID);
    *rax = 1;
    return SYSTEM_$$_SETNOTHREADMANAGER();
}

void SYSTEM_$$_INIT_UNIT_THREADVARS$PLTVINITENTRY(int64_t* arg1)
{
    int64_t* rbx = arg1;
    
    while (*rbx != 0)
    {
        data_435ad0(*rbx, rbx[1]);
        rbx += 0xc;
    }
}

void SYSTEM_$$_INIT_ALL_UNIT_THREADVARS()
{
    int32_t* rbx = data_434c08;
    int32_t r13 = *rbx;
    
    if (r13 >= 1)
    {
        int32_t r12_1 = 0;
        
        do
        {
            r12_1 += 1;
            SYSTEM_$$_INIT_UNIT_THREADVARS$PLTVINITENTRY(**((rbx + (r12_1 << 3)) - 4));
        } while (r13 > r12_1);
    }
}

void SYSTEM_$$_COPY_UNIT_THREADVARS$PLTVINITENTRY(int64_t* arg1)
{
    int64_t* rbx = arg1;
    
    while (*rbx != 0)
    {
        char* rsi = data_435ad8(**rbx, rsi);
        FPC_MOVE((*rbx + 8), rsi, rbx[1]);
        rbx += 0xc;
    }
}

void SYSTEM_$$_COPY_ALL_UNIT_THREADVARS()
{
    int32_t* rbx = data_434c08;
    int32_t r13 = *rbx;
    
    if (r13 >= 1)
    {
        int32_t r12_1 = 0;
        
        do
        {
            r12_1 += 1;
            SYSTEM_$$_COPY_UNIT_THREADVARS$PLTVINITENTRY(**((rbx + (r12_1 << 3)) - 4));
        } while (r13 > r12_1);
    }
}

int64_t SYSTEM_$$_INITTHREADVARS$TRELOCATETHREADVARHANDLER(uint64_t arg1)
{
    SYSTEM_$$_INIT_ALL_UNIT_THREADVARS();
    data_435ae0();
    SYSTEM_$$_COPY_ALL_UNIT_THREADVARS();
    FPC_THREADVAR_RELOCATE = arg1;
    return SYSTEM_$$_RELOCATEHEAP();
}

int64_t SYSTEM_$$_DOSAFELOADLIBRARY$RAWBYTESTRING$$INT64(int64_t arg1)
{
    void var_60;
    void var_48;
    int64_t rbx;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_48, &var_60), rbx, rbp, r12, r13, r14, r15);
    int64_t var_8 = 0;
    int16_t x87control;
    uint16_t var_68 = SYSTEM_$$_GET8087CW$$WORD(x87control);
    int32_t mxcsr;
    uint32_t var_64 = SYSTEM_$$_GETMXCSR$$LONGWORD(mxcsr);
    int64_t result = data_435b68(arg1);
    FPC_POPADDRSTACK();
    SYSTEM_$$_SET8087CW$WORD(var_68);
    SYSTEM_$$_SETMXCSR$LONGWORD(var_64);
    
    if (var_8 != 0)
        FPC_RERAISE();
    
    return result;
}

int64_t SYSTEM_$$_LOADLIBRARY$RAWBYTESTRING$$INT64()
{
    return data_435b68();
}

int64_t SYSTEM_$$_LOADLIBRARY$UNICODESTRING$$INT64()
{
    return U_$SYSTEM_$$_CURRENTDLM();
}

int64_t SYSTEM_$$_SAFELOADLIBRARY$RAWBYTESTRING$$INT64(int64_t arg1)
{
    return SYSTEM_$$_DOSAFELOADLIBRARY$RAWBYTESTRING$$INT64(arg1);
}

uint16_t* SYSTEM_$$_SAFELOADLIBRARY$UNICODESTRING$$INT64(uint16_t* arg1)
{
    int64_t var_18 = 0;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t var_20 = 0;
    SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$UNICODESTRING$$RAWBYTESTRING(&var_18, arg1);
    uint16_t* result = SYSTEM_$$_DOSAFELOADLIBRARY$RAWBYTESTRING$$INT64(var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (var_20 != 0)
        FPC_RERAISE();
    
    return result;
}

int64_t SYSTEM_$$_GETPROCEDUREADDRESS$INT64$ANSISTRING$$POINTER()
{
    return data_435b70();
}

int64_t SYSTEM_$$_GETPROCEDUREADDRESS$INT64$QWORD$$POINTER()
{
    if (data_435b78 == 0)
        return 0;
    
    return data_435b78();
}

int64_t SYSTEM_$$_UNLOADLIBRARY$INT64$$BOOLEAN()
{
    return data_435b80();
}

int64_t SYSTEM_$$_GETLOADERRORSTR$$SHORTSTRING()
{
    return data_435b88();
}

int64_t SYSTEM_$$_FREELIBRARY$INT64$$BOOLEAN()
{
    return SYSTEM_$$_UNLOADLIBRARY$INT64$$BOOLEAN();
}

int64_t SYSTEM_$$_GETPROCADDRESS$INT64$ANSISTRING$$POINTER()
{
    return SYSTEM_$$_GETPROCEDUREADDRESS$INT64$ANSISTRING$$POINTER();
}

int64_t SYSTEM_$$_GETDYNLIBSMANAGER$TDYNLIBSMANAGER()
{
    int64_t rdi;
    __builtin_memcpy(rdi, &U_$SYSTEM_$$_CURRENTDLM, 6);
}

int64_t SYSTEM_$$_SETDYNLIBSMANAGER$TDYNLIBSMANAGER(int64_t arg1)
{
    __builtin_memcpy(&U_$SYSTEM_$$_CURRENTDLM, arg1, 6);
    return arg1;
}

int64_t SYSTEM_$$_SETDYNLIBSMANAGER$TDYNLIBSMANAGER$TDYNLIBSMANAGER(int64_t arg1, int64_t arg2)
{
    __builtin_memcpy(arg2, &U_$SYSTEM_$$_CURRENTDLM, 6);
    __builtin_memcpy(&U_$SYSTEM_$$_CURRENTDLM, arg1, 6);
    return arg1;
}

int64_t SYSTEM_$$_NODYNLIBSERROR()
{
    if (operatingsystem_isconsole != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        void* rsi_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rsi_1 = &data_4346f8;
        else
            rsi_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_STDERR);
        
        FPC_WRITE_TEXT_SHORTSTR(0, rsi_1, "7This binary has no dynamic libr…");
        uint64_t FPC_THREADVAR_RELOCATE_4 = FPC_THREADVAR_RELOCATE;
        void* rdi_3;
        
        if (FPC_THREADVAR_RELOCATE_4 == 0)
            rdi_3 = &data_4346f8;
        else
            rdi_3 = FPC_THREADVAR_RELOCATE_4(U_$SYSTEM_$$_STDERR);
        
        fpc_writeln_end(rdi_3);
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        void* rsi_2;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            rsi_2 = &data_4346f8;
        else
            rsi_2 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_STDERR);
        
        FPC_WRITE_TEXT_SHORTSTR(0, rsi_2, "~Recompile the application with …");
        uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
        void* rdi_6;
        
        if (FPC_THREADVAR_RELOCATE_3 == 0)
            rdi_6 = &data_4346f8;
        else
            rdi_6 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_STDERR);
        
        fpc_writeln_end(rdi_6);
    }
    
    return FPC_RUNERROR(0xeb);
}

int64_t SYSTEM_$$_NOLOADLIBRARYU$UNICODESTRING$$INT64()
{
    return SYSTEM_$$_NODYNLIBSERROR();
}

int64_t SYSTEM_$$_NOLOADLIBRARYA$RAWBYTESTRING$$INT64()
{
    return SYSTEM_$$_NODYNLIBSERROR();
}

int64_t SYSTEM_$$_NOGETPROCADDRESS$INT64$ANSISTRING$$POINTER()
{
    return SYSTEM_$$_NODYNLIBSERROR();
}

int64_t SYSTEM_$$_NOGETPROCADDRESSORDINAL$INT64$QWORD$$POINTER()
{
    return SYSTEM_$$_NODYNLIBSERROR();
}

int64_t SYSTEM_$$_NOGETLOADERRORSTR$$SHORTSTRING()
{
    return SYSTEM_$$_NODYNLIBSERROR();
}

int64_t SYSTEM_$$_NOUNLOADLIBRARY$INT64$$BOOLEAN()
{
    return SYSTEM_$$_NODYNLIBSERROR();
}

int64_t SYSTEM_$$_SETNODYNLIBSMANAGER()
{
    return SYSTEM_$$_SETDYNLIBSMANAGER$TDYNLIBSMANAGER(&TC_$SYSTEM_$$_NODYNLIBSMANAGER);
}

int64_t SYSTEM_$$_INITSYSTEMDYNLIBS()
{
    return SYSTEM_$$_SETNODYNLIBSMANAGER();
}

void* SYSTEM_$$_DODIRSEPARATORS$PCHAR$BOOLEAN(int64_t* arg1, char arg2)
{
    int64_t r15;
    r15 = arg2;
    void* result = FPC_PCHAR_LENGTH(*arg1);
    void* result_1 = result;
    char* var_38 = nullptr;
    int32_t r12 = result_1;
    
    if (r12 >= 0)
    {
        int32_t result_2 = -1;
        
        do
        {
            result_2 += 1;
            result = result_2;
            
            if ((TEST_BITD(TC_$SYSTEM_$$_ALLOWDIRECTORYSEPARATORS, *(*arg1 + result))))
            {
                if ((r15 == 0 && var_38 == 0))
                {
                    SYSTEM_$$_GETMEM$POINTER$QWORD(&var_38, (result_1 + 1));
                    FPC_MOVE(*arg1, var_38, (result_1 + 1));
                    *arg1 = var_38;
                }
                
                result = result_2;
                *(*arg1 + result) = 0x2f;
            }
        } while (r12 > result_2);
    }
    
    return result;
}

int64_t SYSTEM_$$_DODIRSEPARATORS$PWIDECHAR$BOOLEAN(int64_t* arg1, char arg2)
{
    int64_t r15;
    r15 = arg2;
    int64_t result = FPC_PWIDECHAR_LENGTH(*arg1);
    int64_t result_1 = result;
    char* var_38 = nullptr;
    int32_t r12 = result_1;
    
    if (r12 >= 0)
    {
        int32_t result_2 = -1;
        
        do
        {
            result_2 += 1;
            result = *(*arg1 + (result_2 << 1));
            
            if (result < 0xff)
            {
                result = (result & 0xff);
                
                if ((TEST_BITD(TC_$SYSTEM_$$_ALLOWDIRECTORYSEPARATORS, result)))
                {
                    if ((r15 == 0 && var_38 == 0))
                    {
                        SYSTEM_$$_GETMEM$POINTER$QWORD(&var_38, ((result_1 + 1) << 1));
                        FPC_MOVE(*arg1, var_38, ((result_1 + 1) << 1));
                        *arg1 = var_38;
                    }
                    
                    result = result_2;
                    *(*arg1 + (result << 1)) = 0x2f;
                }
            }
        } while (r12 > result_2);
    }
    
    return result;
}

uint32_t SYSTEM_$$_DODIRSEPARATORS$OPENSTRING(char* arg1)
{
    uint32_t result = *arg1;
    
    if (result >= 1)
    {
        int32_t rdx_1 = 0;
        
        do
        {
            rdx_1 += 1;
            
            if ((TEST_BITD(TC_$SYSTEM_$$_ALLOWDIRECTORYSEPARATORS, arg1[rdx_1])))
                arg1[rdx_1] = 0x2f;
        } while (result > rdx_1);
    }
    
    return result;
}

int64_t SYSTEM_$$_DODIRSEPARATORS$RAWBYTESTRING(int64_t* arg1, uint16_t* arg2 @ r13)
{
    uint16_t* var_18 = arg2;
    int64_t r15;
    r15 = 0;
    int64_t result = *arg1;
    
    if (result != 0)
        result = *(result - 8);
    
    int32_t rbx = result;
    
    if (rbx >= 1)
    {
        int32_t result_1 = 0;
        
        do
        {
            result_1 += 1;
            result = *((*arg1 + result_1) - 1);
            
            if ((TEST_BITD(TC_$SYSTEM_$$_ALLOWDIRECTORYSEPARATORS, result)))
            {
                if (r15 == 0)
                {
                    FPC_ANSISTR_UNIQUE(arg1);
                    uint16_t* rax_1 = *arg1;
                    
                    if (rax_1 == 0)
                        rax_1 = &FPC_EMPTYCHAR;
                    
                    arg2 = rax_1;
                    r15 = 1;
                }
                
                result = result_1;
                *((arg2 + result) - 1) = 0x2f;
            }
        } while (rbx > result_1);
    }
    
    return result;
}

int64_t SYSTEM_$$_DODIRSEPARATORS$UNICODESTRING(int64_t* arg1, uint16_t* arg2 @ r13)
{
    uint16_t* var_18 = arg2;
    int64_t r15;
    r15 = 0;
    int64_t result = *arg1;
    
    if (result != 0)
        result = *(result - 8);
    
    uint64_t rbx = result;
    
    if (rbx >= 1)
    {
        int32_t i = 0;
        
        do
        {
            i += 1;
            result = fpc_uchar_to_char(*((*arg1 + (i << 1)) - 2), rbx);
            
            if ((TEST_BITD(TC_$SYSTEM_$$_ALLOWDIRECTORYSEPARATORS, result)))
            {
                if (r15 == 0)
                {
                    FPC_UNICODESTR_UNIQUE(arg1);
                    uint16_t* rax_2 = *arg1;
                    
                    if (rax_2 == 0)
                        rax_2 = &FPC_EMPTYCHAR;
                    
                    arg2 = rax_2;
                    r15 = 1;
                }
                
                result = i;
                arg2[(result - 1)] = 0x2f;
            }
        } while (rbx > i);
    }
    
    return result;
}

int64_t SYSTEM_$$_DO_CLOSE$LONGINT(int32_t arg1)
{
    int32_t i;
    int32_t i_1;
    
    do
    {
        i = FPC_SYSC_CLOSE(arg1);
        i_1 = i;
        
        if (i_1 != 0xffffffff)
            break;
        
        i = FPC_SYS_GETERRNO();
    } while (i == 4);
    
    if (i_1 == 0)
        return i;
    
    return SYSTEM_$$_ERRNO2INOUTRES$$WORD();
}

uint64_t SYSTEM_$$_DO_ERASE$PCHAR$BOOLEAN(int64_t arg1)
{
    void var_98;
    
    if (FPC_SYSC_STAT(arg1, &var_98) < 0)
        return SYSTEM_$$_ERRNO2INOUTRES$$WORD();
    
    int32_t var_80;
    uint64_t result;
    
    if (SYSTEM_$$_FPS_ISDIR$LONGINT$$BOOLEAN(var_80) == 0)
    {
        if (FPC_SYSC_UNLINK(arg1) < 0)
            return SYSTEM_$$_ERRNO2INOUTRES$$WORD();
        
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
        
        *result = 0;
    }
    else
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *result = 2;
    }
    
    return result;
}

uint64_t SYSTEM_$$_DO_TRUNCATE$LONGINT$INT64()
{
    int64_t rsi;
    int32_t rdi;
    
    if (FPC_SYSC_FTRUNCATE(rdi, rsi) < 0)
        return SYSTEM_$$_ERRNO2INOUTRES$$WORD();
    
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    uint64_t result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    *result = 0;
    return result;
}

uint64_t SYSTEM_$$_DO_RENAME$PCHAR$PCHAR$BOOLEAN$BOOLEAN()
{
    int64_t rsi;
    int64_t rdi;
    
    if (FPC_SYSC_RENAME(rdi, rsi) < 0)
        return SYSTEM_$$_ERRNO2INOUTRES$$WORD();
    
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    uint64_t result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    *result = 0;
    return result;
}

uint64_t SYSTEM_$$_DO_WRITE$LONGINT$POINTER$LONGINT$$LONGINT(int32_t arg1, int64_t arg2, int32_t arg3)
{
    int32_t r15_1;
    
    while (true)
    {
        r15_1 = FPC_SYSC_WRITE(arg1, arg2, arg3);
        int32_t rax_2 = FPC_SYS_GETERRNO();
        
        if (r15_1 != 0xffffffff)
            break;
        
        if (rax_2 != 4)
        {
            if (rax_2 != 0xb)
                break;
        }
    }
    
    if (r15_1 >= 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_3;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_3 = &data_434a78;
        else
            rax_3 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *rax_3 = 0;
    }
    else
    {
        SYSTEM_$$_ERRNO2INOUTRES$$WORD();
        r15_1 = 0;
    }
    
    return r15_1;
}

uint64_t SYSTEM_$$_DO_READ$LONGINT$POINTER$LONGINT$$LONGINT(int32_t arg1, int64_t arg2, int32_t arg3)
{
    int32_t r15_1;
    
    while (true)
    {
        r15_1 = FPC_SYSC_READ(arg1, arg2, arg3);
        int32_t rax_2 = FPC_SYS_GETERRNO();
        
        if (r15_1 != 0xffffffff)
            break;
        
        if (rax_2 != 4)
        {
            if (rax_2 != 0xb)
                break;
        }
    }
    
    if (r15_1 >= 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_3;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_3 = &data_434a78;
        else
            rax_3 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *rax_3 = 0;
    }
    else
    {
        SYSTEM_$$_ERRNO2INOUTRES$$WORD();
        r15_1 = 0;
    }
    
    return r15_1;
}

int64_t SYSTEM_$$_DO_FILEPOS$LONGINT$$INT64()
{
    int32_t rdi;
    int64_t result = FPC_SYSC_LSEEK(rdi, 0, 1);
    
    if (result >= 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax = &data_434a78;
        else
            rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *rax = 0;
    }
    else
        SYSTEM_$$_ERRNO2INOUTRES$$WORD();
    
    return result;
}

uint64_t SYSTEM_$$_DO_SEEK$LONGINT$INT64()
{
    int64_t rsi;
    int32_t rdi;
    
    if (FPC_SYSC_LSEEK(rdi, rsi, 0) < 0)
        return SYSTEM_$$_ERRNO2INOUTRES$$WORD();
    
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    uint64_t result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    *result = 0;
    return result;
}

int64_t SYSTEM_$$_DO_SEEKEND$LONGINT$$INT64()
{
    int32_t rdi;
    int64_t result = FPC_SYSC_LSEEK(rdi, 0, 2);
    
    if (result >= 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax = &data_434a78;
        else
            rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *rax = 0;
    }
    else
        SYSTEM_$$_ERRNO2INOUTRES$$WORD();
    
    return result;
}

int64_t SYSTEM_$$_DO_FILESIZE$LONGINT$$INT64()
{
    void var_98;
    int32_t rdi;
    int32_t rax = FPC_SYSC_FSTAT(rdi, &var_98);
    int64_t result;
    int64_t result_1;
    
    if (rax != 0)
        result = 0;
    else
        result = result_1;
    
    if (rax >= 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_1 = &data_434a78;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *rax_1 = 0;
    }
    else
        SYSTEM_$$_ERRNO2INOUTRES$$WORD();
    
    return result;
}

uint64_t SYSTEM_$$_DO_OPEN$formal$PCHAR$LONGINT$BOOLEAN(int32_t* arg1, char* arg2, int32_t arg3, uint64_t arg4 @ r14)
{
    uint64_t var_20 = arg4;
    
    if ((arg3 & 0x10000) != 0)
        goto label_41c076;
    
    int32_t rax_2 = arg1[1];
    uint64_t result;
    
    if (rax_2 < 0xd7b0)
    {
    label_41c04c:
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *result = 0x66;
    }
    else
    {
        if (rax_2 == 0xd7b0)
            goto label_41c076;
        
        if (((rax_2 - 0xd7b0) < 1 || (rax_2 - 0xd7b1) > 2))
            goto label_41c04c;
        
        SYSTEM_$$_DO_CLOSE$LONGINT(*arg1);
    label_41c076:
        *arg1 = 0xffffffff;
        int32_t rax_7 = (arg3 & 3);
        
        if (rax_7 == 0)
        {
            arg4 = 0;
            arg1[1] = 0xd7b1;
        }
        else if (rax_7 == 1)
        {
            arg4 = 1;
            arg1[1] = 0xd7b2;
        }
        else if (rax_7 == 2)
        {
            arg4 = 2;
            arg1[1] = 0xd7b3;
        }
        
        if ((arg3 & 0x1000) == 0x1000)
            arg4 = (arg4 | 0x240);
        else if ((arg3 & 0x100) == 0x100)
            arg4 = (arg4 | 0x400);
        
        if (*arg2 != 0)
        {
            int32_t i;
            
            do
            {
                int32_t rax_12 = FPC_SYSC_OPEN(arg2, arg4, 0x1b6);
                *arg1 = rax_12;
                
                if (rax_12 != 0xffffffff)
                    break;
                
                i = FPC_SYS_GETERRNO();
            } while (i == 4);
            
            if ((*arg1 < 0 && (FPC_SYS_GETERRNO() == 0x1e && (arg4 & 2) != 0)))
            {
                int32_t i_1;
                
                do
                {
                    int32_t rax_16 = FPC_SYSC_OPEN(arg2, (arg4 & 0xfffffffd), 0x1b6);
                    *arg1 = rax_16;
                    
                    if (rax_16 != 0xffffffff)
                        break;
                    
                    i_1 = FPC_SYS_GETERRNO();
                } while (i_1 == 4);
            }
            
            if (*arg1 >= 0)
            {
                uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
                
                if (FPC_THREADVAR_RELOCATE_2 == 0)
                    result = &data_434a78;
                else
                    result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
                
                *result = 0;
            }
            else
            {
                result = SYSTEM_$$_ERRNO2INOUTRES$$WORD();
                arg1[1] = 0xd7b0;
            }
        }
        else
        {
            result = arg1[1];
            
            if (result >= 0xd7b1)
            {
                int32_t temp5_1 = result;
                result = (result - 0xd7b1);
                
                if (temp5_1 == 0xd7b1)
                    *arg1 = 0;
                else
                {
                    int32_t temp6_1 = result;
                    result = (result - 1);
                    
                    if (temp6_1 >= 1)
                    {
                        int32_t temp7_1 = result;
                        result = (result - 1);
                        
                        if (temp7_1 <= 1)
                            *arg1 = 1;
                        else
                        {
                            int32_t temp8_1 = result;
                            result = (result - 1);
                            
                            if (temp8_1 == 1)
                            {
                                *arg1 = 1;
                                arg1[1] = 0xd7b2;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return result;
}

int64_t SYSTEM_$$_DO_OPEN$formal$PWIDECHAR$LONGINT$BOOLEAN(int32_t* arg1, int64_t arg2, int32_t arg3)
{
    uint64_t r13 = arg3;
    uint16_t* var_88 = nullptr;
    void var_80;
    void var_68;
    int64_t rbp;
    uint64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_80), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    int64_t rax_1 = FPC_PWIDECHAR_LENGTH(arg2);
    data_434b68(arg2, &var_88, U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE, rax_1);
    uint16_t* rsi_2 = var_88;
    
    if (rsi_2 == 0)
        rsi_2 = &FPC_EMPTYCHAR;
    
    int64_t rcx_2;
    rcx_2 = 1;
    SYSTEM_$$_DO_OPEN$formal$PCHAR$LONGINT$BOOLEAN(arg1, rsi_2, r13, r14);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_88);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_DO_ERASE$PWIDECHAR$BOOLEAN(int64_t arg1)
{
    uint16_t* var_78 = nullptr;
    void var_70;
    void var_58;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_58, &var_70), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    int64_t rax_1 = FPC_PWIDECHAR_LENGTH(arg1);
    data_434b68(arg1, &var_78, U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE, rax_1);
    uint16_t* rdi_3 = var_78;
    
    if (rdi_3 == 0)
        rdi_3 = &FPC_EMPTYCHAR;
    
    int64_t rsi_2;
    rsi_2 = 1;
    SYSTEM_$$_DO_ERASE$PCHAR$BOOLEAN(rdi_3);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_78);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_DO_RENAME$PWIDECHAR$PWIDECHAR$BOOLEAN$BOOLEAN(int64_t arg1, int64_t arg2)
{
    int64_t var_88 = 0;
    int64_t var_80 = 0;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    int64_t rax_1 = FPC_PWIDECHAR_LENGTH(arg1);
    data_434b68(arg1, &var_88, U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE, rax_1);
    int64_t rax_2 = FPC_PWIDECHAR_LENGTH(arg2);
    int64_t rcx_3;
    int64_t rdx_3;
    rcx_3 = data_434b68(arg2, &var_80, U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE, rax_2);
    rcx_3 = 1;
    rdx_3 = 1;
    SYSTEM_$$_DO_RENAME$PCHAR$PCHAR$BOOLEAN$BOOLEAN();
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_88);
    FPC_ANSISTR_DECR_REF(&var_80);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_DO_RENAME$PWIDECHAR$PCHAR$BOOLEAN$BOOLEAN(int64_t arg1, int64_t arg2, int64_t arg3, char arg4)
{
    int64_t r13;
    r13 = arg4;
    int64_t var_88 = 0;
    void var_80;
    void var_68;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_80), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    int64_t rax_1 = FPC_PWIDECHAR_LENGTH(arg1);
    int64_t rcx_1;
    int64_t rdx_2;
    rcx_1 = data_434b68(arg1, &var_88, U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE, rax_1);
    rcx_1 = r13;
    rdx_2 = 1;
    SYSTEM_$$_DO_RENAME$PCHAR$PCHAR$BOOLEAN$BOOLEAN();
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_88);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

void SYSTEM_$$_MIN$INT64$INT64$$INT64(int64_t arg1, int64_t arg2) __pure
{
    return;
}

int64_t SYSTEM_$$_FILECLOSEFUNC$TEXTREC(int32_t* arg1)
{
    int64_t result = SYSTEM_$$_DO_CLOSE$LONGINT(*arg1);
    *arg1 = 0xffffffff;
    return result;
}

int64_t SYSTEM_$$_FILEREADFUNC$TEXTREC(int32_t* arg1)
{
    int64_t result = SYSTEM_$$_DO_READ$LONGINT$POINTER$LONGINT$$LONGINT(*arg1, *(arg1 + 0x28), arg1[2]);
    *(arg1 + 0x20) = result;
    *(arg1 + 0x18) = 0;
    return result;
}

void SYSTEM_$$_FILEWRITEFUNC$TEXTREC(int32_t* arg1)
{
    if (*(arg1 + 0x18) != 0)
    {
        if (SYSTEM_$$_DO_WRITE$LONGINT$POINTER$LONGINT$$LONGINT(*arg1, *(arg1 + 0x28), arg1[6]) != *(arg1 + 0x18))
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            int64_t rax;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                rax = &data_434a78;
            else
                rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *rax = 0x65;
        }
        
        *(arg1 + 0x18) = 0;
    }
}

int16_t* SYSTEM_$$_FILEOPENFUNC$TEXTREC(int32_t* arg1)
{
    int32_t rax = arg1[1];
    int16_t* result;
    
    if (rax < 0xd7b1)
    {
    label_41c607:
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
        
        *result = 0x66;
    }
    else
    {
        int32_t r12_1;
        
        if (rax == 0xd7b1)
            r12_1 = 0x10000;
        else if (rax == 0xd7b2)
            r12_1 = 0x11001;
        else
        {
            if (rax != 0xd7b4)
                goto label_41c607;
            
            r12_1 = 0x10101;
        }
        
        int64_t rcx;
        rcx = 0;
        result = SYSTEM_$$_DO_OPEN$formal$PWIDECHAR$LONGINT$BOOLEAN(arg1, &arg1[0x1c], r12_1);
        *(arg1 + 0x48) = SYSTEM_$$_FILECLOSEFUNC$TEXTREC;
        *(arg1 + 0x40) = 0;
        
        if (arg1[1] != 0xd7b1)
        {
            *(arg1 + 0x38) = SYSTEM_$$_FILEWRITEFUNC$TEXTREC;
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            if (*result == 0)
            {
                result = SYSTEM_$$_DO_ISDEVICE$LONGINT$$BOOLEAN(*arg1);
                
                if (result != 0)
                    *(arg1 + 0x40) = SYSTEM_$$_FILEWRITEFUNC$TEXTREC;
            }
        }
        else
            *(arg1 + 0x38) = SYSTEM_$$_FILEREADFUNC$TEXTREC;
    }
    
    return result;
}

uint32_t SYSTEM_$$_INITTEXT$TEXT(char* arg1)
{
    int32_t* rbx = arg1;
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(arg1, 0x378, 0);
    *rbx = 0xffffffff;
    rbx[1] = 0xd7b0;
    *(rbx + 8) = 0x100;
    *(rbx + 0x28) = &rbx[0x9d];
    *(rbx + 0x30) = SYSTEM_$$_FILEOPENFUNC$TEXTREC;
    uint32_t TC_$SYSTEM_$$_DEFAULTTEXTLINEBREAKSTYLE_1 = TC_$SYSTEM_$$_DEFAULTTEXTLINEBREAKSTYLE;
    
    if (TC_$SYSTEM_$$_DEFAULTTEXTLINEBREAKSTYLE_1 == 0)
        rbx[0x9c] = 0xa01;
    else
    {
        int32_t rax_1 = (TC_$SYSTEM_$$_DEFAULTTEXTLINEBREAKSTYLE_1 - 1);
        
        if (TC_$SYSTEM_$$_DEFAULTTEXTLINEBREAKSTYLE_1 == 1)
            return FPC_SHORTSTR_TO_SHORTSTR(&rbx[0x9c], 3, &_$SYSTEM$_Ld46);
        
        TC_$SYSTEM_$$_DEFAULTTEXTLINEBREAKSTYLE_1 = (rax_1 - 1);
        
        if (rax_1 == 1)
            rbx[0x9c] = 0xd01;
    }
    
    return TC_$SYSTEM_$$_DEFAULTTEXTLINEBREAKSTYLE_1;
}

int64_t SYSTEM_$$_ASSIGN$TEXT$UNICODESTRING(char* arg1, void* arg2)
{
    SYSTEM_$$_INITTEXT$TEXT(arg1);
    void var_218;
    int64_t result = fpc_unicodestr_to_widechararray(&var_218, 0xff, arg2);
    __builtin_memcpy(&arg1[0x70], &var_218, 0x40);
    *(arg1 + 0x26e) = 0;
    return result;
}

int64_t SYSTEM_$$_ASSIGN$TEXT$RAWBYTESTRING(char* arg1, void* arg2)
{
    SYSTEM_$$_INITTEXT$TEXT(arg1);
    void var_218;
    int64_t result = fpc_ansistr_to_widechararray(&var_218, 0xff, arg2);
    __builtin_memcpy(&arg1[0x70], &var_218, 0x40);
    *(arg1 + 0x26e) = 0;
    return result;
}

int64_t SYSTEM_$$_ASSIGN$TEXT$SHORTSTRING(char* arg1, char* arg2)
{
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_shortstr_to_ansistr(&var_18, arg2, 0);
    SYSTEM_$$_ASSIGN$TEXT$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_ASSIGN$TEXT$PCHAR(char* arg1, char* arg2)
{
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_pchar_to_ansistr(&var_18, arg2, 0);
    SYSTEM_$$_ASSIGN$TEXT$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_ASSIGN$TEXT$CHAR(char* arg1, char arg2)
{
    int64_t r12;
    r12 = arg2;
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    fpc_char_to_ansistr(&var_18, r12, 0);
    SYSTEM_$$_ASSIGN$TEXT$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int16_t* SYSTEM_$$_CLOSE$TEXT(int32_t* arg1, int64_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, arg2, &U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = arg1[1];
        
        if ((rax < 0xd7b1 || (rax > 0xd7b2 && rax != 0xd7b4)))
        {
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            if (arg1[1] == 0xd7b2)
                *(arg1 + 0x38)(arg1);
            
            result = *arg1;
            
            if ((result != 0 && (result != 1 && result != 2)))
                result = *(arg1 + 0x48)(arg1);
            
            arg1[1] = 0xd7b0;
            *(arg1 + 0x18) = 0;
            *(arg1 + 0x20) = 0;
        }
    }
    
    return result;
}

int16_t* SYSTEM_$$_OPENTEXT$TEXT$LONGINT$LONGINT(int32_t* arg1, int64_t arg2)
{
    int32_t rax = arg1[1];
    int16_t* result;
    
    if (rax < 0xd7b0)
    {
    label_41ca8c:
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
        
        *result = 0x66;
    }
    else
    {
        if (rax != 0xd7b0)
        {
            if (((rax - 0xd7b0) < 1 || (rax - 0xd7b1) > 2))
                goto label_41ca8c;
            
            SYSTEM_$$_CLOSE$TEXT(arg1, arg2);
        }
        
        arg1[1] = arg2;
        *(arg1 + 0x18) = 0;
        *(arg1 + 0x20) = 0;
        int32_t rax_1;
        rax_1 = arg1[0xdd];
        uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = rax_1;
        int16_t temp1_1 = rax_1;
        rax_1 -= 1;
        
        if (temp1_1 <= 1)
            U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
        
        arg1[0xdd] = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
        *(arg1 + 0x30)(arg1);
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        if (*result != 0)
            arg1[1] = 0xd7b0;
    }
    
    return result;
}

int16_t* SYSTEM_$$_REWRITE$TEXT(int32_t* arg1, int64_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, arg2, &U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    return SYSTEM_$$_OPENTEXT$TEXT$LONGINT$LONGINT(arg1, 0xd7b2);
}

int16_t* SYSTEM_$$_RESET$TEXT(int32_t* arg1, int64_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, arg2, &U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    return SYSTEM_$$_OPENTEXT$TEXT$LONGINT$LONGINT(arg1, 0xd7b1);
}

int16_t* SYSTEM_$$_APPEND$TEXT(int32_t* arg1, int64_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, arg2, &U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    return SYSTEM_$$_OPENTEXT$TEXT$LONGINT$LONGINT(arg1, 0xd7b4);
}

int16_t* SYSTEM_$$_FLUSH$TEXT(void* arg1)
{
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        if (*(arg1 + 4) == 0xd7b2)
            return *(arg1 + 0x38)(arg1);
        
        if (*(arg1 + 4) != 0xd7b1)
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x69;
        }
    }
    
    return result;
}

int16_t* SYSTEM_$$_ERASE$TEXT(void* arg1)
{
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    int64_t rsi;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        if (*(arg1 + 4) == 0xd7b0)
        {
            rsi = 0;
            return SYSTEM_$$_DO_ERASE$PWIDECHAR$BOOLEAN((arg1 + 0x70));
        }
        
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *result = 0x66;
    }
    
    return result;
}

int64_t SYSTEM_$$_RENAME$TEXT$UNICODESTRING(void* arg1, uint16_t* arg2)
{
    uint16_t* var_278 = nullptr;
    void var_270;
    void var_258;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_258, &var_270), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
    int16_t* rax_1;
    
    if (FPC_THREADVAR_RELOCATE_3 == 0)
        rax_1 = &data_434a78;
    else
        rax_1 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
    
    if (*rax_1 == 0)
    {
        if (*(arg1 + 4) == 0xd7b0)
        {
            SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$UNICODESTRING$$RAWBYTESTRING(&var_278, arg2);
            uint16_t* rsi_2 = var_278;
            
            if (rsi_2 == 0)
                rsi_2 = &FPC_EMPTYCHAR;
            
            int64_t rdx_1;
            rdx_1 = 0;
            SYSTEM_$$_DO_RENAME$PWIDECHAR$PCHAR$BOOLEAN$BOOLEAN((arg1 + 0x70), rsi_2, rdx_1, 1);
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            int16_t* rax_3;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                rax_3 = &data_434a78;
            else
                rax_3 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            if (*rax_3 == 0)
            {
                void var_210;
                fpc_ansistr_to_widechararray(&var_210, 0xff, var_278);
                __builtin_memcpy((arg1 + 0x70), &var_210, 0x40);
            }
        }
        else
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            int16_t* rax_2;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                rax_2 = &data_434a78;
            else
                rax_2 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *rax_2 = 0x66;
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_278);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_RENAME$TEXT$RAWBYTESTRING(void* arg1, uint16_t* arg2)
{
    int64_t r13;
    int64_t var_18 = r13;
    int64_t r14;
    int64_t var_20 = r14;
    uint16_t* var_288 = nullptr;
    void var_280;
    void var_268;
    int64_t rbp;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_268, &var_280), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int16_t* rax_1;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        rax_1 = &data_434a78;
    else
        rax_1 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
    
    if (*rax_1 == 0)
    {
        if (*(arg1 + 4) == 0xd7b0)
        {
            r13 = 0;
            uint16_t* rax_3 = arg2;
            
            if (arg2 == 0)
                rax_3 = &FPC_EMPTYCHAR;
            
            uint16_t* r14_1 = rax_3;
            uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg2);
            uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2;
            
            if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 <= 1)
                U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
            
            if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 == U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE)
                FPC_ANSISTR_ASSIGN(&var_288, arg2);
            else
            {
                SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$RAWBYTESTRING$$RAWBYTESTRING(&var_288, arg2);
                uint16_t* rax_4 = var_288;
                
                if (rax_4 == 0)
                    rax_4 = &FPC_EMPTYCHAR;
                
                r14_1 = rax_4;
                r13 = 1;
            }
            
            int64_t rdx_1;
            rdx_1 = 0;
            SYSTEM_$$_DO_RENAME$PWIDECHAR$PCHAR$BOOLEAN$BOOLEAN((arg1 + 0x70), r14_1, rdx_1, r13);
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            int16_t* rax_5;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                rax_5 = &data_434a78;
            else
                rax_5 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            if (*rax_5 == 0)
            {
                void var_220;
                fpc_ansistr_to_widechararray(&var_220, 0xff, var_288);
                __builtin_memcpy((arg1 + 0x70), &var_220, 0x40);
            }
        }
        else
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            int16_t* rax_2;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                rax_2 = &data_434a78;
            else
                rax_2 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *rax_2 = 0x66;
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_288);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_RENAME$TEXT$SHORTSTRING(void* arg1, char* arg2)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_shortstr_to_ansistr(&var_18, arg2, 0);
    SYSTEM_$$_RENAME$TEXT$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_RENAME$TEXT$PCHAR(void* arg1, char* arg2)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_pchar_to_ansistr(&var_18, arg2, 0);
    SYSTEM_$$_RENAME$TEXT$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_RENAME$TEXT$CHAR(void* arg1, char arg2)
{
    int64_t r12;
    r12 = arg2;
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    fpc_char_to_ansistr(&var_18, r12, 0);
    SYSTEM_$$_RENAME$TEXT$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int16_t* SYSTEM_$$_EOF$TEXT$$BOOLEAN(int16_t* arg1, int64_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, arg2, &U_$SYSTEM_$$_INOUTRES);
    
    int64_t r12;
    
    if (*result != 0)
        r12 = 1;
    else if (*(arg1 + 4) == 0xd7b1)
    {
        if (*(arg1 + 0x18) >= *(arg1 + 0x20))
            *(arg1 + 0x38)(arg1);
        
        if ((*(arg1 + 0x18) >= *(arg1 + 0x20) && *(arg1 + 0x18) >= *(arg1 + 0x20)))
            r12 = 1;
        else if ((TC_$SYSTEM_$$_CTRLZMARKSEOF == 0 || *(*(arg1 + 0x28) + *(arg1 + 0x18)) != 0x1a))
            r12 = 0;
        else
            r12 = 1;
    }
    else
    {
        if (*(arg1 + 4) != 0xd7b2)
        {
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x68;
        }
        
        r12 = 1;
    }
    
    result = r12;
    return result;
}

int16_t* SYSTEM_$$_EOF$$BOOLEAN()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t rsi;
    int16_t* rdi_1;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rdi_1 = &data_433ff8;
    else
    {
        int16_t* rax;
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INPUT, rsi, &U_$SYSTEM_$$_INPUT);
        rdi_1 = rax;
    }
    
    return SYSTEM_$$_EOF$TEXT$$BOOLEAN(rdi_1, rsi);
}

int16_t* SYSTEM_$$_SEEKEOF$TEXT$$BOOLEAN(int16_t* arg1, int64_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, arg2, &U_$SYSTEM_$$_INOUTRES);
    
    int64_t r12;
    
    if (*result != 0)
        r12 = 1;
    else if (*(arg1 + 4) == 0xd7b1)
    {
        while (true)
        {
            if (*(arg1 + 0x18) >= *(arg1 + 0x20))
            {
                *(arg1 + 0x38)(arg1);
                
                if (*(arg1 + 0x18) >= *(arg1 + 0x20))
                {
                    r12 = 1;
                    break;
                }
            }
            
            result = *(*(arg1 + 0x28) + *(arg1 + 0x18));
            
            if (result >= 9)
            {
                char temp0_1 = result;
                result -= 0xa;
                
                if (temp0_1 <= 0xa)
                {
                    *(arg1 + 0x18) += 1;
                    continue;
                }
                else
                {
                    char temp1_1 = result;
                    result -= 3;
                    
                    if (temp1_1 == 3)
                    {
                        *(arg1 + 0x18) += 1;
                        continue;
                    }
                    else
                    {
                        char temp2_1 = result;
                        result -= 0xd;
                        
                        if (temp2_1 == 0xd)
                        {
                            if (TC_$SYSTEM_$$_CTRLZMARKSEOF == 0)
                            {
                                *(arg1 + 0x18) += 1;
                                continue;
                            }
                            
                            r12 = 1;
                            break;
                        }
                        else
                        {
                            char temp3_1 = result;
                            result -= 6;
                            
                            if (temp3_1 == 6)
                            {
                                *(arg1 + 0x18) += 1;
                                continue;
                            }
                        }
                    }
                }
            }
            
            r12 = 0;
            break;
        }
    }
    else
    {
        if (*(arg1 + 4) != 0xd7b2)
        {
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x68;
        }
        
        r12 = 1;
    }
    
    result = r12;
    return result;
}

int16_t* SYSTEM_$$_SEEKEOF$$BOOLEAN()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t rsi;
    int16_t* rdi_1;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rdi_1 = &data_433ff8;
    else
    {
        int16_t* rax;
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INPUT, rsi, &U_$SYSTEM_$$_INPUT);
        rdi_1 = rax;
    }
    
    return SYSTEM_$$_SEEKEOF$TEXT$$BOOLEAN(rdi_1, rsi);
}

int16_t* SYSTEM_$$_EOLN$TEXT$$BOOLEAN(int16_t* arg1)
{
    uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_3 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
    
    int64_t r12;
    
    if (*result != 0)
        r12 = 1;
    else if (*(arg1 + 4) == 0xd7b1)
    {
        if (*(arg1 + 0x18) >= *(arg1 + 0x20))
            *(arg1 + 0x38)(arg1);
        
        if ((*(arg1 + 0x18) >= *(arg1 + 0x20) && *(arg1 + 0x18) >= *(arg1 + 0x20)))
            r12 = 1;
        else if ((TC_$SYSTEM_$$_CTRLZMARKSEOF == 0 || *(*(arg1 + 0x28) + *(arg1 + 0x18)) != 0x1a))
        {
            result = *(*(arg1 + 0x28) + *(arg1 + 0x18));
            bool cond:0_1 = result == 0xa;
            
            if (result != 0xa)
                cond:0_1 = result == 0xd;
            
            r12 = cond:0_1;
        }
        else
            r12 = 1;
    }
    else
    {
        if (*(arg1 + 4) != 0xd7b2)
        {
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x68;
        }
        
        r12 = 1;
    }
    
    result = r12;
    return result;
}

int16_t* SYSTEM_$$_EOLN$$BOOLEAN()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* rdi_1;
    int64_t rsi;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rdi_1 = &data_433ff8;
    else
        rdi_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INPUT, rsi, &U_$SYSTEM_$$_INPUT);
    return SYSTEM_$$_EOLN$TEXT$$BOOLEAN(rdi_1);
}

int16_t* SYSTEM_$$_SEEKEOLN$TEXT$$BOOLEAN(int16_t* arg1, int64_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, arg2, &U_$SYSTEM_$$_INOUTRES);
    
    int64_t r12;
    
    if (*result != 0)
        r12 = 1;
    else if (*(arg1 + 4) == 0xd7b1)
    {
        while (true)
        {
            if (*(arg1 + 0x18) >= *(arg1 + 0x20))
            {
                *(arg1 + 0x38)(arg1);
                
                if (*(arg1 + 0x18) >= *(arg1 + 0x20))
                {
                    r12 = 1;
                    break;
                }
            }
            
            result = *(*(arg1 + 0x28) + *(arg1 + 0x18));
            
            if (result >= 9)
            {
                char temp0_1 = result;
                result -= 9;
                
                if (temp0_1 == 9)
                {
                    *(arg1 + 0x18) += 1;
                    continue;
                }
                else
                {
                    char temp1_1 = result;
                    result -= 1;
                    char temp2_1;
                    
                    if (temp1_1 != 1)
                    {
                        temp2_1 = result;
                        result -= 3;
                    }
                    
                    if ((temp1_1 == 1 || temp2_1 == 3))
                    {
                        r12 = 1;
                        break;
                    }
                    
                    char temp3_1 = result;
                    result -= 0xd;
                    
                    if (temp3_1 == 0xd)
                    {
                        if (TC_$SYSTEM_$$_CTRLZMARKSEOF == 0)
                        {
                            *(arg1 + 0x18) += 1;
                            continue;
                        }
                        
                        r12 = 1;
                        break;
                    }
                    else
                    {
                        char temp4_1 = result;
                        result -= 6;
                        
                        if (temp4_1 == 6)
                        {
                            *(arg1 + 0x18) += 1;
                            continue;
                        }
                    }
                }
            }
            
            r12 = 0;
            break;
        }
    }
    else
    {
        if (*(arg1 + 4) != 0xd7b2)
        {
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x68;
        }
        
        r12 = 1;
    }
    
    result = r12;
    return result;
}

int16_t* SYSTEM_$$_SEEKEOLN$$BOOLEAN()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t rsi;
    int16_t* rdi_1;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rdi_1 = &data_433ff8;
    else
    {
        int16_t* rax;
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INPUT, rsi, &U_$SYSTEM_$$_INPUT);
        rdi_1 = rax;
    }
    
    return SYSTEM_$$_SEEKEOLN$TEXT$$BOOLEAN(rdi_1, rsi);
}

void* SYSTEM_$$_SETTEXTBUF$TEXT$formal$INT64(void* arg1, int64_t arg2, int64_t arg3)
{
    *(arg1 + 0x28) = arg2;
    *(arg1 + 8) = arg3;
    *(arg1 + 0x18) = 0;
    *(arg1 + 0x20) = 0;
    return arg1;
}

uint64_t SYSTEM_$$_SETTEXTLINEENDING$TEXT$SHORTSTRING(void* arg1, char* arg2)
{
    void var_108;
    FPC_SHORTSTR_TO_SHORTSTR(&var_108, 0xff, arg2);
    return FPC_SHORTSTR_TO_SHORTSTR((arg1 + 0x270), 3, &var_108);
}

uint64_t SYSTEM_$$_GETTEXTCODEPAGE$TEXT$$WORD(void* arg1)
{
    return *(arg1 + 0x374);
}

void* SYSTEM_$$_SETTEXTCODEPAGE$TEXT$WORD(void* arg1, uint16_t arg2)
{
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = arg2;
    
    if (arg2 <= 1)
        U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    *(arg1 + 0x374) = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
    return arg1;
}

void* fpc_get_input()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        return &data_433ff8;
    
    int64_t rsi;
    return FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INPUT, rsi, &U_$SYSTEM_$$_INPUT);
}

void* fpc_get_output()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        return &data_433c78;
    
    int64_t rsi;
    return FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_OUTPUT, rsi, &U_$SYSTEM_$$_OUTPUT);
}

int64_t fpc_textinit_iso(char* arg1, int32_t arg2)
{
    void var_108;
    SYSTEM_$$_PARAMSTR$LONGINT$$SHORTSTRING(&var_108, arg2);
    return SYSTEM_$$_ASSIGN$TEXT$SHORTSTRING(arg1, &var_108);
}

int64_t fpc_textinit_filename_iso(char* arg1, int32_t arg2, char* arg3)
{
    char var_118;
    SYSTEM_$$_PARAMSTR$LONGINT$$SHORTSTRING(&var_118, arg2);
    
    if (var_118 == 0)
    {
        fpc_shortstr_concat(&var_118, 0xff, arg3, &_$SYSTEM$_Ld47);
        return SYSTEM_$$_ASSIGN$TEXT$SHORTSTRING(arg1, &var_118);
    }
    
    SYSTEM_$$_PARAMSTR$LONGINT$$SHORTSTRING(&var_118, arg2);
    return SYSTEM_$$_ASSIGN$TEXT$SHORTSTRING(arg1, &var_118);
}

int16_t* fpc_textclose_iso(int32_t* arg1)
{
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int16_t* rax;
    int64_t rsi;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        rax = &data_434a78;
    else
        rax = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
    
    *rax = 0;
    SYSTEM_$$_CLOSE$TEXT(arg1, rsi);
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    *result = 0;
    return result;
}

uint64_t SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(void* arg1, int64_t arg2, uint64_t arg3)
{
    uint64_t r14 = arg3;
    int64_t r12 = 0;
    
    for (uint64_t i = (*(arg1 + 8) - *(arg1 + 0x18)); i < r14; i = (*(arg1 + 8) - *(arg1 + 0x18)))
    {
        FPC_MOVE((arg2 + r12), (*(arg1 + 0x28) + *(arg1 + 0x18)), i);
        r14 -= i;
        r12 += i;
        *(arg1 + 0x18) += i;
        *(arg1 + 0x38)(arg1);
    }
    
    uint64_t result = FPC_MOVE((arg2 + r12), (*(arg1 + 0x28) + *(arg1 + 0x18)), r14);
    *(arg1 + 0x18) += r14;
    return result;
}

int64_t SYSTEM_$$_FPC_WRITEBLANKS$TEXT$LONGINT(void* arg1, int32_t arg2)
{
    int32_t r12 = arg2;
    
    for (int32_t i = (*(arg1 + 8) - *(arg1 + 0x18)); i < r12; i = (*(arg1 + 8) - *(arg1 + 0x18)))
    {
        SYSTEM_$$_FILLCHAR$formal$INT64$CHAR((*(arg1 + 0x28) + *(arg1 + 0x18)), i, 0x20);
        r12 -= i;
        *(arg1 + 0x18) += i;
        *(arg1 + 0x38)(arg1);
    }
    
    int64_t result = SYSTEM_$$_FILLCHAR$formal$INT64$CHAR((*(arg1 + 0x28) + *(arg1 + 0x18)), r12, 0x20);
    *(arg1 + 0x18) += r12;
    return result;
}

void* fpc_write_end(void* arg1)
{
    if (*(arg1 + 0x40) == 0)
        return arg1;
    
    return *(arg1 + 0x40)(arg1);
}

int16_t* fpc_writeln_end(void* arg1)
{
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = *(arg1 + 4);
        
        if (rax < 0xd7b1)
        {
        label_41dbd6:
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else if (rax == 0xd7b1)
        {
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x69;
        }
        else
        {
            if (rax != 0xd7b2)
                goto label_41dbd6;
            
            result = SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(arg1, (arg1 + 0x271), *(arg1 + 0x270));
            
            if (*(arg1 + 0x40) != 0)
                return *(arg1 + 0x40)(arg1);
        }
    }
    
    return result;
}

int16_t* FPC_WRITE_TEXT_SHORTSTR(int32_t arg1, void* arg2, char* arg3)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = *(arg2 + 4);
        
        if (rax < 0xd7b1)
        {
        label_41dcc1:
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            if (rax != 0xd7b1)
            {
                if (rax != 0xd7b2)
                    goto label_41dcc1;
                
                if (*arg3 < arg1)
                    SYSTEM_$$_FPC_WRITEBLANKS$TEXT$LONGINT(arg2, (arg1 - *arg3));
                
                return SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(arg2, &arg3[1], *arg3);
            }
            
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x69;
        }
    }
    
    return result;
}

int16_t* FPC_WRITE_TEXT_SHORTSTR_ISO(uint32_t arg1, void* arg2, char* arg3)
{
    uint32_t rbx = arg1;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = *(arg2 + 4);
        
        if (rax < 0xd7b1)
        {
        label_41ddd5:
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            if (rax != 0xd7b1)
            {
                if (rax != 0xd7b2)
                    goto label_41ddd5;
                
                if (rbx == 0xffffffff)
                    rbx = *arg3;
                
                if (*arg3 >= rbx)
                    return SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(arg2, &arg3[1], rbx);
                
                SYSTEM_$$_FPC_WRITEBLANKS$TEXT$LONGINT(arg2, (rbx - *arg3));
                return SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(arg2, &arg3[1], *arg3);
            }
            
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x69;
        }
    }
    
    return result;
}

int16_t* fpc_write_text_pchar_as_array(int32_t arg1, void* arg2, char (* arg3)[0x10], int64_t arg4, char arg5)
{
    int64_t r14;
    r14 = arg5;
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = *(arg2 + 4);
        
        if (rax < 0xd7b1)
        {
        label_41df01:
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            if (rax != 0xd7b1)
            {
                if (rax != 0xd7b2)
                    goto label_41df01;
                
                int32_t r14_1;
                
                if (r14 == 0)
                    r14_1 = (arg4 + 1);
                else
                {
                    r14_1 = SYSTEM_$$_INDEXBYTE$formal$INT64$BYTE$$INT64(arg3, (arg4 + 1), 0);
                    
                    if (r14_1 == 0xffffffff)
                        r14_1 = (arg4 + 1);
                }
                
                if (r14_1 < arg1)
                    SYSTEM_$$_FPC_WRITEBLANKS$TEXT$LONGINT(arg2, (arg1 - r14_1));
                
                return SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(arg2, arg3, r14_1);
            }
            
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x69;
        }
    }
    
    return result;
}

int16_t* fpc_write_text_pchar_as_array_iso(int32_t arg1, void* arg2, char (* arg3)[0x10], int64_t arg4, char arg5)
{
    int32_t r12 = arg1;
    int64_t r14;
    r14 = arg5;
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = *(arg2 + 4);
        
        if (rax < 0xd7b1)
        {
        label_41e060:
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            if (rax != 0xd7b1)
            {
                if (rax != 0xd7b2)
                    goto label_41e060;
                
                int32_t r14_1;
                
                if (r14 == 0)
                    r14_1 = (arg4 + 1);
                else
                {
                    r14_1 = SYSTEM_$$_INDEXBYTE$formal$INT64$BYTE$$INT64(arg3, (arg4 + 1), 0);
                    
                    if (r14_1 == 0xffffffff)
                        r14_1 = (arg4 + 1);
                }
                
                if (r12 == 0xffffffff)
                    r12 = r14_1;
                
                if (r14_1 >= r12)
                    return SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(arg2, arg3, r12);
                
                SYSTEM_$$_FPC_WRITEBLANKS$TEXT$LONGINT(arg2, (r12 - r14_1));
                return SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(arg2, arg3, r14_1);
            }
            
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x69;
        }
    }
    
    return result;
}

void fpc_write_text_pchar_as_pointer(int32_t arg1, void* arg2, char (* arg3)[0x10])
{
    if (arg3 != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        int16_t* rax;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            rax = &data_434a78;
        else
            rax = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
        
        if (*rax == 0)
        {
            int32_t rax_1 = *(arg2 + 4);
            
            if (rax_1 < 0xd7b1)
            {
            label_41e16c:
                uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
                
                if (FPC_THREADVAR_RELOCATE_1 == 0)
                    rax = &data_434a78;
                else
                    rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
                
                *rax = 0x67;
            }
            else if (rax_1 == 0xd7b1)
            {
                uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
                
                if (FPC_THREADVAR_RELOCATE_3 == 0)
                    rax = &data_434a78;
                else
                    rax = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
                
                *rax = 0x69;
            }
            else
            {
                if (rax_1 != 0xd7b2)
                    goto label_41e16c;
                
                int32_t rax_4 = FPC_PCHAR_LENGTH(arg3);
                
                if (rax_4 < arg1)
                    SYSTEM_$$_FPC_WRITEBLANKS$TEXT$LONGINT(arg2, (arg1 - rax_4));
                
                SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(arg2, arg3, rax_4);
            }
        }
    }
}

int64_t FPC_WRITE_TEXT_ANSISTR(int32_t arg1, void* arg2, uint16_t* arg3)
{
    int64_t r14;
    int64_t var_20 = r14;
    uint64_t r12 = arg1;
    uint64_t var_88 = 0;
    void var_80;
    void var_68;
    int64_t rbp;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_80), arg2, rbp, r12, arg3, r14, r15);
    int64_t result = 0;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* rax_1;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax_1 = &data_434a78;
    else
        rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*rax_1 == 0)
    {
        int32_t rax_2 = *(arg2 + 4);
        
        if (rax_2 < 0xd7b1)
        {
        label_41e319:
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            int16_t* rax_7;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                rax_7 = &data_434a78;
            else
                rax_7 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *rax_7 = 0x67;
        }
        else if (rax_2 == 0xd7b1)
        {
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            int16_t* rax_6;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                rax_6 = &data_434a78;
            else
                rax_6 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *rax_6 = 0x69;
        }
        else
        {
            if (rax_2 != 0xd7b2)
                goto label_41e319;
            
            uint16_t* rax_5 = arg3;
            
            if (arg3 != 0)
                rax_5 = *(rax_5 - 8);
            
            int32_t r14_1 = rax_5;
            
            if (r14_1 < r12)
                SYSTEM_$$_FPC_WRITEBLANKS$TEXT$LONGINT(arg2, (r12 - r14_1));
            
            if (r14_1 > 0)
            {
                uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 = SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg3);
                uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2;
                
                if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_2 <= 1)
                    U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
                
                if (U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 == *(arg2 + 0x374))
                {
                    uint16_t* rsi_5 = arg3;
                    
                    if (arg3 == 0)
                        rsi_5 = &FPC_EMPTYCHAR;
                    
                    SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(arg2, rsi_5, r14_1);
                }
                else
                {
                    FPC_ANSISTR_TO_ANSISTR(&var_88, arg3, *(arg2 + 0x374));
                    uint64_t rsi_4 = var_88;
                    
                    if (rsi_4 == 0)
                        rsi_4 = &FPC_EMPTYCHAR;
                    
                    uint64_t rdx_2 = var_88;
                    
                    if (rdx_2 != 0)
                        rdx_2 = *(rdx_2 - 8);
                    
                    SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(arg2, rsi_4, rdx_2);
                }
            }
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_88);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t fpc_write_text_unicodestr(int32_t arg1, void* arg2, uint16_t* arg3)
{
    int64_t r14;
    int64_t var_20 = r14;
    uint64_t r12 = arg1;
    uint64_t var_88 = 0;
    void var_80;
    void var_68;
    int64_t rbp;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_80), arg2, rbp, r12, arg3, r14, r15);
    int64_t result = 0;
    
    if (arg3 != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_1 = &data_434a78;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        if (*rax_1 == 0)
        {
            int32_t rax_2 = *(arg2 + 4);
            
            if (rax_2 < 0xd7b1)
            {
            label_41e4bd:
                uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
                int16_t* rax_7;
                
                if (FPC_THREADVAR_RELOCATE_2 == 0)
                    rax_7 = &data_434a78;
                else
                    rax_7 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
                
                *rax_7 = 0x67;
            }
            else if (rax_2 == 0xd7b1)
            {
                uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
                int16_t* rax_6;
                
                if (FPC_THREADVAR_RELOCATE_3 == 0)
                    rax_6 = &data_434a78;
                else
                    rax_6 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
                
                *rax_6 = 0x69;
            }
            else
            {
                if (rax_2 != 0xd7b2)
                    goto label_41e4bd;
                
                uint16_t* rax_5 = arg3;
                
                if (arg3 != 0)
                    rax_5 = *(rax_5 - 8);
                
                int32_t r14_1 = rax_5;
                
                if (r14_1 < r12)
                    SYSTEM_$$_FPC_WRITEBLANKS$TEXT$LONGINT(arg2, (r12 - r14_1));
                
                uint16_t* rdi_3 = arg3;
                
                if (arg3 == 0)
                    rdi_3 = &FPC_EMPTYCHAR;
                
                data_434b68(rdi_3, &var_88, *(arg2 + 0x374), r14_1);
                uint16_t* rsi_4 = var_88;
                
                if (rsi_4 == 0)
                    rsi_4 = &FPC_EMPTYCHAR;
                
                uint64_t rdx_2 = var_88;
                
                if (rdx_2 != 0)
                    rdx_2 = *(rdx_2 - 8);
                
                SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(arg2, rsi_4, rdx_2);
            }
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_88);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int16_t* fpc_write_text_sint(int32_t arg1, void* arg2, int64_t arg3)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    void var_118;
    FPC_SHORTSTR_SINT(arg3, -1, &var_118, 0xff);
    return FPC_WRITE_TEXT_SHORTSTR(arg1, arg2, &var_118);
}

int16_t* fpc_write_text_uint(int32_t arg1, void* arg2, uint64_t arg3)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    void var_118;
    FPC_SHORTSTR_UINT(arg3, -1, &var_118, 0xff);
    return FPC_WRITE_TEXT_SHORTSTR(arg1, arg2, &var_118);
}

int16_t* fpc_write_text_sint_iso(uint32_t arg1, void* arg2, int64_t arg3)
{
    uint32_t rbx = arg1;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    char var_118;
    FPC_SHORTSTR_SINT(arg3, -1, &var_118, 0xff);
    
    if (rbx == 0xffffffff)
        rbx = 0xb;
    else if (var_118 > rbx)
        rbx = var_118;
    
    return FPC_WRITE_TEXT_SHORTSTR_ISO(rbx, arg2, &var_118);
}

int16_t* fpc_write_text_uint_iso(uint32_t arg1, void* arg2, uint64_t arg3)
{
    uint32_t rbx = arg1;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    char var_118;
    FPC_SHORTSTR_UINT(arg3, -1, &var_118, 0xff);
    
    if (rbx == 0xffffffff)
        rbx = 0xb;
    else if (var_118 > rbx)
        rbx = var_118;
    
    return FPC_WRITE_TEXT_SHORTSTR_ISO(rbx, arg2, &var_118);
}

int16_t* fpc_write_text_float(int32_t arg1, int16_t arg2, int32_t arg3, void* arg4, int16_t arg5, int16_t arg6)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    uint64_t r9;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    int16_t var_140_1 = arg6;
    void var_118;
    SYSTEM_$$_STR_REAL$SMALLINT$SMALLINT$EXTENDED$TREAL_TYPE$OPENSTRING(arg3, arg2, arg1, &var_118, 0xff, r9, arg5);
    return FPC_WRITE_TEXT_SHORTSTR(arg3, arg4, &var_118);
}

int16_t* fpc_write_text_float_iso(int32_t arg1, int16_t arg2, int32_t arg3, void* arg4, int16_t arg5, int16_t arg6)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    uint64_t r9;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    void var_118;
    SYSTEM_$$_STR_REAL_ISO$LONGINT$LONGINT$EXTENDED$TREAL_TYPE$OPENSTRING(arg3, arg2, arg1, &var_118, 0xff, r9, arg5, arg6);
    return FPC_WRITE_TEXT_SHORTSTR(arg3, arg4, &var_118);
}

uint64_t fpc_write_text_enum(void* arg1, int32_t* arg2, int64_t arg3, void* arg4, int32_t arg5)
{
    uint64_t result;
    
    if (*(arg4 + 4) == 0xd7b2)
    {
        char var_128;
        int16_t rax = SYSTEM_$$_FPC_SHORTSTR_ENUM_INTERN$INT64$INT64$POINTER$POINTER$OPENSTRING$$LONGINT(arg5, arg3, arg1, arg2, &var_128, 0xff);
        uint64_t FPC_THREADVAR_RELOCATE_4 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_4 == 0)
            rax_1 = &data_434a78;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_4(U_$SYSTEM_$$_INOUTRES);
        
        *rax_1 = rax;
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
        
        void var_127;
        
        if (*result == 0)
            return SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(arg4, &var_127, var_128);
    }
    else if (*(arg4 + 4) != 0xd7b1)
    {
        uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_3 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
        
        *result = 0x67;
    }
    else
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *result = 0x69;
    }
    
    return result;
}

int16_t* fpc_write_text_currency(int32_t arg1, int32_t arg2, void* arg3, uint64_t arg4)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    void var_120;
    FPC_SHORTSTR_CURRENCY(arg4, arg2, arg1, &var_120, 0xff);
    return FPC_WRITE_TEXT_SHORTSTR(arg2, arg3, &var_120);
}

int16_t* fpc_write_text_boolean(int32_t arg1, void* arg2, char arg3)
{
    int64_t r13;
    r13 = arg3;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    if (r13 == 0)
        return FPC_WRITE_TEXT_SHORTSTR(arg1, arg2, &_$SYSTEM$_Ld27);
    
    return FPC_WRITE_TEXT_SHORTSTR(arg1, arg2, &_$SYSTEM$_Ld26);
}

int16_t* fpc_write_text_boolean_iso(uint32_t arg1, void* arg2, char arg3)
{
    uint32_t rbx = arg1;
    int64_t r13;
    r13 = arg3;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    if (rbx == 0xffffffff)
        rbx = 5;
    
    if (r13 == 0)
        return FPC_WRITE_TEXT_SHORTSTR_ISO(rbx, arg2, &_$SYSTEM$_Ld49);
    
    return FPC_WRITE_TEXT_SHORTSTR_ISO(rbx, arg2, &_$SYSTEM$_Ld48);
}

int16_t* fpc_write_text_char(int32_t arg1, void* arg2, char arg3)
{
    int64_t r13;
    r13 = arg3;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        if (*(arg2 + 4) == 0xd7b2)
        {
            if (arg1 > 1)
                SYSTEM_$$_FPC_WRITEBLANKS$TEXT$LONGINT(arg2, (arg1 - 1));
            
            if (*(arg2 + 0x18) >= *(arg2 + 8))
                *(arg2 + 0x38)(arg2);
            
            result = *(arg2 + 0x18);
            *(*(arg2 + 0x28) + result) = r13;
            *(arg2 + 0x18) += 1;
        }
        else if (*(arg2 + 4) != 0xd7b0)
        {
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x69;
        }
        else
        {
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
    }
    
    return result;
}

int16_t* fpc_write_text_char_iso(int32_t arg1, void* arg2, char arg3)
{
    int32_t rbx = arg1;
    int64_t r13;
    r13 = arg3;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        if (*(arg2 + 4) == 0xd7b2)
        {
            if (rbx == 0xffffffff)
                rbx = 1;
            
            if (rbx > 1)
            {
                SYSTEM_$$_FPC_WRITEBLANKS$TEXT$LONGINT(arg2, (rbx - 1));
            label_41ed75:
                
                if (*(arg2 + 0x18) >= *(arg2 + 8))
                    *(arg2 + 0x38)(arg2);
                
                result = *(arg2 + 0x18);
                *(*(arg2 + 0x28) + result) = r13;
                *(arg2 + 0x18) += 1;
            }
            else if (rbx >= 1)
                goto label_41ed75;
        }
        else if (*(arg2 + 4) != 0xd7b0)
        {
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x69;
        }
        else
        {
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
    }
    
    return result;
}

int64_t fpc_write_text_widechar(int32_t arg1, void* arg2, int16_t arg3)
{
    uint64_t rbx = arg1;
    int16_t var_88 = arg3;
    uint64_t var_80 = 0;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), rbx, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int16_t* rax_1;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        rax_1 = &data_434a78;
    else
        rax_1 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
    
    if (*rax_1 == 0)
    {
        if (*(arg2 + 4) == 0xd7b2)
        {
            if (rbx > 1)
                SYSTEM_$$_FPC_WRITEBLANKS$TEXT$LONGINT(arg2, (rbx - 1));
            
            if (*(arg2 + 0x18) >= *(arg2 + 8))
                *(arg2 + 0x38)(arg2);
            
            U_$SYSTEM_$$_WIDESTRINGMANAGER(&var_88, &var_80, *(arg2 + 0x374), 1);
            uint64_t rsi_3 = var_80;
            
            if (rsi_3 == 0)
                rsi_3 = &FPC_EMPTYCHAR;
            
            uint64_t rdx_3 = var_80;
            
            if (rdx_3 != 0)
                rdx_3 = *(rdx_3 - 8);
            
            SYSTEM_$$_FPC_WRITEBUFFER$TEXT$formal$INT64(arg2, rsi_3, rdx_3);
        }
        else if (*(arg2 + 4) != 0xd7b0)
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            int16_t* rax_3;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                rax_3 = &data_434a78;
            else
                rax_3 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *rax_3 = 0x69;
        }
        else
        {
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            int16_t* rax_2;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                rax_2 = &data_434a78;
            else
                rax_2 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *rax_2 = 0x67;
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_80);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

void* SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(void* arg1, char* arg2, int64_t arg3)
{
    int64_t rbx;
    rbx = 0;
    
    if ((*(arg1 + 0x18) < *(arg1 + 0x20) && (TC_$SYSTEM_$$_CTRLZMARKSEOF == 0 || *(arg1 + 0x28)[*(arg1 + 0x18)] != 0x1a)))
    {
        if (*arg2 < arg3)
        {
            *arg2 += 1;
            int64_t rdx_1;
            rdx_1 = *(arg1 + 0x28)[*(arg1 + 0x18)];
            arg2[*arg2] = rdx_1;
        }
        
        *(arg1 + 0x18) += 1;
        
        if (*(arg1 + 0x18) >= *(arg1 + 0x20))
            *(arg1 + 0x38)(arg1);
        
        rbx = 1;
    }
    
    void* result;
    result = rbx;
    return result;
}

void* SYSTEM_$$_IGNORESPACES$TEXT$$BOOLEAN(void* arg1)
{
    char var_118 = 0;
    int64_t r12;
    r12 = 0;
    
    if ((*(arg1 + 0x18) < *(arg1 + 0x20) && (TC_$SYSTEM_$$_CTRLZMARKSEOF == 0 || *(*(arg1 + 0x28) + *(arg1 + 0x18)) != 0x1a)))
    {
        while (true)
        {
            if (*(*(arg1 + 0x28) + *(arg1 + 0x18)) <= 0x20)
            {
                if (SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, &var_118, 0xff) == 0)
                    break;
                
                if (*(arg1 + 0x18) < *(arg1 + 0x20))
                {
                    if (TC_$SYSTEM_$$_CTRLZMARKSEOF == 0)
                        continue;
                    else if (*(*(arg1 + 0x28) + *(arg1 + 0x18)) != 0x1a)
                        continue;
                }
            }
            
            r12 = 1;
            break;
        }
    }
    
    void* result;
    result = r12;
    return result;
}

uint64_t SYSTEM_$$_READNUMERIC$TEXT$OPENSTRING(void* arg1, char* arg2, int64_t arg3)
{
    uint64_t result;
    
    do
    {
        result = SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, arg2, arg3);
        
        if (result == 0)
            break;
        
        result = *arg2;
        
        if (result == arg3)
            break;
        
        result = *(arg1 + 0x18);
    } while (*(arg1 + 0x28)[result] > 0x20);
    
    return result;
}

int16_t* SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(void* arg1, int64_t arg2)
{
    int64_t r12;
    r12 = 0;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, arg2, &U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        if (*(arg1 + 4) == 0xd7b1)
        {
            if (*(arg1 + 0x18) >= *(arg1 + 0x20))
                *(arg1 + 0x38)(arg1);
            
            uint64_t FPC_THREADVAR_RELOCATE_4 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_4 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_4(U_$SYSTEM_$$_INOUTRES);
            
            r12 = *result == 0;
        }
        else
        {
            int32_t rax = *(arg1 + 4);
            
            if ((rax < 0xd7b2 || (rax != 0xd7b2 && rax != 0xd7b4)))
            {
                uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
                
                if (FPC_THREADVAR_RELOCATE_3 == 0)
                    result = &data_434a78;
                else
                    result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
                
                *result = 0x67;
            }
            else
            {
                uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
                
                if (FPC_THREADVAR_RELOCATE_2 == 0)
                    result = &data_434a78;
                else
                    result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
                
                *result = 0x68;
            }
        }
    }
    
    result = r12;
    return result;
}

int16_t* SYSTEM_$$_READINTEGER$TEXT$OPENSTRING(int16_t* arg1, char* arg2, int64_t arg3)
{
    *arg2 = 0;
    int16_t* result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (result != 0)
    {
        SYSTEM_$$_IGNORESPACES$TEXT$$BOOLEAN(arg1);
        result = arg1;
        
        if (*(result + 0x18) < *(result + 0x20))
        {
            uint32_t rax_2 = *(*(arg1 + 0x28) + *(arg1 + 0x18));
            
            if (((rax_2 == 0x2b || rax_2 == 0x2d) || rax_2 == 0x2d))
                SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, arg2, arg3);
            
            int64_t r14;
            r14 = 0xa;
            result = arg1;
            
            if (*(result + 0x18) < *(result + 0x20))
            {
                int32_t rax_6 = (*(*(arg1 + 0x28) + *(arg1 + 0x18)) - 0x24);
                bool c_1 = rax_6 < 3;
                
                if (!(c_1))
                {
                    c_1 = true;
                    
                    if (rax_6 != 0x34)
                    {
                        c_1 = true;
                        
                        if (rax_6 != 0x54)
                            c_1 = false;
                    }
                }
                
                if (c_1)
                {
                    int64_t rax_8;
                    rax_8 = *(arg1 + 0x28)[*(arg1 + 0x18)];
                    
                    if (rax_8 >= 0x24)
                    {
                        char temp0_1 = rax_8;
                        rax_8 -= 0x24;
                        
                        if (temp0_1 == 0x24)
                            r14 = 0x10;
                        else
                        {
                            char temp1_1 = rax_8;
                            rax_8 -= 1;
                            
                            if (temp1_1 == 1)
                                r14 = 2;
                            else
                            {
                                char temp2_1 = rax_8;
                                rax_8 -= 1;
                                
                                if (temp2_1 == 1)
                                    r14 = 8;
                                else
                                {
                                    char temp3_1 = rax_8;
                                    rax_8 -= 0x32;
                                    
                                    if (temp3_1 == 0x32)
                                        r14 = 0x10;
                                    else
                                    {
                                        char temp4_1 = rax_8;
                                        rax_8 -= 0x20;
                                        
                                        if (temp4_1 == 0x20)
                                            r14 = 0x10;
                                    }
                                }
                            }
                        }
                    }
                    
                    SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, arg2, arg3);
                    goto label_41f3be;
                }
                
                if (*(arg1 + 0x28)[*(arg1 + 0x18)] != 0x30)
                {
                label_41f3be:
                    
                    while (true)
                    {
                        result = arg1;
                        
                        if (*(result + 0x18) >= *(result + 0x20))
                            break;
                        
                        result = *arg2;
                        
                        if (result >= arg3)
                            break;
                        
                        if (r14 == 2)
                            result = (*(*(arg1 + 0x28) + *(arg1 + 0x18)) - 0x30);
                        
                        if ((r14 != 2 || result >= 2))
                        {
                            if (r14 == 8)
                                result = (*(*(arg1 + 0x28) + *(arg1 + 0x18)) - 0x30);
                            
                            if ((r14 != 8 || result >= 8))
                            {
                                if (r14 == 0xa)
                                    result = (*(*(arg1 + 0x28) + *(arg1 + 0x18)) - 0x30);
                                
                                if ((r14 != 0xa || result >= 0xa))
                                {
                                    if (r14 != 0x10)
                                        break;
                                    
                                    result = (*(*(arg1 + 0x28) + *(arg1 + 0x18)) - 0x30);
                                    bool cond:4_1 = result >= 0xa;
                                    
                                    if (result >= 0xa)
                                    {
                                        result = (result - 0x11);
                                        cond:4_1 = result >= 6;
                                        
                                        if (result >= 6)
                                        {
                                            result = (result - 0x20);
                                            cond:4_1 = result >= 6;
                                        }
                                    }
                                    
                                    if (cond:4_1)
                                        break;
                                }
                            }
                        }
                        
                        SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, arg2, arg3);
                    }
                }
                else
                {
                    SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, arg2, arg3);
                    result = arg1;
                    
                    if (*(result + 0x18) < *(result + 0x20))
                    {
                        uint32_t rax_13 = *(*(arg1 + 0x28) + *(arg1 + 0x18));
                        
                        if (((rax_13 == 0x58 || rax_13 == 0x78) || rax_13 == 0x78))
                        {
                            r14 = 0x10;
                            SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, arg2, arg3);
                        }
                        
                        goto label_41f3be;
                    }
                }
            }
        }
    }
    
    return result;
}

int16_t* SYSTEM_$$_READREAL$TEXT$OPENSTRING(int16_t* arg1, char* arg2, int64_t arg3)
{
    *arg2 = 0;
    int16_t* rax = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (rax != 0)
    {
        SYSTEM_$$_IGNORESPACES$TEXT$$BOOLEAN(arg1);
        rax = arg1;
        
        if (*(rax + 0x18) < *(rax + 0x20))
        {
            uint32_t rax_3 = *(*(arg1 + 0x28) + *(arg1 + 0x18));
            
            if (((rax_3 == 0x2b || rax_3 == 0x2d) || rax_3 == 0x2d))
                SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, arg2, arg3);
            
            int64_t r14;
            r14 = 0;
            rax = arg1;
            
            if (*(rax + 0x18) < *(rax + 0x20))
            {
                if ((*(*(arg1 + 0x28) + *(arg1 + 0x18)) - 0x30) < 0xa)
                {
                    r14 = 1;
                    
                    do
                    {
                        SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, arg2, arg3);
                        
                        if (*(arg1 + 0x18) >= *(arg1 + 0x20))
                            return arg1;
                        
                        rax = *arg2;
                        
                        if (rax >= arg3)
                            return rax;
                    } while ((*(*(arg1 + 0x28) + *(arg1 + 0x18)) - 0x30) < 0xa);
                }
                
                rax = *(arg1 + 0x18);
                
                if (*(*(arg1 + 0x28) + rax) != 0x2e)
                {
                label_41f574:
                    
                    if (r14 != 0)
                    {
                        rax = *(*(arg1 + 0x28) + *(arg1 + 0x18));
                        
                        if (((rax == 0x45 || rax == 0x65) || rax == 0x65))
                        {
                            SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, arg2, arg3);
                            rax = arg1;
                            
                            if (*(rax + 0x18) < *(rax + 0x20))
                            {
                                rax = *arg2;
                                
                                if (rax < arg3)
                                {
                                    uint32_t rax_23 = *(*(arg1 + 0x28) + *(arg1 + 0x18));
                                    
                                    if (((rax_23 == 0x2b || rax_23 == 0x2d) || rax_23 == 0x2d))
                                        SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, arg2, arg3);
                                    
                                    while (true)
                                    {
                                        rax = arg1;
                                        
                                        if (*(rax + 0x18) >= *(rax + 0x20))
                                            break;
                                        
                                        rax = *arg2;
                                        
                                        if (rax >= arg3)
                                            break;
                                        
                                        rax = (*(*(arg1 + 0x28) + *(arg1 + 0x18)) - 0x30);
                                        
                                        if (rax >= 0xa)
                                            break;
                                        
                                        SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, arg2, arg3);
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, arg2, arg3);
                    rax = arg1;
                    
                    if (*(rax + 0x18) < *(rax + 0x20))
                    {
                        rax = *arg2;
                        
                        if (rax < arg3)
                        {
                            rax = (*(*(arg1 + 0x28) + *(arg1 + 0x18)) - 0x30);
                            
                            if (rax < 0xa)
                            {
                                r14 = 1;
                                
                                do
                                {
                                    SYSTEM_$$_NEXTCHAR$TEXT$OPENSTRING$$BOOLEAN(arg1, arg2, arg3);
                                    
                                    if (*(arg1 + 0x18) >= *(arg1 + 0x20))
                                        return arg1;
                                    
                                    rax = *arg2;
                                    
                                    if (rax >= arg3)
                                        return rax;
                                    
                                    rax = (*(*(arg1 + 0x28) + *(arg1 + 0x18)) - 0x30);
                                } while (rax < 0xa);
                            }
                            
                            goto label_41f574;
                        }
                    }
                }
            }
        }
    }
    
    return rax;
}

void* FPC_READ_END(void* arg1)
{
    if (*(arg1 + 0x40) == 0)
        return arg1;
    
    return *(arg1 + 0x40)(arg1);
}

int16_t* FPC_READLN_END(int16_t* arg1, int64_t arg2)
{
    int64_t r12;
    int64_t var_10 = r12;
    int16_t* result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (result != 0)
    {
        result = arg1;
        
        if (*(result + 0x18) < *(result + 0x20))
        {
            if (TC_$SYSTEM_$$_CTRLZMARKSEOF != 0)
                result = *(arg1 + 0x18);
            
            if ((TC_$SYSTEM_$$_CTRLZMARKSEOF == 0 || *(*(arg1 + 0x28) + result) != 0x1a))
            {
                while (true)
                {
                    result = *(arg1 + 0x18);
                    r12 = *(*(arg1 + 0x28) + result);
                    *(arg1 + 0x18) += 1;
                    
                    if (r12 == 0xa)
                        break;
                    
                    if (*(arg1 + 0x18) >= *(arg1 + 0x20))
                    {
                        *(arg1 + 0x38)(arg1);
                        result = arg1;
                        
                        if (*(result + 0x18) >= *(result + 0x20))
                        {
                            if (*(arg1 + 0x40) != 0)
                                return *(arg1 + 0x40)(arg1);
                            
                            break;
                        }
                    }
                    
                    if (TC_$SYSTEM_$$_CTRLZMARKSEOF != 0)
                    {
                        result = *(arg1 + 0x18);
                        
                        if (*(*(arg1 + 0x28) + result) == 0x1a)
                            break;
                    }
                    
                    if (r12 == 0xd)
                    {
                        result = *(arg1 + 0x18);
                        
                        if (*(*(arg1 + 0x28) + result) == 0xa)
                            *(arg1 + 0x18) += 1;
                        
                        break;
                    }
                }
            }
        }
        else if (*(arg1 + 0x40) != 0)
            return *(arg1 + 0x40)(arg1);
    }
    
    return result;
}

int16_t* FPC_READLN_END_ISO(int16_t* arg1, int64_t arg2)
{
    int64_t r12;
    int64_t var_10 = r12;
    int16_t* result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (result != 0)
    {
        result = arg1;
        
        if (*(result + 0x18) < *(result + 0x20))
        {
            result = *(arg1 + 0x18);
            
            if (*(*(arg1 + 0x28) + result) != 0x1a)
            {
                while (true)
                {
                    result = *(arg1 + 0x18);
                    r12 = *(*(arg1 + 0x28) + result);
                    *(arg1 + 0x18) += 1;
                    
                    if (r12 == 0xa)
                        break;
                    
                    if (*(arg1 + 0x18) >= *(arg1 + 0x20))
                    {
                        *(arg1 + 0x38)(arg1);
                        result = arg1;
                        
                        if (*(result + 0x18) >= *(result + 0x20))
                        {
                            if (*(arg1 + 0x40) != 0)
                                return *(arg1 + 0x40)(arg1);
                            
                            break;
                        }
                    }
                    
                    result = *(arg1 + 0x18);
                    
                    if (*(*(arg1 + 0x28) + result) == 0x1a)
                    {
                        *(arg1 + 0x18) += 1;
                        break;
                    }
                    
                    if (r12 == 0xd)
                    {
                        result = *(arg1 + 0x18);
                        
                        if (*(*(arg1 + 0x28) + result) == 0xa)
                            *(arg1 + 0x18) += 1;
                        
                        break;
                    }
                }
            }
            else
                *(arg1 + 0x18) += 1;
        }
        else if (*(arg1 + 0x40) != 0)
            return *(arg1 + 0x40)(arg1);
    }
    
    return result;
}

uint64_t SYSTEM_$$_READPCHARLEN$TEXT$PCHAR$LONGINT$$LONGINT(void* arg1, void* arg2, int32_t arg3)
{
    int32_t var_58 = 0;
    
    if (SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2) != 0)
    {
        int32_t r15_1 = 0;
        int64_t r13;
        r13 = 0;
        
        do
        {
            if (*(arg1 + 0x18) >= *(arg1 + 0x20))
            {
                *(arg1 + 0x38)(arg1);
                
                if (*(arg1 + 0x18) >= *(arg1 + 0x20))
                    break;
            }
            
            char* i = (*(arg1 + 0x28) + *(arg1 + 0x18));
            int64_t r12_1;
            
            if (arg3 >= ((r15_1 + *(arg1 + 0x20)) - *(arg1 + 0x18)))
                r12_1 = (*(arg1 + 0x28) + *(arg1 + 0x20));
            else
                r12_1 = (*(arg1 + 0x28) + ((arg3 + *(arg1 + 0x18)) - r15_1));
            
            char* i_1 = i;
            
            for (; r12_1 > i; i = &i[1])
            {
                if (*i < 0x20)
                {
                    int64_t rdx_8;
                    rdx_8 = *i;
                    uint32_t rax_11 = rdx_8;
                    
                    if (((rax_11 == 0xa || rax_11 == 0xd) || rax_11 == 0xd))
                    {
                        r13 = 1;
                        break;
                    }
                    
                    if ((TC_$SYSTEM_$$_CTRLZMARKSEOF != 0 && rdx_8 == 0x1a))
                    {
                        r13 = 1;
                        break;
                    }
                }
            }
            
            int32_t rdx_10 = (i - i_1);
            *(arg1 + 0x18) += rdx_10;
            FPC_MOVE(i_1, (arg2 + r15_1), rdx_10);
            r15_1 += rdx_10;
            
            if (arg3 == r15_1)
                break;
        } while (r13 == 0);
        
        var_58 = r15_1;
    }
    
    return var_58;
}

int64_t fpc_read_text_shortstr(void* arg1, char* arg2, int32_t arg3)
{
    char result = SYSTEM_$$_READPCHARLEN$TEXT$PCHAR$LONGINT$$LONGINT(arg1, &arg2[1], arg3);
    *arg2 = result;
    return result;
}

char* fpc_read_text_pchar_as_pointer(void* arg1, void* arg2)
{
    char* result = (SYSTEM_$$_READPCHARLEN$TEXT$PCHAR$LONGINT$$LONGINT(arg1, arg2, 0x7fffffff) + arg2);
    *result = 0;
    return result;
}

uint64_t fpc_read_text_pchar_as_array(void* arg1, void* arg2, int64_t arg3, char arg4)
{
    int64_t r13;
    r13 = arg4;
    uint64_t result = SYSTEM_$$_READPCHARLEN$TEXT$PCHAR$LONGINT$$LONGINT(arg1, arg2, (arg3 + 1));
    
    if ((r13 != 0 && result > arg3))
        result = arg3;
    
    if (result <= arg3)
    {
        result = result;
        *(arg2 + result) = 0;
    }
    
    return result;
}

int64_t FPC_READ_TEXT_ANSISTR(void* arg1, int64_t* arg2, int16_t arg3)
{
    int64_t r12;
    int64_t var_10 = r12;
    int64_t r13;
    int64_t var_18 = r13;
    int64_t rbx;
    rbx = arg3;
    *arg2 = 0;
    int64_t var_38 = 0;
    void var_98;
    void var_80;
    int64_t rbp;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_80, &var_98), rbx, rbp, r12, r13, arg1, arg2);
    int64_t result = 0;
    uint64_t r12_1 = 0;
    int64_t i;
    
    do
    {
        FPC_ANSISTR_SETLENGTH(arg2, (r12_1 + 0xff), 0);
        i = SYSTEM_$$_READPCHARLEN$TEXT$PCHAR$LONGINT$$LONGINT(arg1, (*arg2 + r12_1), 0xff);
        r12_1 += i;
    } while (i >= 0xff);
    FPC_ANSISTR_SETLENGTH(arg2, r12_1, 0);
    SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg2, *(arg1 + 0x374), 0);
    
    if (rbx != *(arg1 + 0x374))
    {
        FPC_ANSISTR_TO_ANSISTR(&var_38, *arg2, rbx);
        FPC_ANSISTR_ASSIGN(arg2, var_38);
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_38);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t fpc_read_text_unicodestr(void* arg1, int64_t* arg2)
{
    int64_t r13;
    int64_t var_18 = r13;
    *arg2 = 0;
    uint16_t* var_88 = nullptr;
    void var_80;
    void var_68;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_80), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    FPC_ANSISTR_DECR_REF(&var_88);
    FPC_READ_TEXT_ANSISTR(arg1, &var_88, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE);
    SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(var_88);
    uint16_t* rdi_4 = var_88;
    
    if (rdi_4 == 0)
        rdi_4 = &FPC_EMPTYCHAR;
    
    data_434b70(rdi_4);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_88);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int16_t* FPC_READ_TEXT_CHAR(int16_t* arg1, char* arg2)
{
    *arg2 = 0;
    int16_t* result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (result != 0)
    {
        result = arg1;
        
        if (*(result + 0x18) < *(result + 0x20))
        {
            result = *(*(arg1 + 0x28) + *(arg1 + 0x18));
            *arg2 = result;
            *(arg1 + 0x18) += 1;
        }
        else
            *arg2 = 0x1a;
    }
    
    return result;
}

int64_t fpc_getbuf_text(void* arg1, int64_t arg2)
{
    int64_t result = (*(arg1 + 0x28) + *(arg1 + 0x20));
    
    if ((*(arg1 + 4) != 0xd7b2 && (SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2) != 0 && *(arg1 + 0x18) < *(arg1 + 0x20))))
        return (*(arg1 + 0x28) + *(arg1 + 0x18));
    
    return result;
}

int64_t fpc_read_text_widechar(int16_t* arg1, int16_t* arg2)
{
    int64_t r13;
    int64_t var_18 = r13;
    int16_t* var_88 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    void var_80;
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(&var_80, 6, 0);
    int32_t r13_1 = -1;
    
    while (true)
    {
        r13_1 += 1;
        FPC_READ_TEXT_CHAR(arg1, ((&var_88 + r13_1) + 8));
        int64_t rax_3 = data_434b00(&var_80, (r13_1 + 1));
        
        if (rax_3 != -1)
        {
            if (rax_3 == 0)
            {
                *arg2 = 0;
                break;
            }
            
            data_434ad8(&var_80, arg1[0x1ba], &var_88, (r13_1 + 1));
            int16_t* rax_5 = var_88;
            
            if (rax_5 != 0)
                rax_5 = *(rax_5 - 8);
            
            if (rax_5 == 1)
            {
                int16_t* rax_6;
                rax_6 = *var_88;
                *arg2 = rax_6;
                break;
            }
        }
        else if (r13_1 < 5)
            continue;
        
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_7;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_7 = &data_434a78;
        else
            rax_7 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *rax_7 = 0x6a;
        break;
    }
    
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_88);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int16_t* fpc_read_text_char_iso(int16_t* arg1, char* arg2)
{
    *arg2 = 0x20;
    int16_t* result;
    int64_t rsi;
    result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (result != 0)
    {
        result = arg1;
        
        if (*(result + 0x18) < *(result + 0x20))
        {
            result = *(*(arg1 + 0x28) + *(arg1 + 0x18));
            *arg2 = result;
            *(arg1 + 0x18) += 1;
            
            if (*arg2 == 0xd)
            {
                *arg2 = 0x20;
                int64_t rsi_1;
                result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, rsi);
                
                if (result != 0)
                {
                    result = arg1;
                    
                    if (*(result + 0x18) < *(result + 0x20))
                    {
                        if (*(arg1 + 0x28)[*(arg1 + 0x18)] == 0xa)
                            *(arg1 + 0x18) += 1;
                        
                        result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, rsi_1);
                        
                        if (result != 0)
                        {
                            result = arg1;
                            
                            if (*(result + 0x18) < *(result + 0x20))
                            {
                                result = *(arg1 + 0x18);
                                
                                if (*(*(arg1 + 0x28) + result) == 0x1a)
                                    *(arg1 + 0x18) += 1;
                            }
                        }
                    }
                }
            }
            else if (*arg2 == 0xa)
            {
                *arg2 = 0x20;
                result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, rsi);
                
                if (result != 0)
                {
                    result = arg1;
                    
                    if (*(result + 0x18) < *(result + 0x20))
                    {
                        result = *(arg1 + 0x18);
                        
                        if (*(*(arg1 + 0x28) + result) == 0x1a)
                            *(arg1 + 0x18) += 1;
                    }
                }
            }
            else if (*arg2 == 0x1a)
                *arg2 = 0x20;
        }
        else
            *arg2 = 0x20;
    }
    
    return result;
}

int16_t* fpc_read_text_sint(int16_t* arg1, int64_t* arg2)
{
    *arg2 = 0;
    int16_t* result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (result != 0)
    {
        char var_118 = 0;
        result = SYSTEM_$$_IGNORESPACES$TEXT$$BOOLEAN(arg1);
        
        if (result == 0)
            goto label_42002b;
        
        result = arg1;
        
        if (*(result + 0x18) < *(result + 0x20))
        {
            if (TC_$SYSTEM_$$_CTRLZMARKSEOF != 0)
                result = *(arg1 + 0x18);
            
            if ((TC_$SYSTEM_$$_CTRLZMARKSEOF == 0 || *(*(arg1 + 0x28) + result) != 0x1a))
            {
                result = SYSTEM_$$_READNUMERIC$TEXT$OPENSTRING(arg1, &var_118, 0xff);
            label_42002b:
                
                if (var_118 != 0)
                {
                    int64_t var_18;
                    result = FPC_VAL_SINT_SHORTSTR(8, &var_118, &var_18);
                    *arg2 = result;
                    
                    if (var_18 != 0)
                    {
                        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
                        
                        if (FPC_THREADVAR_RELOCATE_1 == 0)
                            result = &data_434a78;
                        else
                            result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
                        
                        *result = 0x6a;
                    }
                }
                else
                    *arg2 = 0;
            }
        }
    }
    
    return result;
}

int16_t* fpc_read_text_sint_iso(int16_t* arg1, int64_t* arg2)
{
    *arg2 = 0;
    int16_t* result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (result != 0)
    {
        void var_118;
        SYSTEM_$$_READINTEGER$TEXT$OPENSTRING(arg1, &var_118, 0xff);
        int64_t var_18;
        result = FPC_VAL_SINT_SHORTSTR(8, &var_118, &var_18);
        *arg2 = result;
        
        if (var_18 != 0)
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x6a;
        }
    }
    
    return result;
}

int16_t* fpc_read_text_uint(int16_t* arg1, int64_t* arg2)
{
    *arg2 = 0;
    int16_t* result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (result != 0)
    {
        char var_118 = 0;
        result = SYSTEM_$$_IGNORESPACES$TEXT$$BOOLEAN(arg1);
        
        if (result == 0)
            goto label_42019a;
        
        result = arg1;
        
        if (*(result + 0x18) < *(result + 0x20))
        {
            result = SYSTEM_$$_READNUMERIC$TEXT$OPENSTRING(arg1, &var_118, 0xff);
        label_42019a:
            
            if (var_118 != 0)
            {
                int64_t var_18;
                result = FPC_VAL_UINT_SHORTSTR(&var_118, &var_18);
                *arg2 = result;
                
                if (var_18 != 0)
                {
                    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
                    
                    if (FPC_THREADVAR_RELOCATE_1 == 0)
                        result = &data_434a78;
                    else
                        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
                    
                    *result = 0x6a;
                }
            }
            else
                *arg2 = 0;
        }
    }
    
    return result;
}

int16_t* fpc_read_text_uint_iso(int16_t* arg1, int64_t* arg2)
{
    *arg2 = 0;
    int16_t* result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (result != 0)
    {
        void var_118;
        SYSTEM_$$_READINTEGER$TEXT$OPENSTRING(arg1, &var_118, 0xff);
        int64_t var_18;
        result = FPC_VAL_UINT_SHORTSTR(&var_118, &var_18);
        *arg2 = result;
        
        if (var_18 != 0)
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x6a;
        }
    }
    
    return result;
}

int16_t* fpc_read_text_float(int16_t* arg1, long double* arg2)
{
    *arg2 = 0;
    int16_t* result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (result != 0)
    {
        char var_118 = 0;
        
        if (SYSTEM_$$_IGNORESPACES$TEXT$$BOOLEAN(arg1) == 0)
            goto label_4202ff;
        
        result = arg1;
        
        if (*(result + 0x18) < *(result + 0x20))
        {
            SYSTEM_$$_READNUMERIC$TEXT$OPENSTRING(arg1, &var_118, 0xff);
        label_4202ff:
            int16_t var_18;
            long double st0_1;
            st0_1 = FPC_VAL_REAL_SHORTSTR(&var_118, &var_18);
            *arg2 = st0_1;
            result = var_18;
            
            if (result != 0)
            {
                uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
                
                if (FPC_THREADVAR_RELOCATE_1 == 0)
                    result = &data_434a78;
                else
                    result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
                
                *result = 0x6a;
            }
        }
    }
    
    return result;
}

int16_t* fpc_read_text_float_iso(int16_t* arg1, long double* arg2)
{
    *arg2 = 0;
    int16_t* result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (result != 0)
    {
        void var_118;
        SYSTEM_$$_READREAL$TEXT$OPENSTRING(arg1, &var_118, 0xff);
        int16_t var_18;
        long double st0_1;
        st0_1 = FPC_VAL_REAL_SHORTSTR(&var_118, &var_18);
        *arg2 = st0_1;
        result = var_18;
        
        if (result != 0)
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x6a;
        }
    }
    
    return result;
}

int16_t* fpc_read_text_enum(int32_t* arg1, int16_t* arg2, int32_t* arg3)
{
    int16_t* result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg2, arg2);
    
    if (result != 0)
    {
        char var_128 = 0;
        
        if (SYSTEM_$$_IGNORESPACES$TEXT$$BOOLEAN(arg2) == 0)
            goto label_420441;
        
        result = arg2;
        
        if (*(result + 0x18) < *(result + 0x20))
        {
            SYSTEM_$$_READNUMERIC$TEXT$OPENSTRING(arg2, &var_128, 0xff);
        label_420441:
            int64_t var_28;
            result = FPC_VAL_ENUM_SHORTSTR(arg1, &var_128, &var_28);
            *arg3 = result;
            
            if (var_28 != 0)
            {
                uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
                
                if (FPC_THREADVAR_RELOCATE_1 == 0)
                    result = &data_434a78;
                else
                    result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
                
                *result = 0x6a;
            }
        }
    }
    
    return result;
}

int16_t* fpc_read_text_currency(int16_t* arg1, int64_t* arg2)
{
    *arg2 = 0;
    int16_t* result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (result != 0)
    {
        char var_118 = 0;
        
        if (SYSTEM_$$_IGNORESPACES$TEXT$$BOOLEAN(arg1) == 0)
            goto label_4204ef;
        
        result = arg1;
        
        if (*(result + 0x18) < *(result + 0x20))
        {
            SYSTEM_$$_READNUMERIC$TEXT$OPENSTRING(arg1, &var_118, 0xff);
        label_4204ef:
            int64_t var_18;
            long double st0_1;
            st0_1 = FPC_VAL_REAL_SHORTSTR(&var_118, &var_18);
            *arg2 = (st0_1 * _$SYSTEM$_Ld29);
            
            if (var_18 != 0)
            {
                uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
                
                if (FPC_THREADVAR_RELOCATE_1 == 0)
                    result = &data_434a78;
                else
                    result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
                
                *result = 0x6a;
            }
        }
    }
    
    return result;
}

int16_t* fpc_read_text_currency_iso(int16_t* arg1, int64_t* arg2)
{
    *arg2 = 0;
    int16_t* result = SYSTEM_$$_CHECKREAD$TEXT$$BOOLEAN(arg1, arg2);
    
    if (result != 0)
    {
        void var_118;
        SYSTEM_$$_READREAL$TEXT$OPENSTRING(arg1, &var_118, 0xff);
        int64_t var_18;
        long double st0_1;
        st0_1 = FPC_VAL_REAL_SHORTSTR(&var_118, &var_18);
        *arg2 = (st0_1 * _$SYSTEM$_Ld29);
        
        if (var_18 != 0)
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x6a;
        }
    }
    
    return result;
}

void SYSTEM_$$_WRITESTRSHORT$TEXTREC(void* arg1)
{
    if (*(arg1 + 0x18) != 0)
    {
        char* r12_1 = *(arg1 + 0x58);
        uint32_t r13_1 = *(arg1 + 0x18);
        uint32_t r14_1 = *r12_1;
        
        if (*(arg1 + 0x60) < (r14_1 + *(arg1 + 0x18)))
            r13_1 = (*(arg1 + 0x60) - r14_1);
        
        FPC_SHORTSTR_SETLENGTH(r12_1, 0xff, (*r12_1 + r13_1));
        FPC_MOVE(*(arg1 + 0x28), &r12_1[(r14_1 + 1)], r13_1);
        *(arg1 + 0x18) = 0;
    }
}

int64_t SYSTEM_$$_WRITESTRSHORTFLUSH$TEXTREC(void* arg1)
{
    SYSTEM_$$_WRITESTRSHORT$TEXTREC(arg1);
    FPC_MOVE(*(arg1 + 0x58), *(arg1 + 0x50), (*(arg1 + 0x60) + 1));
    *(arg1 + 0x58);
    return SYSTEM_$$_FREEMEM$POINTER$$QWORD();
}

void SYSTEM_$$_WRITESTRANSI$TEXTREC(void* arg1)
{
    if (*(arg1 + 0x18) != 0)
    {
        void* r13_1 = *(arg1 + 0x58);
        
        if (r13_1 != 0)
            r13_1 = *(r13_1 - 8);
        
        FPC_ANSISTR_SETLENGTH((arg1 + 0x58), (r13_1 + *(arg1 + 0x18)), 0);
        void* rsi_3 = ((FPC_ANSISTR_UNIQUE((arg1 + 0x58)) + (r13_1 + 1)) - 1);
        FPC_MOVE(*(arg1 + 0x28), rsi_3, *(arg1 + 0x18));
        *(arg1 + 0x18) = 0;
    }
}

int64_t SYSTEM_$$_WRITESTRANSIFLUSH$TEXTREC(void* arg1)
{
    SYSTEM_$$_WRITESTRANSI$TEXTREC(arg1);
    FPC_ANSISTR_ASSIGN(*(arg1 + 0x50), *(arg1 + 0x58));
    return FPC_ANSISTR_ASSIGN((arg1 + 0x58), 0);
}

void* SYSTEM_$$_ENDOFLASTCOMPLETEUTF8CODEPOINT$TEXTREC$$INT64(void* arg1)
{
    void* r12 = (*(arg1 + 0x18) - 1);
    
    if (r12 >= 0)
    {
        void* i = (r12 + 1);
        
        do
        {
            i -= 1;
            void* rax_5 = SYSTEM_$$_UTF8CODEPOINTLEN$PCHAR$INT64$BOOLEAN$$INT64((*(arg1 + 0x28) + i), (((*(arg1 + 0x18) - 1) - i) + 1), 0);
            
            if (rax_5 > 0)
                return (i + rax_5);
        } while (i > 0);
    }
    
    return *(arg1 + 0x18);
}

int64_t SYSTEM_$$_WRITESTRUNICODEINTERN$TEXTREC$BOOLEAN(void* arg1, char arg2)
{
    int64_t rbx;
    int64_t var_8 = rbx;
    int64_t r13;
    r13 = arg2;
    void* var_88 = nullptr;
    void var_80;
    void var_68;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_80), rbx, rbp, arg1, r13, r14, r15);
    int64_t result = 0;
    
    if (*(arg1 + 0x18) != 0)
    {
        void* r13_1;
        
        if (r13 != 0)
            r13_1 = *(arg1 + 0x18);
        else
            r13_1 = SYSTEM_$$_ENDOFLASTCOMPLETEUTF8CODEPOINT$TEXTREC$$INT64(arg1);
        
        data_434b70(*(arg1 + 0x28), 0xfde9, &var_88, r13_1);
        fpc_unicodestr_concat((arg1 + 0x58), *(arg1 + 0x58), var_88);
        *(arg1 + 0x18) -= r13_1;
        
        if (*(arg1 + 0x18) != 0)
            FPC_MOVE((*(arg1 + 0x28) + r13_1), *(arg1 + 0x28), *(arg1 + 0x18));
    }
    
    FPC_POPADDRSTACK();
    FPC_UNICODESTR_DECR_REF(&var_88);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_WRITESTRUNICODE$TEXTREC(void* arg1)
{
    return SYSTEM_$$_WRITESTRUNICODEINTERN$TEXTREC$BOOLEAN(arg1, 0);
}

int64_t SYSTEM_$$_WRITESTRUNICODEFLUSH$TEXTREC(void* arg1)
{
    SYSTEM_$$_WRITESTRUNICODEINTERN$TEXTREC$BOOLEAN(arg1, 1);
    FPC_UNICODESTR_ASSIGN(*(arg1 + 0x50), *(arg1 + 0x58));
    return FPC_UNICODESTR_ASSIGN((arg1 + 0x58), nullptr);
}

uint16_t SYSTEM_$$_SETUPWRITESTRCOMMON$TEXTREC$WORD(char* arg1, int16_t arg2)
{
    int64_t r12;
    r12 = arg2;
    SYSTEM_$$_ASSIGN$TEXT$SHORTSTRING(arg1, &_$SYSTEM$_Ld2);
    *(arg1 + 4) = 0xd7b2;
    *(arg1 + 0x30) = 0;
    *(arg1 + 0x48) = 0;
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = r12;
    int16_t temp0 = r12;
    r12 -= 1;
    
    if (temp0 <= 1)
        U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    *(arg1 + 0x374) = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
    return U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
}

char* fpc_setupwritestr_shortstr(char* arg1, int64_t arg2, int64_t arg3)
{
    SYSTEM_$$_SETUPWRITESTRCOMMON$TEXTREC$WORD(arg1, U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE);
    *(arg1 + 0x50) = arg2;
    SYSTEM_$$_GETMEM$POINTER$QWORD(&arg1[0x58], (arg3 + 1));
    char* result = FPC_SHORTSTR_SETLENGTH(*(arg1 + 0x58), 0xff, 0);
    arg1[0x60] = arg3;
    *(arg1 + 0x38) = SYSTEM_$$_WRITESTRSHORT$TEXTREC;
    *(arg1 + 0x40) = SYSTEM_$$_WRITESTRSHORTFLUSH$TEXTREC;
    return result;
}

void* fpc_setupwritestr_ansistr(char* arg1, int64_t arg2, int16_t arg3)
{
    int64_t r12 = arg2;
    arg2 = arg3;
    
    if (arg2 == 0xffff)
        arg2 = 0;
    
    SYSTEM_$$_SETUPWRITESTRCOMMON$TEXTREC$WORD(arg1, (arg2 & 0xffff));
    *(arg1 + 0x50) = r12;
    *(arg1 + 0x58) = 0;
    *(arg1 + 0x38) = SYSTEM_$$_WRITESTRANSI$TEXTREC;
    *(arg1 + 0x40) = SYSTEM_$$_WRITESTRANSIFLUSH$TEXTREC;
    return &arg1[0x58];
}

void* fpc_setupwritestr_unicodestr(char* arg1, int64_t arg2)
{
    SYSTEM_$$_SETUPWRITESTRCOMMON$TEXTREC$WORD(arg1, 0xfde9);
    *(arg1 + 0x50) = arg2;
    *(arg1 + 0x58) = 0;
    *(arg1 + 0x38) = SYSTEM_$$_WRITESTRUNICODE$TEXTREC;
    *(arg1 + 0x40) = SYSTEM_$$_WRITESTRUNICODEFLUSH$TEXTREC;
    return &arg1[0x58];
}

int64_t SYSTEM_$$_READANSISTRFINAL$TEXTREC(void* arg1)
{
    return FPC_ANSISTR_ASSIGN((arg1 + 0x50), 0);
}

void* SYSTEM_$$_READSTRCOMMON$TEXTREC$PCHAR$INT64(void* arg1, int64_t arg2, int64_t arg3)
{
    void* result = *(arg1 + 0x60);
    void* r12_1 = (arg3 - result);
    
    if (r12_1 >= *(arg1 + 8))
        r12_1 = *(arg1 + 8);
    
    if (r12_1 > 0)
    {
        FPC_MOVE((arg2 + *(arg1 + 0x60)), *(arg1 + 0x28), r12_1);
        result = (arg1 + 0x60);
        *result += r12_1;
    }
    
    *(arg1 + 0x20) = r12_1;
    *(arg1 + 0x18) = 0;
    return result;
}

void* SYSTEM_$$_READSTRANSI$TEXTREC(void* arg1)
{
    void* rdx = *(arg1 + 0x50);
    
    if (rdx != 0)
        rdx = *(rdx - 8);
    
    return SYSTEM_$$_READSTRCOMMON$TEXTREC$PCHAR$INT64(arg1, *(arg1 + 0x50), rdx);
}

void* SYSTEM_$$_SETUPREADSTRCOMMON$TEXTREC$WORD(char* arg1, int16_t arg2)
{
    int64_t r12;
    r12 = arg2;
    SYSTEM_$$_ASSIGN$TEXT$SHORTSTRING(arg1, &_$SYSTEM$_Ld2);
    *(arg1 + 4) = 0xd7b1;
    *(arg1 + 0x30) = 0;
    *(arg1 + 0x48) = 0;
    uint16_t U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = r12;
    int16_t temp0 = r12;
    r12 -= 1;
    
    if (temp0 <= 1)
        U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1 = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE;
    
    *(arg1 + 0x374) = U_$SYSTEM_$$_DEFAULTSYSTEMCODEPAGE_1;
    *(arg1 + 0x60) = 0;
    return &arg1[0x60];
}

int64_t FPC_SETUPREADSTR_ANSISTR(char* arg1, void* arg2)
{
    SYSTEM_$$_SETUPREADSTRCOMMON$TEXTREC$WORD(arg1, SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg2));
    int64_t result = FPC_ANSISTR_ASSIGN(&arg1[0x50], arg2);
    *(arg1 + 0x38) = SYSTEM_$$_READSTRANSI$TEXTREC;
    *(arg1 + 0x40) = SYSTEM_$$_READANSISTRFINAL$TEXTREC;
    return result;
}

int64_t fpc_setupreadstr_shortstr(char* arg1, char* arg2)
{
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_shortstr_to_ansistr(&var_18, arg2, 0);
    FPC_SETUPREADSTR_ANSISTR(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t fpc_setupreadstr_unicodestr(char* arg1, void* arg2)
{
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_unicodestr_to_ansistr(&var_18, arg2, 0);
    FPC_SETUPREADSTR_ANSISTR(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_OPENSTDIO$TEXT$LONGINT$LONGINT(int32_t* arg1, int32_t arg2, int32_t arg3)
{
    SYSTEM_$$_ASSIGN$TEXT$SHORTSTRING(arg1, &_$SYSTEM$_Ld2);
    *arg1 = arg3;
    arg1[1] = arg2;
    *(arg1 + 0x48) = SYSTEM_$$_FILECLOSEFUNC$TEXTREC;
    int16_t result;
    
    if (arg2 == 0xd7b1)
    {
        *(arg1 + 0x38) = SYSTEM_$$_FILEREADFUNC$TEXTREC;
        result = data_434b90(1);
        arg1[0xdd] = result;
        return result;
    }
    
    if (arg2 == 0xd7b2)
    {
        *(arg1 + 0x38) = SYSTEM_$$_FILEWRITEFUNC$TEXTREC;
        arg1[0xdd] = data_434b90(2);
        result = SYSTEM_$$_DO_ISDEVICE$LONGINT$$BOOLEAN(arg3);
        
        if (result != 0)
            *(arg1 + 0x40) = SYSTEM_$$_FILEWRITEFUNC$TEXTREC;
        
        return result;
    }
    
    return FPC_HANDLEERROR(0x66);
}

int64_t SYSTEM_$$_INITFILE$file(char* arg1)
{
    int32_t* rbx = arg1;
    int64_t result = SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(arg1, 0x270, 0);
    *rbx = 0xffffffff;
    rbx[1] = 0xd7b0;
    return result;
}

int64_t SYSTEM_$$_ASSIGN$file$UNICODESTRING(char* arg1, void* arg2)
{
    SYSTEM_$$_INITFILE$file(arg1);
    void var_218;
    int64_t result = fpc_unicodestr_to_widechararray(&var_218, 0xff, arg2);
    __builtin_memcpy(&arg1[0x70], &var_218, 0x40);
    *(arg1 + 0x26e) = 0;
    return result;
}

int64_t SYSTEM_$$_ASSIGN$file$RAWBYTESTRING(char* arg1, void* arg2)
{
    SYSTEM_$$_INITFILE$file(arg1);
    void var_218;
    int64_t result = fpc_ansistr_to_widechararray(&var_218, 0xff, arg2);
    __builtin_memcpy(&arg1[0x70], &var_218, 0x40);
    *(arg1 + 0x26e) = 0;
    return result;
}

int64_t SYSTEM_$$_ASSIGN$file$SHORTSTRING(char* arg1, char* arg2)
{
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_shortstr_to_ansistr(&var_18, arg2, 0);
    SYSTEM_$$_ASSIGN$file$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_ASSIGN$file$PCHAR(char* arg1, char* arg2)
{
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_pchar_to_ansistr(&var_18, arg2, 0);
    SYSTEM_$$_ASSIGN$file$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_ASSIGN$file$CHAR(char* arg1, char arg2)
{
    int64_t r12;
    r12 = arg2;
    void* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    fpc_char_to_ansistr(&var_18, r12, 0);
    SYSTEM_$$_ASSIGN$file$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int16_t* SYSTEM_$$_REWRITE$file$LONGINT(int32_t* arg1, int64_t arg2)
{
    int32_t r12 = arg2;
    uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    int64_t rcx;
    
    if (FPC_THREADVAR_RELOCATE_3 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = arg1[1];
        
        if (rax < 0xd7b0)
        {
        label_421063:
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x66;
        }
        else
        {
            if (rax == 0xd7b0)
                goto label_42108a;
            
            if ((rax != 0xd7b1 && ((rax - 0xd7b1) < 1 || (rax - 0xd7b2) > 1)))
                goto label_421063;
            
            SYSTEM_$$_CLOSE$file(arg1, arg2);
        label_42108a:
            
            if (r12 != 0)
            {
                rcx = 0;
                result = SYSTEM_$$_DO_OPEN$formal$PWIDECHAR$LONGINT$BOOLEAN(arg1, &arg1[0x1c], 0x1002);
                *(arg1 + 8) = r12;
            }
            else
            {
                uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
                
                if (FPC_THREADVAR_RELOCATE_2 == 0)
                    result = &data_434a78;
                else
                    result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
                
                *result = 2;
            }
        }
    }
    
    return result;
}

int16_t* SYSTEM_$$_RESET$file$LONGINT(int32_t* arg1, int64_t arg2)
{
    int32_t r12 = arg2;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    int64_t rcx;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = arg1[1];
        
        if (rax < 0xd7b0)
        {
        label_421153:
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x66;
        }
        else
        {
            if (rax == 0xd7b0)
                goto label_42117a;
            
            if ((rax != 0xd7b1 && ((rax - 0xd7b1) < 1 || (rax - 0xd7b2) > 1)))
                goto label_421153;
            
            SYSTEM_$$_CLOSE$file(arg1, arg2);
        label_42117a:
            
            if (r12 != 0)
            {
                rcx = 0;
                result = SYSTEM_$$_DO_OPEN$formal$PWIDECHAR$LONGINT$BOOLEAN(arg1, &arg1[0x1c], TC_$SYSTEM_$$_FILEMODE);
                *(arg1 + 8) = r12;
            }
            else
            {
                uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
                
                if (FPC_THREADVAR_RELOCATE_3 == 0)
                    result = &data_434a78;
                else
                    result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
                
                *result = 2;
            }
        }
    }
    
    return result;
}

int16_t* SYSTEM_$$_REWRITE$file(int32_t* arg1, int64_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, arg2, &U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    return SYSTEM_$$_REWRITE$file$LONGINT(arg1, 0x80);
}

int16_t* SYSTEM_$$_RESET$file(int32_t* arg1, int64_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, arg2, &U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    return SYSTEM_$$_RESET$file$LONGINT(arg1, 0x80);
}

int16_t* SYSTEM_$$_BLOCKWRITE$file$formal$INT64$INT64(int32_t* arg1, int64_t arg2, int32_t arg3, int64_t* arg4)
{
    *arg4 = 0;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = arg1[1];
        
        if (rax < 0xd7b1)
        {
        label_421344:
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else if (rax == 0xd7b1)
        {
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x69;
        }
        else
        {
            if (((rax - 0xd7b1) < 1 || (rax - 0xd7b2) > 1))
                goto label_421344;
            
            int64_t rax_7;
            int64_t rdx_2;
            rdx_2 = HIGHQ(SYSTEM_$$_DO_WRITE$LONGINT$POINTER$LONGINT$$LONGINT(*arg1, arg2, (arg3 * *(arg1 + 8))));
            rax_7 = LOWQ(SYSTEM_$$_DO_WRITE$LONGINT$POINTER$LONGINT$$LONGINT(*arg1, arg2, (arg3 * *(arg1 + 8))));
            *(arg1 + 8);
            result = (COMBINE(rdx_2, rax_7) / *(arg1 + 8));
            *arg4 = result;
        }
    }
    
    return result;
}

int64_t SYSTEM_$$_BLOCKWRITE$file$formal$LONGINT$LONGINT(int32_t* arg1, int64_t arg2, int32_t arg3, int32_t* arg4)
{
    int32_t result_1;
    SYSTEM_$$_BLOCKWRITE$file$formal$INT64$INT64(arg1, arg2, arg3, &result_1);
    int32_t result = result_1;
    *arg4 = result;
    return result;
}

int64_t SYSTEM_$$_BLOCKWRITE$file$formal$WORD$WORD(int32_t* arg1, int64_t arg2, int16_t arg3, int16_t* arg4)
{
    int16_t result_1;
    SYSTEM_$$_BLOCKWRITE$file$formal$INT64$INT64(arg1, arg2, arg3, &result_1);
    int16_t result = result_1;
    *arg4 = result;
    return result;
}

int64_t SYSTEM_$$_BLOCKWRITE$file$formal$LONGWORD$LONGWORD(int32_t* arg1, int64_t arg2, int32_t arg3, int32_t* arg4)
{
    int32_t result_1;
    SYSTEM_$$_BLOCKWRITE$file$formal$INT64$INT64(arg1, arg2, arg3, &result_1);
    int32_t result = result_1;
    *arg4 = result;
    return result;
}

int64_t SYSTEM_$$_BLOCKWRITE$file$formal$WORD$SMALLINT(int32_t* arg1, int64_t arg2, int16_t arg3, int16_t* arg4)
{
    int16_t result_1;
    SYSTEM_$$_BLOCKWRITE$file$formal$INT64$INT64(arg1, arg2, arg3, &result_1);
    int16_t result = result_1;
    *arg4 = result;
    return result;
}

int16_t* SYSTEM_$$_BLOCKWRITE$file$formal$LONGINT(int32_t* arg1, int64_t arg2, int32_t arg3)
{
    int64_t var_18;
    SYSTEM_$$_BLOCKWRITE$file$formal$INT64$INT64(arg1, arg2, arg3, &var_18);
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        result = arg3;
        
        if ((result > var_18 && arg3 > 0))
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x65;
        }
    }
    
    return result;
}

int16_t* SYSTEM_$$_BLOCKREAD$file$formal$INT64$INT64(int32_t* arg1, int64_t arg2, int32_t arg3, int64_t* arg4)
{
    *arg4 = 0;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = arg1[1];
        
        if (rax < 0xd7b1)
        {
        label_421594:
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else if (rax == 0xd7b1)
        {
        label_421554:
            int64_t rax_7;
            int64_t rdx_2;
            rdx_2 = HIGHQ(SYSTEM_$$_DO_READ$LONGINT$POINTER$LONGINT$$LONGINT(*arg1, arg2, (arg3 * *(arg1 + 8))));
            rax_7 = LOWQ(SYSTEM_$$_DO_READ$LONGINT$POINTER$LONGINT$$LONGINT(*arg1, arg2, (arg3 * *(arg1 + 8))));
            *(arg1 + 8);
            result = (COMBINE(rdx_2, rax_7) / *(arg1 + 8));
            *arg4 = result;
        }
        else
        {
            if (rax != 0xd7b2)
            {
                if (rax != 0xd7b3)
                    goto label_421594;
                
                goto label_421554;
            }
            
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x68;
        }
    }
    
    return result;
}

int64_t SYSTEM_$$_BLOCKREAD$file$formal$LONGINT$LONGINT(int32_t* arg1, int64_t arg2, int32_t arg3, int32_t* arg4)
{
    int32_t result_1;
    SYSTEM_$$_BLOCKREAD$file$formal$INT64$INT64(arg1, arg2, arg3, &result_1);
    int32_t result = result_1;
    *arg4 = result;
    return result;
}

int64_t SYSTEM_$$_BLOCKREAD$file$formal$WORD$WORD(int32_t* arg1, int64_t arg2, int16_t arg3, int16_t* arg4)
{
    int16_t result_1;
    SYSTEM_$$_BLOCKREAD$file$formal$INT64$INT64(arg1, arg2, arg3, &result_1);
    int16_t result = result_1;
    *arg4 = result;
    return result;
}

int64_t SYSTEM_$$_BLOCKREAD$file$formal$LONGWORD$LONGWORD(int32_t* arg1, int64_t arg2, int32_t arg3, int32_t* arg4)
{
    int32_t result_1;
    SYSTEM_$$_BLOCKREAD$file$formal$INT64$INT64(arg1, arg2, arg3, &result_1);
    int32_t result = result_1;
    *arg4 = result;
    return result;
}

int64_t SYSTEM_$$_BLOCKREAD$file$formal$WORD$SMALLINT(int32_t* arg1, int64_t arg2, int16_t arg3, int16_t* arg4)
{
    int16_t result_1;
    SYSTEM_$$_BLOCKREAD$file$formal$INT64$INT64(arg1, arg2, arg3, &result_1);
    int16_t result = result_1;
    *arg4 = result;
    return result;
}

int16_t* SYSTEM_$$_BLOCKREAD$file$formal$INT64(int32_t* arg1, int64_t arg2, int64_t arg3)
{
    int64_t var_18;
    SYSTEM_$$_BLOCKREAD$file$formal$INT64$INT64(arg1, arg2, arg3, &var_18);
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
    
    if ((*result == 0 && (arg3 > var_18 && arg3 > 0)))
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *result = 0x64;
    }
    
    return result;
}

int64_t SYSTEM_$$_FILEPOS$file$$INT64(int32_t* arg1, int64_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434a78;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, arg2, &U_$SYSTEM_$$_INOUTRES);
    
    if (*rax == 0)
    {
        int32_t rax_1 = arg1[1];
        
        if (rax_1 >= 0xd7b1)
        {
            if (rax_1 == 0xd7b1)
            {
            label_421777:
                *arg1;
                int64_t rax_6;
                int64_t rdx_1;
                rdx_1 = HIGHQ(SYSTEM_$$_DO_FILEPOS$LONGINT$$INT64());
                rax_6 = LOWQ(SYSTEM_$$_DO_FILEPOS$LONGINT$$INT64());
                *(arg1 + 8);
                return (COMBINE(rdx_1, rax_6) / *(arg1 + 8));
            }
            
            if (((rax_1 - 0xd7b1) >= 1 && (rax_1 - 0xd7b2) <= 1))
                goto label_421777;
        }
        
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_8;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            rax_8 = &data_434a78;
        else
            rax_8 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
        
        *rax_8 = 0x67;
    }
    
    return 0;
}

int64_t SYSTEM_$$_FILESIZE$file$$INT64(int32_t* arg1, int64_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* rax;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax = &data_434a78;
    else
        rax = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, arg2, &U_$SYSTEM_$$_INOUTRES);
    
    if (*rax == 0)
    {
        int32_t rax_1 = arg1[1];
        
        if ((rax_1 < 0xd7b1 || (rax_1 != 0xd7b1 && ((rax_1 - 0xd7b1) < 1 || (rax_1 - 0xd7b2) > 1))))
        {
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            int16_t* rax_8;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                rax_8 = &data_434a78;
            else
                rax_8 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *rax_8 = 0x67;
        }
        else if (*(arg1 + 8) > 0)
        {
            *arg1;
            int64_t rax_6;
            int64_t rdx_1;
            rdx_1 = HIGHQ(SYSTEM_$$_DO_FILESIZE$LONGINT$$INT64());
            rax_6 = LOWQ(SYSTEM_$$_DO_FILESIZE$LONGINT$$INT64());
            *(arg1 + 8);
            return (COMBINE(rdx_1, rax_6) / *(arg1 + 8));
        }
    }
    
    return 0;
}

int16_t* SYSTEM_$$_EOF$file$$BOOLEAN(int32_t* arg1)
{
    int64_t r12;
    r12 = 0;
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    int64_t rsi;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, rsi, &U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = arg1[1];
        
        if ((rax < 0xd7b1 || (rax != 0xd7b1 && ((rax - 0xd7b1) < 1 || (rax - 0xd7b2) > 1))))
        {
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            int64_t rax_4;
            int64_t rsi_1;
            rax_4 = SYSTEM_$$_FILESIZE$file$$INT64(arg1, rsi);
            r12 = rax_4 <= SYSTEM_$$_FILEPOS$file$$INT64(arg1, rsi_1);
        }
    }
    
    result = r12;
    return result;
}

int16_t* SYSTEM_$$_SEEK$file$INT64(int32_t* arg1, int64_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = arg1[1];
        
        if (rax >= 0xd7b1)
        {
            if (rax == 0xd7b1)
            {
            label_421987:
                *(arg1 + 8);
                *arg1;
                return SYSTEM_$$_DO_SEEK$LONGINT$INT64();
            }
            
            if (((rax - 0xd7b1) >= 1 && (rax - 0xd7b2) <= 1))
                goto label_421987;
        }
        
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
        
        *result = 0x67;
    }
    
    return result;
}

int16_t* SYSTEM_$$_TRUNCATE$file(int32_t* arg1)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    int64_t rsi;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, rsi, &U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = arg1[1];
        
        if ((rax >= 0xd7b2 && rax <= 0xd7b3))
        {
            SYSTEM_$$_FILEPOS$file$$INT64(arg1, rsi);
            *(arg1 + 8);
            *arg1;
            return SYSTEM_$$_DO_TRUNCATE$LONGINT$INT64();
        }
        
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
        
        *result = 0x67;
    }
    
    return result;
}

int16_t* SYSTEM_$$_CLOSE$file(int32_t* arg1, int64_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES, arg2, &U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = arg1[1];
        
        if ((rax < 0xd7b1 || (rax != 0xd7b1 && ((rax - 0xd7b1) < 1 || (rax - 0xd7b2) > 1))))
        {
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            result = SYSTEM_$$_DO_CLOSE$LONGINT(*arg1);
            arg1[1] = 0xd7b0;
        }
    }
    
    return result;
}

int16_t* SYSTEM_$$_ERASE$file(void* arg1)
{
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    int64_t rsi;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        if (*(arg1 + 4) == 0xd7b0)
        {
            rsi = 0;
            return SYSTEM_$$_DO_ERASE$PWIDECHAR$BOOLEAN((arg1 + 0x70));
        }
        
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            result = &data_434a78;
        else
            result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *result = 0x66;
    }
    
    return result;
}

int64_t SYSTEM_$$_RENAME$file$UNICODESTRING(void* arg1, uint16_t* arg2)
{
    uint16_t* var_278 = nullptr;
    void var_270;
    void var_258;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_258, &var_270), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
    int16_t* rax_1;
    
    if (FPC_THREADVAR_RELOCATE_3 == 0)
        rax_1 = &data_434a78;
    else
        rax_1 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
    
    if (*rax_1 == 0)
    {
        if (*(arg1 + 4) == 0xd7b0)
        {
            SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$UNICODESTRING$$RAWBYTESTRING(&var_278, arg2);
            uint16_t* rsi_2 = var_278;
            
            if (rsi_2 == 0)
                rsi_2 = &FPC_EMPTYCHAR;
            
            int64_t rdx_1;
            rdx_1 = 0;
            SYSTEM_$$_DO_RENAME$PWIDECHAR$PCHAR$BOOLEAN$BOOLEAN((arg1 + 0x70), rsi_2, rdx_1, 1);
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            int16_t* rax_3;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                rax_3 = &data_434a78;
            else
                rax_3 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            if (*rax_3 == 0)
            {
                void var_210;
                fpc_ansistr_to_widechararray(&var_210, 0xff, var_278);
                __builtin_memcpy((arg1 + 0x70), &var_210, 0x40);
            }
        }
        else
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            int16_t* rax_2;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                rax_2 = &data_434a78;
            else
                rax_2 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *rax_2 = 0x66;
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_278);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_RENAME$file$RAWBYTESTRING(void* arg1, uint16_t* arg2)
{
    int64_t r13;
    int64_t var_18 = r13;
    int64_t r14;
    int64_t var_20 = r14;
    uint16_t* var_288 = nullptr;
    void var_280;
    void var_268;
    int64_t rbp;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_268, &var_280), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
    int16_t* rax_1;
    
    if (FPC_THREADVAR_RELOCATE_3 == 0)
        rax_1 = &data_434a78;
    else
        rax_1 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
    
    if (*rax_1 == 0)
    {
        if (*(arg1 + 4) == 0xd7b0)
        {
            r13 = 0;
            uint16_t* rax_3 = arg2;
            
            if (arg2 == 0)
                rax_3 = &FPC_EMPTYCHAR;
            
            uint16_t* r14_1 = rax_3;
            
            if (SYSTEM_$$_STRINGCODEPAGE$RAWBYTESTRING$$WORD(arg2) == U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE)
                FPC_ANSISTR_ASSIGN(&var_288, arg2);
            else
            {
                SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$RAWBYTESTRING$$RAWBYTESTRING(&var_288, arg2);
                uint16_t* rax_5 = var_288;
                
                if (rax_5 == 0)
                    rax_5 = &FPC_EMPTYCHAR;
                
                r14_1 = rax_5;
                r13 = 1;
            }
            
            int64_t rdx_1;
            rdx_1 = 0;
            SYSTEM_$$_DO_RENAME$PWIDECHAR$PCHAR$BOOLEAN$BOOLEAN((arg1 + 0x70), r14_1, rdx_1, r13);
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            int16_t* rax_6;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                rax_6 = &data_434a78;
            else
                rax_6 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            if (*rax_6 == 0)
            {
                void var_220;
                fpc_ansistr_to_widechararray(&var_220, 0xff, var_288);
                __builtin_memcpy((arg1 + 0x70), &var_220, 0x40);
            }
        }
        else
        {
            uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
            int16_t* rax_2;
            
            if (FPC_THREADVAR_RELOCATE_1 == 0)
                rax_2 = &data_434a78;
            else
                rax_2 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
            
            *rax_2 = 0x66;
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_288);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_RENAME$file$SHORTSTRING(void* arg1, char* arg2)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_shortstr_to_ansistr(&var_18, arg2, 0);
    SYSTEM_$$_RENAME$file$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_RENAME$file$PCHAR(void* arg1, char* arg2)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_pchar_to_ansistr(&var_18, arg2, 0);
    SYSTEM_$$_RENAME$file$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_RENAME$file$CHAR(void* arg1, char arg2)
{
    int64_t r12;
    r12 = arg2;
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    fpc_char_to_ansistr(&var_18, r12, 0);
    SYSTEM_$$_RENAME$file$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_ASSIGN$TYPEDFILE$UNICODESTRING(char* arg1, void* arg2)
{
    return SYSTEM_$$_ASSIGN$file$UNICODESTRING(arg1, arg2);
}

int64_t SYSTEM_$$_ASSIGN$TYPEDFILE$RAWBYTESTRING(char* arg1, void* arg2)
{
    return SYSTEM_$$_ASSIGN$file$RAWBYTESTRING(arg1, arg2);
}

int64_t SYSTEM_$$_ASSIGN$TYPEDFILE$SHORTSTRING(char* arg1, char* arg2)
{
    return SYSTEM_$$_ASSIGN$file$SHORTSTRING(arg1, arg2);
}

int64_t SYSTEM_$$_ASSIGN$TYPEDFILE$PCHAR(char* arg1, char* arg2)
{
    return SYSTEM_$$_ASSIGN$file$PCHAR(arg1, arg2);
}

int64_t SYSTEM_$$_ASSIGN$TYPEDFILE$CHAR(char* arg1, char arg2)
{
    return SYSTEM_$$_ASSIGN$file$CHAR(arg1, arg2);
}

int16_t* FPC_RESET_TYPED(int32_t* arg1, int64_t arg2)
{
    return SYSTEM_$$_RESET$file$LONGINT(arg1, arg2);
}

int16_t* FPC_REWRITE_TYPED(int32_t* arg1, int64_t arg2)
{
    return SYSTEM_$$_REWRITE$file$LONGINT(arg1, arg2);
}

uint64_t SYSTEM_$$_GETTEMPDIR$$SHORTSTRING(char* arg1)
{
    int64_t r12;
    int64_t var_10 = r12;
    int64_t r13;
    int64_t var_18 = r13;
    int64_t r14;
    int64_t var_20 = r14;
    char var_128;
    FPC_SHORTSTR_TO_SHORTSTR(&var_128, 0xff, &_$SYSTEM$_Ld50);
    uint64_t U_$SYSTEM_$$_ENVP_1;
    
    while (true)
    {
        U_$SYSTEM_$$_ENVP_1 = U_$SYSTEM_$$_ENVP;
        
        if (U_$SYSTEM_$$_ENVP_1 == 0)
            break;
        
        if (*U_$SYSTEM_$$_ENVP_1 == 0)
            break;
        
        r14 = 0;
        r12 = 1;
        void var_228;
        
        while (true)
        {
            uint32_t rax_5 = *(**&U_$SYSTEM_$$_ENVP + r14);
            
            if (rax_5 == 0)
                break;
            
            if (rax_5 == 0x3d)
                break;
            
            if (rax_5 == 0x3d)
                break;
            
            int64_t rax_2;
            rax_2 = **&U_$SYSTEM_$$_ENVP[r14];
            *(&var_228 + r12) = rax_2;
            r14 += 1;
            r12 += 1;
        }
        
        FPC_SHORTSTR_SETLENGTH(&var_228, 0xff, (r12 - 1));
        
        if (FPC_SHORTSTR_COMPARE_EQUAL(&var_228, &_$SYSTEM$_Ld51) == 0)
        {
        label_422155:
            r14 += 1;
            r13 = 1;
            
            while (**&U_$SYSTEM_$$_ENVP[r14] != 0)
            {
                int64_t rax_10;
                rax_10 = **&U_$SYSTEM_$$_ENVP[r14];
                &var_128[r13] = rax_10;
                r14 += 1;
                r13 += 1;
            }
            
            FPC_SHORTSTR_SETLENGTH(&var_128, 0xff, (r13 - 1));
        }
        else
        {
            if (FPC_SHORTSTR_COMPARE_EQUAL(&var_228, &_$SYSTEM$_Ld52) == 0)
                goto label_422155;
            
            if (FPC_SHORTSTR_COMPARE_EQUAL(&var_228, &_$SYSTEM$_Ld53) == 0)
                goto label_422155;
        }
        
        U_$SYSTEM_$$_ENVP += 8;
    }
    
    U_$SYSTEM_$$_ENVP_1 = var_128;
    
    if ((U_$SYSTEM_$$_ENVP_1 > 0 && &var_128[(U_$SYSTEM_$$_ENVP_1 & 0xff)] != 0x2f))
        fpc_shortstr_concat(&var_128, 0xff, &var_128, &_$SYSTEM$_Ld54);
    
    return FPC_SHORTSTR_TO_SHORTSTR(arg1, 0xff, &var_128);
}

int64_t SYSTEM_$$_DOASSIGN$TYPEDFILE(char* arg1)
{
    void var_208;
    SYSTEM_$$_GETTEMPDIR$$SHORTSTRING(&var_208);
    void* var_228 = &var_208;
    uint48_t* const var_220 = &_$SYSTEM$_Ld55;
    void var_108;
    SYSTEM_$$_HEXSTR$LONGINT$BYTE$$SHORTSTRING(&var_108, SYSTEM_$$_RANDOM$LONGINT$$LONGINT(0x3b9aca00), 8);
    void* var_218 = &var_108;
    uint48_t* const var_210 = &_$SYSTEM$_Ld56;
    void var_328;
    fpc_shortstr_concat_multi(&var_328, 0xff, &var_228, 3);
    return SYSTEM_$$_ASSIGN$TYPEDFILE$SHORTSTRING(arg1, &var_328);
}

int16_t* FPC_RESET_TYPED_ISO(char* arg1, int32_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    if (*(arg1 + 4) == 0)
        SYSTEM_$$_DOASSIGN$TYPEDFILE(arg1);
    
    arg1[0x10] = 0;
    SYSTEM_$$_RESET$file$LONGINT(arg1, arg2);
    return SYSTEM_$$_BLOCKREAD$file$formal$INT64(arg1, &arg1[0x270], 1);
}

int16_t* FPC_REWRITE_TYPED_ISO(char* arg1, int32_t arg2)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    if (*(arg1 + 4) == 0)
        SYSTEM_$$_DOASSIGN$TYPEDFILE(arg1);
    
    return SYSTEM_$$_REWRITE$file$LONGINT(arg1, arg2);
}

int16_t* FPC_RESET_TYPED_NAME_ISO(char* arg1, char* arg2, int32_t arg3)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    if (*(arg1 + 4) == 0)
        SYSTEM_$$_ASSIGN$TYPEDFILE$SHORTSTRING(arg1, arg2);
    
    arg1[0x10] = 0;
    SYSTEM_$$_RESET$file$LONGINT(arg1, arg3);
    return SYSTEM_$$_BLOCKREAD$file$formal$INT64(arg1, &arg1[0x270], 1);
}

int16_t* FPC_REWRITE_TYPED_NAME_ISO(char* arg1, char* arg2, int32_t arg3)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result != 0)
        return result;
    
    if (*(arg1 + 4) == 0)
        SYSTEM_$$_ASSIGN$TYPEDFILE$SHORTSTRING(arg1, arg2);
    
    return SYSTEM_$$_REWRITE$file$LONGINT(arg1, arg3);
}

int16_t* FPC_TYPED_WRITE(int32_t arg1, int32_t* arg2, int64_t arg3)
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = arg2[1];
        
        if (rax < 0xd7b1)
        {
        label_422561:
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else
        {
            if (rax != 0xd7b1)
            {
                if (((rax - 0xd7b1) >= 1 && (rax - 0xd7b2) <= 1))
                    return SYSTEM_$$_DO_WRITE$LONGINT$POINTER$LONGINT$$LONGINT(*arg2, arg3, arg1);
                
                goto label_422561;
            }
            
            uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_3 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x69;
        }
    }
    
    return result;
}

int16_t* FPC_TYPED_READ(int32_t arg1, int32_t* arg2, int64_t arg3)
{
    uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_3 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
    
    if (*result == 0)
    {
        int32_t rax = arg2[1];
        
        if (rax < 0xd7b1)
        {
        label_42266d:
            uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_2 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x67;
        }
        else if (rax == 0xd7b1)
        {
        label_4225fd:
            result = SYSTEM_$$_DO_READ$LONGINT$POINTER$LONGINT$$LONGINT(*arg2, arg3, arg1);
            
            if (arg1 > result)
            {
                uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
                
                if (FPC_THREADVAR_RELOCATE_1 == 0)
                    result = &data_434a78;
                else
                    result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
                
                *result = 0x64;
            }
        }
        else
        {
            if (rax != 0xd7b2)
            {
                if (rax != 0xd7b3)
                    goto label_42266d;
                
                goto label_4225fd;
            }
            
            uint64_t FPC_THREADVAR_RELOCATE_4 = FPC_THREADVAR_RELOCATE;
            
            if (FPC_THREADVAR_RELOCATE_4 == 0)
                result = &data_434a78;
            else
                result = FPC_THREADVAR_RELOCATE_4(U_$SYSTEM_$$_INOUTRES);
            
            *result = 0x68;
        }
    }
    
    return result;
}

int64_t FPC_TYPED_READ_ISO(int32_t arg1, int32_t* arg2, char* arg3)
{
    FPC_MOVE(&arg2[0x9c], arg3, arg1);
    char result = SYSTEM_$$_EOF$file$$BOOLEAN(arg2);
    
    if (result == 0)
        return SYSTEM_$$_BLOCKREAD$file$formal$INT64(arg2, &arg2[0x9c], 1);
    
    arg2[4] = 1;
    return result;
}

int64_t fpc_getbuf_typedfile(int64_t arg1) __pure
{
    return (arg1 + 0x270);
}

int64_t fpc_typedfile_init_iso(char* arg1, int32_t arg2)
{
    void var_108;
    SYSTEM_$$_PARAMSTR$LONGINT$$SHORTSTRING(&var_108, arg2);
    return SYSTEM_$$_ASSIGN$TYPEDFILE$SHORTSTRING(arg1, &var_108);
}

int64_t fpc_typedfile_init_filename_iso(char* arg1, int32_t arg2, char* arg3)
{
    char var_118;
    SYSTEM_$$_PARAMSTR$LONGINT$$SHORTSTRING(&var_118, arg2);
    
    if (var_118 == 0)
        return SYSTEM_$$_ASSIGN$TYPEDFILE$SHORTSTRING(arg1, arg3);
    
    SYSTEM_$$_PARAMSTR$LONGINT$$SHORTSTRING(&var_118, arg2);
    return SYSTEM_$$_ASSIGN$TYPEDFILE$SHORTSTRING(arg1, &var_118);
}

int16_t* fpc_typedfile_close_iso(int32_t* arg1)
{
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int16_t* rax;
    int64_t rsi;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        rax = &data_434a78;
    else
        rax = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
    
    *rax = 0;
    SYSTEM_$$_CLOSE$file(arg1, rsi);
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* result;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        result = &data_434a78;
    else
        result = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    *result = 0;
    return result;
}

int64_t SYSTEM_$$_DO_MKDIR$RAWBYTESTRING(uint16_t* arg1)
{
    uint16_t* var_68 = arg1;
    FPC_ANSISTR_INCR_REF(arg1);
    void var_60;
    void var_48;
    int64_t rbx;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_48, &var_60), rbx, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    uint16_t* rdi_1 = var_68;
    
    if (rdi_1 == 0)
        rdi_1 = &FPC_EMPTYCHAR;
    
    if (FPC_SYSC_MKDIR(rdi_1, 0x1ff) < 0)
        SYSTEM_$$_ERRNO2INOUTRES$$WORD();
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_68);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_DO_RMDIR$RAWBYTESTRING(uint64_t arg1)
{
    uint64_t var_68 = arg1;
    FPC_ANSISTR_INCR_REF(arg1);
    void var_60;
    void var_48;
    int64_t rbx;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_48, &var_60), rbx, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    
    if (FPC_ANSISTR_COMPARE_EQUAL(var_68, &.Ld33) != 0)
    {
        uint64_t rdi_3 = var_68;
        
        if (rdi_3 == 0)
            rdi_3 = &FPC_EMPTYCHAR;
        
        if (FPC_SYSC_RMDIR(rdi_3) < 0)
            SYSTEM_$$_ERRNO2INOUTRES$$WORD();
    }
    else
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_2;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_2 = &data_434a78;
        else
            rax_2 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *rax_2 = 0x10;
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_68);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_DO_CHDIR$RAWBYTESTRING(uint16_t* arg1)
{
    uint16_t* var_68 = arg1;
    FPC_ANSISTR_INCR_REF(arg1);
    void var_60;
    void var_48;
    int64_t rbx;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_48, &var_60), rbx, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    uint16_t* rdi_1 = var_68;
    
    if (rdi_1 == 0)
        rdi_1 = &FPC_EMPTYCHAR;
    
    if (FPC_SYSC_CHDIR(rdi_1) < 0)
        SYSTEM_$$_ERRNO2INOUTRES$$WORD();
    
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int16_t* rax_2;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax_2 = &data_434a78;
    else
        rax_2 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
    
    if (*rax_2 == 2)
    {
        uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_3;
        
        if (FPC_THREADVAR_RELOCATE_2 == 0)
            rax_3 = &data_434a78;
        else
            rax_3 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_INOUTRES);
        
        *rax_3 = 3;
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_68);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_DO_GETDIR$BYTE$RAWBYTESTRING(int64_t arg1, int64_t* arg2)
{
    int64_t r12;
    int64_t var_10 = r12;
    int64_t r13;
    int64_t var_18 = r13;
    int64_t i = 0;
    uint64_t var_160 = 0;
    int64_t var_c8 = 0;
    uint16_t* var_20 = nullptr;
    int64_t var_28 = 0;
    void var_c0;
    void var_a8;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_a8, &var_c0), arg2, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    FPC_ANSISTR_ASSIGN(arg2, 0);
    void var_a88;
    
    if (FPC_SYSC_GETCWD(&var_a88, 0x800) == 0)
    {
        FPC_ANSISTR_ASSIGN(&var_160, 0);
        FPC_ANSISTR_ASSIGN(&var_c8, &.Ld57);
        int64_t var_1f8;
        
        if (FPC_SYSC_STAT(var_c8, &var_1f8) >= 0)
        {
            while (true)
            {
                uint64_t var_60 = var_160;
                void* const var_58_1 = &.Ld33;
                void* const var_50_1 = &.Ld58;
                fpc_ansistr_concat_multi(&var_c8, &var_60, 2, 0xffff);
                int64_t var_288;
                
                if (FPC_SYSC_STAT(var_c8, &var_288) < 0)
                    break;
                
                var_60 = var_160;
                void* const var_58_2 = &.Ld59;
                void* const var_50_2 = &.Ld58;
                fpc_ansistr_concat_multi(&var_c8, &var_60, 2, 0xffff);
                int32_t* rax_6 = FPC_SYSC_OPENDIR(var_c8);
                
                if (rax_6 == 0)
                    break;
                
                int64_t var_280;
                
                do
                {
                    FPC_ANSISTR_ASSIGN(&i, 0);
                    int64_t* rax_7 = FPC_SYSC_READDIR(rax_6);
                    
                    if (rax_7 == 0)
                        break;
                    
                    uint64_t var_48 = var_160;
                    void* const var_40_1 = &.Ld60;
                    fpc_chararray_to_ansistr(&var_28, (rax_7 + 0x13), 0xfec, 0, 1);
                    int64_t var_38_1 = var_28;
                    void* const var_30_1 = &.Ld58;
                    fpc_ansistr_concat_multi(&var_c8, &var_48, 3, 0xffff);
                    int64_t var_158;
                    int64_t var_150;
                    
                    if ((FPC_SYSC_STAT(var_c8, &var_158) == 0 && (var_288 == var_158 && var_280 == var_150)))
                    {
                        if (*(rax_7 + 0x13) != 0x2e)
                        {
                            fpc_chararray_to_ansistr(&var_20, (rax_7 + 0x13), 0xfec, 0, 1);
                            fpc_ansistr_concat(&i, &.Ld61, var_20, 0xffff);
                        }
                        else
                        {
                            char rdx_2 = *(rax_7 + 0x14);
                            
                            if ((rdx_2 != 0 && (rdx_2 != 0x2e || *(rax_7 + 0x15) != 0)))
                            {
                                fpc_chararray_to_ansistr(&var_20, (rax_7 + 0x13), 0xfec, 0, 1);
                                fpc_ansistr_concat(&i, &.Ld61, var_20, 0xffff);
                            }
                        }
                    }
                } while (i == 0);
                
                if (FPC_SYSC_CLOSEDIR(rax_6) < 0)
                    break;
                
                fpc_ansistr_concat(&var_160, var_160, &.Ld60, 0xffff);
                
                if (var_288 == var_1f8)
                {
                    int64_t var_1f0;
                    
                    if (var_280 == var_1f0)
                    {
                        if (i != 0)
                        {
                            FPC_ANSISTR_ASSIGN(arg2, i);
                            FPC_ANSISTR_ASSIGN(&i, 0);
                        }
                        else
                            FPC_ANSISTR_ASSIGN(arg2, &.Ld61);
                        
                        SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg2, U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE, 0);
                        break;
                    }
                }
            }
        }
    }
    else
    {
        fpc_chararray_to_ansistr(arg2, &var_a88, 0x7ff, 0, 1);
        SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg2, U_$SYSTEM_$$_DEFAULTFILESYSTEMCODEPAGE, 0);
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_20);
    FPC_ANSISTR_DECR_REF(&var_28);
    FPC_ANSISTR_DECR_REF(&i);
    FPC_ANSISTR_DECR_REF(&var_160);
    FPC_ANSISTR_DECR_REF(&var_c8);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_MKDIR$RAWBYTESTRING(int64_t arg1)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    
    if (arg1 != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_1 = &data_434a78;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        if (*rax_1 == 0)
        {
            SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$RAWBYTESTRING$$RAWBYTESTRING(&var_18, arg1);
            SYSTEM_$$_DO_MKDIR$RAWBYTESTRING(var_18);
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_RMDIR$RAWBYTESTRING(int64_t arg1)
{
    uint64_t var_18 = 0;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    
    if (arg1 != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_1 = &data_434a78;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        if (*rax_1 == 0)
        {
            SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$RAWBYTESTRING$$RAWBYTESTRING(&var_18, arg1);
            SYSTEM_$$_DO_RMDIR$RAWBYTESTRING(var_18);
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_CHDIR$RAWBYTESTRING(int64_t arg1)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    
    if (arg1 != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_1 = &data_434a78;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        if (*rax_1 == 0)
        {
            SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$RAWBYTESTRING$$RAWBYTESTRING(&var_18, arg1);
            SYSTEM_$$_DO_CHDIR$RAWBYTESTRING(var_18);
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_GETDIR$BYTE$RAWBYTESTRING(char arg1, int64_t* arg2)
{
    SYSTEM_$$_DO_GETDIR$BYTE$RAWBYTESTRING(arg1, arg2);
    return SYSTEM_$$_SETCODEPAGE$RAWBYTESTRING$WORD$BOOLEAN(arg2, U_$SYSTEM_$$_DEFAULTRTLFILESYSTEMCODEPAGE, 1);
}

int64_t SYSTEM_$$_GETDIRSTRFROMSHORTSTRING$SHORTSTRING$$RAWBYTESTRING(int64_t* arg1, char* arg2)
{
    int64_t var_18 = 0;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    fpc_shortstr_to_ansistr(&var_18, arg2, 0);
    SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$RAWBYTESTRING$$RAWBYTESTRING(arg1, var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_MKDIR$SHORTSTRING(char* arg1)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    
    if (*arg1 != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_1 = &data_434a78;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        if (*rax_1 == 0)
        {
            SYSTEM_$$_GETDIRSTRFROMSHORTSTRING$SHORTSTRING$$RAWBYTESTRING(&var_18, arg1);
            SYSTEM_$$_DO_MKDIR$RAWBYTESTRING(var_18);
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_RMDIR$SHORTSTRING(char* arg1)
{
    uint64_t var_18 = 0;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    
    if (*arg1 != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_1 = &data_434a78;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        if (*rax_1 == 0)
        {
            SYSTEM_$$_GETDIRSTRFROMSHORTSTRING$SHORTSTRING$$RAWBYTESTRING(&var_18, arg1);
            SYSTEM_$$_DO_RMDIR$RAWBYTESTRING(var_18);
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_CHDIR$SHORTSTRING(char* arg1)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    
    if (*arg1 != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_1 = &data_434a78;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        if (*rax_1 == 0)
        {
            SYSTEM_$$_GETDIRSTRFROMSHORTSTRING$SHORTSTRING$$RAWBYTESTRING(&var_18, arg1);
            SYSTEM_$$_DO_CHDIR$RAWBYTESTRING(var_18);
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_GETDIR$BYTE$OPENSTRING(char arg1, char* arg2, uint64_t arg3)
{
    int64_t rbx;
    rbx = arg1;
    uint64_t var_88 = 0;
    void var_80;
    void var_68;
    int64_t rbp;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_68, &var_80), rbx, rbp, arg2, arg3, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_DO_GETDIR$BYTE$RAWBYTESTRING(rbx, &var_88);
    uint64_t rax_1 = var_88;
    
    if (rax_1 != 0)
        rax_1 = *(rax_1 - 8);
    
    if (rax_1 > arg3)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_2;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_2 = &data_434a78;
        else
            rax_2 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        *rax_2 = 3;
    }
    else
        FPC_ANSISTR_TO_SHORTSTR(arg2, arg3, var_88);
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_88);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_DO_MKDIR$UNICODESTRING(uint16_t* arg1)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$UNICODESTRING$$RAWBYTESTRING(&var_18, arg1);
    SYSTEM_$$_DO_MKDIR$RAWBYTESTRING(var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_DO_RMDIR$UNICODESTRING(uint16_t* arg1)
{
    uint64_t var_18 = 0;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$UNICODESTRING$$RAWBYTESTRING(&var_18, arg1);
    SYSTEM_$$_DO_RMDIR$RAWBYTESTRING(var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_DO_CHDIR$UNICODESTRING(uint16_t* arg1)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$UNICODESTRING$$RAWBYTESTRING(&var_18, arg1);
    SYSTEM_$$_DO_CHDIR$RAWBYTESTRING(var_18);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_DO_GETDIR$BYTE$UNICODESTRING(char arg1, void** arg2)
{
    int64_t rbx;
    rbx = arg1;
    uint16_t* var_78 = nullptr;
    void var_70;
    void var_58;
    int64_t rbp;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_58, &var_70), rbx, rbp, arg2, r13, r14, r15);
    int64_t result = 0;
    SYSTEM_$$_DO_GETDIR$BYTE$RAWBYTESTRING(rbx, &var_78);
    fpc_ansistr_to_unicodestr(arg2, var_78);
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_78);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_MKDIR$UNICODESTRING(uint16_t* arg1)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    
    if (arg1 != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_1 = &data_434a78;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        if (*rax_1 == 0)
        {
            SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$UNICODESTRING$$RAWBYTESTRING(&var_18, arg1);
            SYSTEM_$$_DO_MKDIR$RAWBYTESTRING(var_18);
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_RMDIR$UNICODESTRING(uint16_t* arg1)
{
    uint64_t var_18 = 0;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    
    if (arg1 != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_1 = &data_434a78;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        if (*rax_1 == 0)
        {
            SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$UNICODESTRING$$RAWBYTESTRING(&var_18, arg1);
            SYSTEM_$$_DO_RMDIR$RAWBYTESTRING(var_18);
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_CHDIR$UNICODESTRING(uint16_t* arg1)
{
    uint16_t* var_18 = nullptr;
    void var_78;
    void var_60;
    int64_t rbp;
    int64_t r12;
    int64_t r13;
    int64_t r14;
    int64_t r15;
    FPC_SETJMP(FPC_PUSHEXCEPTADDR(1, &var_60, &var_78), arg1, rbp, r12, r13, r14, r15);
    int64_t result = 0;
    
    if (arg1 != 0)
    {
        uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
        int16_t* rax_1;
        
        if (FPC_THREADVAR_RELOCATE_1 == 0)
            rax_1 = &data_434a78;
        else
            rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INOUTRES);
        
        if (*rax_1 == 0)
        {
            SYSTEM_$$_TOSINGLEBYTEFILESYSTEMENCODEDFILENAME$UNICODESTRING$$RAWBYTESTRING(&var_18, arg1);
            SYSTEM_$$_DO_CHDIR$RAWBYTESTRING(var_18);
        }
    }
    
    FPC_POPADDRSTACK();
    FPC_ANSISTR_DECR_REF(&var_18);
    
    if (result == 0)
        return result;
    
    return FPC_RERAISE();
}

int64_t SYSTEM_$$_GETDIR$BYTE$UNICODESTRING(char arg1, void** arg2)
{
    return SYSTEM_$$_DO_GETDIR$BYTE$UNICODESTRING(arg1, arg2);
}

int64_t SYSTEM_$$_IS_INTRESOURCE$PCHAR$$BOOLEAN(int64_t arg1) __pure
{
    int64_t result;
    result = (arg1 >> 0x10) == 0;
    return result;
}

uint64_t SYSTEM_$$_MAKELANGID$WORD$WORD$$WORD(int16_t arg1, int16_t arg2) __pure
{
    return ((arg1 & 0x3ff) | (arg2 << 0xa));
}

int64_t SYSTEM_$$_FINDRESOURCE$QWORD$ANSISTRING$ANSISTRING$$QWORD(int64_t arg1, int64_t arg2, int64_t arg3)
{
    return SYSTEM_$$_FINDRESOURCE$QWORD$PCHAR$PCHAR$$QWORD();
}

int64_t SYSTEM_$$_FINDRESOURCEEX$QWORD$ANSISTRING$ANSISTRING$WORD$$QWORD(int64_t arg1, uint16_t* arg2, uint16_t* arg3, int16_t arg4)
{
    if (arg3 == 0)
        arg3 = &FPC_EMPTYCHAR;
    
    if (arg2 == 0)
        arg2 = &FPC_EMPTYCHAR;
    
    return SYSTEM_$$_FINDRESOURCEEX$QWORD$PCHAR$PCHAR$WORD$$QWORD(arg1, arg2, arg3, arg4);
}

int64_t SYSTEM_$$_FINDRESOURCE$QWORD$ANSISTRING$PCHAR$$QWORD(int64_t arg1, int64_t arg2)
{
    return SYSTEM_$$_FINDRESOURCE$QWORD$PCHAR$PCHAR$$QWORD();
}

int64_t SYSTEM_$$_FINDRESOURCEEX$QWORD$PCHAR$ANSISTRING$WORD$$QWORD(int64_t arg1, int64_t arg2, uint16_t* arg3, int16_t arg4)
{
    if (arg3 == 0)
        arg3 = &FPC_EMPTYCHAR;
    
    return SYSTEM_$$_FINDRESOURCEEX$QWORD$PCHAR$PCHAR$WORD$$QWORD(arg1, arg2, arg3, arg4);
}

int64_t SYSTEM_$$_FINDRESOURCE$QWORD$PCHAR$ANSISTRING$$QWORD(int64_t arg1, int64_t arg2, int64_t arg3)
{
    return SYSTEM_$$_FINDRESOURCE$QWORD$PCHAR$PCHAR$$QWORD();
}

int64_t SYSTEM_$$_FINDRESOURCEEX$QWORD$ANSISTRING$PCHAR$WORD$$QWORD(int64_t arg1, uint16_t* arg2, int64_t arg3, int16_t arg4)
{
    if (arg2 == 0)
        arg2 = &FPC_EMPTYCHAR;
    
    return SYSTEM_$$_FINDRESOURCEEX$QWORD$PCHAR$PCHAR$WORD$$QWORD(arg1, arg2, arg3, arg4);
}

int64_t SYSTEM_$$_DEFAULTHINSTANCE$$QWORD() __pure
{
    return 0;
}

int64_t SYSTEM_$$_DEFAULTENUMRESOURCETYPES$QWORD$ENUMRESTYPEPROC$INT64$$LONGBOOL() __pure
{
    return 0;
}

int64_t SYSTEM_$$_DEFAULTENUMRESOURCENAMES$QWORD$PCHAR$ENUMRESNAMEPROC$INT64$$LONGBOOL() __pure
{
    return 0;
}

int64_t SYSTEM_$$_DEFAULTENUMRESOURCELANGUAGES$QWORD$PCHAR$PCHAR$ENUMRESLANGPROC$INT64$$LONGBOOL() __pure
{
    return 0;
}

int64_t SYSTEM_$$_DEFAULTFINDRESOURCE$QWORD$PCHAR$PCHAR$$QWORD() __pure
{
    return 0;
}

int64_t SYSTEM_$$_DEFAULTFINDRESOURCEEX$QWORD$PCHAR$PCHAR$WORD$$QWORD() __pure
{
    return 0;
}

int64_t SYSTEM_$$_DEFAULTLOADRESOURCE$QWORD$QWORD$$QWORD() __pure
{
    return 0;
}

int64_t SYSTEM_$$_DEFAULTSIZEOFRESOURCE$QWORD$QWORD$$LONGWORD() __pure
{
    return 0;
}

int64_t SYSTEM_$$_DEFAULTLOCKRESOURCE$QWORD$$POINTER() __pure
{
    return 0;
}

int64_t SYSTEM_$$_DEFAULTUNLOCKRESOURCE$QWORD$$LONGBOOL() __pure
{
    return 0;
}

int64_t SYSTEM_$$_DEFAULTFREERESOURCE$QWORD$$LONGBOOL() __pure
{
    return 0;
}

int64_t SYSTEM_$$_GETRESOURCEMANAGER$TRESOURCEMANAGER()
{
    int64_t rdi;
    __builtin_memcpy(rdi, &TC_$SYSTEM_$$_RESOURCEMANAGER, 0xb);
}

int64_t SYSTEM_$$_SETRESOURCEMANAGER$TRESOURCEMANAGER(int64_t arg1)
{
    __builtin_memcpy(&TC_$SYSTEM_$$_RESOURCEMANAGER, arg1, 0xb);
    return arg1;
}

int64_t SYSTEM_$$_HINSTANCE$$QWORD()
{
    return TC_$SYSTEM_$$_RESOURCEMANAGER();
}

int64_t SYSTEM_$$_ENUMRESOURCETYPES$QWORD$ENUMRESTYPEPROC$INT64$$LONGBOOL()
{
    return data_4282f8();
}

int64_t SYSTEM_$$_ENUMRESOURCENAMES$QWORD$PCHAR$ENUMRESNAMEPROC$INT64$$LONGBOOL()
{
    return data_428300();
}

int64_t SYSTEM_$$_ENUMRESOURCELANGUAGES$QWORD$PCHAR$PCHAR$ENUMRESLANGPROC$INT64$$LONGBOOL()
{
    return data_428308();
}

int64_t SYSTEM_$$_FINDRESOURCE$QWORD$PCHAR$PCHAR$$QWORD()
{
    return data_428310();
}

int64_t SYSTEM_$$_FINDRESOURCEEX$QWORD$PCHAR$PCHAR$WORD$$QWORD(int64_t arg1, int64_t arg2, int64_t arg3, int16_t arg4)
{
    return data_428318(arg1, arg2, arg3, arg4);
}

int64_t SYSTEM_$$_LOADRESOURCE$QWORD$QWORD$$QWORD()
{
    return data_428320();
}

int64_t SYSTEM_$$_SIZEOFRESOURCE$QWORD$QWORD$$LONGWORD()
{
    return data_428328();
}

int64_t SYSTEM_$$_LOCKRESOURCE$QWORD$$POINTER()
{
    return data_428330();
}

int64_t SYSTEM_$$_UNLOCKRESOURCE$QWORD$$LONGBOOL()
{
    return data_428338();
}

int64_t SYSTEM_$$_FREERESOURCE$QWORD$$LONGBOOL()
{
    return data_428340();
}

uint64_t SYSTEM_$$_SYSSETCTRLBREAKHANDLER$TCTRLBREAKHANDLER$$TCTRLBREAKHANDLER(uint64_t arg1)
{
    uint64_t TC_$SYSTEM_$$_CTRLBREAKHANDLER_1 = TC_$SYSTEM_$$_CTRLBREAKHANDLER;
    TC_$SYSTEM_$$_CTRLBREAKHANDLER = arg1;
    return TC_$SYSTEM_$$_CTRLBREAKHANDLER_1;
}

uint64_t SYSTEM_$$_OSSETUPENTRYINFORMATION$TENTRYINFORMATION(void* arg1)
{
    U_$SYSTEM_$$_ARGC = *(arg1 + 0x38);
    U_$SYSTEM_$$_ARGV = *(arg1 + 0x40);
    U_$SYSTEM_$$_ENVP = *(arg1 + 0x48);
    U_$SYSTEM_$$_INITIALSTKPTR = *(arg1 + 0x50);
    uint64_t result = *(arg1 + 0x58);
    TC_$SYSTEM_$$_INITIALSTKLEN = result;
    return result;
}

int64_t FPC_SysEntry(void* arg1)
{
    SYSTEM_$$_SETUPENTRYINFORMATION$TENTRYINFORMATION(arg1);
    return *(arg1 + 0x28)();
}

int64_t SYSTEM_$$_SYSTEM_EXIT()
{
    return data_434c60(operatingsystem_result);
}

uint64_t SYSTEM_$$_PARAMCOUNT$$LONGINT()
{
    return (U_$SYSTEM_$$_ARGC - 1);
}

void SYSTEM_$$_PARAMSTR$LONGINT$$SHORTSTRING(char* arg1, int32_t arg2)
{
    if (arg2 == 0)
        FPC_SHORTSTR_TO_SHORTSTR(arg1, 0xff, &U_$SYSTEM_$$_EXECPATHSTR);
    else if (arg2 >= U_$SYSTEM_$$_ARGC)
        *arg1 = 0;
    else
        FPC_PCHAR_TO_SHORTSTR(arg1, 0xff, *(U_$SYSTEM_$$_ARGV + (arg2 << 3)));
}

uint32_t SYSTEM_$$_RANDOMIZE()
{
    uint32_t result = FPC_SYSC_TIME(0);
    U_$SYSTEM_$$_RANDSEED = result;
    return result;
}

void SYSTEM_$$_SETUPCMDLINE()
{
    int64_t r12;
    int64_t var_10 = r12;
    
    if (U_$SYSTEM_$$_ARGC > 0)
    {
        void* rax_1 = SYSTEM_$$_SYSGETMEM$QWORD$$POINTER(0x20000);
        int32_t var_34_1 = 0;
        int32_t var_38 = 0;
        
        for (int32_t i = 0; i < U_$SYSTEM_$$_ARGC; i += 1)
        {
            int32_t rbx_1 = FPC_PCHAR_LENGTH(*(U_$SYSTEM_$$_ARGV + (i << 3)));
            
            if (rbx_1 > 0x1fffe)
                rbx_1 = 0x1fffe;
            
            r12 = 0;
            
            if (rbx_1 >= 1)
            {
                int32_t r13_1 = 0;
                
                do
                {
                    r13_1 += 1;
                    
                    if (*(U_$SYSTEM_$$_ARGV + (i << 3))[r13_1] == 0x20)
                    {
                        r12 = 1;
                        break;
                    }
                } while (rbx_1 > r13_1);
            }
            
            if ((r12 != 0 || rbx_1 == 0))
                r12 = 1;
            else
                r12 = 0;
            
            if ((rbx_1 + var_38) >= 0x1fffe)
                SYSTEM$_$SETUPCMDLINE_$$_ADDBUF(&var_38);
            
            if (r12 != 0)
            {
                *(rax_1 + var_38) = 0x22;
                var_38 += 1;
            }
            
            if (rbx_1 > 0)
            {
                FPC_MOVE(*(U_$SYSTEM_$$_ARGV + (i << 3)), (rax_1 + var_38), rbx_1);
                var_38 += rbx_1;
            }
            
            if (r12 != 0)
            {
                *(rax_1 + var_38) = 0x22;
                var_38 += 1;
            }
            
            if ((U_$SYSTEM_$$_ARGC - 1) <= i)
                *(rax_1 + var_38) = 0;
            else
                *(rax_1 + var_38) = 0x20;
            
            var_38 += 1;
        }
        
        SYSTEM$_$SETUPCMDLINE_$$_ADDBUF(&var_38);
        SYSTEM_$$_SYSFREEMEM$POINTER$$QWORD(rax_1);
    }
}

int32_t* SYSTEM$_$SETUPCMDLINE_$$_ADDBUF(int32_t* arg1)
{
    void* rax_2 = SYSTEM_$$_SYSGETMEM$QWORD$$POINTER((arg1[1] + *arg1));
    FPC_MOVE(TC_$SYSTEM_$$_CALCULATED_CMDLINE, rax_2, arg1[1]);
    FPC_MOVE(*(arg1 + 8), (rax_2 + arg1[1]), *arg1);
    arg1[1] += *arg1;
    SYSTEM_$$_SYSFREEMEM$POINTER$$QWORD(TC_$SYSTEM_$$_CALCULATED_CMDLINE);
    TC_$SYSTEM_$$_CALCULATED_CMDLINE = rax_2;
    *arg1 = 0;
    return arg1;
}

uint64_t SYSTEM_$$_GET_CMDLINE$$PCHAR()
{
    if (TC_$SYSTEM_$$_CALCULATED_CMDLINE == 0)
        SYSTEM_$$_SETUPCMDLINE();
    
    return TC_$SYSTEM_$$_CALCULATED_CMDLINE;
}

int32_t* SYSTEM_$$_REENABLE_SIGNAL$LONGINT$$BOOLEAN(int32_t arg1)
{
    void var_28;
    SYSTEM_$$_FILLCHAR$formal$INT64$CHAR(&var_28, 0x10, 0);
    int64_t rbx_2 = (arg1 - 1);
    *(&var_28 + (((rbx_2 + ((rbx_2 >> 0x3f) & 0x3f)) >> 6) << 3)) = (1 << ((arg1 - 1) % 0x40));
    int32_t rax_7 = FPC_SYS_GETERRNO();
    FPC_SYSC_SIGPROCMASK(1, &var_28, 0);
    int64_t r12;
    r12 = FPC_SYS_GETERRNO() == 0;
    FPC_SYS_SETERRNO(rax_7);
    int32_t* result;
    result = r12;
    return result;
}

uint64_t SYSTEM_$$_GETFPUSTATE$TSIGCONTEXT$$WORD(void* arg1)
{
    void* rax;
    
    if (*(arg1 + 0xe0) == 0)
        rax = 0;
    else
        rax = *(*(arg1 + 0xe0) + 2);
    
    return (rax & 0xffff);
}

uint64_t SYSTEM_$$_GETMMSTATE$TSIGCONTEXT$$LONGWORD(void* arg1)
{
    if (*(arg1 + 0xe0) == 0)
        return 0;
    
    return *(*(arg1 + 0xe0) + 0x18);
}

int32_t* SYSTEM_$$_SIGNALTORUNERROR$LONGINT$PSIGINFO$PSIGCONTEXT(int32_t arg1, void* arg2, void* arg3)
{
    int64_t r13;
    r13 = 0;
    
    if (arg1 == 2)
        r13 = 0xd9;
    else if (arg1 == 3)
        r13 = 0xe9;
    else if ((arg1 == 4 || arg1 == 7))
        r13 = 0xd8;
    else if (arg1 == 8)
    {
        r13 = 0xc8;
        
        if (*(arg2 + 8) != 1)
        {
            int32_t rax_7 = SYSTEM_$$_GETFPUSTATE$TSIGCONTEXT$$WORD(arg3);
            
            if ((rax_7 & 0x7f) == 0)
            {
                int32_t rax_9 = SYSTEM_$$_GETMMSTATE$TSIGCONTEXT$$LONGWORD(arg3);
                
                if ((rax_9 & 0x3f) != 0)
                {
                    if ((rax_9 & 4) != 0)
                        r13 = 0xd0;
                    else if ((rax_9 & 1) != 0)
                        r13 = 0xcf;
                    else if ((rax_9 & 8) != 0)
                        r13 = 0xcd;
                    else if ((rax_9 & 0x10) != 0)
                        r13 = 0xce;
                    else if ((rax_9 & 2) == 0)
                        r13 = 0xcf;
                    else
                        r13 = 0xce;
                }
            }
            else if ((rax_7 & 4) != 0)
                r13 = 0xd0;
            else if ((rax_7 & 8) != 0)
                r13 = 0xcd;
            else if ((rax_7 & 0x10) != 0)
                r13 = 0xce;
            else if ((rax_7 & 2) != 0)
                r13 = 0xce;
            else if ((rax_7 & 0x61) == 0)
                r13 = 0xcf;
            else
                r13 = 0xcf;
            
            if (*(arg3 + 0xe0) != 0)
            {
                uint16_t* rax_11 = *(arg3 + 0xe0);
                *rax_11 = TC_$SYSTEM_$$_DEFAULT8087CW;
                rax_11[2] = 0;
                rax_11[1] &= 0xc8ff;
                *(rax_11 + 0x18) &= 0xffffffc0;
                rax_11[1] &= 0xc800;
            }
        }
    }
    else if (arg1 == 0xb)
        r13 = 0xd8;
    
    int32_t* result = SYSTEM_$$_REENABLE_SIGNAL$LONGINT$$BOOLEAN(arg1);
    
    if (r13 != 0)
    {
        *(arg3 + 0x68) = (r13 & 0xffff);
        *(arg3 + 0x70) = *(arg3 + 0xa8);
        result = *(arg3 + 0x78);
        *(arg3 + 0x88) = result;
        *(arg3 + 0xa8) = SYSTEM_$$_SIGNALTOHANDLEERRORADDRFRAME$LONGINT$POINTER$POINTER;
    }
    
    return result;
}

int64_t SYSTEM_$$_INSTALLDEFAULTSIGNALHANDLER$LONGINT$SIGACTIONREC(int32_t arg1, int64_t arg2)
{
    int32_t* (* var_38)(int32_t arg1, void* arg2, void* arg3);
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(&var_38, 0x28, 0);
    var_38 = SYSTEM_$$_SIGNALTORUNERROR$LONGINT$PSIGINFO$PSIGCONTEXT;
    int64_t var_30 = 4;
    return FPC_SYSC_SIGACTION(arg1, &var_38, arg2);
}

int64_t SYSTEM_$$_INSTALLSIGNALS()
{
    SYSTEM_$$_INSTALLDEFAULTSIGNALHANDLER$LONGINT$SIGACTIONREC(8, &_FPC_OLDSIGFPE);
    SYSTEM_$$_INSTALLDEFAULTSIGNALHANDLER$LONGINT$SIGACTIONREC(0xb, &_FPC_OLDSIGSEGV);
    SYSTEM_$$_INSTALLDEFAULTSIGNALHANDLER$LONGINT$SIGACTIONREC(7, &_FPC_OLDSIGBUS);
    return SYSTEM_$$_INSTALLDEFAULTSIGNALHANDLER$LONGINT$SIGACTIONREC(4, &_FPC_OLDSIGILL);
}

int64_t SYSTEM_$$_SYSINITSTDIO()
{
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int32_t* rdi_1;
    int64_t rsi;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rdi_1 = &data_433ff8;
    else
        rdi_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_INPUT, rsi, &U_$SYSTEM_$$_INPUT);
    SYSTEM_$$_OPENSTDIO$TEXT$LONGINT$LONGINT(rdi_1, 0xd7b1, 0);
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int32_t* rdi_3;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        rdi_3 = &data_433c78;
    else
        rdi_3 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_OUTPUT);
    
    SYSTEM_$$_OPENSTDIO$TEXT$LONGINT$LONGINT(rdi_3, 0xd7b2, 1);
    uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
    int32_t* rdi_5;
    
    if (FPC_THREADVAR_RELOCATE_3 == 0)
        rdi_5 = &data_4338f8;
    else
        rdi_5 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_ERROUTPUT);
    
    SYSTEM_$$_OPENSTDIO$TEXT$LONGINT$LONGINT(rdi_5, 0xd7b2, 2);
    uint64_t FPC_THREADVAR_RELOCATE_4 = FPC_THREADVAR_RELOCATE;
    int32_t* rdi_7;
    
    if (FPC_THREADVAR_RELOCATE_4 == 0)
        rdi_7 = &data_434378;
    else
        rdi_7 = FPC_THREADVAR_RELOCATE_4(U_$SYSTEM_$$_STDOUT);
    
    SYSTEM_$$_OPENSTDIO$TEXT$LONGINT$LONGINT(rdi_7, 0xd7b2, 1);
    uint64_t FPC_THREADVAR_RELOCATE_5 = FPC_THREADVAR_RELOCATE;
    int32_t* rdi_9;
    
    if (FPC_THREADVAR_RELOCATE_5 == 0)
        rdi_9 = &data_4346f8;
    else
        rdi_9 = FPC_THREADVAR_RELOCATE_5(U_$SYSTEM_$$_STDERR);
    
    return SYSTEM_$$_OPENSTDIO$TEXT$LONGINT$LONGINT(rdi_9, 0xd7b2, 2);
}

int64_t SYSTEM_$$_RESTOREOLDSIGNALHANDLERS()
{
    FPC_SYSC_SIGACTION(8, &_FPC_OLDSIGFPE, 0);
    FPC_SYSC_SIGACTION(0xb, &_FPC_OLDSIGSEGV, 0);
    FPC_SYSC_SIGACTION(7, &_FPC_OLDSIGBUS, 0);
    return FPC_SYSC_SIGACTION(4, &_FPC_OLDSIGILL, 0);
}

int64_t SYSTEM_$$_SYSINITEXECPATH()
{
    U_$SYSTEM_$$_EXECPATHSTR = 0;
    int32_t result = FPC_SYSC_READLINK("/proc/self/exe", &data_435ba1, 0xff);
    
    if ((result > 0 && data_435ba1 == 0x2f))
        U_$SYSTEM_$$_EXECPATHSTR = result;
    
    return result;
}

int64_t SYSTEM_$$_GETPROCESSID$$QWORD()
{
    return FPC_SYSC_GETPID();
}

int64_t SYSTEM_$$_CHECKINITIALSTKLEN$QWORD$$QWORD(int64_t arg1)
{
    int64_t r12;
    r12 = 0;
    int64_t var_28;
    SYSTEM_$$_FILLCHAR$formal$INT64$BYTE(&var_28, 0x10, 0);
    r12 = FPC_SYSC_GETRLIMIT(3, &var_28) == 0;
    
    if ((r12 != 0 && arg1 > var_28))
        return var_28;
    
    return arg1;
}

int64_t WRPR_$SYSTEM_$$_TINTERFACEDOBJECT_$_IUNKNOWN_$_0_$_SYSTEM$_$TINTERFACEDOBJECT_$__$$_QUERYINTERFACE$TGUID$formal$$LON$CRC5A30FEB1(int64_t arg1, int64_t* arg2, int64_t* arg3)
{
    /* tailcall */
    return SYSTEM$_$TINTERFACEDOBJECT_$__$$_QUERYINTERFACE$TGUID$formal$$LONGINT((arg1 - 0x10), arg2, arg3);
}

int64_t WRPR_$SYSTEM_$$_TINTERFACEDOBJECT_$_IUNKNOWN_$_1_$_SYSTEM$_$TINTERFACEDOBJECT_$__$$__ADDREF$$LONGINT(int64_t arg1)
{
    /* tailcall */
    return SYSTEM$_$TINTERFACEDOBJECT_$__$$__ADDREF$$LONGINT((arg1 - 0x10));
}

int64_t WRPR_$SYSTEM_$$_TINTERFACEDOBJECT_$_IUNKNOWN_$_2_$_SYSTEM$_$TINTERFACEDOBJECT_$__$$__RELEASE$$LONGINT(int64_t arg1)
{
    /* tailcall */
    return SYSTEM$_$TINTERFACEDOBJECT_$__$$__RELEASE$$LONGINT((arg1 - 0x10));
}

int64_t WRPR_$SYSTEM_$$_TCONTAINEDOBJECT_$_IUNKNOWN_$_0_$_SYSTEM$_$TCONTAINEDOBJECT_$__$$_QUERYINTERFACE$TGUID$formal$$LONGI$CRC4325E599(int64_t arg1)
{
    /* jump -> *(*(arg1 - 0x10) + 0xc8) */
}

int64_t WRPR_$SYSTEM_$$_TCONTAINEDOBJECT_$_IUNKNOWN_$_1_$_SYSTEM$_$TAGGREGATEDOBJECT_$__$$__ADDREF$$LONGINT(int64_t arg1)
{
    /* tailcall */
    return SYSTEM$_$TAGGREGATEDOBJECT_$__$$__ADDREF$$LONGINT((arg1 - 0x10));
}

int64_t WRPR_$SYSTEM_$$_TCONTAINEDOBJECT_$_IUNKNOWN_$_2_$_SYSTEM$_$TAGGREGATEDOBJECT_$__$$__RELEASE$$LONGINT(int64_t arg1)
{
    /* tailcall */
    return SYSTEM$_$TAGGREGATEDOBJECT_$__$$__RELEASE$$LONGINT((arg1 - 0x10));
}

int64_t INIT$_$SYSTEM()
{
    operatingsystem_isconsole = 1;
    int64_t rax = SYSTEM_$$_CHECKINITIALSTKLEN$QWORD$$QWORD(TC_$SYSTEM_$$_INITIALSTKLEN);
    uint64_t FPC_THREADVAR_RELOCATE_1 = FPC_THREADVAR_RELOCATE;
    int64_t* rax_1;
    
    if (FPC_THREADVAR_RELOCATE_1 == 0)
        rax_1 = &data_434a98;
    else
        rax_1 = FPC_THREADVAR_RELOCATE_1(U_$SYSTEM_$$_STACKLENGTH);
    
    *rax_1 = rax;
    uint64_t FPC_THREADVAR_RELOCATE_4 = FPC_THREADVAR_RELOCATE;
    int64_t* rax_2;
    
    if (FPC_THREADVAR_RELOCATE_4 == 0)
        rax_2 = &data_434a98;
    else
        rax_2 = FPC_THREADVAR_RELOCATE_4(U_$SYSTEM_$$_STACKLENGTH);
    
    int64_t rbx_2 = (((U_$SYSTEM_$$_INITIALSTKPTR | 0xfff) + 1) - *rax_2);
    uint64_t FPC_THREADVAR_RELOCATE_2 = FPC_THREADVAR_RELOCATE;
    int64_t* rax_3;
    
    if (FPC_THREADVAR_RELOCATE_2 == 0)
        rax_3 = &data_434a88;
    else
        rax_3 = FPC_THREADVAR_RELOCATE_2(U_$SYSTEM_$$_STACKBOTTOM);
    
    *rax_3 = rbx_2;
    SYSTEM_$$_INSTALLSIGNALS();
    SYSTEM_$$_INITHEAP();
    SYSTEM_$$_SYSINITEXCEPTIONS();
    SYSTEM_$$_INITUNICODESTRINGMANAGER();
    SYSTEM_$$_SYSINITSTDIO();
    SYSTEM_$$_SYSINITEXECPATH();
    uint64_t FPC_THREADVAR_RELOCATE_3 = FPC_THREADVAR_RELOCATE;
    int16_t* rax_4;
    
    if (FPC_THREADVAR_RELOCATE_3 == 0)
        rax_4 = &data_434a78;
    else
        rax_4 = FPC_THREADVAR_RELOCATE_3(U_$SYSTEM_$$_INOUTRES);
    
    *rax_4 = 0;
    SYSTEM_$$_INITSYSTEMTHREADS();
    int64_t result = SYSTEM_$$_INITSYSTEMDYNLIBS();
    
    if (operatingsystem_islibrary == 0)
        return result;
    
    return SYSTEM_$$_RESTOREOLDSIGNALHANDLERS();
}

