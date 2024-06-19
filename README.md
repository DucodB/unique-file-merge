# Unique File Merge

Unique File Merge is a command-line tool designed to merge multiple files. It reads the files, stores each line sepeartely into a set to remove the duplicates and then stores the result, line by line, to a specified output file.
This utility is useful for joining sets of data written to files from multiple experiments without having to worry about ordering.

## Usage

To use Unique File Merge, follow these steps:


1. **Compile the Program**: Compile `mergefiles.cpp` using a C++ compiler of choice.
   ```bash
   g++ mergefiles.cpp -o mergefiles
   ```

3. **Run the Program**: Execute the compiled program with the desired input files.
   ```bash
   ./mergefiles <output_file> <input_file1> <input_file2> ... <input_fileN>
   ```

   - `<output_file>`: Name of the output file where the merged content will be stored.
   - `<input_file1>`, `<input_file2>`, ..., `<input_fileN>`: Names of the input files to be merged.

4. **View Results**: The merged content, with unique lines, will be written to the specified output file.

## Example

```bash
./mergefiles merged_output.txt file1.txt file2.txt file3.txt
```

This command will merge the contents of `file1.txt`, `file2.txt`, and `file3.txt`, ensuring that each line is unique, and store the result in `merged_output.txt`.
