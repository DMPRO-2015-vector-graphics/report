
add_cus_dep( 'glo', 'gls', 0, 'makeglossaries' );
   sub makeglossaries {
      system( "makeglossaries \"$_[0]\"" );
   }

add_cus_dep( 'acr', 'acn', 0, 'makeacr2acn' );
sub makeacr2acn {
    system( "makeindex -s \"$_[0].ist\" -t \"$_[0].alg\" -o \"$_[0].acn\" \"$_[0].acr\"" );
}
