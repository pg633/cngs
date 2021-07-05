syntax on " 语法高亮
syntax enable
set background=dark
colorscheme solarized

autocmd InsertLeave * se nocul  " 用浅色高亮当前行 
autocmd InsertEnter * se cul    " 用浅色高亮当前行 

set ruler           " 显示标尺

set showcmd         " 输入的命令显示出来，看的清楚些

set cmdheight=1     " 命令行（在状态行下）的高度，设置为1
"set whichwrap+=<,>,h,l   " 允许backspace和光标键跨越行边界(不建议)
set scrolloff=3     " 光标移动到buffer的顶部和底部时保持3行距离
set novisualbell    " 不要闪烁(不明白)


set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}   "状态行显示的内容 
set laststatus=1    " 启动显示状态行(1),总是显示状态行(2) 
set foldenable      " 允许折叠 
set foldmethod=manual   " 手动折叠 

" 映射全选+复制 ctrl+a
map <C-A> ggVGY
map! <C-A> <Esc>ggVGY
map <F12> gg=G
" 选中状态下 Ctrl+c 复制
vmap <C-c> "+y

"比较文件
nnoremap <C-F2> :vert diffsplit
"新建标签
map <M-F2> :tabnew<CR>
"列出当前目录文件
map <F3> :tabnew .<CR>
"打开树状文件目录
map <C-F3> \be

set autowrite
set ruler                   " 打开状态栏标尺
set cursorline              " 突出显示当前行
set magic                   " 设置魔术
set guioptions-=T           " 隐藏工具栏
set guioptions-=m           " 隐藏菜单栏

" add tab space
set ts=4
set softtabstop=4
set shiftwidth=4
" tab 替换为 空格
set expandtab
set autoindent
set expandtab




" set mouse-=a
" 取消上下左右
noremap <up> <nop>
noremap <down> <nop>
noremap <left> <nop>
noremap <right> <nop>
" jk 替换 Esc
inoremap kj <Esc>

" command mode
"cmoremap <C-j> <t_kd>
"acnoremap <C-k> <t_ku>
cnoremap <c-a> <Home>
cnoremap <c-e> <End>
noremap <C-h> ^
noremap <C-l> $

" // Ctrl+j组合键，在插入模式下返回命令模式
//imap <C-j> <Esc>
"  Ctrl+k组合键，在插入模式下，光标后退一格
//imap <C-k> <Esc>A

//noremap <C-h> <left>
//noremap <C-j> <down>
noremap <C-k> <up>
noremap <C-l> <right>
inoremap <C-h> <left>
inoremap <C-j> <down>
inoremap <C-k> <up>
inoremap <C-l> <right>
cnoremap <c-h> <left>
cnoremap <c-j> <down>
cnoremap <c-k> <up>
cnoremap <c-l> <right>

