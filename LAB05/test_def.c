Status test_init_default_returns_nonNULL(char* buffer, int length)
{
MY_STRING hString = NULL;
hString = my_string_init_default();
if(hString == NULL)
{
my_string_
destroy(&hString);
strncpy(buffer, "test_init_default_returns_nonNULL
\
n"
"my_string_init_default returns NULL", length);
return FAILURE;
}
else
{
my_string_
destroy(&hString);
strncpy(buffer, "
\
ttest_init_default_returns_nonNULL
\
n", length);
return SUCCESS;
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
MY_STRING hString = NULL;
Status status;
hString = my_string_init_default();
if(my_string_get_size(hString) != 0)
{
status = FAILURE;
printf("Expected a size of 0 but got %d
\
n", my_string_get_size(hString));
strncpy(buffer, "test_get_size_on_init_default_returns_0
\
n"
"Did not receive 0 from 
get_size after init_default
\
n", length);
}
else
{
status = SUCCESS;
strncpy(buffer, "test_get_size_on_init_default_returns_0
\
n"
, length);
}
my_string_destroy(&hString);
return status;
}
