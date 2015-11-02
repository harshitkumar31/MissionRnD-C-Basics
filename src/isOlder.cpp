/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isValidDate(char *dob);

int findOlder(char *dob1, char *dob2);

int charToNum(char *inp);



struct date{

	int d;
	int month;
	int year;

	};

typedef struct date Date;

Date convDate(char *dob);

int compareDates(Date d1, Date d2);

int isOlder(char *dob1, char *dob2) {

	int older = findOlder(dob1, dob2);

	return older;
	}

int findOlder(char *dob1, char *dob2){

	Date d1, d2;
	int flag1, flag2;

	int cmp;

	flag1 = isValidDate(dob1);
	flag2 = isValidDate(dob2);

	if (flag1 == -1 || flag2 == -1)
		return -1;

	d1 = convDate(dob1);
	d2 = convDate(dob2);

	cmp = compareDates(d1, d2);

	return cmp;
	}

int isValidDate(char *dob){

	int count = 0;

	char a[5];
	Date d;
	int i = 0, j = 0, k = 0, temp;
	int date[3];
	//a = calloc(5, sizeof(char));

	while (dob[i] != '\0'){

		if (dob[i] == '-'){
			a[j] = '\0';

			count++;
			temp = charToNum(a);

			if (temp == -1)
				return temp;

			j = 0;

			date[k] = temp;
			i++;
			k++;
			//a = calloc(5, sizeof(char));

			}
		else{

			a[j] = dob[i];
			i++;
			j++;

			}



		}

	if (count<2 || count > 3)
		return -1;
	a[j] = '\0';
	temp = charToNum(a);

	date[k] = temp;

	d.d = date[0];
	d.month = date[1];
	d.year = date[2];

	if (d.d > 31)
		return -1;
	else if (d.d == 31){
		if (d.month == 2 || d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
			return -1;
		
		}
	else if (d.d == 29){
		if (d.month == 2){
			if (d.year % 4 == 0)
				{
				}
			else
				return -1;
			}

		}

	if (d.month > 12 || d.month <= 0)
		return -1;

	return 1;

	}

int compareDates(Date d1, Date d2){

	if (d1.year > d2.year){
		return 2;
		}
	else if (d1.year < d2.year){
		return 1;
		}
	else{
		if (d1.month == d2.month){
			if (d1.d == d2.d)
				return 0;
			else if (d1.d>d2.d)
				return 2;
			else
				return 1;

			}
			
		else if (d1.month>d2.month)
			return 2;
		else
			return 1;

		}

	}

Date convDate(char *dob){

	char a[5];
	Date d;
	int i = 0, j = 0, k = 0, temp;
	int date[3];
	//a = calloc(5, sizeof(char));

	while (dob[i] != '\0'){

		if (dob[i] == '-'){
			a[j] = '\0';

			temp = charToNum(a);

			j = 0;

			date[k] = temp;
			i++;
			k++;
			//a = calloc(5, sizeof(char));

			}
		else{

			a[j] = dob[i];
			i++;
			j++;

			}



		}

	a[j] = '\0';
	temp = charToNum(a);
	date[k] = temp;

	d.d = date[0];
	d.month = date[1];
	d.year = date[2];

	return d;

	}


int charToNum(char *inp){

	int i = 0;
	int num = 0;
	while (inp[i] != '\0')
		{

		if (inp[i] - '0' > 9 || inp[i] - '0' < 0)
			return -1;

		num = num * 10 + (inp[i] - '0');
		i++;
		}

	return num;
	}

