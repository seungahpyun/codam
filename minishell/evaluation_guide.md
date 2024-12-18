# Minishell Evaluation Guide

## 1. Compilation Check
- Check compilation flags:
```bash
make -n  # Should show -Wall -Wextra -Werror
```
- Verify clean compilation:
```bash
make clean
make
```
- Check for relink:
```bash
touch main.c
make
```

## 2. Simple Commands & Global Variables
### Basic Execution
```bash
/bin/ls
/bin/pwd
/bin/echo hello
```

### Empty Commands
- Press Enter with no input
- Type multiple spaces/tabs and press Enter

### Global Variable Check
Ask the student:
- How many global variables are used?
- Why was this implementation chosen?
- Example of why it's necessary

## 3. Arguments Testing
### Basic Arguments
```bash
/bin/ls -l
/bin/ls -la
/bin/cat README.md
```

### Multiple Arguments
```bash
/bin/ls -l -a -h
/usr/bin/grep hello test.txt
/bin/echo hello world test
```

## 4. Echo Command
### Basic Echo
```bash
echo hello world
echo testing spaces
```

### Echo with -n Option
```bash
echo -n hello
echo -n "no newline"
```

### Echo with Multiple Arguments
```bash
echo hello      world
echo -n first second third
```

## 5. Exit Command
### Basic Exit
```bash
exit
```

### Exit with Status
```bash
exit 42
exit 0
exit 256
exit -1
```

### Invalid Exit
```bash
exit hello
exit 42 53
```

## 6. Process Return Values
### Success Cases
```bash
/bin/ls
echo $?  # Should be 0
```

### Error Cases
```bash
/bin/ls nonexistentfile
echo $?  # Should be non-zero
```

### Return Value Operations
```bash
ls nonexistentfile
expr $? + $?
```

## 7. Signal Handling
### Empty Prompt
- Try Ctrl+C → Should show new prompt
- Try Ctrl+\ → Should do nothing
- Try Ctrl+D → Should exit shell

### With Content
1. Type some text without Enter:
   - Try Ctrl+C → Should clear line, show new prompt
   - Try Ctrl+D → Should do nothing
   - Try Ctrl+\ → Should do nothing

### Running Command
1. Run: `cat` (no args)
   - Try Ctrl+C → Should terminate
   - Try Ctrl+\ → Should terminate with core dump
   - Try Ctrl+D → Should terminate

## 8. Double Quotes
### Basic Quotes
```bash
echo "hello world"
echo "  multiple   spaces  "
```

### Command Syntax
```bash
echo "cat lol.c | cat > lol.c"
```

### Without $
```bash
echo "hello\nworld"
echo "special chars: <>|&;"
```

## 9. Single Quotes
### Basic Quotes
```bash
echo 'hello world'
echo '  multiple   spaces  '
```

### Environment Variables
```bash
echo '$USER'  # Should print $USER literally
```

### Special Characters
```bash
echo 'special chars: <>|&;'
echo '\ backslash'
```

## 10. Environment Variables
### Display Environment
```bash
env
```

### Export New Variables
```bash
export TEST1=hello
export TEST2=world
env | grep TEST
```

### Update Existing Variables
```bash
export PATH="/new/path:$PATH"
echo $PATH
```

## 11. Unset Command
### Basic Unset
```bash
export TEST=42
echo $TEST
unset TEST
echo $TEST
```

### Multiple Unset
```bash
export A=1 B=2 C=3
unset A B C
echo $A $B $C
```

## 12. CD Command
### Basic Navigation
```bash
pwd
cd ..
pwd
cd .
pwd
```

### Absolute/Relative Paths
```bash
cd /tmp
pwd
cd ../etc
pwd
```

### Edge Cases
```bash
cd ~
cd /nonexistent
cd ""
```

## 13. PWD Command
```bash
pwd
cd /
pwd
cd ~
pwd
```

## 14. Relative Path
```bash
cd
./minishell
../program
../../usr/bin/env
```

## 15. Environment PATH
### Basic Commands
```bash
ls
grep
awk
```

### PATH Modification
```bash
unset PATH
ls  # Should fail
export PATH=/bin
ls  # Should work
```

## 16. Redirections
### Output Redirection
```bash
echo hello > file1
echo world > file2
echo append >> file1
```

### Input Redirection
```bash
cat < file1
grep hello < file1
```

### Heredoc
```bash
cat << EOF
hello
world
EOF
```

### Combined Redirections
```bash
cat < input > output
echo test >> file1 > file2
```

## 17. Pipes
### Basic Pipes
```bash
ls | grep a
cat file | grep hello | wc -l
```

### Multiple Pipes
```bash
ls | grep a | sort | uniq
echo hello | cat | cat | cat
```

### Error Cases
```bash
ls nonexistent | grep a
cat | ls nonexistent | grep a
```

## 18. Complex Tests
### Combined Features
```bash
echo hello > file && cat < file | grep hello > output
export TEST=hello && echo $TEST | cat > file && cat file
cd /tmp && ls -la | grep ^d > dirs && cat dirs
```

### Error Handling
```bash
./nonexistent || echo failed
cat nonexistent | grep test || echo "not found"
```

## Evaluation Flags
- [ ] Invalid Compilation
- [ ] Crash
- [ ] Incomplete Work

## Notes
- Compare all outputs with bash
- Check memory leaks
- Verify error messages
- Test edge cases
- Ensure proper cleanup

