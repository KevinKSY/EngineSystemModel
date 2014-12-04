
function delta = fcn(p)
    delta = zeros(size(p));
    idx0 = p<.33;
    delta(idx0) = .33-.303*p(idx0);
    idx1 = p<.56;
    delta(~(idx1==idx0)) = .3-.217*p(~(idx1==idx0));
    idx0 = p<.74;
    delta(~(idx1==idx0)) = -.068+.444*p(~(idx1==idx0));
    delta(~idx0) = .26;



