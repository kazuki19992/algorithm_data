"行番号を表示
set number

"バックスペース削除
set backspace=indent,eol,start
noremap! <C-?> <C-h>

"シンタックスハイライト
:syntax on

"TABインデントでスペース挿入
set expandtab
set tabstop=4
set shiftwidth=4

"文字コードをUFT-8に設定
set fenc=utf-8

" バックアップファイルを作らない
set nobackup

" スワップファイルを作らない
set noswapfile

" 編集中のファイルが変更されたら自動で読み直す
set autoread

" バッファが編集中でもその他のファイルを開けるように
set hidden

" 入力中のコマンドをステータスに表示する
set showcmd

" 現在の行を強調表示
set cursorline

" 現在の行を強調表示（縦）
" set cursorcolumn

" 行末の1文字先までカーソルを移動できるように
set virtualedit=onemore

" ビープ音を可視化
set visualbell

" 括弧入力時の対応する括弧を表示
set showmatch

" ステータスラインを常に表示
set laststatus=2

" コマンドラインの補完
set wildmode=list:longest

" 折り返し時に表示行単位での移動できるようにする
nnoremap j gj
nnoremap k gk


"オートインデント
"有効化
set autoindent



"検索
"検索時に大文字小文字区別なし
set ignorecase

"小文字検索時に大文字小文字無視検索
set smartcase

"ハイライト表示
set hlsearch

"ファイル末尾まで検索したら先頭から
set wrapscan



