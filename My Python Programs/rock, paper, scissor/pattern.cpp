{
	int i, j, space, k = 0, n;
	cout << “\nEnter the number of rows : “;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			cout << ” “;
		}
		for(int j=1;j<=i;j++)
		{
			cout << “*”;
		}
		cout << endl;
	}

	for(int i=n-1;i>0;i–)
	{
		for(int j=1;j<=n-i;j++)
			{
				cout << ” “;
			}
		for(int j=1;j<=i;j++)
			{
				cout << "* ";
			}
		cout << endl;
	}
}