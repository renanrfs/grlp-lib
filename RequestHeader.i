Field messageCode = add({ buffer, 4 });

Field messageVersion = add({ buffer, &messageCode, 2 });

Field growllerId = add({ buffer, &messageVersion, 5 });

Field transactionDate = add({ buffer, &growllerId, 14 });

Field token = add({ buffer, &transactionDate, 5 });

