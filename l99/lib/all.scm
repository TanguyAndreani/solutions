(define (my-last ls)
  (if (or (not (list? ls)) (null? ls))
      'undefined
      (if (null? (cdr ls))
          ls
          (my-last (cdr ls)))))

(define (my-but-last ls)
  (if (or (not (list? ls)) (null? ls) (null? (cdr ls)))
      'undefined
      (if (null? (cddr ls))
          ls
          (my-last (cdr ls)))))