void Out_f_Arr(double* A, int na, bool flag)
{
	If(flag)
	{
		ofstream out("Lab7a.txt", ios::app); // �������� � �������� ����� ��� ������
			if (!out) // �������� ���������� �������� �����
			{
				cout << "\n ��� ����� OUT\n"; system("pause"); exit(1);
			}
		for (int i = 0; i < na; i++)
			out << A[i] << ' ';
		out << endl << endl << endl;
		out.close(); // �������� ����� 
	}
	Else
}