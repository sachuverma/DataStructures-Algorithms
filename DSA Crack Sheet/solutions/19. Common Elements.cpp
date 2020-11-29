// O(n1log(n1) + n2log(n2) + n3log(n3))
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
  map<int, int> ma, mb, mc;
  vector<int> ans;

  for (int i = 0; i < n1; ++i)
    ma[A[i]]++;
  for (int i = 0; i < n2; ++i)
    mb[B[i]]++;
  for (int i = 0; i < n3; ++i)
    mc[C[i]]++;

  for (auto it = ma.begin(); it != ma.end(); ++it)
  {
    int element = it->first;
    if (mb.find(element) != mb.end() && mc.find(element) != mc.end())
      ans.push_back(element);
  }
  return ans;
}

/* ======================================================= */
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
  unordered_map<int, int> ma, mb, mc;
  vector<int> ans;

  for (int i = 0; i < n1; ++i)
    ma[A[i]]++;
  for (int i = 0; i < n2; ++i)
    mb[B[i]]++;
  for (int i = 0; i < n3; ++i)
    mc[C[i]]++;

  for (auto it = ma.begin(); it != ma.end(); ++it)
  {
    int element = it->first;
    if (mb.find(element) != mb.end() && mc.find(element) != mc.end())
      ans.push_back(element);
  }

  sort(ans.begin(), ans.end());
  return ans;
}

/* ======================================================= */
// O(n1 + n2 + n3)
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
  vector<int> ans;
  int i = 0, j = 0, k = 0;

  while (i < n1 && j < n2 && k < n3)
  {
    int ma = max(A[i], max(B[j], C[k]));

    while (i < n1 && A[i] < ma)
      i++;
    while (i < n1 - 1 && A[i] == A[i + 1])
      i++;

    while (j < n2 && B[j] < ma)
      j++;
    while (j < n2 - 1 && B[j] == B[j + 1])
      j++;

    while (k < n3 && C[k] < ma)
      k++;
    while (k < n1 - 1 && C[k] == C[k + 1])
      k++;

    if (i >= n1 || j >= n2 || k >= n3)
      break;
    if (A[i] == B[j] && B[j] == C[k])
    {
      ans.push_back(A[i]);
      i++;
      j++;
      k++;
    }
  }

  return ans;
}
