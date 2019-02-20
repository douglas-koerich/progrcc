set backspace=eol,start,indent
set nobackup

set cindent
set colorcolumn=100
set shiftwidth=4
set tabstop=4
set softtabstop=4
set expandtab
set smarttab

filetype on
filetype plugin indent on
set ffs=dos,unix

set hlsearch
set incsearch
set ruler
set number
syntax enable

set showcmd
set wildignore=*.o,*.d
set wildmenu

set title

map <C-\>l :pyf ~/.vim/clang-format.py<cr>
imap <C-\>l <c-o>:pyf ~/.vim/clang-format.py<cr>
