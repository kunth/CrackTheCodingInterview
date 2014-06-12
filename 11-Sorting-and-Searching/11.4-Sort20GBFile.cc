//Imagine you have 20GB file with one string per line. Explain how you would sort the file.
//
//外部排序
//直接引用原文
//So what do we do? We only bring part of the data into memory.
//We'll divide the file into chunks which are x megabytes each, where x is the amount of memory we have available. Each chunk is sorted separately and then saved back to the file system.
//Once all the chunks are sorted, we then merge the chunks, one by one. At the end, we have a fully sorted file.
//This algorithm is known as external sort.
