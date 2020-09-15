int initNumber, number, sum = 0;

    cout<<"Enter a number : ";
    cin>>initNumber;

    number = initNumber;

    while(initNumber != 0) {

        int digit = initNumber % 10;
        initNumber /= 10;

        sum = sum + digit * digit * digit;
    }

    if(sum == number) {
        cout<<"This is a armstrong number";
    } else {
        cout<<"This is not a armstrong number";
    }

    return 0;