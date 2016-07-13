bool TopologicalSort(int a[][101]) //可以完成拓扑排序则返回True
{
    int n = a[0][0], i, j;
    int into[101], ans[101];
    memset(into, 0, sizeof(into));
    memset(ans, 0, sizeof(ans));
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (a[i][j] > 0)
            into[j]++;
        }
    }
    into[0] = 1;
    for (i = 1; i <= n; i++)
    {
        j = 0;
        while (into[j] != 0)
        {
            j++;
            if (j > n)
            return false;
        }
        ans[i] = j;
        into[j] = -1;
        for (int k = 1; k <= n; k++)
        {
            if (a[j][k] > 0)
            into[k]--;
        }
    }
    for (i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return true;
}