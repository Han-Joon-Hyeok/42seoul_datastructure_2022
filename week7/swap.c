void    swap(int *data, int from, int to)
{
    int temp;

    temp = data[from];
    data[from] = data[to];
    data[to] = temp;
}