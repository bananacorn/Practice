(declare splitting)
(declare merging)

(def mergesort
    (fn [less? unsorted]
        (if (or (= (second unsorted) nil) (empty? unsorted))
            unsorted
            (splitting less? unsorted '() '()))))

(def splitting
    (fn [less? unsorted left right]
        (if (empty? unsorted)
            (merging less? (mergesort less? left) (mergesort less? right))
            (if (= (second unsorted) nil)
                (merging less? (mergesort less? (cons (first unsorted) left)) (mergesort less? right))
                (splitting less? (rest (rest unsorted)) (cons (first unsorted) left) (cons (second unsorted) right))))))

(def merging
    (fn [less? left right]
        (if (empty? left)
            right
            (if (empty? right)
                left
                (if (less? (first left) (first right))
                    (cons (first left) (merging less? (rest left) right))
                    (cons (first right) (merging less? left (rest right))))))))
