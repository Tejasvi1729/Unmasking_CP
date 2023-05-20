#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <chrono>
using namespace std::chrono;
using namespace std;
int binary_number_adder(int n, int m)
{
    int sum = 0;
    int carry = 0;
    int temp = 1;
    while (n > 0 && m > 0)
    {
        int ttt = (n % 10) + (m % 10) + carry;
        n = n / 10;
        m = m / 10;
        if (ttt == 0)
        {
            carry = 0;
        }
        else if (ttt == 1)
        {
            carry = 0;
            sum += (temp);
        }
        else if (ttt == 2)
        {
            carry = 1;
        }
        else if (ttt == 3)
        {
            carry = 1;
            sum += (temp);
        }
        temp *= 10;
    }
    while (n > 0)
    {
        int tn = (n % 10) + carry;
        n = n / 10;
        if (tn == 0)
        {
            carry = 0;
        }
        else if (tn == 1)
        {
            carry = 0;
            sum += temp;
        }
        else if (tn == 2)
        {
            carry = 1;
        }
        temp *= 10;
    }
    while (m > 0)
    {
        int tm = (m % 10) + carry;
        m = m / 10;
        if (tm == 0)
        {
            carry = 0;
        }
        else if (tm == 1)
        {
            carry = 0;
            sum += temp;
        }
        else if (tm == 2)
        {
            carry = 1;
        }
        temp *= 10;
    }
    sum += (carry * temp);
    return sum;
}
int binary_search(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}
char behave(int arr[], int n)
{
    if (arr[n] < arr[n - 1] && arr[n] < arr[n + 1])
    {
        return 'm';
    }
    else if (arr[n] > arr[n - 1] && arr[n] < arr[n + 1])
    {
        return 'i';
    }
    else
    {
        return 'd';
    }
}
int minima(int arr[], int n)
{
    int s = 1;
    int e = n - 2;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (behave(arr, mid) == 'm')
        {
            return mid;
        }
        else if (behave(arr, mid) == 'i')
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}
void slection_sort(int arr[], int n)
{
    int t;
    int index;
    for (int i = 0; i < n; i++)
    {
        t = arr[i];
        index = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < t)
            {
                t = arr[j];
                index = j;
            }
        }
        int rrr = arr[i];
        arr[i] = arr[index];
        arr[index] = rrr;
    }
    for (int f = 0; f < n; f++)
    {
        cout << arr[f] << " ";
    }
}
void bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
    for (int f = 0; f < n; f++)
    {
        cout << arr[f] << " ";
    }
}
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int index = i;
        for (int k = 0; k < i; k++)
        {
            if (arr[k] > arr[i])
            {
                index = k;
                break;
            }
        }
        int storage = arr[i];
        for (int r = i; r > index; r--)
        {
            arr[r] = arr[r - 1];
        }
        arr[index] = storage;
    }
    for (int f = 0; f < n; f++)
    {
        cout << arr[f] << " ";
    }
}
void sum_of_all_subarray_optimised(int arr[], int n)
{
    int sum = 0;
    int count = 1;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        sum += (arr[s] + arr[e]) * count;
        count++;
        s++;
        e--;
    }
    cout << sum;
}
void longest_arithematic_subarray(int arr[], int n)
{
    int l = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int d = arr[i + 1] - arr[i];
        if (d < 0)
        {
            d *= -1;
        }
        int lc = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j] - arr[j - 1]) == d || (-arr[j] + arr[j - 1]) == d)
            {
                lc++;
            }
            l = max(lc, l);
        }
    }
    cout << l;
}
void longest_arithematic_subarray_optimised(int arr[], int n)
{
    int lmax = 1;
    int lcurr = 1;
    int d = arr[1] - arr[0];
    if (d < 0)
    {
        d *= -1;
    }
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - arr[i - 1]) == d || (-arr[i] + arr[i - 1]) == d)
        {
            lcurr++;
            lmax = max(lmax, lcurr);
        }
        else
        {
            d = arr[i] - arr[i - 1];
            if (d < 0)
            {
                d *= -1;
            }
            lcurr = 2;
        }
    }
    lmax = max(lcurr, lmax);
    cout << lmax;
}
int recordbreaker(int arr[], int n)
{
    int count = 0;
    int maxx = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxx = max(arr[i - 1], maxx);
        if (i == (n - 1))
        {
            if (arr[i] > maxx)
            {
                count++;
            }
        }
        else
        {
            if (arr[i] > arr[i + 1] && arr[i] > maxx)
            {
                count++;
            }
        }
    }
    return count;
}
void first_occuring_minimum_index(int arr[], int n)
{
    int index[100];
    int f = 99;
    while (f--)
    {
        index[f] = -1;
    }
    bool flag = 1;
    int min_index = n;
    for (int i = 0; i < n; i++)
    {
        int t = arr[i];
        if (index[t] == -1)
        {
            index[t] = i;
        }
        else
        {
            min_index = min(min_index, index[t]);
            flag = 0;
        }
    }
    if (flag == 0)
    {
        cout << min_index << endl;
    }
    if (flag)
    {
        cout << -1;
    }
}
void subarray_sum_equals_s(int arr[], int n, int key)
{
    int sum = 0;
    int s = 0;
    int e = 0;
    bool flag = 1;
    while (s <= e && e < n && s >= 0)
    {
        // cout<<sum<<"->";
        if (sum == key)
        {
            cout << s << " " << e - 1 << endl;
            return;
        }
        else if (sum > key)
        {
            sum -= arr[s];
            s++;
            if (sum == key)
            {
                cout << s << " " << e - 1 << endl;
                return;
            }
        }
        else
        {
            sum += arr[e];
            e++;
            if (sum == key)
            {
                cout << s << " " << e - 1 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}
void temp(int arr[], int n)
{
    int freq[101] = {0};
    for (int i = 0; i < 101; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (int j = 0; j < 101; j++)
    {
        if (freq[j] == 0)
        {
            cout << (j);
            break;
        }
    }
}
int circular_kadane(int arr[], int n)
{
    int minn = 0;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        minn = min(minn, curr_sum);
        if (curr_sum > 0)
        {
            curr_sum = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        minn -= arr[i];
    }
    return (-1) * minn;
}
int pair_sum(int arr[], int n, int key)
{
    sort(arr, arr + n);
    int s = 0;
    int e = n - 1;
    int sum = arr[s] + arr[e];
    while (s <= e)
    {
        if (sum > key)
        {
            sum -= arr[e];
            e--;
            sum += arr[e];
        }
        else if (sum < key)
        {
            sum -= arr[s];
            s++;
            sum += arr[s];
        }
        else
        {
            return 1;
        }
    }
    return -1;
}
void matrix_spiral_printer(int arr[][4], int n, int m)
{
    int l = 0;
    int r = m;
    int u = 0;
    int b = n;
    while (l <= r && u <= b)
    {
        for (int i = l; i < r; i++)
        {
            cout << arr[u][i] << " ";
        }
        for (int i = u + 1; i < b; i++)
        {
            cout << arr[i][r - 1] << " ";
        }
        for (int i = r - 2; i > l; i--)
        {
            cout << arr[b - 1][i] << " ";
        }
        for (int i = b - 1; i > u; i--)
        {
            cout << arr[i][l] << " ";
        }
        l++;
        u++;
        r--;
        b--;
    }
}
void matrix_mutliplication(int arr1[3][4], int n1, int n2, int n3, int arr2[4][3])
{
    vector<int> v;
    for (int j = 0; j < n3; j++)
    {
        for (int i = 0; i < n1; i++)
        {
            int sum = 0;
            for (int temp = 0; temp < n2; temp++)
            {
                sum += arr1[i][temp] * arr2[temp][j];
            }
            v.push_back(sum);
        }
    }
    for (auto x : v)
    {
        cout << x << " ";
    }
}
bool matrix_search(int arr[][4], int n1, int n2, int key)
{
    for (int i = 0; i < n1; i++)
    {
        if (arr[i][n2 - 1] < key)
        {
            continue;
        }
        else
        {
            for (int j = 0; j < n2; j++)
            {
                if (arr[i][j] == key)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
int char_array(char *arr, int n)
{
    int temp = 0;
    int maxx = 0;
    int index = 0;
    int indexcurr = 0;
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (maxx <= temp)
            {
                index = indexcurr;
            }
            indexcurr = i + 1;
            maxx = max(maxx, temp);
            temp = 0;
        }
        else
        {
            temp++;
        }
    }
    for (int i = index; (arr[i] != '\0' && arr[i] != ' '); i++)
    {
        cout << arr[i];
    }
    return maxx;
}
void subset(int arr[], int n)
{
    int z = n - 1;
    for (int i = 1; i < pow(2, n); i++)
    {
        int temp = i;
        z = n - 1;
        while (temp)
        {
            if (temp & 1)
            {
                cout << arr[z] << " ";
            }
            z--;
            temp /= 2;
        }
        cout << endl;
    }
}
string backchodi(string s, int n)
{
    if (n < 0)
    {
        return "";
    }
    return s[n] + backchodi(s, n - 1);
}
string replace_pi(string s, int i)
{
    if (i == s.length())
    {
        return s;
    }
    if (s[i] == 'p' && s[i + 1] == 'i')
    {
        string t1 = s.substr(0, i);
        string t2 = s.substr(i + 2);
        s = t1 + "3.14" + t2;
        return replace_pi(s, i + 4);
    }
    else
    {
        return replace_pi(s, i + 1);
    }
}
int sieve_of_erethrosenes(int n)
{
    int prime[10000];
    int answer = -1;
    for (int i = 0; i < 10000; i++)
    {
        prime[i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            continue;
        }
        else
        {
            for (int p = (i * i); p <= n; p += i)
            {
                prime[p] = 0;
            }
            if (prime[n] == 0)
            {
                return i;
            }
        }
    }
    return -1;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
}
void smallest_prime_factor(int n)
{
    int spf[1000];
    for (int i = 1; i < 1000; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        if (spf[i] != i)
        {
            continue;
        }
        else
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        cout << spf[i] << " ";
    }
}
void tower_of_hanoi(int n, char a, char b, char c)
{
    if (n == 0)
        return;
    tower_of_hanoi(n - 1, a, c, b);
    cout << "Moving " << n << " from " << a << " to " << c << endl;
    tower_of_hanoi(n - 1, b, a, c);
    return;
}
void substring(string str, int i, string temp)
{
    if (i == str.length())
    {
        cout << temp << endl;
        return;
    }
    substring(str, i + 1, temp);
    temp.push_back(str[i]);
    substring(str, i + 1, temp);
    return;
}
void substrings_from_phone_numbers(int n, string record[10], string tempo, int dig)
{
    if (n == 0)
    {
        cout << tempo << endl;
        return;
    }
    int t;
    if (dig == 0)
    {
        t = n;
    }
    t = n / dig;
    n = (n - (t * dig));
    string temp = record[t];
    for (int i = 0; i < temp.length(); i++)
    {
        tempo.push_back(temp[i]);
        substrings_from_phone_numbers(n, record, tempo, dig / 10);
        tempo.pop_back();
    }
    return;
}
void all_permutations_of_string(string str, int i, int &count)
{
    if (i == str.size())
    {
        cout << str << endl;
        count++;
        return;
    }
    for (int j = i; j < str.size(); j++)
    {
        string temp = str;
        swap(temp[i], temp[j]);
        all_permutations_of_string(temp, i + 1, count);
    }
    return;
}
//****
// int tiling_general(int x,int y,int tilex,int tiley){

// }
//******
bool rat_in_a_maze(char arr[][5], int i, int j, int n, int m, bool solution[][5])
{
    if (i == n || j == m)
    {
        return 0;
    }
    solution[i][j] = 1;
    if (i == n - 1 && j == m - 1)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << solution[i][j];
            }
            cout << endl;
        }
        cout << endl;
        solution[i][j] = 0;
        return 0;
    }
    if (arr[i + 1][j] == 'O' && rat_in_a_maze(arr, i + 1, j, n, m, solution))
    {
        solution[i][j] = 0;
        return 1;
    }
    else if (arr[i][j + 1] == 'O' && rat_in_a_maze(arr, i, j + 1, n, m, solution))
    {
        solution[i][j] = 0;
        return 1;
    }
    else
    {
        solution[i][j] = 0;
        return 0;
    }
}
void permutaions(int n, int i, vector<int> ans, int &count)
{
    if (i == n)
    {
        count++;
        for (int j = 0; j < n; j++)
        {
            cout << ans[j] << " ";
        }
        cout << endl;
        return;
    }
    permutaions(n, i + 1, ans, count);
    for (int p = i + 1; p < n; p++)
    {
        if (ans[i] != ans[p])
        {
            swap(ans[i], ans[p]);
            permutaions(n, i + 1, ans, count);
            swap(ans[i], ans[p]);
        }
    }
    return;
}
bool possible(int **arr, int n, int i, int j)
{
    bool poss = 1;
    for (int x = 0; x < n; x++)
    {
        if (arr[x][j] == 1 && x != i)
        {
            return 0;
        }
        else if (arr[i][x] == 1 && x != j)
        {
            return 0;
        }
    }
    int tx = i;
    int ty = j;
    while (tx >= 0 && ty >= 0 && tx < n && ty < n)
    {
        if (arr[tx][ty] == 1 && (tx != i && ty != j))
        {
            return 0;
        }
        ty--;
        tx++;
    }
    tx = i;
    ty = j;
    while (tx >= 0 && ty >= 0 && tx < n && ty < n)
    {
        if (arr[tx][ty] == 1 && (tx != i && ty != j))
        {
            return 0;
        }
        ty++;
        tx++;
    }
    tx = i;
    ty = j;
    while (tx >= 0 && ty >= 0 && tx < n && ty < n)
    {
        if (arr[tx][ty] == 1 && (tx != i && ty != j))
        {
            return 0;
        }
        tx--;
        ty++;
    }
    tx = i;
    ty = j;
    while (tx >= 0 && ty >= 0 && tx < n && ty < n)
    {
        if (arr[tx][ty] == 1 && (tx != i && ty != j))
        {
            return 0;
        }
        ty--;
        tx--;
    }
    return 1;
}
bool chessboard(int **arr, int n, int i)
{
    if (i == n)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return 1;
    }
    for (int y = 0; y < n; y++)
    {
        arr[i][y] = 1;
        if (possible(arr, n, i, y))
        {
            bool temp = chessboard(arr, n, i + 1);
            if (temp)
            {
                return 1;
            }
        }
        arr[i][y] = 0;
    }
    return 0;
}
int merger(int a[], int b[], int na, int nb, int c[])
{
    int inversions=0;
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < na && j < nb)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
            inversions+=(na-i);
        }
        k++;
    }
    while (i < na)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < nb)
    {
        c[k] = b[j];
        j++;
        k++;
    }
    return inversions;
}
void merge_sort(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }
    int *a;
    int *b = new int[n - (n / 2)];
    a = new int[n / 2];
    for (int i = 0; i < n / 2; i++)
    {
        a[i] = arr[i];
    }
    for (int i = n / 2; i < n; i++)
    {
        b[i - (n / 2)] = arr[i];
    }
    merge_sort(a, n / 2);
    merge_sort(b, (n - (n / 2)));
    int discard=merger(a, b, n / 2, n - (n / 2), arr);
    return;
}
void quick_sort(int arr[], int s, int e)
{
    if (s >= e)
        return;
    int p1 = s;
    int p2 = s - 1;
    while (p1 < e)
    {
        if (arr[p1] < arr[e])
        {
            p2++;
            swap(arr[p2], arr[p1]);
        }
        p1++;
    }
    swap(arr[p2 + 1], arr[e]);
    quick_sort(arr, s, p2);
    quick_sort(arr, p2 + 2, e);
    return;
}
bool comparator(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
    {
        return true;
    }
    return false;
}
void count_sort(int arr[], int n)
{
    int maxx = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxx = max(maxx, arr[i]);
    }
    int *freq;
    freq = new int[maxx + 1];
    for (int i = 0; i <= maxx; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    int temp = 0;
    for (int i = 0; i <= maxx; i++)
    {
        temp += freq[i];
        freq[i] = temp;
    }
    int pointer = 0;
    for (int i = 0; i <= maxx; i++)
    {
        int temp = freq[i];
        for (int j = pointer; j < temp; j++)
        {
            arr[j] = i;
        }
        pointer = temp;
    }
}void dnf_sort(int arr[],int n){
    int low=-1;
    int mid=0;
    int high=n;
    while(mid<high){
        if(arr[mid]==1){
            // continue;
            mid++;
        }
        else if(arr[mid]==0){
            low++;
            swap(arr[mid],arr[low]);
            mid++;
        }
        else if(arr[mid]==2){
            high--;
            swap(arr[mid],arr[high]);
        }
    }
}
void wave_sort(int arr[],int n){
    for(int i=1;i<n-1;i+=2){
        if(arr[i]<=arr[i-1] && arr[i]<=arr[i+1]){
            continue;
        }
        else if((arr[i]<=arr[i-1] && arr[i]>arr[i+1])){
            swap(arr[i],arr[i+1]);
        }
        else if((arr[i]>arr[i-1] && arr[i]<=arr[i+1])){
            swap(arr[i],arr[i-1]);
        }
        else{
            if(arr[i-1]>=arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
            else if(arr[i-1]>=arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
    }
}
int count_number_of_inversions(int arr[],int n){
    if(n==1){return 0;}
    // if(n==0){return 0;}
    int temp=n/2;
    int sum=0;
    int b[temp];
    for(int i=0;i<temp;i++){
        b[i]=arr[i];
    }
    int a[n-temp];
    for(int i=0;i<n-temp;i++){
        a[i]=arr[i+temp];
    }
    sum+=count_number_of_inversions(a,n-temp);
    sum+=count_number_of_inversions(b,temp);
    sum+=merger(b,a,temp,n-temp,arr);
    return sum;
}
void sum(int arr[],int k,int n){
    int sum=0;int minn;
    for(int i=0;i<k;i++){sum+=arr[i];}
    minn=sum;
    for(int i=k;i<n;i++){
        sum+=arr[i]-arr[i-k];
        minn=min(minn,sum);
    }
    cout<<minn;
}
bool valid(int arr[3][3],int i,int j,int val){
    for(int pt=0;pt<3;pt++){if(arr[pt][j]==val){return 0;}}
    for(int pt=0;pt<3;pt++){if(arr[i][pt]==val){return 0;}}
    int left,top;
    left=i-(i%3);
    top=j-(j%3);
    for(int ii=left;ii<(left+3);ii++){
        for(int jj=top;jj<(top+3);jj++){if(arr[ii][jj]==val){return 0;}}
    }
    return 1;
}
void sudoku_solver(int arr[3][3],bool rec[3][3],int i,int j){
    if(i==3){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){cout<<arr[i][j]<<" ";}
            cout<<endl;
        }
        return;
    }
    if(j==3){sudoku_solver(arr,rec,i+1,0);return;}
    if(rec[i][j]==1){
        bool b1=0;
        for(int val=1;val<=3;val++){
            if(valid(arr,i,j,val)==1){
                arr[i][j]=val;
                sudoku_solver(arr,rec,i,j+1);
            }
        }
    }
    else{sudoku_solver(arr,rec,i,j+1);}
    return;
}
int activity_selection(vector<pair<int,int> >arr,int n){
    sort(arr.begin(),arr.end());
    int time=0;
    time=arr[0].first;
    int count=1;
    for(int i=1;i<n;i++){
        if(time<=arr[i].second){count++;time=arr[i].first;}
    }
    return count;
}
int main()
{
    int n;cin>>n;
    vector<pair<int,int> >arr;
    for(int i=0;i<n;i++){
        int t1,t2;cin>>t1>>t2;
        arr.push_back(make_pair(t2,t1));
    }
    cout<<activity_selection(arr,n);
    return 0;
}