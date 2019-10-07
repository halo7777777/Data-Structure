//函数
Position BinarySearch(List L, ElementType X)
{
    Position high = L->Last;
    Position low = 1;
    Position middle = (L->Last + 1)/2;
    for( ;low <= high; )
    {
        middle = (low + high)/2;
        if(X == L->Data[middle])
            return middle;
        else if(X < L->Data[middle])
            high = middle - 1;
        else
            low = middle + 1;
    }
    return NotFound;
}
