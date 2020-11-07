
int middle(int A, int B, int C)
{
  if (A > B)
  {
    if (C > A)
      return A;
    else if (C < A && B > C)
      return B;
    else
      return C;
  }
  else
  {
    if (C > B)
      return B;
    else if (C < B && A > C)
      return A;
    else
      return C;
  }
}
