Field messageCode { buffer, 4 };

Field messageVersion { buffer, &messageCode, 2 };

Field growllerId { buffer, &messageVersion, 5 };

Field transactionDate { buffer, &growllerId, 14 };

Field token { buffer, &transactionDate, 5 };

Field status { buffer, &token, 1 };

